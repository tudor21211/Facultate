#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{

    int value;
    struct elem *urm;

} elem;

elem *nou(int v, elem *lista)
{

    elem *e = (elem*)malloc(sizeof(elem*));
    if (!e)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    e->value = v;
    e->urm = lista;
    return e;
}

elem *adaugaSfarsit(int v, elem* lista)
{

    if (!lista) return nou(v,NULL);

    elem *p=lista,*urm;
    for(urm=p->urm; urm; p=urm,urm=p->urm) {}
    p->urm=nou(v,NULL);
    return lista;


}

void afiseaza(elem *lista)
{
    if (lista == NULL) printf("Lista vida");
    elem *temp = lista;
    while (temp!=NULL)
    {
        printf("%d->",temp->value);
        temp = temp ->urm;
    }
    putchar('\n');

}


elem *oSinguraParcurgere(elem *lista)
{
    int c=0,pr=0;
    elem *p,*u,*mijloc,*pred;
    p=lista;
    u = lista->urm;
    mijloc=lista->urm;
    pred=lista;

    if (lista->urm == NULL) return NULL;
    else
    {
        while (p->urm)
        {
            if (c==2)
            {
                mijloc = mijloc->urm;
                pred=pred->urm;
                c=0;
            }

            p=p->urm;
            c++;
        }
    }

    pred->urm=mijloc->urm;

    return lista;


}


int main()
{
    elem *lista=NULL;
    int n,d;
    d=1;
    printf("n=");
    scanf("%d",&n);

    while (d<=n)
    {
        lista = adaugaSfarsit(d,lista);
        d++;
    }
    afiseaza(lista);
    afiseaza(oSinguraParcurgere(lista));
}
