#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n;

typedef struct Matrice
{
    int val;
    bool verificat;
}Matrice;

Matrice **matrice;

typedef struct coordenate
{
    int x,y;
}coordonate;

coordonate *a;
coordonate *pos;

 void initializare() //int pos[] variabila globala
{

    pos[0].x = 0; //NORD
    pos[0].y = -1;
    pos[3].x = 1; //EST
    pos[3].y = 0;
    pos[2].x = 0; //SUD
    pos[2].y = 1;
    pos[1].x = -1; //VEST
    pos[1].y = 0;
}

void printare(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("A[%d]=(%d,%d)->",i,a[i].x,a[i].y);
    }
    printf("\n");
}

bool solutie(int k,coordonate c)
{
    if( c.x==0 || c.y==0 || c.x==n-1 || c.y==n-1) return true; else return false;
}

bool valid(coordonate c, int k)
{
    if(matrice[c.x][c.y].verificat==true) return false;
    else
    {
        if(matrice[a[k].x][a[k].y].val<matrice[c.x][c.y].val) return false; else return true;
    }
}

void backtracking(int k)
{
    //printare(k);
    int i;
    coordonate aux;
    if (solutie(k,a[k-1])){
        printare(k);
    }
    else
    {
        for(i=0;i<4;i++)
        {
            aux.x = a[k - 1].x + pos[i].x;
            aux.y = a[k - 1].y + pos[i].y;
            if (valid(aux,k-1)) {
                //printf("(%d,%d)",aux.x,aux.y);
                a[k] = aux;
                matrice[a[k].x][a[k].y].verificat = true;
                backtracking(k+1);
                matrice[a[k].x][a[k].y].verificat = false;
            }
        }
    }
}



int main()
{
    FILE *f=fopen("matrice.txt","r");

    fscanf(f,"%d",&n);
    matrice=(Matrice **)malloc(n*sizeof(Matrice*));
    for(int i=0;i<n;i++)
    {
        matrice[i]=(Matrice *)malloc(n*sizeof(Matrice));
    }
    a=(coordonate*)malloc(n*n*sizeof(coordonate));
    pos=(coordonate*)malloc(n*sizeof(coordonate));
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            fscanf(f,"%d",&matrice[i][j].val);
            matrice[i][j].verificat = false;
        }
    }
    fscanf(f,"%d",&a[0].x);
    fscanf(f,"%d",&a[0].y);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
    }
    initializare();
    matrice[a[0].x][a[0].y].verificat=true;
    backtracking(1);
    return 0;
}
