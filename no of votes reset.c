#include<stdio.h>
FILE *p,*c,*h;
int z[500]={0},g=0;
struct votes{int m,dm,s1,s2,s3,s4,s5;}v;

int main()
{


 c=fopen("card no.txt","w");

    fwrite(z,sizeof(z),1,c);

    fclose(c);
h=fopen("no of cards.txt","w");
fwrite(&g,sizeof(g),1,h);
fclose(h);

    v.m=0;

    v.dm=0;

    v.s1=0;

    v.s2=0;

    v.s3=0;

     v.s4=0;

    v.s5=0;





    p=fopen("no of votes.txt","w");

    fwrite(&v,sizeof(v),1,p);

    printf("reset successful\n");

    fclose(p);

return 0;


}
