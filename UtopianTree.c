#include<stdio.h>
int main()
{
    int n, i, l, j;
    printf("Enter the Number of Test Cases: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&l);
        int H=1;
        for (j=0;j<l;j++)
        {
            if (j%2==0)
            {
                H++;
            }
            else if (j%2!=0)
            {
                H=H*2;
            }
        }
        printf("%d",H);
    }

return 0;
}