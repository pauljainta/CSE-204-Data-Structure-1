#include<stdio.h>

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    float item;
    ListNode * next;
};

class LinkedList
{

    ListNode * list;
    int length;

public:
    LinkedList()
    {
        list=0; //initially set to NULL
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertItem(float item) //insert at the beginning
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        return SUCCESS_VALUE ;
    }

    int deleteItem(float item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0) return NULL_VALUE ; //item not found to delete
        if (temp == list) //delete the first node
        {
            list = list->next ;
            delete temp;
            length--;
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }


    ListNode * searchItem(float item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

    void printList()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%f->", temp->item);
            temp = temp->next;
        }
        printf("\n");
       // printf("Length: %d\n",length);
    }

    //------------write code for the functions below-----------

    int insertLast(float item)
    {

        length++;
        ListNode *node =new ListNode;
        node->item=item;

        if(list==0)
        {
            return insertItem(item);

        }
        ListNode *temp=list;
        while(temp->next!=0)
        {
            temp=temp->next;

        }
       node->next=temp->next;
        temp->next=node;


        return SUCCESS_VALUE;
    }

    int insertAfter(float oldItem, float newItem)
    {
        length++;

       ListNode *temp=list;
       //ListNode *temp2=new ListNode;
       ListNode *node=new ListNode;
       node->item=newItem;
       while(1)
       {
           if(temp->item==oldItem||temp==NULL)
           {
              // temp2=temp->next;
               break;
           }
           temp=temp->next;

       }
       if(temp==NULL)
       {

           cout<<"Item not found"<<endl;
           length--;
           return NULL_VALUE;
       }
       node->next=temp->next;
       temp->next=node;

     return SUCCESS_VALUE;

    }

    ListNode * getItemAt(int pos)
    {
      if(pos>length)
      {
          ListNode *N=NULL;
          N->item=NULL_VALUE;

           return N;
      }

        ListNode *temp=list;
        int i=1;

        for(i=1;i<pos;i++)
        {
            temp=temp->next;

        }
        return temp;

    }

    int deleteFirst()
    {

        if(list==NULL)
        {
          cout<<"list is empty"<<endl;
          return NULL_VALUE;
        }
        length--;
        ListNode *tmp=list;
        delete list;
        list=tmp->next;

        return SUCCESS_VALUE;
    }






   void insertionSort(float item)
{
   ListNode *temp=list;
    	ListNode *prev=NULL;
    	ListNode *ptr;

    	ptr=new ListNode;
    	ptr->item=item;
    	ptr->next=NULL;

    	if(temp==NULL)
    	{
        		//Executes when linked list is empty
        		ptr->next=NULL;
        		list=ptr;
        		return;
    	}

    	if(item<temp->item)
    	{
        		//Executes if given data is less than data in first node of linked list
        		ptr->next=list;
        		list=ptr;
        		return;
    	}
    	else
    	{
        		while(temp!=NULL)
        		{
            			if(item>temp->item)
            			{
                				//Traverse to location we want to insert the node + 1 node
                				prev=temp;
                				temp=temp->next;
                				continue;
            			}
            			else
            			{
                	//Insert the node
                				prev->next=ptr;
                				ptr->next=temp;
                				return;
            			}
        		}
        		prev->next=ptr;
        		//Insert node at last
    	}

}










    ~LinkedList()
{


       ListNode *node =list;
       ListNode *temp=new ListNode;
      while (node != NULL)
     {
       temp = node;
      node = node->next ;
      free(temp);
     }
     list = NULL;

}

};



void BucSort(float arr[],int n,float min,float max)
{
    if(min>=0.0)
    {


    LinkedList *L=new LinkedList[n];
    for(int i=0;i<n;i++)
    {

        L[(int)(n*arr[i])].insertionSort(arr[i]);
    }
     for(int i=0;i<n;i++)
   {
      // printf("%d",i);
       L[i].printList();

   }

}


else
{
    int m=(float)n;
    //min=min*(-1.0)*m;
   // max=max*m;
    LinkedList *minus=new LinkedList[n];
    LinkedList *plus=new LinkedList[n];
  //  printf("0\n");
     for(int i=0;i<n;i++)
    {

        if(arr[i]<0.0)
        {

            minus[(int)(n*arr[i]*(-1))].insertionSort(arr[i]);
        }

        else
        {

            plus[(int)(n*arr[i])].insertionSort(arr[i]);

        }
    }

     for(int i=n-1;i>=0;i--)
   {
       minus[i].printList();

   }
    for(int i=0;i<n;i++)
   {
      // printf("%d",i);
       plus[i].printList();

   }




}

}
int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    float arr[n];
    float min;
    float max;
    for(int i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }
    min=arr[0];
    max=arr[0];
     for(int i=0;i<n;i++)
    {
        if(arr[i]<=min*1.0)
            min=arr[i];
            else
            max=arr[i];
    }
    //float f=-0.25;
//    printf("%f",max);




    BucSort(arr,n,min,max);


    return 0;
}
