#include<iostream>
using namespace std;
class Item
{
     public:
    int value,weight;
    double ratio;
    Item(int v,int w)
    {
        value=v;
        weight=w;
        ratio=value/weight;
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

                    int v =  I[i].value;
                    int w=I[i].weight;
                   // char ch=L[i].ch;
                    I[i].value=I[j].value;
                    I[i].weight=I[j].weight;
                    I[j].value =v;
                    I[j].weight=w;

                }

            }

        }

}
