#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *f;
int N;
typedef struct
{

    char nume[25];
    int salar;
    int bonus;

} angajat;

void mutareAngajati(angajat a[N])
{
    int i;

    for (i=0; i<N; i++)
    {
        if(a[i].bonus)
            for (int j=0; j<N; j++)
                if (a[j].bonus==0)
                {
                    angajat aux;
                    aux = a[i];
                    a[i]=a[j];
                    a[j]=aux;
                }
    }


}

void sortareAngajati(angajat a[N],int stanga, int dreapta)
{

    int i=stanga,j=dreapta;
    angajat aux;
    int k=0;
    for(k=i; k<=j; k++)
        if (a[k].bonus==0)
        {
            aux = a[k];
            break;
        }

    angajat tmp;

    do
    {

        while(a[i].bonus==1 || a[i].salar>aux.salar) i++;
        while (a[j].bonus==1 || a[j].salar<aux.salar) j--;

        if (i<=j)
        {
            tmp = a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }
    }
    while(i<=j);

    if (stanga<j) sortareAngajati(a,stanga,j);
    if (dreapta>i) sortareAngajati(a,i,dreapta);

}




int main()
{
    f=fopen("angajati.txt","r");
    fscanf(f,"%d",&N);
    int i;
    //angajat *a = (angajat*)malloc(N*sizeof(angajat));
    angajat a[N];
    for (i=0; i<N; i++)
    {
        fscanf(f,"%s",a[i].nume);
        fscanf(f,"%d",&a[i].salar);
        fscanf(f,"%d",&a[i].bonus);
    }
    for (i=0; i<N; i++)
        printf("%s %d %d\n",a[i].nume,a[i].salar,a[i].bonus);
    printf("\n\n");
    //mutareAngajati(a);
    //for (i=0; i<N; i++)
        //printf("%s %d %d\n",a[i].nume,a[i].salar,a[i].bonus);
    printf("\n\n");
    sortareAngajati(a,0,N);
    for (i=0; i<N; i++)
        printf("%s %d %d\n",a[i].nume,a[i].salar,a[i].bonus);

}
