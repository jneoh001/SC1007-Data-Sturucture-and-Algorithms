#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;


int cr_bottom_up_dp_print(int *p, int n)
{
   if(n==0) return 0;

    int l[n+1];
    l[0] = 0;


    int sol[n];
    for(int i=1; i<=n; i++)
    {   

        int maxprofit = 0;
        int profit = 0;



        for(int j=1; j<=i ;j++)
        {
            profit = p[j] + cr_bottom_up_dp_print(p, n-j);

            if(profit >= maxprofit)
            {
                maxprofit = profit;
                sol[i] = j;
            } 
        }
        l[i] = maxprofit;
    }

    printf("%d",sol[n]);
    return l[n];
}

 
void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,4,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    
    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;
    
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    
    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;
                
    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}