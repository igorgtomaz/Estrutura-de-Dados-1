#include "Escopa.h"

/*
  Função que exibe a entrada do jogo
*/
void entrada()
{
    int i, j;
    char opcao;

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
                    if ((i > 8 && i < 35) && (j == 40 || j == 108))
                    {
                        printf(" ");
                    }
                    else if (((i == 6) || (i == 34)) && (j > 41 && j < 106))
                        printf(" ");
                    else if ((i == 7) && (j == 41))
                        printf("................................................................");
                    else if ((i == 7) && (j > 41 && j < 105));
                    else if ((i == 8) && (j == 41))
                        printf(":: ########:: ######::: ######::: #######:: ########::::: ###:::::");
                    else if ((i == 8) && (j > 41 && j < 107));
                    else if ((i == 9) && (j == 41))
                        printf(":: ##.....:: ##... ##: ##... ##: ##.... ##: ##.... ##::: ## ##::::");
                    else if ((i == 9) && (j > 41 && j < 107));
                    else if ((i == 10) && (j == 41))
                        printf (":: ##::::::: ##:::..:: ##:::..:: ##:::: ##: ##:::: ##:: ##:. ##:::");
                    else if ((i == 10) && (j > 41 && j < 107));
                    else if ((i == 11) && (j == 41))
                        printf (":: ######:::. ######:: ##::::::: ##:::: ##: ########:: ##:::. ##::");
                    else if ((i == 11) && (j > 41 && j < 107));
                    else if ((i == 12) && (j == 41))
                        printf (":: ##...:::::..... ##: ##::::::: ##:::: ##: ##.....::: #########::");
                    else if ((i == 12) && (j > 41 && j < 107));
                    else if ((i == 13) && (j == 41))
                        printf (":: ##::::::: ##::: ##: ##::: ##: ##:::: ##: ##:::::::: ##.... ##::");
                    else if ((i == 13) && (j > 41 && j < 107));
                    else if ((i == 14) && (j == 41))
                        printf (":: ########:. ######::. ######::. #######:: ##:::::::: ##:::: ##::");
                    else if ((i == 14) && (j > 41 && j < 107));
                    else if ((i == 15) && (j == 41))
                        printf ("::.......:::......::::......::::.......:::..:::::::::..:::::...:: ");
                    else if ((i == 15) && (j > 41 && j < 107));
                    else if ((i == 16) && (j == 62))
                        printf(" ......................");
                    else if ((i == 16) && (j > 62 && j < 85));
                    else if ((i == 17) && (j == 62))
                        printf(":: ########: ########::");
                    else if ((i == 17) && (j > 62 && j < 85));
                    else if ((i == 18) && (j == 62))
                        printf(": ##.... ##: ##.....:::");
                    else if ((i == 18) && (j > 62 && j < 85));
                    else if ((i == 19) && (j == 62))
                        printf(": ##:::: ##: ##::::::::");
                    else if ((i == 19) && (j > 62 && j < 85));
                    else if ((i == 20) && (j == 62))
                        printf(": ##:::: ##: ######::::");
                    else if ((i == 20) && (j > 62 && j < 85));
                    else if ((i == 21) && (j == 62))
                        printf(": ##:::: ##: ##...:::::");
                    else if ((i == 21) && (j > 62 && j < 85));
                    else if ((i == 22) && (j == 62))
                        printf(": ##:::: ##: ##::::::::");
                    else if ((i == 22) && (j > 62 && j < 85));
                    else if ((i == 23) && (j == 62))
                        printf(": ########:: ########::");
                    else if ((i == 23) && (j > 62 && j < 85));
                    else if ((i == 24) && (j == 62))
                        printf(":........:::........::");
                    else if ((i == 24) && (j > 62 && j < 84));
                    else if ((i == 25) && (j == 43))
                        printf (" ........................................................... ");
                    else if ((i == 25) && (j > 43 && j < 104));
                    else if ((i == 26) && (j == 43))
                        printf ("::: #######:: ##:::: ##: ####: ##::: ##: ########: ########::");
                    else if ((i == 26) && (j > 43 && j < 104));
                    else if ((i == 27) && (j == 43))
                        printf (":: ##.... ##: ##:::: ##:. ##:: ###:: ##:..... ##:: ##.....:::");
                    else if ((i == 27) && (j > 43 && j < 104));
                    else if ((i == 28) && (j == 43))
                        printf (":: ##:::: ##: ##:::: ##:: ##:: ####: ##::::: ##::: ##::::::::");
                    else if ((i == 28) && (j > 43 && j < 104));
                    else if ((i == 29) && (j == 43))
                        printf (":: ##:::: ##: ##:::: ##:: ##:: ## ## ##:::: ##:::: ######::::");
                    else if ((i == 29) && (j > 43 && j < 104));
                    else if ((i == 30) && (j == 43))
                        printf (":: ##: ## ##: ##:::: ##:: ##:: ##. ####::: ##::::: ##...:::::");
                    else if ((i == 30) && (j > 43 && j < 104));
                    else if ((i == 31) && (j == 43))
                        printf (":: ##:.. ##:: ##:::: ##:: ##:: ##:. ###:: ##:::::: ##::::::::");
                    else if ((i == 31) && (j > 43 && j < 104));
                    else if ((i == 32) && (j == 43))
                        printf ("::: ######::: #######::: ####: ##::. ##: ########: ########::");
                    else if ((i == 32) && (j > 43 && j < 104));
                    else if ((i == 33) && (j == 43))
                        printf (":::........:::........::.....:;..::::..::........::........: ");
                    else if ((i == 33) && (j > 43 && j < 104));
                    else if ((i == 41) && (j == 122))
                        printf("Create By Igor & Fabio");
                    else if ((i == 41) && (j > 122 && j < 144));
                    else
                    {
                        printf(" ");
                    }

                }
            }
        }
        printf("\n");
    }
    printf("Pressione qualquer tecla para iniciar: ");
    scanf("%c", &opcao);

}

