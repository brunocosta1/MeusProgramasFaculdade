#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
    char *palavra;
    int quantidade; 
    struct elemento *prox, *ant;
};

struct elemento *CriaLista()
{
    struct elemento *sentinela = (struct elemento*)malloc(sizeof(struct elemento));
    sentinela->prox = sentinela;
    sentinela->ant = sentinela;
    return sentinela;
}
  
struct elemento *CriaElemento(char *palavra)
{
    struct elemento *resp = (struct elemento*)malloc(sizeof(struct elemento));
    resp->palavra = (char*)malloc(sizeof(palavra));
    
    strcpy(resp->palavra, palavra);
    resp->prox = NULL;
    resp->ant = NULL;
    resp->quantidade = 1;
    return resp;

}

struct elemento *Busca(struct elemento *lista, char *palavra)
{
    struct elemento *aux = lista->prox;
    
    while(aux != lista && strcmp(aux->palavra, palavra) != 0)
        aux = aux->prox;

    if(aux != lista)
        return aux;
    else
        return NULL;

}


struct elemento *Remove(struct elemento *lista, char *palavra)
{
    struct elemento *aux = Busca(lista, palavra);
    if(aux != NULL)
    {

        if(aux->prox = aux)
        {
           lista = NULL;
        }
        else
        {
            if(lista == aux)
                lista = aux->prox;
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }

        free(aux);
    }
    return lista;
}
     
struct elemento *RemoveRepetido(struct elemento *lista)
{
    struct elemento *aux = lista->prox;

    if(aux == NULL)
    return lista;

    while(aux != lista)
    { 
        struct elemento *aux1 = Busca(lista, aux->palavra);
        
        if(aux1 != aux)
        {    
            if(aux1 != NULL && strcmp(aux1->palavra, aux->palavra) == 0)
            {
                    
                    aux->quantidade += aux1->quantidade;
                    
                    if(lista == aux1)
                        lista = aux1->prox;

                    aux1->ant->prox = aux1->prox;
                    aux1->prox->ant = aux1->ant;
                    
                    free(aux1);
            }

        }
            aux = aux->prox;
    }

    return lista;
}

void InsereFim(struct elemento *lista, char *palavra)
{
    struct elemento *novo = CriaElemento(palavra);
    novo->prox = lista;
    novo->ant = lista->ant;
    lista->ant->prox = novo;
    lista->ant = novo;

}


void Listar(struct elemento *lista)
{
    struct elemento *aux = lista->prox;

    while(aux != lista)
    {
        printf("String: %s Quantidade: %d\n", aux->palavra, aux->quantidade);
        aux = aux->prox;
    }

}

struct elemento *LerArquivo(struct elemento *lista)
{
    FILE *arquivo;

    arquivo = fopen("strings.txt", "r");
    if(arquivo == NULL)
        return lista;

    while(!feof(arquivo))
    {
        char *aux;

        fscanf(arquivo, "%s", aux); 


        InsereFim(lista, aux);
    }
    
    return lista;


}



int main()
{
    struct elemento *novo;
    novo = CriaLista();
    
    
    
    LerArquivo(novo);
    novo = RemoveRepetido(novo);
    Listar(novo);




    return 0;
}
