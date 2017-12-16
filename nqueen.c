//N queens code by Sir's method.
#include <stdio.h>
#include <stdlib.h>
int n=4;
void nQueen(int k,int x[])
{
    int i,p,j;
    for(i=1;i<=n;i++)
    {
        x[k]=i;
        for(p=1;p<=k-1;p++)
        {
            if((x[k]==x[p])||(abs(x[k]-x[p])==abs(k-p)))
                break;
        }
            if(p==k)
            {
                if(k<n)
                    nQueen(k+1,x);
                else{
                    for(j=1;j<=n;j++)
                        printf("%d",x[j]);
                    printf("\n");
 
                }
            }
 
    }
}
int main(void) {
    //printf("Enter number od queens");
    //scanf("%d",&n);
    int x[n+1];
    nQueen(1,x);
	// your code goes here
	return 0;
}