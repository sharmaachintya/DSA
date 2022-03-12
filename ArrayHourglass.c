#include<stdio.h>
int Hourglass(int arr[6][6]);
int main(){
    int arr[6][6];
    int i, j, res=0;
    for (i=0;i<6;i++)
    {
        for (j=0;j<6;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    res = Hourglass(arr);
    printf("%d ",res);
return 0;
}
int Hourglass(int arr[6][6])
{
    int i, j, output=-99;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            int result=0;
            result=result+arr[i][j];
            result=result+arr[i][j+1];
            result=result+arr[i][j+2];
            result=result+arr[i+1][j+1];
            result=result+arr[i+2][j];
            result=result+arr[i+2][j+1];
            result=result+arr[i+2][j+2];
            if (result > output)
            {
                output=result;
            }
        }
    }
    return output;
}