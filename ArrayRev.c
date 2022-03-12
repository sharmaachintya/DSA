#include<stdio.h>
int rev(int arr[10], int n);
int main(){
    int arr[10], n, i;
    printf("Size: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter the Element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n BEFORE REVERSAL: \n");
    for (i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n AFTER REVERSAL: \n");
    rev(arr,n);

return 0;
}
int rev(int arr[10], int n)
{
    int arr2[10], i;
    for (i=n-1;i>=0;i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}