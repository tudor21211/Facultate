#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char nume[25];
    char email[25];
    struct student *urm;

} student;

typedef struct conferinta
{
    int ID;
    int data;
    char numeGazda[25];
    struct conferinta *urm;
    struct student *inceput_ls;

} conferinta;

conferinta *inceput;

student *nouStudent(char nume[25],char email[25],student *lista)
{

    student *s = (student*)malloc(sizeof(student));
    if (!s)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    strcpy(s->nume,nume);
    strcpy(s->email,email);
    s->urm = lista;
    return s;

}

conferinta *nouConferinta(int ID, int data, char numeGazda[25],student *inceputSt,conferinta *lista)
{
    conferinta *c = (conferinta*)malloc(sizeof(conferinta));
    if (!c)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
    }

    c->ID = ID;
    c->data = data;
    strcpy(c->numeGazda,numeGazda);
    c->urm = lista;
    c->inceput_ls = inceputSt;
    return c;
}

student *adaugaSfarsitStudent(char nume[25],char email[25],student *lista)
{
    if (!lista) return nouStudent(nume,email,NULL);
    student *s = lista,*urm;

    for (urm = s->urm; urm; s=urm,urm=s->urm) {}

    s->urm = nouStudent(nume,email,NULL);
    return lista;
}

conferinta *adaugaSfarsitConferinta(int ID, int data, char numeGazda[25],student *inceputSt,conferinta *lista)
{

    if (!lista) return nouConferinta(ID,data,numeGazda,inceputSt,NULL);
    conferinta *c = lista, *urm;
    for (urm = c->urm; urm; c=urm,urm=c->urm) {}

    c->urm = nouConferinta(ID,data,numeGazda,inceputSt,NULL);
    return lista;
}



void afisareStudenti(student *lista)
{
    if (!lista) printf("Lista vida");
    student *tmp = lista;
    while (tmp!=NULL)
    {
        printf("%s %s->",tmp->nume,tmp->email);
        tmp=tmp->urm;
    }
    printf("\n");

}

void afisareConferinta(conferinta *lista)
{

    if (!lista) printf("Lista vida");
    conferinta *tmp = lista;
    while (tmp!=NULL)
    {
        printf("ID:%d;Data:%d;Owner:%s->",tmp->ID,tmp->data,tmp->numeGazda);
        afisareStudenti(tmp->inceput_ls);
        tmp=tmp->urm;
    }
    printf("\n");
}


conferinta *modificareMail(conferinta *lista,int id, char nume[25],char email[25]){

    conferinta *tmp = lista;

    while (tmp!=NULL && tmp->ID!=id){
        tmp=tmp->urm;
    }
    student *i = tmp->inceput_ls;
    while (i){
        if (strcmp(i->nume,nume)==0) {strcpy(i->email,email);break;}
        i=i->urm;
    }

    return lista;


}

int main()
{
    conferinta *listaConf = NULL;
    student *lista1 = NULL;
    student *lista2 = NULL;
    student *lista3 = NULL;

    lista1 = adaugaSfarsitStudent("Tudor","tudor.androne@yahoo.com",lista1);
    lista2 = adaugaSfarsitStudent("Marian","andrei@yahoo.com",lista2);
    lista2 = adaugaSfarsitStudent("Andrei","andrei@yahoo.com",lista2);
    lista2 = adaugaSfarsitStudent("Maria","andrei@yahoo.com",lista2);
    lista3 = adaugaSfarsitStudent("Maria","maria@yahoo.com",lista3);
    lista3 = adaugaSfarsitStudent("Robert","robert@yahoo.com",lista3);
    afisareStudenti(lista1);
    afisareStudenti(lista2);
    afisareStudenti(lista3);
    listaConf = adaugaSfarsitConferinta(1,2021,"Raul",lista1,listaConf);
    listaConf = adaugaSfarsitConferinta(2,2022,"Andreea",lista2,listaConf);
    listaConf = adaugaSfarsitConferinta(3,2023,"Maria",lista3,listaConf);
    afisareConferinta(listaConf);
    listaConf=modificareMail(listaConf,2,"Andrei","cacat@yahoo.com");
    afisareConferinta(listaConf);
}
