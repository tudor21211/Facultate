#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nume[25];
    char telefon[10];
    int an;
    int venit;
} agenda;
FILE *f;
FILE *o;
int N;
int contor = 0;
void mutarePersoane(agenda a[N])
{
    int c=0,j;
    for (int i=0; i<N; i++)
    {

        if (a[i].venit<1000)
        {
            agenda tmp=a[i];
            for (j=i; j<N; j++)
                a[j]=a[j+1];
            a[N-1] =tmp;
            c++;
            contor++;
        }
        if (c==2) return;
    }
}

void sortareAlfabetica(agenda a[N], int s, int d)
{

    int i=s;
    int j=d;
    agenda x;
    for (int k=i; k<=j; k++)
        if ((((2022-a[k].an)<=40) && ((2022-a[k].an)>=30)))
        {
            x = a[k];
            break;
        }
    printf("PIVOT - %s\n",x.nume);
    agenda tmp;
    do
    {

        while ((strcmp(a[i].nume,x.nume)<0) || (((2022-a[i].an)>40) || ((2022-a[i].an)<30)))
        {
            printf("I:%s\n",a[i].nume);
            i++;
        }

        while ((strcmp(a[j].nume,x.nume)>0) || (((2022-a[j].an)>40) || ((2022-a[j].an)<30)))
        {
            printf("J:%s\n",a[j].nume);
            j--;
        }

        if (i<=j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    while (i<=j);
    //for (i=0; i<N; i++)
   // {
     //   printf("%s\n",a[i].nume);
    //}
    if (s<j) sortareAlfabetica(a,s,j);
    if (d>i) sortareAlfabetica(a,i,d);

}


void afisare (agenda a[N])
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("%s %s %d %d\n",a[i].nume,a[i].telefon,a[i].an,a[i].venit);
    }

}

int main()
{
    f = fopen("agenda.txt","r");
    o=fopen("rezultat.txt","w");
    if (!f)
    {
        printf("Eroare deschidere fisier");
        exit(1);
    }
    fscanf(f,"%d",&N);

    agenda a[N];
    int i;

    for (i=0; i<N; i++)
    {
        fscanf(f,"%s",a[i].nume);
        fscanf(f,"%s",a[i].telefon);
        fscanf(f,"%d",&a[i].an);
        fscanf(f,"%d",&a[i].venit);
    }
    fclose(f);
    for (i=0; i<N; i++)
    {
        printf("%s\n",a[i].nume);
    }
    sortareAlfabetica(a,0,N-1);

    afisare(a);
    fclose(f);
    fclose(o);
    return 1;
}
