#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void GerarListas(TLista *time1, TLista *time2);
void ExibirTimes(TLista *time1, TLista *time2);
void Atacar(Pokemon *atacante, Pokemon *defensor);
int Batalha(Pokemon *p1, Pokemon *p2);
TLista *EscolherPokemon(TLista *time, int jogador);


/* =========================================================
   MAIN
   ========================================================= */

int main() {

    TLista *time1;
    TLista *time2;

    TLista *pokemon1;
    TLista *pokemon2;

    int escolha1;
    int escolha2;
    int resultado;

    /* Cria as listas dos dois jogadores */
    time1 = CriarLista();
    time2 = CriarLista();

    /* Gera os times */
    GerarListas(time1, time2);

    /* Exibe os times inicialmente */
    ExibirTimes(time1, time2);


    /* =====================================================
       BATALHAS
       ===================================================== */

    while (QuantidadeNaLista(time1) > 0 &&
           QuantidadeNaLista(time2) > 0) {

        /* =============================================
           Escolha do jogador 1
           ============================================= */

        pokemon1 = EscolherPokemon(time1, 1);

        /* =============================================
           Escolha do jogador 2
           ============================================= */

        pokemon2 = EscolherPokemon(time2, 2);


        /* =============================================
           Cria cópias dos Pokémon para a batalha
           ============================================= */

        Pokemon p1 = pokemon1->dados;
        Pokemon p2 = pokemon2->dados;


        /* =============================================
           Batalha
           ============================================= */

        resultado = Batalha(&p1, &p2);


        /* =============================================
           Remove o Pokémon derrotado
           ============================================= */

        if (resultado == 1) {

            /* Jogador 1 venceu */
            RemoverPokemon(time2, pokemon2);

            printf("\nPokemon do Jogador 2 foi eliminado!\n");

        }
        else if (resultado == 2) {

            /* Jogador 2 venceu */
            RemoverPokemon(time1, pokemon1);

            printf("\nPokemon do Jogador 1 foi eliminado!\n");
        }


        /* =============================================
           Verifica se algum time ficou sem Pokémon
           ============================================= */

        if (QuantidadeNaLista(time1) == 0 ||
            QuantidadeNaLista(time2) == 0) {

            break;
        }


        /* =============================================
           Exibe os times após a batalha
           ============================================= */

        printf("\nPressione ENTER para continuar...");
        getchar();
        getchar();

        ExibirTimes(time1, time2);
    }


    /* =====================================================
       RESULTADO FINAL
       ===================================================== */

    printf("\n===============================================\n");
    printf("                 FIM DA BATALHA\n");
    printf("===============================================\n\n");

    if (QuantidadeNaLista(time1) == 0) {

        printf("Jogador 2 venceu a batalha!\n");

    }
    else if (QuantidadeNaLista(time2) == 0) {

        printf("Jogador 1 venceu a batalha!\n");
    }


    /* =====================================================
       Libera a memória
       ===================================================== */

    time1 = DestruirLista(time1);
    time2 = DestruirLista(time2);

    return 0;
}


/* =========================================================
   ESCOLHER POKEMON
   ========================================================= */

TLista *EscolherPokemon(TLista *time, int jogador) {

    int escolha;
    TLista *pokemon;

    while (1) {

        printf("\nJogador %d - Escolha seu Pokemon: ", jogador);
        scanf("%d", &escolha);

        pokemon = SelecionarPokemon(time, escolha);

        if (pokemon != NULL) {
            return pokemon;
        }

        printf("Escolha invalida!\n");
    }
}


/* =========================================================
   GERACAO DOS TIMES
   ========================================================= */

void GerarListas(TLista *time1, TLista *time2) {

    Pokemon p1[6];
    Pokemon p2[6];

    GerarTimes(p1, p2);

    for (int i = 0; i < 6; i++) {
        InserirNoFim(time1, p1[i]);
    }

    for (int i = 0; i < 6; i++) {
        InserirNoFim(time2, p2[i]);
    }
}


/* =========================================================
   EXIBICAO DOS TIMES
   ========================================================= */

void ExibirTimes(TLista *time1, TLista *time2) {

    /*
       "cls" funciona no Windows.
       Se estiver usando Linux, substitua por "clear".
    */

    system("cls");

    printf("===============================================\n");
    printf("                POKEMON BATTLE\n");
    printf("===============================================\n\n");


    printf("JOGADOR 1\n\n");

    ExibirLista(time1);


    printf("\n");

    printf("******************* VS ************************\n\n");


    printf("JOGADOR 2\n\n");

    ExibirLista(time2);

    printf("\n");
}


/* =========================================================
   ATAQUE
   ========================================================= */

void Atacar(Pokemon *atacante, Pokemon *defensor) {

    int dano;

    /*
       Calcula o dano.
       A defesa reduz metade do dano.
    */

    dano = atacante->AT - defensor->DF / 2;

    /* Dano mínimo de 1 */
    if (dano < 1) {
        dano = 1;
    }

    defensor->HP -= dano;

    /* HP não pode ficar negativo */
    if (defensor->HP < 0) {
        defensor->HP = 0;
    }

    printf("%s atacou %s!\n",
           atacante->Nome,
           defensor->Nome);

    printf("Dano causado: %d\n", dano);

    printf("%s ficou com %d de HP\n\n",
           defensor->Nome,
           defensor->HP);
}


/* =========================================================
   BATALHA
   ========================================================= */

int Batalha(Pokemon *p1, Pokemon *p2) {

    Pokemon *atacante;
    Pokemon *defensor;
    Pokemon *aux;


    system("cls");


    printf("===============================================\n");
    printf("                   BATALHA\n");
    printf("===============================================\n\n");


    /* =============================================
       Define quem começa baseado na velocidade
       ============================================= */

    if (p2->SP > p1->SP) {

        atacante = p2;
        defensor = p1;

    }
    else {

        atacante = p1;
        defensor = p2;
    }


    /* =============================================
       Realiza os ataques alternadamente
       ============================================= */

    while (p1->HP > 0 && p2->HP > 0) {

        Atacar(atacante, defensor);

        /*
           Troca atacante e defensor
        */

        aux = atacante;
        atacante = defensor;
        defensor = aux;
    }


    /* =============================================
       Verifica vencedor
       ============================================= */

    if (p1->HP <= 0) {

        printf("%s venceu!\n", p2->Nome);
        printf("%s foi eliminado!\n", p1->Nome);

        return 2;
    }

    else {

        printf("%s venceu!\n", p1->Nome);
        printf("%s foi eliminado!\n", p2->Nome);

        return 1;
    }
}
