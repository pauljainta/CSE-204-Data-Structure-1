#include<stdio.h>


void sort(int data[],int n,int max,int min){

    int SortedArray[n+1];

   if(min>=0)
   {



  //  int SortedArray[n+1];
    int countArray[max+1];
    for(int i=0;i<=max;i++)
    {
        countArray[i]=0;

    }


    for(int i=1;i<=n;i++)
     countArray[data[i]]++;



    for(int i=0;i<=max;i++)
      countArray[i+1]+=countArray[i];




     for(int i=1;i<=n;i++){
        SortedArray[countArray[data[i]]]=data[i];
        countArray[data[i]]--;
    }


     for(int i=1;i<=n;i++)
    {
        printf("%d\n",SortedArray[i]);

    }
   }
    else{
        min=min*(-1);

        int plus[max+1],minus[min+1];
        int i;

                for(i=0;i<max+1;i++)
                {

                      plus[i]=0;

                }
                for(i=0;i<=min;i++)
                {

                    minus[i]=0;
                }
                for(i=1;i<=n;i++)
                {

                    if(data[i]>=0)
                    {

                        plus[data[i]]++;
                    }
                    else if(data[i]<0)
                    {

                        minus[data[i]*(-1)]++;
                    }
                }
                for(i=min-1;i>=0;i--)
                {

                    minus[i]+=minus[i+1];
                }
                for(i=1;i<=max;i++)
                {

                    plus[i]+=plus[i-1];
                }
                for(i=0;i<=max;i++)
                {

                    plus[i]+=minus[0];
                }
                for(i=1;i<=n;i++)
                {

                    if(data[i]>=0)
                    {

                        SortedArray[plus[data[i]]]=data[i];
                        plus[data[i]]--;
                    }
                    else
                    {

                        SortedArray[minus[data[i]*(-1)]]=data[i];
                        minus[data[i]*(-1)]--;
                    }

                }
                printf("\n\n\n");
        for(i=1;i<=n;i++)
        {

            printf("%d\n",SortedArray[i]);
        }





    }



}


int main() {

	int n;
	int max,min;
	printf("Enter the value of n:");
	scanf("%d",&n);

	int data[n+1];
	printf("Give input:\n");
	for(int i=1;i<=n;i++)
    {

        scanf("%d",&data[i]);

    }
    max=data[1];
    min=data[1];
    for(int i=2;i<=n;i++)
    {
        if(data[i]>=max)
            max=data[i];
            else min=data[i];

    }

  //  printf("%d\n",min);
    sort(data,n,max,min);
    return 0;
}
