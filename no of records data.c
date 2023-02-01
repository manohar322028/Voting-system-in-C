#include<stdio.h>
int main()
{
    int n;
    FILE *f;
    f=fopen("no of records.txt","w");
    printf("*****correction*********\n");
    printf("enter the number corrected number:");
    scanf("%d",&n);
    putw(n,f);
    printf("value of number of records is changed. Thankyou!!\n");
    return 0;
}
