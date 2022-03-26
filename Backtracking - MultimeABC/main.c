#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char text[10];
char t[3]="abc";
int d=0;
bool valid (char sir[10],int l){
    int a=0,b=0,c=0,i;
    for (i=0;i<=l;i++){
        if (sir[i]=='a') a++;
       if (sir[i]=='b') b++;
       if (sir[i]=='c') c++;
    }
    if (a<=3 && b<=4 && c<=3 && l<=9) return true;
    return false;
}

bool solutie(char sir[10],int l){
    int a=0,b=0,c=0,i;
    if (l<9) return false;

    for (i=0;i<=l;i++){
        if (sir[i]=='a') a++;
       if (sir[i]=='b') b++;
       if (sir[i]=='c') c++;}
    if (a==3 && b==4 && c==3 && l==9) return true;
    }




void backtracking (char sir[10],int l){
    int i;

    for (i=0;i<3;i++){
            if (d==5) return;
            sir[l]=t[i];
        if (valid(sir,l))
            if (solutie(sir,l)){
            printf("%s \n",sir);d++;}
                else backtracking(sir,l+1);
    }
}

int main()
{
    backtracking(text,0);
}