/*
  Função que exibe o menu do jogo
*/
void menu_principal(int *opcao)
{
    int i, j, resp;

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
                    if(((i > 13 && i < 27) && j == 50) || ((i > 13 && i < 27) && j == 100))
                    {
                        printf("|");
                    }
                    else if (((i == 13) || (i == 26)) && (j > 50 && j < 100))
                        printf("_");
                    else
                    {
                        if ((i > 14 && i < 27) && j > 50 && j < 100)
                        {
                            if (j == 55 && i == 16)
                                printf("Bem vindo ao jogo");
                            else if (i == 16 && (j > 55 && j < 72));
                            else if (j == 55 && i == 18)
                                printf("Menu");
                            else if (i == 18 && (j > 55 && j < 59));
                            else if (j == 55 && i == 20)
                                printf("1 - Jogar");
                            else if (i == 20 && (j > 55 && j < 64));
                            else if (j == 55 && i == 21)
                                printf("2 - Instruções");
                            else if (i == 21 && (j > 55 && j < 69));
                            else if (j == 55 && i == 22)
                                printf("3 - Criadores");
                            else if (i == 22 && (j > 55 && j < 68));
                            else if (j == 55 && i == 23)
                                printf("4 - Sair");
                            else if (i == 23 && (j > 55 && j < 63));
                            else
                                printf(" ");
                        }
                        else
                            printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("Resposta: ");
    scanf("%i", &resp);
    *opcao = resp;
}

/*
  Função que exibe as instruções do jogo
*/
void instrucao()
{
    int i, j;
    char opcao;

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
                    if(((i > 4 && i < 39) && j == 10) || ((i > 4 && i < 39) && j == 135))
                    {
                        printf("|");
                    }
                    else if (((i == 4) || (i == 38)) && (j > 10 && j < 135))
                        printf("_");
                    else
                    {
                        if (j == 12  && i == 6)
                            printf("Objetivo:");
                        else if (i == 6 && (j > 12 && j < 21));
                        else if (j == 12  && i == 8)
                            printf("- Fazer a maior pontuação possível, formando combinações equivalentes a 15 e escopas.");
                        else if (i == 8 && (j > 12 && j < 97));
                        else if (j == 12  && i == 10)
                            printf("Pontuações:");
                        else if (i == 10 && (j > 12 && j < 23));
                        else if (j == 12  && i == 12)
                            printf("- Para cada escopa: 1 ponto;");
                        else if (i == 12 && (j > 12 && j < 40));
                        else if (j == 12  && i == 13)
                            printf("- Por ter todas as cartas de Ouros: 2 pontos;");
                        else if (i == 13 && (j > 12 && j < 57));
                        else if (j == 12  && i == 14)
                            printf("- Por ter a maioria das cartas de Ouros: 1 ponto;");
                        else if (i == 14 && (j > 12 && j < 61));
                        else if (j == 12  && i == 15)
                            printf("- Por ter o Sete de Ouros (Sete Belo): 1 ponto;");
                        else if (i == 15 && (j > 12 && j < 59));
                        else if (j == 12  && i == 16)
                            printf("- Por ter os quatro 7, inclusive o Belo: 3 pontos;");
                        else if (i == 16 && (j > 12 && j < 62));
                        else if (j == 12  && i == 17)
                            printf("- Por ter a maioria das cartas: 1 ponto;");
                        else if (i == 17 && (j > 12 && j < 52));
                        else if (j == 12  && i == 18)
                            printf("- Por ter a maioria dos 7: 1 ponto;");
                        else if (i == 18 && (j > 12 && j < 47));
                        else if (j == 12  && i == 19)
                            printf("- Se o adversário tiver menos de 10 cartas: 2 pontos.");
                        else if (i == 19 && (j > 12 && j < 65));
                        else if (j == 12  && i == 21)
                            printf("Observações:");
                        else if (i == 21 && (j > 12 && j < 24));
                        else if (j == 12  && i == 23)
                            printf("- Se você não possuir carta que combinada forme 15, deve descartar uma carta;");
                        else if (i == 23 && (j > 12 && j < 89));
                        else if (j == 12  && i == 24)
                            printf("- Ao digitar um número inválido, o jogo retorna ao menu automaticamente;");
                        else if (i == 24 && (j > 12 && j < 84));
                        else if (j == 12  && i == 25)
                            printf("- Para sair das opções (jogar e descartar), basta apenas digitar 0;");
                        else if (i == 25 && (j > 12 && j < 79));
                        else if (j == 12  && i == 26)
                            printf("- O jogo termina quando não houver mais cartas pra comprar/jogar.");
                        else if (i == 26 && (j > 12 && j < 77));
                        else if (j == 12  && i == 28)
                            printf("Cartas:");
                        else if (i == 28 && (j > 12 && j < 19));
                        else if (j == 12  && i == 30)
                            printf("- Carta 10 equivale a 8;");
                        else if (i == 30 && (j > 12 && j < 36));
                        else if (j == 12  && i == 31)
                            printf("- Carta 11 equivale a 9;");
                        else if (i == 31 && (j > 12 && j < 36));
                        else if (j == 12  && i == 32)
                            printf("- Carta 12 equivale a 10.");
                        else if (i == 32 && (j > 12 && j < 37));
                        else
                            printf(" ");
                    }
                }
            }
        }
    }
    printf("Pressione qualquer tecla para retornar ao menu: ");
    scanf("%c", &opcao);
    getchar();
}

