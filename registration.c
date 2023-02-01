#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>





struct party

{
    int regno;
  char name[20],m[20],dm[20],s1[20],s2[20],s3[20],s4[20],s5[20];

} p;

char query[20],name[20],un[30],pa[10];

FILE *fp, *ft,*nop,*x;

int i,n,ch,l,found,del,c,k=0;
int pno;
struct login{char usn[30],pw[10];}us;
int login()
{
    x=fopen("login.txt","r");
    fread(&us,sizeof(us),1,x);
    fclose(x);
    printf("\n\n\t\t*******log in********\n");
    printf("\n\n\t\tenter user name:");
    gets(un);
    fflush(stdin);
    printf("\n\n\t\tenter password:");
    for(k=0;k<strlen(us.pw);k++)
    {

        pa[k]=getch();
        printf("*");

    }
    if (strcmp(us.usn,un)==0 && strcmp(us.pw,pa)==0) return 1;
    else return 0;
}

int main()

{
    int u,yn;
char t;
    u= login();

    if(u==0)printf("\twrong username or password!!\n");

    else{

main:
    fflush(stdin);
   nop= fopen("no of records.txt","r");
   pno=getw(nop);
   fclose(nop);



    system("cls");    /* ************Main menu ***********************  */

    printf("\n\t *******party registration***********\n\n");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Party registration\n\t\t[2] List all records\n\t\t[3] Search by party name\n\t\t[4] Edit a record\n\t\t[5] Delete a record\n\t\t[6] delete all records\n\t\t[7] About\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* *********************Add ************  */

    case 1:

        system("cls");





            fflush(stdin);


        do
            {
system("cls");
            fflush(stdin);
            printf("registration number:");

            scanf("%d",&p.regno);

            fflush(stdin);

            printf("Party name:");

            scanf("%[^\n]s",p.name);

            fflush(stdin);

            printf("name of contestant for mayor:");

            scanf("%[^\n]s",p.m);

            fflush(stdin);

            printf("name of contestant for deputy mayor:");

            scanf("%[^\n]s",p.dm);

            fflush(stdin);

             printf("name of contestant for ward chairperson:");

            scanf("%[^\n]s",p.s1);

            fflush(stdin);

            printf("name of contestant for woman member:");

            scanf("%[^\n]s",p.s2);

            fflush(stdin);

             printf("name of contestant for dalit woman member:");

            scanf("%[^\n]s",p.s3);

            fflush(stdin);

            printf("name of contestant for member 1:");

            scanf("%[^\n]s",p.s4);

            fflush(stdin);

            printf("name of contestant for member 2:");

            scanf("%[^\n]s",p.s5);

            fflush(stdin);
            printf("\n\t\t ARE YOU SURE TO SAVE THE RECORD?(Y/N)\t");

scanf("%c",&t);
if (t=='y'||t=='Y'){
            pno=pno+1;

            nop=fopen("no of records.txt","w");

            putw(pno,nop);

            fclose(nop);
             fp=fopen("party.dat","a");


 fwrite(&p,sizeof(p),1,fp);

        fclose(fp);
}

printf("\n\n\t\t[1] ADD ANOTHER RECORD           [2] FINISH\n\n\t");
scanf("%d",&yn);
            }while(yn==1);




        break;

        /* *********************list ************************  */

    case 2:

        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF RECORDS\n\t\t================================\n\n");

printf("\t\ttotal no. of parties registered=%d\n",pno);

            fp=fopen("party.dat","r");

            fflush(stdin);

          while(fread(&p,sizeof(p),1,fp)==1)

            {

             printf("\nregistration no.:%d\nparty name:%s\ncontestant for mayor:%s\ncontestant for deputy mayor:%s\ncontestant for ward chairperson:%s\ncontestant for woman member:%s\ncontestant for dalit woman member:%s\ncontestant for member 1:%s\ncontestant for member 2:%s\n",p.regno,p.name,p.m,p.dm,p.s1,p.s2,p.s3,p.s4,p.s5);

             printf("=========================================================== \n\n");
            }

            fclose(fp);



        break;

        /* *******************search **********************  */

    case 3:

        system("cls");

        do

        {


            found=0;

            printf("\n\n\t..:: SEARCH BY PARTY NAME\n\t===========================\n\t..::Name of party to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("party.dat","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&p,sizeof(p),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=p.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {
printf("\nregistration no.:%d\nparty name:%s\ncontestant for mayor:%s\n,contestant for deputy mayor:%s\n,contestant for ward chairperson:%s\n,contestant for woman member:%s\ncontestant for dalit woman member:%s\n,contestant for member 1:%s\n,contestant for member 2:%s\n",p.regno,p.name,p.m,p.dm,p.s1,p.s2,p.s3,p.s4,p.s5);

             printf("=========================================================== \n\n");

                    found++;



                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

        /* *********************edit *******************/

    case 4:

        system("cls");

        fp=fopen("party.dat","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Edit record\n===============================\n\n\t..::Enter the name of party to edit:");

        scanf("%[^\n]s",name);

        while(fread(&p,sizeof(p),1,fp)==1)

        {

            if(stricmp(name,p.name)!=0)

                fwrite(&p,sizeof(p),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::registration no.:");

        scanf("%d",&p.regno);

        fflush(stdin);

        printf("..::Party name:");

        scanf("%[^\n]s",p.name);

        fflush(stdin);

        printf("..::mayor:");

        scanf("%[^\n]s",p.m);

        fflush(stdin);

        printf("..::deputy mayor:");

        scanf("%[^\n]s",p.dm);

        fflush(stdin);

         printf("..::ward chairperson:");

        scanf("%[^\n]s",p.s1);

        fflush(stdin);

         printf("..::woman member:");

        scanf("%[^\n]s",p.s2);

        fflush(stdin);

         printf("..::dalit woman member:");

        scanf("%[^\n]s",p.s3);

        fflush(stdin);

         printf("..::member 1:");

        scanf("%[^\n]s",p.s4);

        fflush(stdin);

         printf("..::member 2:");

        scanf("%[^\n]s",p.s5);

        fflush(stdin);

        printf("\n");

        fwrite(&p,sizeof(p),1,ft);

        fclose(fp);

        fclose(ft);

        remove("party.dat");

        rename("temp.dat","party.dat");

        break;

        /* ********************delete *******************/

    case 5:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A RECORD\n\t==========================\n\t..::Enter the name of party to delete:");

        scanf("%[^\n]s",name);

        fp=fopen("party.dat","r");

        ft=fopen("temp.dat","w");

        while(fread(&p,sizeof(p),1,fp)!=0)

            if (stricmp(name,p.name)!=0)

                fwrite(&p,sizeof(p),1,ft);

        fclose(fp);

        fclose(ft);

        remove("party.dat");

        rename("temp.dat","party.dat");

        pno=pno-1;

        nop=fopen("no of records.txt","w");

         putw(pno,nop);

fclose(nop);


        break;
/*********delete all*****/
    case 6:
        system("cls");
        printf("are you sure to delete all records?\n\t\t [1]yes  [0] no\n");

        scanf("%d",&del);

        if(del==1)
       {
    fp= fopen("party.dat","w");

    fclose(fp);

    pno=0;
 nop=fopen("no of records.txt","w");

         putw(pno,nop);

fclose(nop);


       }
       break;

   case 7:
       system("cls");
        printf("\n\nHi, this is a sample application designed by Manohar Dahal, Shubhechha Marasini and Swostika Basukala.\nWe all are beginners in programming. Sorry for the errors if any.\nfor feedbacks, email us at: manohardahal40@gmail.com\n\t\tTHANKYOU!!!\n");
        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    }
    return 0;

}


