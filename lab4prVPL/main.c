#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
typedef struct
    {
        char nume[40];
        char gen;
        int nota;
    }student;


    void citire(int N, student arr[])
    {   int i;
        char *stringg;
        for(i=0;i<N;i++){
        scanf("%d %c %[^\n]s",&arr[i].nota,&arr[i].gen,stringg);
        strcpy(arr[i].nume,stringg);
    }
}


    void bubbleSort(student arr[], int N)
    {
    int i, j;
    student temp;
    for (i = 1; i < N; i++)
        for (j = N-1; j >=i; j--)
        if (strcmp(arr[j-1].nume,arr[j].nume)>0){
            temp = arr[j-1];
            arr[j-1]= arr[j];
            arr[j]=temp;
        }
    }



    bool compararee(student s1, student s2)
    {
        if (s1.nota>5 && s2.nota < 5) return true;
        else if (s1.nota < 5 && s2.nota > 5) return false;

        if ((s1.nota <=5 && s2.nota <=5) ||(s1.nota > 5 && s2.nota >5))
        {
            if (s1.gen == 'M' && s2.gen == 'F') return true;
        }
        if ((s1.gen == s2.gen) && (strcmp(s1.nume,s2.nume)>0)) return true;
        return false;


    }
   void bubbleSort1(student arr[], int N)
    {
    int i, j;
    student temp;
    for (i = 1; i < N; i++)
        for (j = N-1; j >=i; j--)
        if (compararee(arr[j-1],arr[j])){
            temp = arr[j-1];
            arr[j-1]= arr[j];
            arr[j]=temp;
        }
    }

    void afisareStudenti(student arr[], int N)
    {
        int i;
        for (i=0;i<N;i++)
        {
            printf("%s ",arr[i].nume);
             printf("%c ",arr[i].gen);
              printf("%d\n",arr[i].nota);
        }

    }


    void cautaNume(student arr[],int N, char nume[])
    {   int p=0;
        int i;
        for (i=0;i<N;i++)
        {
            if (!strncmp(arr[i].nume,nume,strlen(nume))) {printf("%d",i);break;}
        }

    }



int main()
{
    int N;
    char nume[40],nume1[40];
    printf("N=");
    scanf("%d",&N);
    student *arr = (student*)malloc(sizeof(student)*N);
    citire(N,arr);
    bubbleSort(arr,N);
    afisareStudenti(arr,N);
    scanf("%s",nume);
    cautaNume(arr,N,nume);
    bubbleSort1(arr,N);
    afisareStudenti(arr,N);
    scanf("%s",nume1);
    cautaNume(arr,N,nume1);

}
