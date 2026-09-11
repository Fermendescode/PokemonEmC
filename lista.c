#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

TLista *CriarLista(void){
    TLista *p;

    p = (TLista *) malloc(sizeof(TLista));

    if (p == NULL){
        printf("Nao foi possivel criar a lista.\n");
        exit(EXIT_FAILURE);
    }
    p->prox = NULL;
    return p;
}


void InserirNoFim(TLista *p, Pokemon dados){
    TLista* novo;
    novo = (TLista*) malloc(sizeof(TLista));

    if (novo == NULL)
    {
        printf("Nao foi possivel alocar memoria!");
        exit(EXIT_FAILURE);
    }
    novo->dados = dados;
    TLista *aux;
    aux = p;

    while(aux->prox != NULL)
        aux = aux->prox;

    novo->prox = NULL;
    aux->prox = novo;

}


void ExibirLista(TLista *p){
    TLista *aux;
    int posicao = 1;

    aux = p->prox;

    printf("    Nome                HP\tAT\tDF\tSP\n");
    printf("-------------------------------------------------\n");

    while (aux != NULL){
        printf("[%d] %-18s %3d\t%3d\t%3d\t%3d\n",posicao,aux->dados.Nome,aux->dados.HP,aux->dados.AT,aux->dados.DF,aux->dados.SP);
        aux = aux->prox;
        posicao++;
    }
}


int QuantidadeNaLista(TLista *p){
    TLista *aux;
    aux = p;
    int i = 0;
    while(aux->prox != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}


TLista *SelecionarPokemon(TLista *p, int posicao){
    if (posicao <= 0){
        return NULL;
    }
    TLista *aux;
    aux = p;
    for(int i = 0; i < posicao; i++){
        aux = aux->prox;
        if (aux == NULL){
            break;
        }
    }
    return aux;
}


int RemoverPokemon(TLista *p, TLista *pokemon) {
    TLista *ant = p;
    if (pokemon == NULL || pokemon == p) {
        return 0;
    }
    while (ant->prox != pokemon) {
        ant = ant->prox;
        if (ant == NULL) {
            return 0;
        }
    }
    ant->prox = pokemon->prox;
    free(pokemon);
    return 1;
}


TLista *DestruirLista(TLista *p){
    TLista *aux;

    while (p != NULL){
        aux = p;

        p = p->prox;

        free(aux);
    }

    return NULL;
}