/*
  Função que exibe os criadores do jogo
*/
void criadores()
{
    int i, j;
    char opcao;

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
                    if(((i > 13 && i < 27) && j == 50) || ((i > 13 && i < 27) && j == 100))
                    {
                        printf("|");
                    }
                    else if (((i == 13) || (i == 26)) && (j > 50 && j < 100))
                        printf("_");
                    else
                    {
                        if ((i > 14 && i < 27) && j > 50 && j < 100)
                        {
                            if (j == 55 && i == 16)
                                printf("Universidade Federal da Fronteira Sul");
                            else if (i == 16 && (j > 55 && j < 92));
                            else if (j == 55 && i == 18)
                                printf("CC - Estrutura de Dados 1 - Noturno");
                            else if (i == 18 && (j > 55 && j < 90));
                            else if (j == 55 && i == 20)
                                printf("Alunos:");
                            else if (i == 20 && (j > 55 && j < 62));
                            else if (j == 55 && i == 22)
                                printf("Igor Luiz Tomaz - Matrícula: 1521101033");
                            else if (i == 22 && (j > 55 && j < 94));
                            else if (j == 55 && i == 23)
                                printf("Fabio Antonio  -  Matrícula: 1621101039");
                            else if (i == 23 && (j > 55 && j < 94));
                            else
                                printf(" ");
                        }
                        else
                            printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("Pressione qualquer tecla para retornar ao menu: ");
    scanf("%c", &opcao);
    getchar();
}

/*
  Função que exibe a parte do embaralhando (apenas apresentada inicialmente)
*/
void embaralhando()
{
    char opcao;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("\t\t\t\t\t\t\t  Embaralhando...\n\n");
    printf("\t\t\t\t\t\t\t                     .------.\n");
    printf("\t\t\t\t\t\t\t  .------.           |7 .   |\n");
    printf("\t\t\t\t\t\t\t  |7_  _ |    .------; / \\  |\n");
    printf("\t\t\t\t\t\t\t  |( \\/ )|-----. _   |(_,_) |\n");
    printf("\t\t\t\t\t\t\t  | \\  / | /\\  |( )  |  I  7|\n");
    printf("\t\t\t\t\t\t\t  |  \\/ 7|/  \\ |_x_) |------'\n");
    printf("\t\t\t\t\t\t\t  `-----+'\\  / | Y  7|\n");
    printf("\t\t\t\t\t\t\t        |  \\/ 7|-----'\n");
    printf("\t\t\t\t\t\t\t        `------'\n");


    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Pressione qualquer tecla para retornar ao menu: ");
    scanf("%c", &opcao);
    getchar();
}

/*
  Função que exibe as cartas da maquina + a contagem do baralho principal
*/
void partida_cima(int qtd_carta, int tam_bar)
{
    system("clear");


    printf("\n\n");

    if (qtd_carta == 0)
    {
        printf("\n\n\n\n");
    }
    else if (qtd_carta == 1)
    {
        char espace8[10], espace5[7];

        strcpy(espace5, "\t\t\t\t\t");
        strcpy(espace8, "\t\t\t\t\t\t\t\t");

        printf("%s.-------.\n", espace8);
        printf("%s|   _   |\n", espace8);
        printf("\tBaralho Principal%s|  ( )  |\n", espace5);
        printf("\t\t%i\t%s| (_x_) |\n", tam_bar, espace5);
        printf("%s|   Y   |\n", espace8);
        printf("%s|_______+\n", espace8);

    }
    else if (qtd_carta == 2)
    {
        char espace7[10], espace5[7];

        strcpy(espace7, "\t\t\t\t\t\t\t   ");
        strcpy(espace5, "\t\t\t\t       ");

        printf("%s    .------.\n", espace7);
        printf("%s    | _  _ |\n", espace7);
        printf("\tBaralho Principal%s|( \\/ )|-----.\n", espace5);
        printf("\t\t%i%s        | -  - | /\\  |\n", tam_bar, espace5);
        printf("%s    |  --  |/  \\ |\n", espace7);
        printf("%s    `-----+'\\  / |\n", espace7);
        printf("%s          |  \\/  |\n", espace7);
        printf("%s          `------'\n", espace7);

    }
    else if (qtd_carta == 3)
    {
        char espace7[10], espace5[7];

        strcpy(espace7, "\t\t\t\t\t\t\t   ");
        strcpy(espace5, "\t\t\t\t   ");

        printf("%s.------.\n", espace7);
        printf("%s| _  _ |    .------.\n", espace7);
        printf("\tBaralho Principal%s|( \\/ )|-----. _   |\n", espace5);
        printf("\t\t%i%s\t   | -  - | /\\  |( )  |\n", tam_bar, espace5);
        printf("%s|  --  |/  \\ |_x_) |\n", espace7);
        printf("%s`-----+'\\  / | Y   |\n", espace7);
        printf("%s      |  \\/  |-----'\n", espace7);
        printf("%s      '------'      \n", espace7);
    }

}

/*
  Função que exibe as cartas da mesa de acordo com o tamanho do baralho da mesa
*/

void partida_meio(Baralho *ba, int *number, int *naipe, int qtd_carta_c)
{
    int tam = tamanho_baralho(ba);

    exibe_baralho(ba, number, naipe);

    imprime_carta_v2(tam, number, naipe, qtd_carta_c);
}

/*
  Função que exibe as cartas do jogador
*/
void partida_baixo(Baralho *ba, int *number, int *naipe, int mont)
{
    int tam = tamanho_baralho(ba);

    exibe_baralho(ba, number, naipe);

    imprime_carta(tam, number, naipe, mont);
}

/*
  Função que imprime carta por carta a partir da entrada dos vetores.
*/
void imprime_carta(int qtd_carta, int *carta, int *naipe, int mont)
{
    int i;
    char espace[100];

    printf("\n\n\n\n\n\n\n\n\n");

    if (qtd_carta == 1)
        strcpy(espace, "\t\t\t\t\t\t\t\t");
    else if (qtd_carta == 2)
        strcpy(espace, "\t\t\t\t\t\t\t   ");
    else if (qtd_carta == 3)
        strcpy(espace, "\t\t\t\t\t\t\t");

    printf("%s", espace);

    for(i = 0; i < qtd_carta; i++)
        if (carta[i] >= 10)
            printf(".--------. ");
        else
            printf(".------. ");

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if(carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("|%i _   | ", carta[i]);
            else if (naipe[i] == 1)
                printf("|%i .   | ", carta[i]);
            else if (naipe[i] == 2)
                printf("|%i /\\  | ", carta[i]);
            else
                printf("|%i_  _ | ", carta[i]);
        }
        else
        {
            if (naipe[i] == 0)
                printf("|%i _    | ", carta[i]);
            else if (naipe[i] == 1)
                printf("|%i .    | ", carta[i]);
            else if (naipe[i] == 2)
                printf("|%i /\\   | ", carta[i]);
            else
                printf("|%i_  _  | ", carta[i]);
        }

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("| ( )  | ");
            else if (naipe[i] == 1)
                printf("| / \\  | ");
            else if (naipe[i] == 2)
                printf("| /  \\ | ");
            else
                printf("|( \\/ )| ");
        }
        else
        {
            if (naipe[i] == 0)
                printf("|  ( )   | ");
            else if (naipe[i] == 1)
                printf("|  / \\   | ");
            else if (naipe[i] == 2)
                printf("|  /  \\  | ");
            else
                printf("| ( \\/ ) | ");
        }

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("|(_x_) | ");
            else if (naipe[i] == 1)
                printf("|(_,_) | ");
            else if (naipe[i] == 2)
                printf("| \\  / | ");
            else
                printf("| \\  / | ");
        }
        else
        {
            if (naipe[i] == 0)
                printf("| (_x_)  | ");
            else if (naipe[i] == 1)
                printf("| (_,_)  | ");
            else if (naipe[i] == 2)
                printf("|  \\  /  | ");
            else
                printf("|  \\  /  | ");
        }

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("|  Y  %i| ", carta[i]);
            else if (naipe[i] == 1)
                printf("|  I  %i| ", carta[i]);
            else if (naipe[i] == 2)
                printf("|  \\/ %i| ", carta[i]);
            else
                printf("|  \\/ %i| ", carta[i]);
        }
        else
        {
            if (naipe[i] == 0)
                printf("|   Y  %i| ", carta[i]);
            else if (naipe[i] == 1)
                printf("|   I  %i| ", carta[i]);
            else if (naipe[i] == 2)
                printf("|   \\/ %i| ", carta[i]);
            else
                printf("|   \\/ %i| ", carta[i]);
        }

    printf("\n");

    printf("%s", espace);

    for(i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
            printf("`------' ");
        else
            printf("`--------' ");

    printf("\n");
    printf("%s", espace);

    for(i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
            printf("   [%i]   ", (i+1));
        else
            printf("    [%i]    ", (i+1));


    printf("\n");

}

/*
  Função que exibe carta por carta, a partir de dois vetores.
*/
void imprime_carta_v2(int qtd_carta, int *carta, int *naipe, int qtd_carta_c)
{
    int i;
    char espace[100];

    printf("\n\n\n\n\n\n\n\n");

    if (qtd_carta == 1)
        strcpy(espace, "\t\t\t\t\t\t\t\t");
    else if (qtd_carta == 2)
        strcpy(espace, "\t\t\t\t\t\t\t   ");
    else if (qtd_carta == 3)
        strcpy(espace, "\t\t\t\t\t\t\t");
    else if (qtd_carta == 4)
        strcpy(espace, "\t\t\t\t\t\t   ");
    else if (qtd_carta == 5)
        strcpy(espace, "\t\t\t\t\t    ");
    else if (qtd_carta == 6)
        strcpy(espace, "\t\t\t\t\t");
    else if (qtd_carta == 7)
        strcpy(espace, "\t\t\t\t\t");
    else if (qtd_carta == 8)
        strcpy(espace, "\t\t\t\t");
    else
        strcpy(espace, "\t\t\t");

    printf("%s", espace);

    for(i = 0; i < qtd_carta; i++)
        if (carta[i] >= 10)
            printf(".--------. ");
        else
            printf(".------. ");

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if(carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("|%i _   | ", carta[i]);
            else if (naipe[i] == 1)
                printf("|%i .   | ", carta[i]);
            else if (naipe[i] == 2)
                printf("|%i /\\  | ", carta[i]);
            else
                printf("|%i_  _ | ", carta[i]);
        }
        else
        {
            if (naipe[i] == 0)
                printf("|%i _    | ", carta[i]);
            else if (naipe[i] == 1)
                printf("|%i .    | ", carta[i]);
            else if (naipe[i] == 2)
                printf("|%i /\\   | ", carta[i]);
            else
                printf("|%i_  _  | ", carta[i]);
        }

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("| ( )  | ");
            else if (naipe[i] == 1)
                printf("| / \\  | ");
            else if (naipe[i] == 2)
                printf("| /  \\ | ");
            else
                printf("|( \\/ )| ");
        }
        else
        {
            if (naipe[i] == 0)
                printf("|  ( )   | ");
            else if (naipe[i] == 1)
                printf("|  / \\   | ");
            else if (naipe[i] == 2)
                printf("|  /  \\  | ");
            else
                printf("| ( \\/ ) | ");
        }

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("|(_x_) | ");
            else if (naipe[i] == 1)
                printf("|(_,_) | ");
            else if (naipe[i] == 2)
                printf("| \\  / | ");
            else
                printf("| \\  / | ");
        }
        else
        {
            if (naipe[i] == 0)
                printf("| (_x_)  | ");
            else if (naipe[i] == 1)
                printf("| (_,_)  | ");
            else if (naipe[i] == 2)
                printf("|  \\  /  | ");
            else
                printf("|  \\  /  | ");
        }

    printf("\n");

    printf("%s", espace);

    for (i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
        {
            if (naipe[i] == 0)
                printf("|  Y  %i| ", carta[i]);
            else if (naipe[i] == 1)
                printf("|  I  %i| ", carta[i]);
            else if (naipe[i] == 2)
                printf("|  \\/ %i| ", carta[i]);
            else
                printf("|  \\/ %i| ", carta[i]);
        }
        else
        {
            if (naipe[i] == 0)
                printf("|   Y  %i| ", carta[i]);
            else if (naipe[i] == 1)
                printf("|   I  %i| ", carta[i]);
            else if (naipe[i] == 2)
                printf("|   \\/ %i| ", carta[i]);
            else
                printf("|   \\/ %i| ", carta[i]);
        }

    printf("\n");

    printf("%s", espace);

    for(i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
            printf("`------' ");
        else
            printf("`--------' ");

    printf("\n");

    printf("%s", espace);

    for(i = 0; i < qtd_carta; i++)
        if (carta[i] <= 9)
            printf("   [%i]   ", (i+1));
        else
            printf("   [%i]     ", (i+1));

}
