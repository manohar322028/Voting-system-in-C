#include<stdio.h>
#include<conio.h>
FILE *p;
struct login{char usn[30],pw[10];}us;

int main()
{
    int no;
    printf("\n\n\t\tENTER THE AUTHORIZED PIN NUMBER:");
    scanf("%d",&no);
    if(no==2057)
    {
    system("cls");
    fflush(stdin);
    printf ("\n\t\t*****sign in**********\n");
    printf("enter username:");
    gets(us.usn);
    fflush(stdin);
    printf("enter password:(maximum 8 characters)");
    gets(us.pw);
    fflush(stdin);
    p=fopen("login.txt","w");
    fwrite(&us,sizeof(us),1,p);
    fclose(p);
    }
    else{
        printf("\n\t\twrong pin!!\n");
    }

    return 0;
}
