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
    ListNode * prev;
};


class LinkedListDoubly
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListDoubly()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertFirst(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;

        if(list==0) //inserting the first item
        {
            newNode->next = 0;
            newNode->prev = 0;
            list = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = list;
            list->prev = newNode;
            newNode->prev = 0;
            list = newNode;
        }
        length++;
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

    void printListForward()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {


    if(list == 0) {
       return insertFirst(item);
    }

     ListNode * node = new ListNode();
        node->item = item;
        ListNode * temp = tail;
        node->next =0;
        node->prev = temp;
        temp->next = node;
        tail = tail->next;

        length++;

        return SUCCESS_VALUE;

    }

    int deleteLast()
    {
        if(list ==0)
        {
          cout<<"List is empty"<<endl;
          return NULL_VALUE;

        }

       else if(length==1)
        {
            list->next =0;
            list = tail =0;
            length--;
            delete list;
            return SUCCESS_VALUE;
        }

        ListNode * temp = tail;
        tail = temp->prev;
        delete temp;
        tail->next =0;
        length--;

        return SUCCESS_VALUE;

    }

    void printListBackward()
    {
      ListNode *ptr = tail;

  // printf("\n[head] <=>");
   while(ptr != 0) {
      printf(" %d <=>",ptr->item);
      ptr = ptr->prev;
   }

printf("\n");

    }

};

int main(void)
{
    LinkedListDoubly ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Print forward. 5. Print backward. 6. exit. 7.Delete Last  8.Insert last \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertFirst(item);
        }
        else if(ch==2)
        {
            int item = ll.deleteLast();
            if(item!=NULL_VALUE) printf("Deleted: %d\n", item);
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
            ll.printListForward();
        }
        else if(ch==5)
        {
            ll.printListBackward();
        }
        else if(ch==7)
        {
            ll.deleteLast();

        }
        else if(ch==8)
        {
            int item;
            printf("Enter the item:");
            scanf("%d",&item);
            ll.insertLast(item);


        }
        else if(ch==6)
        {
            break;
        }
    }

}
