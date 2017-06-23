#include "Escopa.h"
#include "Graph-fun.c"

struct Baralho
{
    int number;
    int naipe;
};

struct elemento
{
    struct Baralho b;
    struct elemento *prox;
    struct elemento *ante;
};

struct pontuacao
{
    int escopa;
    int todas_cartas_ouro;
    int cartas_ouro;
    int sete_belo;
    int quatro_setes;
    int qtd_setes;
    int qtd_cartas;
};

typedef struct elemento Elem;
typedef struct pontuacao Pontuacao;

// Acerta a pontuação da carta de acordo com a carta que cair
int verif_pont_carta(int x)
{
    if (x >= 10)
        x = x - 2;

    return x;
}

//Cria a lista do baralho vazio
Baralho *cria_baralho()
{
    Baralho *b = calloc(1, sizeof(Baralho));

    if (b != NULL)
        *b = NULL;

    return b;
}

//Apaga o baralho
void elimina_baralho(Baralho *ba)
{
    if(ba != NULL)
    {
        Elem* no;
        while((*ba) != NULL)
        {
            no = *ba;
            *ba = (*ba)->prox;
            free(no);
        }
        free(ba);
    }
}

/*
  Exibe o nome do naipe a partir do valor
  de entrada
*/
void nome_naipe (int naipe, char *nome_n)
{
    switch(naipe)
    {
    case 0:
        strcpy(nome_n, "Basto");
        break;
    case 1:
        strcpy(nome_n, "Espada");
        break;
    case 2:
        strcpy(nome_n, "Ouro");
        break;
    case 3:
        strcpy(nome_n, "Copa");
        break;
    }
}

//Verifica se o baralho está vazio
int baralho_vazio(Baralho *ba)
{
    if(ba == NULL)
        return 1;
    if(*ba == NULL)
        return 1;
    return 0;
}

//Exibe o tamanho do baralho
int tamanho_baralho(Baralho *ba)
{
    if(ba == NULL)
        return 0;

    int cont = 0;
    Elem *node = *ba;

    while(node != NULL)
    {
        cont++;
        node = node->prox;
    }
    return cont;
}

/* Insere no começo do baralho, de forma que
quando for emabralhado ele insere ja embaralhado
*/
int insere_comeco_baralho(Baralho *ba, int num, int naipe)
{
    if (ba == NULL)
        return 0;

    Elem *node = calloc(1, sizeof(Elem));

    if (node == NULL)
        return 0;

    node->b.number = num;
    node->b.naipe = naipe;
    node->prox = (*ba);
    node->ante = NULL;

    if (*ba != NULL)
        (*ba)->ante = node;

    *ba = node;
    return 1;
}

/* Insere no baralho de forma ordenada. */
int insere_baralho(Baralho *ba, int num, int naipe)
{
    if(ba == NULL)
        return 0;
    Elem *node = calloc(1, sizeof(Elem));
    if(node == NULL)

        return 0;

    node->b.number = num;
    node->b.naipe = naipe;

    // Se a lista for vazia, insere no inicio
    if((*ba) == NULL)
    {
        node->prox = NULL;
        node->ante = NULL;
        *ba = node;
        return 1;
    }
    else
    {
        Elem *anterior, *atual = *ba;

        while(atual != NULL && atual->b.number < num)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if(atual == *ba)
        {
            // Insere no inicio
            node->ante = NULL;
            (*ba)->ante = node;
            node->prox = (*ba);
            *ba = node;
        }
        else
        {
            node->prox = anterior->prox;
            node->ante = anterior;
            anterior->prox = node;
            if (atual != NULL)
                atual->ante = node;
        }
        return 1;
    }

    free(node);
    return 1;
}

/* Procura uma carta do baralho e então apaga */
int remove_carta(Baralho *ba, int num, int naipe)
{
    if (ba == NULL || (*ba) == NULL)
        return 0;

    Elem *node = *ba;

    while(node != NULL)
    {
        if (node->b.number == num && node->b.naipe == naipe)
            break;

        node = node->prox;
    }

    if (node == NULL)
        return 0;

    if(node->ante == NULL)
        *ba = node->prox;
    else
        node->ante->prox = node->prox;

    if(node->prox != NULL)
        node->prox->ante = node->ante;

    free(node);
    return 1;
}

