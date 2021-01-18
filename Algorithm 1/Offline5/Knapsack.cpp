#include<iostream>
#include<stdio.h>
using namespace std;
class Item
{
     public:
    int value,weight;
    int number;
    double ratio;
    void setValues(int v,int w,int i)
    {
        value=v;
        weight=w;
        ratio=value/weight;
        number=i;
    }


};

void sort(Item I[],int n)
{



    int i,j;
      for (i = 0; i < n; ++i)
        {

            for (j = i + 1; j < n; ++j)
            {

                if (I[i].ratio < I[j].ratio)
                {

                    Item temp=I[i];
                    I[i]=I[j];
                    I[j]=temp;

                }

            }

        }

}


void Knapsack(int w,Item I[],int n)
{
     int curWeight = 0;
    double f = 0.0;

    for (int i = 0; i < n; i++)
    {

        if (curWeight + I[i].weight <= w)
        {
            curWeight += I[i].weight;
            f += I[i].value;
            printf("%d Weight %d Value %d\n",I[i].number,I[i].weight,I[i].value);
        }


        else
        {
            int mod= w- curWeight;
            int val=I[i].value * ((double)mod / I[i].weight);
            f +=val;
            printf("%d Weight %d Value %d\n",I[i].number,mod,val);
            break;
        }
    }

    printf("The final value is %f",f);

}


int main()
{
    int n,maxCap,value,weight;
    scanf("%d",&n);
    Item *I=new Item[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&weight,&value);
        I[i].setValues(value,weight,i+1);

    }
    scanf("%d",&maxCap);
    sort(I,n);
    Knapsack(maxCap,I,n);




}
