#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cerinta : https://pastecode.io/s/32hs2r6m

typedef struct
{
    int id;
    char meserie[351];
} loc_munca;


    int nr=0;
    FILE *f;
    loc_munca *arr = NULL, *xtmp;



void cautare_binara(int x)
{
    int numarr = nr;
    loc_munca *a = arr;

    int stanga=0, contor=0, mijloc,dreapta=numarr-1;

    while(stanga <= dreapta)
    {
        mijloc = (stanga+dreapta) / 2;
        if(a[mijloc].id == x)
        {
            contor = 1;
            break;
        }
        else
        {
            if(a[mijloc].id < x)
                dreapta = mijloc-1;
            else
                stanga = mijloc+1;
        }
    }
    if(contor)
    {
        printf("%s\n",a[mijloc].meserie);
    }
    else
    {
        printf("COD INEXISTENT\n");
    }
}

void cautare_liniara(char cuvant[50])
{
    int NR = nr;
    char x[50];
    strcpy(x,cuvant);

    char **p;
    p = malloc(NR*sizeof(char*));

    if(p==NULL)
    {
        printf("Insufficient memory");
        free(p);
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<NR-1; i++)
    {
        char tmp[351];
        strcpy(tmp,arr[i].meserie);

        char c1[351];
        strcpy(c1, strtok(tmp," /-,"));

        p[i] = malloc((strlen(c1)+1)*sizeof(char));
        strcpy(p[i], c1);

    }

    int contor, j=0;
    do
    {
        contor=0;
        int i;
        for(i=j; (i<NR-1) && (strcmp(p[i],x)!=0); i++);

        if (strcmp(p[i],x)==0)
        {
            /*am gasit elementul x la indicele i*/
            printf("%d %s\n",arr[i].id, arr[i].meserie);
            contor=1;
            j=i+1;
        }
        else
        {

        }
    }
    while(contor==1);
}

void analise(char l[351])
{

    if(strstr(l,"Cod")==NULL)
    {


        xtmp = (loc_munca*)realloc(arr, sizeof(loc_munca)*(nr+1));
        if(xtmp == NULL)
        {
            printf("Insufficient memory");
            free(arr);
            exit(EXIT_FAILURE);
        }

        arr = xtmp;

        char *split;
        split=strtok(l,"\t");
        int contor = 0;

        while(split)
        {
            if (contor == 0) //in aceasta secventa verificam daca trebuie sa adaugam ce avem in split la id sau la meserie
            {
                arr[nr].id = atoi(split);
                contor++;
            }
            else
            {
                strcpy(arr[nr].meserie, split);
                contor++;
            }
            split = strtok(NULL,"\t");
        }
        nr++;
    }
}

void citire_fisier()
{
     char l[351];
    f = fopen("COR_Descrescator.txt", "r");

    if(f == NULL)
    {
        printf("Eroare deschidere fisier");
        exit(EXIT_FAILURE);
    }



    while(!feof(f))
    {
        fgets(l, 351, f);
        l[strcspn(l, "\n")] = '\0';
        analise(l);
    }
}

int main()
{
    citire_fisier();

    char cuv[50];
    int input_id;
    printf("Meserie loc munca pt codul introdus\n");
    printf("Introduceti cod:");
    scanf("%d",&input_id);
    cautare_binara(input_id);

    printf("Afisare toate ocupatii care contin urmatorul cuvant\n");
    printf("Introduceti cuvant:");
    scanf("%s",cuv);
    cautare_liniara(cuv);

    free(xtmp);
    free(arr);
    fclose(f);
    return 0;
}
