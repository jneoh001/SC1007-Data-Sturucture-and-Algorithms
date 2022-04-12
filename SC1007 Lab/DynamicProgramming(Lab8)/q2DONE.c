#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;

int cr_recursive(int *p, int n)
{
    //write your code herec
    if( n == 0) return 0;  // case where n == 0

    int maxprofit = 0;
    int profit = 0;

    for(int i = 1; i <= n; i++)
    {
        profit = p[i] + cr_recursive(p, n-i);
        
        if(profit>=maxprofit)   maxprofit = profit;
    }
   
   return maxprofit;
}

int cr_top_down_dp(int *p, int n)   // memoization since top down
{
    //write your code here
    int l[n+1];
    for(int i = 0; i<n+1; i++)
    {
        l[i] = 0;
    }

    if (n==0) return 0;

    if( l[n] == 0) // Have not been memoized
    {
        for(int j =1; j<=n; j++)
        {
            int profit = 0;
            int maxprofit = 0;
            for(int i=1; i<= n; i++)
            {
                profit = p[i] + cr_top_down_dp(p, n-i);

                if(profit >= maxprofit) maxprofit = profit;
            }

            l[j] = maxprofit;
        }
        
    }
    return l[n];
}

int cr_bottom_up_dp(int *p, int n)
{
    if(n==0) return 0;

    int l[n+1];
    l[0] = 0;

    for(int i=1; i<=n; i++)
    {   

        int maxprofit = 0;
        int profit = 0;
        for(int j=1; j<=i ;j++)
        {
            profit = p[j] + cr_bottom_up_dp(p, n-j);

            if(profit >= maxprofit) maxprofit = profit;
        }
        l[i] = maxprofit;
    }

    return l[n];

}
 
void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,5,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    
    n = sizeof(price_list) / sizeof(int) - 1;

    //printf(" n is %d\n",n);
    p = price_list;
    
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
    scanf("%d",&function);
    while (function != 0)
    {
        if (function == 1)
        {
            printf("The maximun value is: %d \n", cr_recursive(p,n));
        }
        else if (function == 2)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximun value is: %d \n", cr_top_down_dp(p,n));
        }
        else if (function == 3)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximun value is: %d \n", cr_bottom_up_dp(p,n));
        }
        printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
        scanf("%d",&function);
    }
}