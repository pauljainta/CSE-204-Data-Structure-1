#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
using namespace std;

#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int *list;
int length;
int clr_Flag=0;
int div_flag=0;


void initializeList()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}

int searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

int insertItem(int newitem)
{
    if(clr_Flag==1)
    {
        initializeList();
    }
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}

	list[length] = newitem ; //store new item
	length++ ;
	return SUCCESS_VALUE ;
}

int clear()
{
    length=0;
    listMaxSize=0;
    delete list;

    clr_Flag=1;
    return SUCCESS_VALUE;

}

int insertItemAt(int pos,int item)
{

    int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	}

   if(pos<length)
   {
     length++;

     list[length-1]=list[length-2];
     for(int j=length-3;j>=pos;j--)
     {

         list[j+1]=list[j];

     }
     list[pos]=item;


   }
   	return SUCCESS_VALUE ;


}
int shrink()
{
   int *tempList;
    if(length==(listMaxSize/2)&&listMaxSize!=LIST_INIT_SIZE)
    {


     //allocate new memory space for tempList
		listMaxSize = listMaxSize/2 ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ;

    }


    	return SUCCESS_VALUE ;

}




int deleteItemAt(int position) //version 2, do not preserve order of items
{
	if ( position>= length ) return NULL_VALUE;
	list[position] = list[length-1] ;
	length-- ;
	shrink();
	return SUCCESS_VALUE ;
}

int deleteAll()
{

    for(int j=0;j<length;j++)
    {

        deleteItemAt(j);
    }
    length=0;


    if(listMaxSize>LIST_INIT_SIZE)
    {


     //allocate new memory space for tempList
		listMaxSize = LIST_INIT_SIZE ;
		list = (int*) malloc (listMaxSize*sizeof(int)) ;


    }



}


int deleteItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return NULL_VALUE;
	deleteItemAt(position) ;
	return SUCCESS_VALUE ;
}

void deleteLast()
{

    length--;
    //shrink();


}
void printList()
{
    int i;
    for(i=0;i<length;i++)
    {
        printf("%d\n ", list[i]);
    }

    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

int getLength()
{
    return length;

}

void postfix()
{
    int sum;
    string str;
    cout<<"Input:";
    cin>>str;

    for(int i=0;i<str.length();i++)
    {

        if(str[i]>=48&&str[i]<=57)
        {
            insertItem(str[i]-48);
        }
        else{
            if(str[i]=='+')
            {
                int temp;
                temp=list[length-2]+list[length-1];
                deleteLast();
                deleteLast();
                insertItem(temp);

            }

             if(str[i]=='-')
            {
                int temp;
                temp=list[length-2]-list[length-1];

                deleteLast();
                deleteLast();
                insertItem(temp);

            }

             if(str[i]=='*')
            {
                int temp;
                temp=list[length-2]*list[length-1];
                deleteLast();
                deleteLast();
                insertItem(temp);

            }

            if(str[i]=='/')
            {
                if(list[length-1]==0)
                {
                    div_flag=1;
                    cout<<"invalid input"<<endl;

                }
                else{
                int temp;
                temp=(list[length-2])/(list[length-1]);
                deleteLast();
                deleteLast();
                insertItem(temp);
                }

            }



        }



    }


     if(div_flag!=1)
        cout<<list[0]<<endl;
        deleteLast();




}

/*int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item.\n");
        printf("4.deleteLast 5. Print. 6.InsertAt 7.deleteAll\n");
        printf("8.Clear 9.Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("Enter the item:");
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==4)
        {

            deleteLast();
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            int pos,item;
            cout<<"position ";
            cin>>pos;
            cout<<"Item";
            cin>>item;
            insertItemAt(pos,item);
        }

        else if(ch==7)
        {

            deleteAll();
        }
        else if(ch==8)
        {

            clear();
        }
        else if(ch==9)
        {

            break;
        }
    }

}*/
int main()
{
    initializeList();
    cout<<"task 7"<<endl;


    while(true)
      postfix();


}
