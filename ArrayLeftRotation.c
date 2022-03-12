#include<stdio.h>
#include<stdlib.h>
int leftRotation(int *arr, int *arr2, int n,int d);
int main()
{
    int n, i, d;
    printf("SIZE: ");
    scanf("%d",&n);
    printf("Enter the Number of Left Rotations: ");
    scanf("%d",&d);
    int *arr= malloc(sizeof(int) * n);
    for (i=0;i<n;i++)
    {
        printf("Enter the %d Element: ", i+1);
        scanf("%d",&arr[i]);
    }
    int *arr2=malloc(sizeof(int) * n);
    leftRotation(arr, arr2,n, d);
return 0;
}
int leftRotation(int *arr, int *arr2, int n, int d)
{
    int current=0, i;
    for (i=d;i<n;i++)
    {
        arr2[current]=arr[i];
        current++;
    }
    for (i=0;i<d;i++)
    {
        arr2[current]=arr[i];
        current++;
    }
    for (i=0;i<n;i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}