/* Preenche de forma ordenada */
int preenche_baralho(Baralho *ba)
{
    if(ba == NULL)
        return 0;

    int i, j;

    for(j = 0; j < 4; j++)
    {
        for (i = 1; i <= 12; i++)
        {
            if (i < 8 || i > 9)
            {
                insere_baralho(ba, i, j);
            }
        }
    }

    return 1;
}
void exibe_baralho_1(Baralho *ba)
{
    int i = 1;
    char nome_n[10];

    if (ba != NULL)
    {
        Elem *node = *ba;

        while(node != NULL)
        {
            nome_naipe(node->b.naipe, nome_n);
            printf("%i - Carta: %i de %s\n", i, node->b.number, nome_n);
            i++;
            node = node->prox;
        }
        free(node);
    }
}


/* Exibe as cartas do baralho */
void exibe_baralho(Baralho *ba, int *number, int *naipe)
{
    int i = 0;

    if (ba != NULL)
    {
        Elem *node = *ba;

        while(node != NULL)
        {
            number[i] = node->b.number;
            naipe[i] = node->b.naipe;

            node = node->prox;
            i++;
        }
        free(node);
    }
}

/* Gera numeros randomicos e insere no baralho de forma ordenada */
void embaralha(Baralho *ba)
{
    int n, np,
        j, k = 0, verif = 0, vet1[40], vet2[40];
    srand(time(NULL));

    while (k < 40)
    {
        n = rand() % 13;
        np = rand() % 4;

        if (n > 0 && (n < 8 || n > 9))
        {
            for (j = 0; j <= k; j++)
                if (vet1[j] == n && vet2[j] == np)
                    verif++;

            if (verif == 0)
            {
                vet1[k] = n;
                vet2[k] = np;
                insere_comeco_baralho(ba, n, np);
                k++;
            }
            else
                verif = 0;
        }
    }
}

/* Procura uma carta no baralho principal,
insere no baralho secundário e remove do principal. */
int insere_remove_carta(Baralho *ba1, Baralho *ba2, int num, int naipe)
{
    int n = 0, np = 0;

    if (ba1 == NULL || ba2 == NULL)
        return 0;

    Elem *node = *ba1;

    while (node != NULL)
    {
        if (node->b.number == num && node->b.naipe == naipe)
        {
            n = node->b.number;
            np = node->b.naipe;
            break;
        }
        node = node->prox;
    }

    if (node == NULL)
        return 0;
    else
    {
        insere_baralho(ba2, n, np);
        remove_carta(ba1, n, np);
        return 1;
    }

}

/*
  Distribui a quantidade de cartas de acordo com o necessário
  qtd é a variavel que controla quantas cartas sãi distribuidas
*/
int distribui_carta(Baralho *ba1, Baralho *ba2, int qtd)
{
    int i = 1, j = 0, np = 0, n = 0, pos;
    srand(time(NULL));
    if(ba1 == NULL ||ba2 == NULL)
        return 0;

    Elem *node;

    while(j < qtd)
    {
        node = *ba1;

        pos = rand() % (40-j);

        while(node != NULL && i < pos)
        {
            node = node->prox;
            i++;
        }
        if(node != NULL)
        {
            n = node->b.number;
            np = node->b.naipe;
            insere_baralho(ba2, n, np);
            remove_carta(ba1, n, np);
            j++;
        }
    }
    return 1;
}

/*
  Confere a mão da maquina e a mesa e realiza a jogada de acordo.
  ba1 = mão da maquina, ba2 = mesa, ba3 = monte da maquina
*/
int maquina_jogada(Baralho *ba1, Baralho *ba2, Baralho *ba3)
{
    int baralho1 = tamanho_baralho(ba1);
    int baralho2 = tamanho_baralho(ba2);
    int i, j, carta_m, carta_j;
    char naipe_j[10], naipe_m[10], tecla_continua;

    Elem *node1 = *ba1;
    Elem *node2 = *ba2;

    for (i = 0; ((i <= baralho1) && node1 != NULL); i++)
    {
        for(j = 0; ((j <= baralho2) && node2 != NULL); j++)
        {

            carta_j = verif_pont_carta(node1->b.number);
            carta_m = verif_pont_carta(node2->b.number);

            nome_naipe(node1->b.naipe, naipe_j);
            nome_naipe(node2->b.naipe, naipe_m);

            if((carta_j + carta_m) == 15)
            {
                printf("\nMaquina Joga:\nCarta da mão - %i de %s\n", node1->b.number, naipe_j);

                if(node2->b.number == 0)
                    printf("Carta da mesa - %i de %s\n", (node2->b.number+1), naipe_m);
                else
                    printf("Carta da mesa - %i de %s\n", node2->b.number, naipe_m);

                insere_remove_carta(ba1, ba3, node1->b.number, node1->b.naipe);
                insere_remove_carta(ba2, ba3, node2->b.number, node2->b.naipe);

                __fpurge(stdin);
                scanf("%c", &tecla_continua);

                return 1;
            }
            else
                node2 = node2->prox;
        }
        node1 = node1->prox;
        node2 = *ba2;
    }

    return 0;
}

