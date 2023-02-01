#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

#include<dos.h>

FILE *d,*r,*nov,*cno,*y,*h;
struct login{char usn[30], pw[10];}us;
char pa[10],un[30];

int login()
{
    int k;
    y=fopen("login.txt","r");
    fread(&us,sizeof(us),1,y);
    fclose(y);
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


struct party

{
    int regno;
  char name[20],m[20],dm[20],s1[20],s2[20],s3[20],s4[20],s5[20];

} p[20];




struct votes{int m,dm,s1,s2,s3,s4,s5;}v[20];

int main()
{
    int card,g;

    int i,n,ch,c,z[500],sum=0,u,j,lar1,lar2,lar3,lar4,lar5,lar6,lar7;

h=fopen("no of cards.txt","r");
fread(&g,sizeof(g),1,h);

fclose(h);


    r=fopen("no of records.txt","r");

    n=getw(r);

    fclose(r);





    goto options;

    main:

    system("cls");

    printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");
    fflush(stdin);


    printf("\n\t\tenter voter's card number:\t");

    scanf("%d",&card);


 cno=fopen("card no.txt","r");
 fread(z,sizeof(z),1,cno);
for(c=0;c<500;c++)
   {


        if(card==z[c]){
        printf("\n\t\tthe card has been already used\n\n\t\tpress any key to continue\n");
        getch();

        system("cls");

        goto options;
        }
   }

    fclose(cno);
   for(c=0;c<500;c++)
   {
       if(g==c) z[c]=card;
   }

 g=g+1;

h=fopen("no of cards.txt","w");
fwrite(&g,sizeof(g),1,h);
fclose(h);

  cno=fopen("card no.txt","w");
   fwrite(z,sizeof(z),1,cno);
   fclose(cno);

    fflush(stdin);

    system("cls");

    printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");

    printf("\n\t\t1. for mayor:\n");

   d= fopen("party.dat","r");

    fread(p,sizeof(p),1,d);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t[%d]%s",i+1,p[i].name);
    }
    printf("\n\t\t[0]no vote\n");

    fclose(d);

    scanf("%d",&ch);


    for(i=0;i<n;i++){

           if(ch==i+1)
               {

                v[i].m=v[i].m+1;


               }
       }

        nov=fopen("no of votes.txt","w");

       fwrite(v,sizeof(v),1,nov);
        fclose(nov);


     if(ch>n){ printf("\n\n\t\tinvalid input... vote discarded!!\n");

     printf("\n\t\tenter any key to continue....\n");
     getch();
     }
     system("cls");
     fflush(stdin);

      printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");

     printf("\n\t\t2.for deputy mayor:\n");

       d= fopen("party.dat","r");

    fread(p,sizeof(p),1,d);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t[%d]%s",i+1,p[i].name);
    }
      printf("\n\t\t[0]no vote\n");
    fclose(d);

    scanf("%d",&ch);


    for(i=0;i<n;i++){

           if(ch==i+1)
               {

                v[i].dm=v[i].dm+1;
            }

    }
     nov=fopen("no of votes.txt","w");

       fwrite(v,sizeof(v),1,nov);
        fclose(nov);



    if(ch>n){ printf("\n\n\t\tinvalid input... vote discarded!!\n");

     printf("\n\t\tenter any key to continue....\n");
     getch();
    }
     system("cls");

     fflush(stdin);

      printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");

     printf("\n\t\t3.for ward chairperson:\n");
       d= fopen("party.dat","r");

    fread(p,sizeof(p),1,d);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t[%d]%s",i+1,p[i].name);
    }
      printf("\n\t\t[0]no vote\n");
    fclose(d);

    scanf("%d",&ch);


    for(i=0;i<n;i++){

           if(ch==i+1)
               {

                v[i].s1=v[i].s1+1;




               }


    }
     nov=fopen("no of votes.txt","w");

       fwrite(v,sizeof(v),1,nov);
        fclose(nov);



    if(ch>n){ printf("\n\n\t\tinvalid input... vote discarded!!\n");

     printf("\n\t\tenter any key to continue....\n");

     getch();
    }
     system("cls");

     fflush(stdin);

      printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");

     printf("\n\t\t4.for woman member:\n");

       d= fopen("party.dat","r");

    fread(p,sizeof(p),1,d);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t[%d]%s",i+1,p[i].name);
    }
      printf("\n\t\t[0]no vote\n");
    fclose(d);

    scanf("%d",&ch);


    for(i=0;i<n;i++){

           if(ch==i+1)
               {

                v[i].s2=v[i].s2+1;

               }


    }
     nov=fopen("no of votes.txt","w");

       fwrite(v,sizeof(v),1,nov);
        fclose(nov);



     if(ch>n){ printf("\n\n\t\tinvalid input... vote discarded!!\n");

     printf("\n\t\tenter any key to continue....\n");

     getch();
     }
     system("cls");

      printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");
     printf("\n\t\t5.for dalit woman member:\n");

       d= fopen("party.dat","r");

    fread(p,sizeof(p),1,d);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t[%d]%s",i+1,p[i].name);
    }
      printf("\n\t\t[0]no vote\n");
    fclose(d);

    scanf("%d",&ch);


    for(i=0;i<n;i++){

           if(ch==i+1)
               {

                v[i].s3=v[i].s3+1;


               }

    }
     nov=fopen("no of votes.txt","w");

       fwrite(v,sizeof(v),1,nov);
        fclose(nov);



    if(ch>n){ printf("\n\n\t\tinvalid input... vote discarded!!\n");

     printf("\n\t\tenter any key to continue....\n");

     getch();
    }
     system("cls");
     fflush(stdin);

      printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");

     printf("\n\t\t6.for member 1:\n");

       d= fopen("party.dat","r");

    fread(p,sizeof(p),1,d);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t[%d]%s",i+1,p[i].name);
    }
      printf("\n\t\t[0]no vote\n");
    fclose(d);

    scanf("%d",&ch);


    for(i=0;i<n;i++){

           if(ch==i+1)
               {

                v[i].s4=v[i].s4+1;



               }

    }
     nov=fopen("no of votes.txt","w");

       fwrite(v,sizeof(v),1,nov);
        fclose(nov);



    if(ch>n){ printf("\n\n\t\tinvalid input... vote discarded!!\n");

     printf("\n\t\tenter any key to continue....\n");

     getch();
    }
     system("cls");

      printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");
     printf("\n\t\t7.for member 2:\n");

       d= fopen("party.dat","r");

    fread(p,sizeof(p),1,d);

    for(i=0;i<n;i++)
    {
        printf("\n\t\t[%d]%s",i+1,p[i].name);
    }
      printf("\n\t\t[0]no vote\n");
    fclose(d);

    scanf("%d",&ch);


    for(i=0;i<n;i++){

           if(ch==i+1)
               {

                v[i].s5=v[i].s5+1;

               }

    }
     nov=fopen("no of votes.txt","w");

       fwrite(v,sizeof(v),1,nov);
        fclose(nov);



     if(ch>n){ printf("\n\n\t\tinvalid input... vote discarded!!\n");

     printf("\n\t\tenter any key to continue....\n");

     getch();
     }

     system("cls");

     fflush(stdin);

   options:
        printf("\n\n\t\t*******************ELECTRONIC VOTING SYSTEM***********************\n");

         printf("\n\t\t[1]new voter\t[2]see results\t[0]end process\n");

     scanf("%d",&ch);

     switch(ch)
     {
         case 1: goto main;
         break;
         case 2:
             fflush(stdin);
            system("cls");

          u= login();


    if (u==1)
    {
               system("cls");
                d=fopen("party.dat","r");
                nov=fopen("no of votes.txt","r");
             fread(p,sizeof(p),1,d);
            fread(v,sizeof(v),1,nov);



               printf("\n\n\t\t===================\n\t\t   WINNING LIST\n\t\t================\n\n");
              printf("\n\n\t\t\t\tMAYOR");
               lar1=v[0].m;
               for(i=0;i<n;i++){

        if(v[i].m>lar1)
        {
                lar1=v[i].m;

                }
           }
               for(i=0;i<n;i++){
                    if(v[i].m==lar1) printf("\n\t\tparty name:   %s\n\t\tname:   %s\n\t\tno. of votes:   %d\n\n",p[i].name,p[i].m,v[i].m);
               }
   printf("\n\n\t\t\t\t DEPUTY MAYOR");
               lar2=v[0].dm;
               for(i=0;i<n;i++){

        if(v[i].dm>lar2)
        {
                lar2=v[i].dm;

                }
           }
               for(i=0;i<n;i++){
                    if(v[i].dm==lar2) printf("\n\t\tparty name:   %s\n\t\tname:   %s\n\t\tno. of votes:   %d\n\n",p[i].name,p[i].dm,v[i].dm);
               }
                 printf("\n\n\t\t\t\tWARD CHAIRPERSON");
               lar3=v[0].s1;
               for(i=0;i<n;i++){

        if(v[i].s1>lar3)
        {
                lar3=v[i].s1;

                }
           }
               for(i=0;i<n;i++){
                    if(v[i].s1==lar3) printf("\n\t\tparty name:   %s\n\t\tname:   %s\n\t\tno. of votes:   %d\n\n",p[i].name,p[i].s1,v[i].s1);
               }
  printf("\n\n\t\t\t\tWOMAN MEMBER");
               lar4=v[0].s2;
               for(i=0;i<n;i++){

        if(v[i].s2>lar4)
        {
                lar4=v[i].s2;

                }
           }
               for(i=0;i<n;i++){
                    if(v[i].s2==lar4) printf("\n\t\tparty name:   %s\n\t\tname:   %s\n\t\tno. of votes:   %d\n\n",p[i].name,p[i].s2,v[i].s2);
               }
                 printf("\n\n\t\t\t\tDALIT WOMAN MEMBER");
               lar5=v[0].s3;
               for(i=0;i<n;i++){

        if(v[i].s3>lar5)
        {
                lar5=v[i].s3;

                }
           }
               for(i=0;i<n;i++){
                    if(v[i].s3==lar5) printf("\n\t\tparty name:   %s\n\t\tname:   %s\n\t\tno. of votes:   %d\n\n",p[i].name,p[i].s3,v[i].s3);
               }

                 printf("\n\n\t\t\t\tMEMBER 1");
               lar6=v[0].s4;
               for(i=0;i<n;i++){

        if(v[i].s4>lar6)
        {
                lar6=v[i].s4;

                }
           }
               for(i=0;i<n;i++){
                    if(v[i].s4==lar6) printf("\n\t\tparty name:   %s\n\t\tname:   %s\n\t\tno. of votes:   %d\n\n",p[i].name,p[i].s4,v[i].s4);
               }

                 printf("\n\n\t\t\t\tMEMBER 2");
               lar7=v[0].s5;
               for(i=0;i<n;i++){

        if(v[i].s5>lar7)
        {
                lar7=v[i].s5;

                }
           }
               for(i=0;i<n;i++){
                    if(v[i].s5==lar7) printf("\n\t\tparty name:   %s\n\t\tname:   %s\n\t\tno. of votes:   %d\n\n",p[i].name,p[i].s5,v[i].s5);
               }
        printf("\n\t\t================================\n\t\t\tLIST OF RECORDS\n\t\t================================\n\n");









for(i=0;i<n;i++)
{

            {

             printf("\nregistration no.:%d\nparty name:%s\nvotes for mayor:%d\nvotes for deputy mayor:%d\nvotes for ward chairperson:%d\nvotes for woman member:%d\nvotes for dalit woman member:%d\nvotes for member 1:%d\nvotes for member 2:%d\n",p[i].regno,p[i].name,v[i].m,v[i].dm,v[i].s1,v[i].s2,v[i].s3,v[i].s4,v[i].s5);

             printf("=========================================================== \n\n");
            }
}

            fclose(d);
            fclose(nov);
            printf("\npress any key to go back to menu\n");
            getch();
            system("cls");
            goto options;
}
else{ printf("\n\t\twrong user name or password\n");
getch();
system("cls");
goto options;}




        break;

        case 0:
fflush(stdin);
          u= login();


    if (u==1){
            printf("\n\n\t\tare you sure to end process?\n\t\t[1]yes\t[0]no\n");

                  scanf("%d",&ch);

            if(ch==0){system("cls");
            goto options;}
                break;}
    else{printf("\n\t\twrong user name or password\n");
    getch();
    system("cls");
    goto options;
    break;
                }
        default: system("cls");
        goto options;
     }





     return 0;
    }





