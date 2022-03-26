#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int N;

bool valid(int **a,int r, int c)
{

    if (a[r][c]==a[r-1][c-1] || a[r][c]==a[r-1][c+1] || a[r][c]==a[r+1][c-1] || a[r][c]==a[r+1][c+1])
    {
        return false;
    }

    if (r<=N-1 && c<=N-1) return true;
    return false;
}

bool solutie(int **a,int r, int c)
{

    if (c==N-1 && r==N-1) return true;
    else return false;

}

void afisare(int **a)
{
    int i,j;
    for (i=1; i<N; i++)
    {
        for (j=1; j<N; j++)
            if (a[i][j]==1) printf("rosu ");
            else if (a[i][j]==2) printf("verde ");
            else if (a[i][j]==3) printf("alb ");
            else if (a[i][j]==4) printf("negru ");
        printf("\n");
    }
    printf("\n");

}

void backtracking (int **a,int r, int c)
{

    int i;
    for (i=1; i<=4; i++)
    {
        a[r][c]=i;
        if (valid(a,r,c))
            if (solutie(a,r,c))
            {
                afisare(a);
            }
            else if (c==N-1 && r<N-1) backtracking(a,r+1,1);
            else if (c<N-1 && r<=N-1) backtracking(a,r,c+1);
    }

}

int main()
{
    printf("N+1=");
    scanf("%d",&N);

    int **a=(int**)malloc((N+1)*sizeof(int*));
    for (int index=0; index<N+1; ++index)
    {
        a[index] = (int*)malloc((N+1) * sizeof(int));
    }


    for (int i=0; i<N+1; i++)
        for(int j=0; j<N+1; j++)
            if (i==0 || j==0 || i==N || j==N) a[i][j]=-1;
            else a[i][j]=0;


    backtracking(a,1,1);

}
