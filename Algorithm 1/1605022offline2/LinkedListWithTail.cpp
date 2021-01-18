#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedListWithTail
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListWithTail()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    //add required codes to set up tail pointer
    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
         if(list==0)
       {
           tail=newNode;
       }
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;




        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
    int deleteItem(int item)
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
            delete temp ;
            length--;
        }

        else if(temp == tail)
        {
            deleteLast();
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            length--;
        }

        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
    ListNode * searchItem(int item)
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
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        printf("Length: %d\n",getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
  {

        ListNode *temp=new ListNode;
        temp->item=item;

	if(list ==0)
	{
		return insertItem(item);
	}
	else
	{
		tail->next =temp;
		tail= tail->next;
		tail->next=0;
		length++;

	}
	return SUCCESS_VALUE;


}

 ListNode * getItemAt(int pos)
    {
      if(pos>length)
      {
        //  ListNode *N=NULL;
        //  N->item=NULL_VALUE;

           return 0;
      }

        ListNode *temp=list;
        int i=1;

        for(i=1;i<pos;i++)
        {
            temp=temp->next;

        }
        return temp;

    }


    int deleteLast()
    {

       ListNode * temp=new ListNode;

	if(tail == 0)
	{
		cout<<"List is Empty"<<endl;
		return NULL_VALUE;
	}
	else if(length==1)
    {
        list=0;
        tail=0;
        length--;
        return SUCCESS_VALUE;
        //tail->next=0;
        //list->next=0;
    }
	else
	{
		temp =list;

		while(temp->next!=tail)
		{
		     temp = temp->next;
		}
        delete tail->next;
		tail = temp;
		tail->next = 0;
		length--;
	}

	return SUCCESS_VALUE;
    }
};

int main(void)
{
    LinkedListWithTail ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4.Insert Last. 5.DeleteLast. 6.Print 7.exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("Enter item:");
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            ll.deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            printf("Enter the item:");
            scanf("%d",&item);
            ll.insertLast(item);

        }
        else if(ch==5)
        {
            ll.deleteLast();

        }
        else if(ch==6)
        {
            ll.printList();
        }
        else if(ch==7)
        {
            break;
        }
    }

}