/*
  Se não conseguir fazer com 2 cartas, tenta com 3 cartas
*/
int maquina_jogada_multipla(Baralho *ba1, Baralho *ba2, Baralho *ba3)
{
    int baralho1 = tamanho_baralho(ba1);
    int baralho2 = tamanho_baralho(ba2);
    int i, j, k, carta_m, carta_j, carta_k;
    char naipe_j[10], naipe_m[10], naipe_k[10], tecla_continua;

    Elem *node1 = *ba1;
    Elem *node2;
    Elem *node3 = *ba2;

    for (i = 0; ((i <= baralho1) && node1 != NULL); i++)
    {
        for(j = 0, node2 = *ba2; ((j <= baralho2) && node2 != NULL); j++)
        {
            for(k = j, node3 = node2->prox; (k <= baralho2) && node3 != NULL; k++)
            {
                carta_j = verif_pont_carta(node1->b.number);
                carta_m = verif_pont_carta(node2->b.number);
                carta_k = verif_pont_carta(node3->b.number);

                nome_naipe(node1->b.naipe, naipe_j);
                nome_naipe(node2->b.naipe, naipe_m);
                nome_naipe(node3->b.naipe, naipe_k);

                if ((carta_j + carta_m + carta_k) == 15)
                {

                    printf("Maquina Joga:\nCarta da mão - %i de %s\n", node1->b.number, naipe_j);
                    if (node2->b.number == 0)
                        printf("Carta da mesa - %i de %s\n", (node2->b.number+1), naipe_m);
                    else
                        printf("Carta da mesa - %i de %s\n", node2->b.number, naipe_m);

                    if (node3->b.number == 0)
                        printf("Carta da mesa - %i de %s\n", (node3->b.number+1), naipe_k);
                    else
                        printf("Carta da mesa - %i de %s\n", node3->b.number, naipe_k);

                    __fpurge(stdin);
                    scanf("%c", &tecla_continua);

                    insere_remove_carta(ba1, ba3, node1->b.number, node1->b.naipe);
                    insere_remove_carta(ba2, ba3, node2->b.number, node2->b.naipe);
                    insere_remove_carta(ba2, ba3, node3->b.number, node3->b.naipe);

                    return 1;
                }
                else
                    node3 = node3->prox;
            }
            node2 = node2->prox;
        }
        node1 = node1->prox;
    }
    return 0;
}

/*
  Realiza a jogada a partir da posição das cartas em minha mão
  e na mesa.
  ba1 = mão do jogador, ba2 = mesa, ba3 = monte do jogador
*/
int faz_jogada(Baralho *ba1, Baralho *ba2, Baralho *ba3, int pos_carta_j, int pos_carta_m)
{
    int carta_m, carta_j;

    if (ba1 == NULL || ba2 == NULL || pos_carta_j <= 0 || pos_carta_m <= 0)
        return -1;

    int k = 1;

    Elem *node1 = *ba1;
    Elem *node2 = *ba2;

    while(node1 != NULL && k < pos_carta_j)
    {
        node1 = node1->prox;
        k++;
    }

    k = 1;

    while(node2 != NULL && k < pos_carta_m)
    {
        node2 = node2->prox;
        k++;
    }

    carta_j = verif_pont_carta(node1->b.number);
    carta_m = verif_pont_carta(node2->b.number);

    /* Verifica se encontrou as posições, se não encontrou não joga
    verifica se o valor da 15, se não, não realiza a jogada.
    */
    if(node1 == NULL || node2 == NULL)
        return 0;
    else
    {
        if (carta_j + carta_m == 15)
        {
            insere_remove_carta(ba1, ba3, node1->b.number, node1->b.naipe);
            insere_remove_carta(ba2, ba3, node2->b.number, node2->b.naipe);
            return 1;
        }
        else
        {
            printf("Impossível jogar o valor, não forma o valor 15. Favor digitar uma opção valida.");
            return 2;
        }

        return 0;
    }
    return 0;
}

/*
  Descarta uma carta da mão para a mesa
*/
int descarta(Baralho *ba1, Baralho *ba2, int pos)
{
    int tam_baralho = tamanho_baralho(ba1);

    /*
    Verifica o tamanho do baralho,
    se a posição selecionada for maior
    que o tamanho do baralho, não faz a jogada.
    */
    if (pos <= tam_baralho)
    {
        int cont = 1;

        if (ba1 == NULL || ba2 == NULL || pos <= 0)
            return -1;

        Elem *node1 = *ba1;

        while(cont <= pos)
        {
            if (cont == pos)
                break;

            node1 = node1->prox;
            cont++;
        }

        if(node1 == NULL)
            return 0;
        else
        {
            insere_remove_carta(ba1, ba2, node1->b.number, node1->b.naipe);;
            return 1;
        }
    }
    else
        return 0;
}

