#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char culori[6]= "agrvun";//u=albastru

bool solutie(char c[3],int l){

   if (l==2 &&((c[1]=='v') || (c[1]=='g')) && c[0]!=c[1] && c[1]!=c[2] && c[0]!=c[2]) return true;
    return false;

}

bool valid (char c[3],int l){

    //if ((c[0]!=c[1]) && (c[1]!=c[2]) && (c[0]!=c[2]) && l<=2) return true;
    //return false;
    int alb=0,galben=0,rosu=0,verde=0,albastru=0,negru=0;

    for (int i=0;i<l;i++){
        if (c[i]=='a') alb++;
        if (c[i]=='g') galben++;
        if (c[i]=='r') rosu++;
        if (c[i]=='v') verde++;
        if (c[i]=='u') albastru++;
        if (c[i]=='n') negru++;
    }

    if (alb<=1 && galben <=1 && rosu<=1 && verde<=1 && albastru<=1 && negru<=1 &&l<=2) return true;
    return false;
}

void afisare(char c[3])
{

    int i;
    for (i=0; i<3; i++)
    {
        if (c[i]=='a') printf("alb ");
        if (c[i]=='g') printf("galben ");
        if (c[i]=='r') printf("rosu ");
        if (c[i]=='v') printf("verde ");
        if (c[i]=='u') printf("albastru ");
        if (c[i]=='n') printf("negru ");
    }
    printf("\n");
}

void backtracking(char backk[3],int l)
{
    int i;
    for (i=0; i<6; i++)
    {
        backk[l] = culori[i];
        if (valid(backk,l))
            if (solutie(backk,l))
                afisare(backk);
                else backtracking(backk,l+1);
    }
}
int main()
{
    char backk[3]="";
    backtracking(backk,0);
}
