#include <stdio.h>
#include <stdlib.h>

typedef struct palet
{
    long int cod;
    struct palet *urm;
} palet;

typedef struct depozit
{
    char nume[25];
    struct depozit *urm;
    struct palet *inceputPalet;
} depozit;

palet *nouPalet(int cod,palet *lista)
{

    palet *p = (palet*)malloc(sizeof(palet));
    if (!p)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    p->cod = cod;
    p->urm = lista;
    return p;

}
depozit *nouDepozit(char nume[25],palet *inceputPalet,depozit *lista)
{
    depozit *d = (depozit*)malloc(sizeof(depozit));
    if (!d)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
    }


    strcpy(d->nume,nume);
    d->urm = lista;
    d->inceputPalet = inceputPalet;
    return d;
}

palet *adaugaSfarsitPalet(int cod,palet *lista)
{
    if (!lista) return nouPalet(cod,NULL);
    palet *p = lista,*urm;

    for (urm = p->urm; urm; p=urm,urm=p->urm) {}

    p->urm = nouPalet(cod,NULL);
    return lista;
}
depozit *adaugaSfarsitDepozit(char nume[25],palet *inceputPalet,depozit *lista)
{

    if (!lista) return nouDepozit(nume,inceputPalet,NULL);
    depozit *d = lista, *urm;
    for (urm = d->urm; urm; d=urm,urm=d->urm) {}

    d->urm = nouDepozit(nume,inceputPalet,NULL);
    return lista;
}

void afisarePaleti(palet *lista)
{
    if (!lista) printf("Lista vida");
    palet *tmp = lista;
    while (tmp!=NULL)
    {
        printf("%ld->",tmp->cod);
        tmp=tmp->urm;
    }
    printf("\n");

}

void afisareDepozit(depozit *lista)
{

    if (!lista) printf("Lista vida");
    depozit *tmp = lista;
    while (tmp!=NULL)
    {
        printf("%s->",tmp->nume);
        afisarePaleti(tmp->inceputPalet);
        tmp=tmp->urm;
    }
    printf("\n");
}

depozit *eliminaPaleti(depozit *lista,int cod)
{

    depozit *d = lista;
    while(d)
    {
        int c=0;
        palet *urm;
        palet *p = d->inceputPalet;
        palet *ant;
       if (p->cod==cod)
        {
            ant = p;
            p=p->urm;
            ant->urm = NULL;
            d->inceputPalet = p;
        }
        for(urm=p->urm;urm;ant=p,p=urm,urm=p->urm)
        {
            if (p->cod == cod){
                ant->urm = p->urm;
                p->urm = NULL;
            }
        }
        if (p->cod==cod) {
            ant->urm = NULL;
        }
        d=d->urm;
    }
    return lista;

}

int main()
{
    depozit *Depozit1 = NULL;
    palet *palet1 = NULL;
    palet *palet2 = NULL;
    palet *palet3 = NULL;
     palet1 = adaugaSfarsitPalet(3,palet1);
    palet1 = adaugaSfarsitPalet(5,palet1);
    palet1 = adaugaSfarsitPalet(1,palet1);
    palet1 = adaugaSfarsitPalet(3,palet1);
    palet1 = adaugaSfarsitPalet(2,palet1);
    palet1 = adaugaSfarsitPalet(3,palet1);
    palet2 = adaugaSfarsitPalet(3,palet2);
    palet2 = adaugaSfarsitPalet(2,palet2);
    palet2 = adaugaSfarsitPalet(3,palet2);
    palet3 = adaugaSfarsitPalet(5,palet3);
    palet3 = adaugaSfarsitPalet(6,palet3);
    palet3 = adaugaSfarsitPalet(3,palet3);
    palet3 = adaugaSfarsitPalet(1,palet3);
    afisarePaleti(palet1);
    afisarePaleti(palet2);
    afisarePaleti(palet3);
    Depozit1 = adaugaSfarsitDepozit("nume1",palet1,Depozit1);
    Depozit1 = adaugaSfarsitDepozit("nume2",palet2,Depozit1);
    Depozit1 = adaugaSfarsitDepozit("nume3",palet3,Depozit1);
    afisareDepozit(Depozit1);
    Depozit1 = eliminaPaleti(Depozit1,3);
    afisareDepozit(Depozit1);
}