/*
  Mostra a carta descartada (usada pra mostrar
a carta que a máquina descartou)
*/
void exibe_carta_descartada(Baralho *ba1, int pos)
{
    Elem *node = *ba1;
    int cont_c = 1;
    char naipe_n[10];

    while(node != NULL)
    {
        if (cont_c == pos)
            break;

        cont_c++;
        node = node->prox;
    }

    if (node != NULL)
    {
        nome_naipe(node->b.naipe, naipe_n);
        printf("carta %i de %s.\n", node->b.number, naipe_n);
    }
}

/*
  Jogador escolhe uma carta de sua mão
  e com quantas cartas do baralho deseja combinar
  para dar 15
*/
int faz_jogada_multipla(Baralho *ba1, Baralho *ba2, Baralho *ba1_m, int pos_mao, int qtd_carta, int jogada[])
{
    int i, j, cont = 1, soma = 0;

    for (i = 0; i < qtd_carta; i++)
        printf("%i\n", jogada[i]);

    Elem *node, *node1, *reserva;
    Baralho *bar = cria_baralho(), *verif = cria_baralho();

    node1 = *ba1;
    reserva = *ba2;

    while (node1 != NULL)
    {
        if (cont == pos_mao)
            break;

        cont++;
        node1 = node1->prox;
    }

    soma += verif_pont_carta(node1->b.number);

    cont = 1;
    i = 0;

    while (i < qtd_carta)
    {
        j = 1;
        node = reserva;

        while (node != NULL && j != jogada[i])
        {
            node = node->prox;
            j++;
        }
        soma += verif_pont_carta(node->b.number);


        insere_comeco_baralho(verif, node->b.number, node->b.naipe);
        i++;
    }

    if (soma == 15)
    {
        i = 0;
        insere_remove_carta(ba1, ba1_m, node1->b.number, node1->b.naipe);

        while (bar != NULL && i < qtd_carta)
        {
            insere_remove_carta(ba2, ba1_m, (*verif)->b.number, (*verif)->b.naipe);
            (*verif) = (*verif)->prox;
            i++;
        }

        return 1;
    }
    else
    {
        return -1;
    }
}

void contagem_pontos(Pontuacao *p, Baralho *ba1)
{
    /*
    - Conta as cartas ouros para verificar se o jogador
    ou a máquina possui todas as cartas de ouros
    para gerar o ponto.
    - Caso não tenha 9 (todas) ele passa a pontuação
    do jogador para comparar com a do outro futuramente
    - Conta os 7 que o jogador possui, se ele possui os 4
    recebe os pontos, se não, atribui ao jogador a quantidade
    de 7 que ele tem para comparações futuras
    - Se o jogador possui o 7 Belo, recebe um pontos
    - Conta a quantidade das cartas que o jogador possui
    */
    int cont_ouro = 0;
    int cont_sete = 0;
    int cont_carta = 0;
    Elem *node = *ba1;

    while(node != NULL)
    {
        if (node->b.number == 7)
            cont_sete++;

        if (node->b.number == 7 && node->b.naipe == 2)
            p->sete_belo = 1;

        if (node->b.naipe == 2)
            cont_ouro++;

        cont_carta++;

        node = node->prox;
    }

    if(cont_ouro == 10)
        p->todas_cartas_ouro = 1;
    else
        p->cartas_ouro = cont_ouro;

    if (cont_sete == 4)
        p->quatro_setes = 1;
    else
        p->qtd_setes = cont_sete;

    p->qtd_cartas = cont_carta;
}

