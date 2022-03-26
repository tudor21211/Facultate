#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
typedef struct
{
    char nume[40];
    char gen;
    int nota;
} student;


void citire(int N, student arr[])
{
    int i;
    char stringg[50];
    for(i=0; i<N; i++)
    {
        scanf("%d %c %[^\n]s",&arr[i].nota,&arr[i].gen,stringg);
        strcpy(arr[i].nume,stringg);
        scanf("\n");
    }
}

unsigned bits(unsigned x, int k, int j)
{
    return (x>>k)&~(~0<<j);
}

void radix_exchange (int left, int right, int b, student a[])
{
    int i,j;
    student aux;
    if((right>left) && (b>=0))
    {
        i= left;
        j= right;

        do
        {
            while((bits(a[i].nota,b,1)==1)&&(i<j)) i= i+1;
            while((bits(a[j].nota,b,1)==0)&&(i<j)) j= j-1;
            aux= a[i];
            a[i]= a[j];
            a[j]= aux;
        }
        while (!(j==i));
        if (bits(a[right].nota,b,1)== 1) j= j+1;
        radix_exchange(left,j-1,b-1,a);
        radix_exchange(j,right,b-1,a);
        b--;
    }
}




bool compararee(student s1, student s2)
{
    if (s1.gen == 'M' && s2.gen == 'F') return false;
    else if (s1.gen == 'F' && s2.gen == 'M') return true;
    if (s1.nota < s2.nota) return true;
    else return false;
    if (strcmp(s1.nume,s2.nume)<0) return true;
    else return false;


}

void quicksort(int left,int right,student arr[]) //quicksort nu poate fi implementat stabil
{
    int i=left,j=right;
    student x=arr[(left+right)/2];
    student temp;
    do
    {
        while(compararee(arr[i],x))i++;
        while(compararee(x,arr[j]))j--;
        if(i<=j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(left<j)quicksort(left,j,arr);
    if(right>i)quicksort(i,right,arr);
}





void afisareStudenti(student arr[], int N)
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("%s ",arr[i].nume);
        printf("%c ",arr[i].gen);
        printf("%d\n",arr[i].nota);
    }

}


void cautaNume(student arr[],int N, char nume[])
{
    int p=0;
    int i;
    for (i=0; i<N; i++)
    {
        if (!strncmp(arr[i].nume,nume,strlen(nume)))
        {
            printf("%d\n",i);
            break;
        }
    }

}



int main()
{
    int N;
    char nume[40],nume1[40],n1[40],n2[40];
    scanf("%d",&N);
    student *arr = (student*)malloc(sizeof(student)*N);
    citire(N,arr);
    scanf("%[^\n]s",nume);
    scanf("\n");
    scanf("%[^\n]s",nume1);
    radix_exchange(0,N-1,4,arr);
    afisareStudenti(arr,N);
    cautaNume(arr,N,nume);
    quicksort(0,N-1,arr);
    afisareStudenti(arr,N);
    cautaNume(arr,N,nume1);

//printf("%d",bits(5,1,1));
}
