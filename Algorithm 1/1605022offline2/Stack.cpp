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
class LinkedList
{
public:
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

    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        return SUCCESS_VALUE ;
    }

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
        printf("Length: %d\n",length);
    }
    void printReverse(ListNode *list)
    {

        if (list ==0)
       return;

    // print the list after head node
    printReverse(list->next);

    // After everything else is printed, print head
    printf("%d\n", list->item);

    }

    //------------write code for the functions below-----------

    int insertLast(int item)
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

    int insertAfter(int oldItem, int newItem)
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



class Stack
{
    LinkedList ll;
public:
    Stack(){};
    void push(int item)
    {

        ll.insertItem(item);

    }
    int pop()
    {
       ListNode *temp=ll.getItemAt(1);
       if(ll.deleteFirst()==SUCCESS_VALUE)

       return temp->item;
       else return NULL_VALUE;

    }

    void print()
    {
      ll.printReverse(ll.list);
    }
};

int main(void)
{
    Stack st;

    while(1)
    {
        printf("1. Push. 2. Pop. 3.Print. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("Enter item:");
            scanf("%d", &item);
            st.push(item);
        }
        else if(ch==2)
        {
            int item=st.pop();
            printf("%d\n",item);
        }
        else if(ch==3)
        {
            st.print();

        }
        else if(ch==4)
        {
            break;
        }
    }

}