/*
  Função que verifica e exibe a função do jogador e da maquina
*/
void verifica_pontuacao(Pontuacao *p1, Pontuacao *p2, int *resp_j)
{
    int pont_jogador = 0, pont_maquina = 0;

    int i, j;
    pont_jogador = p1->escopa;
    pont_maquina = p2->escopa;

    for(i = 1; i <= 42; i++)
    {
        for(j = 1; j <= 145; j++)
        {
            if (i == 1 ||i == 42)
                printf("#");
            else
            {
                if (j == 1 || j == 145)
                    printf("#");
                else
                {
                    if(((i > 5 && i < 28) && j == 10) || ((i > 5 && i < 28) && j == 70) || ((i > 5 && i < 28) && j == 75) || ((i > 5 && i < 28) && j == 135))
                        printf("|");
                    else if ((i == 5 || i == 24 || i == 27 ) && ((j > 10 && j < 70) || (j > 75 && j < 135)))
                        printf("_");
                    else if ((i == 29 || i == 36) && (j > 10 && j < 135))
                        printf("_");
                    else if(((i > 29 && i < 37) && j == 10) || ((i > 29 && i < 37) && j == 135))
                        printf("|");
                    else if(i == 3 && j == 10)
                        printf("FINAL DE JOGO");
                    else if ((i == 3) && (j > 10 && j < 23));
                    else if (i == 7 && j == 12)
                        printf("Sua pontuação:");
                    else if ((i == 7) && (j > 12 && j < 26));
                    else if (i == 9 && j == 12)
                        printf("Você fez %i escopa(s);", p1->escopa);
                    else if ((i == 9) && (j > 12 && j < 33));
                    else if (i == 11 && j == 12)
                        printf("Você possui todas as cartas ouro: ");
                    else if ((i == 11) && (j > 12 && j < 46));
                    else if ((i == 11 && j == 46) && p1->todas_cartas_ouro == 1)
                    {
                        printf("X");
                        pont_jogador += 2;
                    }
                    else if (i == 13 && j == 12)
                        printf("Você possui mais cartas de ouro: ");
                    else if ((i == 13) && (j > 12 && j < 45));
                    else if ((i == 13 && j == 45) && p1->cartas_ouro > p2->cartas_ouro)
                    {
                        printf("X");
                        pont_jogador += 1;
                    }
                    else if (i == 15 && j == 12)
                        printf("Você possui a 7 belo: ");
                    else if ((i == 15) && (j > 12 && j < 34));
                    else if ((i == 15 && j == 34) && p1->sete_belo == 1)
                    {
                        printf("X");
                        pont_jogador += 1;
                    }
                    else if (i == 17 && j == 12)
                        printf("Você possui as quatro cartas 7 do baralho: ");
                    else if ((i == 17) && (j > 12 && j < 55));
                    else if ((i == 17 && j == 55) && p1->quatro_setes == 1)
                    {
                        printf("X");
                        pont_jogador += 3;
                    }
                    else if (i == 19 && j == 12)
                        printf("Você possui mais cartas 7 que a máquina: ");
                    else if ((i == 19) && (j > 12 && j < 53));
                    else if ((i == 19 && j == 53) && p1->qtd_setes > p2->qtd_setes)
                    {
                        printf("X");
                        pont_jogador += 1;
                    }
                    else if (i == 21 && j == 12)
                        printf("Você possui mais cartas que a máquina: ");
                    else if ((i == 21) && (j > 12 && j < 51));
                    else if ((i == 21 && j == 51) && p1->qtd_cartas > p2->qtd_cartas)
                    {
                        printf("X");
                        pont_jogador += 1;
                    }
                    else if (i == 23 && j == 12)
                        printf("A maquina possui menos de 10 cartas no monte: ");
                    else if ((i == 23) && (j > 12 && j < 58));
                    else if ((i == 23 && j == 58) && p2->qtd_cartas < 10)
                    {
                        printf("X");
                        pont_jogador += 2;
                    }
                    else if (i == 26 && j == 12)
                        printf("Você fez %i pontos.", pont_jogador);
                    else if ((i == 26) && (j > 12 && j < 30));
                    else if (i == 7 && j == 77)
                        printf("Pontuação da Máquina:");
                    else if ((i == 7) && (j > 77 && j < 98));
                    else if (i == 9 && j == 77)
                        printf("A máquina fez %i escopa(s);", p2->escopa);
                    else if ((i == 9) && (j > 77 && j < 103));
                    else if (i == 11 && j == 77)
                        printf("A máquina possui todas as cartas ouro: ");
                    else if ((i == 11) && (j > 77 && j < 116));
                    else if ((i == 11 && j == 116) && p2->todas_cartas_ouro == 1)
                    {
                        printf("X");
                        pont_maquina += 2;
                    }
                    else if (i == 13 && j == 77)
                        printf("A máquina possui mais cartas de ouro: ");
                    else if ((i == 13) && (j > 77 && j < 115));
                    else if ((i == 13 && j == 115) && p2->cartas_ouro > p1->cartas_ouro)
                    {
                        printf("X");
                        pont_maquina += 1;
                    }
                    else if (i == 15 && j == 77)
                        printf("A máquina possui a 7 belo: ");
                    else if ((i == 15) && (j > 77 && j < 104));
                    else if ((i == 15 && j == 104) && p2->sete_belo == 1)
                    {
                        printf("X");
                        pont_maquina += 1;
                    }
                    else if (i == 17 && j == 77)
                        printf("A máquina possui as quatro cartas 7 do baralho: ");
                    else if ((i == 17) && (j > 77 && j < 125));
                    else if ((i == 17 && j == 125) && p2->quatro_setes == 1)
                    {
                        printf("X");
                        pont_maquina += 3;
                    }
                    else if (i == 19 && j == 77)
                        printf("A máquina possui mais cartas 7 que a máquina: ");
                    else if ((i == 19) && (j > 77 && j < 123));
                    else if ((i == 19 && j == 123) && p2->qtd_cartas > p1->qtd_cartas)
                    {
                        printf("X");
                        pont_maquina += 1;
                    }
                    else if (i == 21 && j == 77)
                        printf("A máquina possui mais cartas que você: ");
                    else if ((i == 21) && (j > 77 && j < 116));
                    else if ((i == 21 && j == 116) && p2->qtd_cartas > p1->qtd_cartas)
                    {
                        printf("X");
                        pont_maquina += 1;
                    }
                    else if (i == 23 && j == 77)
                        printf("Você possui menos de 10 cartas no monte: ");
                    else if ((i == 23) && (j > 77 && j < 118));
                    else if ((i == 23 && j == 118) && p1->qtd_cartas < 10)
                    {
                        printf("X");
                        pont_maquina += 2;
                    }
                    else if (i == 26 && j == 77)
                        printf("A maquina fez %i pontos.", pont_maquina);
                    else if ((i == 26) && (j > 77 && j < 100));
                    else if (((i == 32) && (j == 61)) && (pont_jogador > pont_maquina))
                        printf("Parabéns, você venceu!");
                    else if ((i == 32) && (j > 61 && j < 83) && (pont_jogador > pont_maquina));
                    else if (((i == 32) && (j == 61)) && (pont_maquina > pont_jogador))
                        printf("Que pena, a máquina venceu!");
                    else if ((i == 32) && (j > 61 && j < 88) && (pont_maquina > pont_jogador));
                    else if ((i == 39) && (j == 10))
                        printf("Deseja jogar novamente? (1 - Sim/2 - Não)");
                    else if ((i == 39) && (j > 61 && j < 102));

                    else
                        printf(" ");
                }
            }
        }
    }
    printf("\nResp: ");
    scanf("%i", resp_j);
}

