#include<stdio.h>
void menu();
void crypte();
void decrypte();
void genere();
void pq(int x);
void inscrit(int p,int q);
int premier(int z);
int pgcd(int x,int y);
int cle_privee(int e,int p,int q);
int crypter(char c,int e,int n);
char decrypter(long int s,int d,int n);
 int mod( long  int a, int e, int n);
int teste(int p);
void quiter();
main()
{
clrscr();
printf("\n\n\n\n\n\n\n\n\n\t\t\tAlgorithme de cryptage RSA\n");
getch();
menu();
}
void menu()
{
char choix;
clrscr();
printf("\n\n\n\n\t\tLe menu principal \n\n\n");
printf("\t1    ..      Le menu  cryptage .......\n\n");
printf("\t2    ..      Le menu  decryptage .....\n\n");
printf("\t3    ..      La generation des cles .. \n\n");
printf("\t4    ..      Quiter le programme ..... \n\n");
printf("\t  Votre choix..\t");
scanf("%c",&choix);
switch(choix)
{ case '1':clrscr();crypte();break;
  case '2':clrscr();decrypte();break;
  case '3':clrscr();genere();break;
case '4':clrscr();quiter();break;
default:menu();
}}
void crypte(){
FILE *f,*k;
char c,nom[20];
int i, d,e,n;
printf("\n\n\n\n\n\n\n\n\n\t\t\t le menu cryptage \n");
getch();
clrscr();

printf("\n\n\t\t Entrer la cle de chiffrement\n\n ");
do{
n=1;
puts(" Entrer n");
scanf("%d",&n) ;}
while(n<0);
do{
e=1;
puts(" Entrer e");
scanf("%d",&e);}
while(e<0);
clrscr();
printf("\n\n\t\tEntrer le nom du fichier cible (EX:source.txt)\n");
scanf("%s",nom);
f=fopen(nom,"r");
if(!f)
{printf("\n\n\t\tle fichier n'existe pas  ");
getch();
menu();}
k=fopen("crypte","w+");
i=0;
while(fread(&c,1,1,f)!=0)
 { fseek(f,1*i,0);
   fscanf(f,"%c",&c);
 d=crypter(c,e,n);
  fprintf(k,"%d\n",d);
  i++;

}
printf("\n\n\t\tle fichier crupte est sous le nom crupte\n ");
 fclose(f);
 fclose(k);
 getch();
 menu();
}

int crypter(char c,int e,int n)
{
 long int r=1,a;
a=((int)c);
while(e>0)
{
if(e%2==1) r=(r*a)%n;
a=(a*a)%n;
e/=2;}

return r;
}
void decrypte(){
FILE *f,*k;
char c,nom[20];
int d,s,e,n;
printf("\n\n\n\n\n\n\n\n\n\t\t\t le menu decryptage \n");
getch();
clrscr();
printf("\n\n\t\tEntrer la cle de dechiffrement\n\n ");
do{
n=1;
puts(" Entrer n");
scanf("%d",&n) ;}
while(n<0);
do{
d=1;
puts(" Entrer d");
scanf("%d",&d);}
while(d<0);
clrscr();
printf("\n\n\t\tEntrer le nom du fichier cible \n\n ");
scanf("%s",nom);
f=fopen(nom,"r");
if(!f){printf("\n\n\t\tle fichier n'existe pas ");getch();
menu();}
k=fopen("source","w");
while(!feof(f))
 {  fscanf(f,"%d\n",&s);
   c=decrypter(s,d,n);
   fprintf(k,"%c",c);
      }
printf("\n\n\t\tLe fichier decrypte est sous le nom 'source' ");
      fclose(f);
 fclose(k);
 getch();
 menu();
}

char decrypter(long int s,int d,int n)
{  long int r;
char x;
r=mod(s,d,n);
x=(( char)r);
return x;
}
 int mod( long int a, int e, int n)
{   int r=1;
while(e>0)
{
if(e%2==1) r=(r*a)%n ;
a=(a*a)%n;
e/=2;}
return r;
}
void genere()
{
int choix;
printf("\n\n\n\n\n\n\n\n\n\t\t\t La generation des cles \n");
getch();
clrscr();
pq(1);
}
void pq(int x)
{ int p,q,i,trouve,tab[10];
if(x==1)
{do
  { printf("\n Entrer p= ");
    scanf("%d",&p);

        }
 while (teste(p)==1);
do
  { printf("\n Entrer q= ");
    scanf("%d",&q);}
 while (teste(q)==1);
inscrit(p,q);}
else
{ p=80;
for(q=0;q<10;q++)
{i=2;trouve=1;
 while(i<(p/2)&&trouve==0)
   {if(p%i==0)
     trouve=1;
     i++;}
  if(trouve==0)tab[q]=p;
   p++;}
p=tab[rand()%10];
do
q=tab[rand()%10];
while(p==q);
inscrit(p,q);
}
}
void inscrit(int p,int q)
{ int n,e,d,z;
n=p*q;
z=(p-1)*(q-1);
e=premier(z);
clrscr();
printf("\n\n\tVotre cle puplique est:\n\ne=%d\tet n=%d\n",e,n);
d=cle_privee(e,p,q);
printf("\n\n\tVotre cle prive est:\n\nd=%d\tet n=%d\n\n\n\t",d,n);
puts(" frapper une touche pour retourner au menu principal ");
getch();
menu();
}
int premier(int z)
{ int h;
 int tab[100];
 int j=0,i=85;
 while(j<100){
 if(pgcd(z,i)==1)
 { tab[j]=i;
 i++;
 j++;}
else i++;}
h=tab[rand()%100];
return(h);
}
int pgcd(int x,int y)
   { int g;
    if(x<0)x=-x;
    if(y<0)y=-y;
    g=y;
    while(x>0)
     { g=x;
       x=y%x;
       y=g;
      }
     return(g);
    }
int cle_privee(int e,int p,int q)
{unsigned long int  d,r, ed ;
ed = 1;
do
{
ed = ed + (p-1)*(q-1);
r = ed % e ;
}while (r != 0);
d = ed / e;
return(d); }
int teste(int p)
{int i,trouve;
i=2;
trouve=0;
if(p==1){clrscr();puts(" le programme RSA n'admet pas le 1");return(1);}else{
while(i<=(p/2)&&trouve==0)
{if(p%i==0)
{clrscr();puts(" non premier");trouve=1;}
i++;}
if(trouve==1)return(1);else{if(p<0){clrscr();puts(" nombre negatif ");return(1);}else return(0);}}}
void quiter()
{printf("\n\n\n\n\n\n\n\n\n\t\t\tFin de programme   ");
getch();
exit(1);}
