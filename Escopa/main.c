/*
Trabalho feito por:
  Igor Luiz Gonçalves Tomaz
  Fabio Antonio Ribeiro
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Escopa-fun.c"
#include "Escopa.h"

int main()
{
    int menu;

    // ponteiro de ponteiro que aponta para o elemento
    Baralho *jogador_b;
    Baralho *maquina_b;
    Baralho *principal;
    Baralho *mesa;
    Baralho *montante_j;
    Baralho *montante_m;
    Pontuacao jogador;
    Pontuacao maquina;

    // Cria os baralhos de cada jogador, mesa ou baralho principal
    jogador_b = cria_baralho();
    maquina_b = cria_baralho();
    principal = cria_baralho();
    mesa = cria_baralho();
    montante_j = cria_baralho();
    montante_m = cria_baralho();

    // Cria a pontuação
    jogador.escopa = 0;
    jogador.todas_cartas_ouro = 0;
    jogador.cartas_ouro = 0;
    jogador.sete_belo = 0;
    jogador.quatro_setes = 0;
    jogador.qtd_cartas = 0;
    jogador.qtd_setes = 0;

    maquina = jogador;

    /*
      Executa as funções do jogo e trata o menu
    */
    entrada();
    while (1)
    {
        menu_principal(&menu);

        if (menu == 1)
        {
            embaralhando();
            partida(principal, mesa, maquina_b, montante_m, jogador_b, montante_j, &jogador, &maquina);
        }
        else if (menu == 2)
            instrucao();
        else if (menu == 3)
            criadores();
        else
        {
            system("clear");
            printf("\nPrograma encerrado.\n");
            break;
        }

    }
}