//Função que executa a partida.
void partida(Baralho *principal, Baralho *mesa, Baralho *maquina_b, Baralho *montante_m, Baralho *jogador_b, Baralho *montante_j, Pontuacao *p_jogador, Pontuacao *p_maquina)
{
    system("clear");
    int carta_j, tam_b_p, number_j[40], number_m[40], naipe_j[40], naipe_m[40];
    int  mont_j, tam_b_j, jogar_novamente = 0, t_fim = 0;
    char tecla_continua;
    srand(time(NULL));

    jog_nov:
    if (jogar_novamente == 1)
    {
        elimina_baralho(principal);
        elimina_baralho(mesa);
        elimina_baralho(jogador_b);
        elimina_baralho(montante_j);
        elimina_baralho(maquina_b);
        elimina_baralho(montante_m);

        jogador_b = cria_baralho();
        maquina_b = cria_baralho();
        principal = cria_baralho();
        mesa = cria_baralho();
        montante_j = cria_baralho();
        montante_m = cria_baralho();
        t_fim = 0;
    }

    //Embaralha o baralho principal
    embaralha(principal);

    // Distribui as cartas, 3 pra cada jogador e 4 na mesa
    distribui_carta(principal, jogador_b, 3);
    distribui_carta(principal, maquina_b, 3);
    distribui_carta(principal, mesa, 4);

    while ((t_fim != 1))
    {
        tam_b_p = tamanho_baralho(principal);
        tam_b_j = tamanho_baralho(jogador_b);

        if (tamanho_baralho(montante_j) >= 1)
            mont_j = 1;
        else
            mont_j = 0;

        // Distribui cartas ao jogador
        if ((tam_b_j == 0) && (baralho_vazio(principal) != 1))
        {

            partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
            partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
            partida_baixo(jogador_b, number_j, naipe_j, mont_j);

            printf("\n\n\n\n\nVocê não possui nenhuma carta na mão, ");
            if (tam_b_p < 3)
            {
                printf("como o baralho principal tem menos de 3 cartas,\nforam dadas %i cartas a você.\n\n", tam_b_p);
                distribui_carta(principal, jogador_b, tam_b_p);
            }
            else if (tam_b_p >= 3)
            {
                printf("foram dadas 3 cartas a você.\n");
                distribui_carta(principal, jogador_b, 3);
            }
            else
            {
                printf("e não possui mais cartas no baralho.\n");
            }

            scanf("%c", &tecla_continua);
            system("clear");
        }


        // Distribui cartas para a mesa
        if ((tamanho_baralho(maquina_b) == 0) && (baralho_vazio(principal) != 1))
        {
            partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
            partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
            partida_baixo(jogador_b, number_j, naipe_j, mont_j);

            printf("\n\n\n\n\nA maquina não tem nenhuma carta na mão, ");

            if (tamanho_baralho(principal) < 3)
            {
                printf("como o baralho principal tem menos de 3 cartas,\nforam dadas %i cartas a você.\n", tam_b_p);
                distribui_carta(principal, maquina_b, tam_b_p);
            }
            else if (tamanho_baralho(principal) >= 3)
            {
                printf("foram dadas 3 cartas a maquina.\n");
                distribui_carta(principal, maquina_b, 3);
            }
            else
            {
                printf("e não possui mais cartas no baralho, não será distribuido novas cartas.\n");
            }

            scanf("%c", &tecla_continua);
        }

        /*
          Verifica se o baralho não esta vazio
          permite jogar
        */

        if (baralho_vazio(jogador_b) == 0)
        {
            int verif_jogada = 0, tam_bar_m, menu, verif_tam_b = 0;

            if (tamanho_baralho(mesa) >= 1)
            {

                //Você realiza a jogada
                while(verif_jogada != 1)
                {
                    inicio_menu:

                    partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                    partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                    partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                    printf("\nO que deseja fazer:\n1 - Jogar\n2 - Descartar uma carta\nResposta: ");
                    scanf("%i", &menu);


                    if (menu == 1)
                    {
                        int qtd_carta, i;
                        verif_tam_b = tamanho_baralho(jogador_b);

                        partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                        partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                        partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                        printf("\n\n\nQual carta da sua mão quer jogar? (Digite 0 para cancelar)\nResp: ");
                        scanf("%i", &carta_j);

                        /*
                          Impede o jogador de selecionar uma posição das cartas
                          que não existe em sua mão
                        */
                        if (carta_j > 0 && carta_j <= verif_tam_b)
                        {
                            while(1)
                            {
                                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                                printf("\n\n\nQuantas cartas da mesa irá selecionar? (Digite 0 para cancelar)\nResp: ");
                                scanf("%i", &qtd_carta);

                                if (qtd_carta <= tamanho_baralho(mesa) && qtd_carta > 0)
                                    break;
                                else if (qtd_carta == 0)
                                    goto inicio_menu;
                                else
                                {
                                    partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                                    partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                                    partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                                    printf("\n\n\nValor inválido, digite um valor entre 1 e %i.\n", tamanho_baralho(mesa));
                                    scanf("%c", &tecla_continua);
                                    getchar();
                                }
                            }

                            int jogada[qtd_carta], verif_num = 0;

                            partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                            partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                            partida_baixo(jogador_b, number_j, naipe_j, mont_j);


                            for(i = 0; i < qtd_carta;)
                            {
                                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                                printf("\n\n\nQuais cartas (posições da mesa) irá jogar? (Digite 0 para cancelar)\nResp: ");
                                scanf("%i", &verif_num);

                                if (verif_num <= tamanho_baralho(mesa) && verif_num > 0)
                                {
                                    jogada[i] = verif_num;
                                    i++;
                                }
                                else if (verif_num == 0)
                                    goto inicio_menu;
                                else
                                {
                                    partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                                    partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                                    partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                                    printf("\n\n\nOpção inválida, favor digitar uma opção entre 1 e %i.\n", tamanho_baralho(mesa));

                                }
                            }

                            verif_jogada = faz_jogada_multipla(jogador_b, mesa, montante_j, carta_j, qtd_carta, jogada);
                            if (verif_jogada == -1)
                            {
                                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                                printf("\n\n\nImpossível realizar jogada, cartas não formam o valor 15.\n");
                                scanf("%c", &tecla_continua);
                                getchar();
                            }
                        }
                        else if (carta_j == 0)
                            goto inicio_menu;
                        else
                        {
                            partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                            partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                            partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                            verif_jogada = 0;
                            printf("\n\n\nErro: Carta digitada inválida, favor digitar uma carta de 1 a %i.\n", tamanho_baralho(jogador_b));
                            scanf("%c", &tecla_continua);
                            getchar();
                        }


                        tam_bar_m = tamanho_baralho(mesa);

                        /*
                          Se o baralho está vazio, então
                          o jogador fez escopa.
                        */
                        if (tam_bar_m == 0)
                        {
                            partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                            partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                            partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                            printf("\n\n\nNão existe nenhuma carta a mais na mesa, jogador fez uma Escopa.\n");
                            __fpurge(stdin);
                            scanf("%c", &tecla_continua);
                            p_jogador->escopa++;
                        }

                    }
                    else if (menu == 2)
                    {
                        verif_tam_b = tamanho_baralho(jogador_b);
                        int descarta_carta, verif = 0;

                        while (verif != 1)
                        {
                            partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                            partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                            partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                            printf("\n\n\nQual carta deseja descartar? (Digite 0 para cancelar)\nResp: ");
                            scanf("%i", &descarta_carta);

                            if (descarta_carta > 0 && descarta_carta <= verif_tam_b)
                            {
                                verif = descarta(jogador_b, mesa, descarta_carta);

                                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                                printf("\n\n\nCarta descartada.\n");
                                scanf("%c", &tecla_continua);
                                getchar();
                                verif_jogada = 1;
                            }
                            else if (descarta_carta == 0)
                                goto inicio_menu;
                            else
                            {
                                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                                printf("\n\n\nErro: Carta digitada inválida, favor digitar uma carta de 1 a %i.\n", tamanho_baralho(jogador_b));
                                scanf("%c", &tecla_continua);
                                getchar();
                                verif = 0;
                            }
                        }
                    }
                    else
                    {
                        partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                        partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                        partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                        printf("\n\n\nOpção inválida, favor digitar uma opção valida.\n");
                        scanf("%c", &tecla_continua);
                        getchar();
                    }

                }

            }
            else
            {
                verif_tam_b = tamanho_baralho(jogador_b);
                int descarta_carta, verif = 0;

                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                printf("\n\n\nNão existe nenhuma carta na mesa.\n");
                scanf("%c", &tecla_continua);


                while (verif != 1)
                {
                    partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                    partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                    partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                    printf("\n\n\nQual carta deseja descartar?\n");

                    scanf("%i", &descarta_carta);

                    if (descarta_carta > 0 && descarta_carta <= verif_tam_b)
                        verif = descarta(jogador_b, mesa, descarta_carta);
                    else
                        verif = 0;

                    if (verif == 0)
                    {
                        partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                        partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                        partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                        printf("\n\n\nA opção é inválida, favor digitar uma opção válida.\n");
                        scanf("%c", &tecla_continua);
                        getchar();
                    }
                    else
                    {
                        partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                        partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                        partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                        printf("\n\n\nCarta descartada.\n");
                        scanf("%c", &tecla_continua);
                        getchar();
                        verif_jogada = 1;
                    }
                }
            }
        }

        if (baralho_vazio(maquina_b) == 0)
        {
            int tam_bar_m;

            partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
            partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
            partida_baixo(jogador_b, number_j, naipe_j, mont_j);

            if (maquina_jogada(maquina_b, mesa, montante_m) == 0)
            {

                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                if (maquina_jogada_multipla(maquina_b, mesa, montante_m) == 0)
                {
                    partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                    partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                    partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                    printf("\n\n\nA maquina não possui carta para jogar, ");

                    int tam_ba_m = tamanho_baralho(maquina_b);

                    int desc_carta_m = 0;

                    while(desc_carta_m == 0)
                        desc_carta_m = rand() % (tam_ba_m+1);

                    if(desc_carta_m <= tam_ba_m)
                    {
                        printf("então descartou a ");
                        exibe_carta_descartada(maquina_b, desc_carta_m);
                        descarta(maquina_b, mesa, desc_carta_m);
                        __fpurge(stdin);
                        scanf("%c", &tecla_continua);
                    }
                }
            }

            /*
              Se o baralho está vazio, então
              a maquina fez escopa.
            */
            tam_bar_m = tamanho_baralho(mesa);
            if (tam_bar_m == 0)
            {
                partida_cima(tamanho_baralho(maquina_b), tamanho_baralho(principal));
                partida_meio(mesa, number_m, naipe_m, tamanho_baralho(maquina_b));
                partida_baixo(jogador_b, number_j, naipe_j, mont_j);

                printf("\n\n\nNão existe nenhuma carta a mais na mesa, maquina fez uma Escopa.\n");
                __fpurge(stdin);
                scanf("%c", &tecla_continua);
                p_maquina->escopa++;
            }
        }

        if ((baralho_vazio(jogador_b) == 1) && (baralho_vazio(maquina_b) == 1) && (baralho_vazio(principal)))
        {
            t_fim = 1;
        }
    }

    contagem_pontos(p_jogador, montante_j);
    contagem_pontos(p_maquina, montante_m);
    verifica_pontuacao(p_jogador, p_maquina, &jogar_novamente);

    if(jogar_novamente == 1)
        goto jog_nov;

    scanf("%c", &tecla_continua);

}
