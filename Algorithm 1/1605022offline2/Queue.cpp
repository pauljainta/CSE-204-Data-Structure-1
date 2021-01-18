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






class Queue
{
    LinkedListWithTail ll;
public:
    Queue(){};

    void enqueue(int item)
    {
        ll.insertItem(item);

    }

    int dequeue()
    {
       ListNode *temp=ll.searchItem(1);
       if(temp!=0)
       {
           ll.deleteLast();
           return temp->item;
       }
       return NULL_VALUE;

    }
    void print()
    {
        ll.printList();

    }
};

int main(void)
{
    Queue qu;

    while(1)
    {
        printf("1. Enque. 2. Deque. 3.Print 4.Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("Enter item:");
            scanf("%d", &item);
            qu.enqueue(item);
        }
        else if(ch==2)
        {
            int item=qu.dequeue();
            printf("%d\n",item);
        }
        else if(ch==3)
        {
            qu.print();
        }
        else if(ch==4)
        {
            break;
        }
    }

}

