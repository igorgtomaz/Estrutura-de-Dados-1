typedef struct elemento *Baralho;
typedef struct pontuacao Pontuacao;

//Funções do back
int verif_pont_carta(int x);
Baralho *cria_baralho();
void elimina_baralho(Baralho *b);
int baralho_vazio(Baralho *ba);
int tamanho_baralho(Baralho *ba);
void nome_naipe (int naipe, char *nome_n);
int insere_baralho(Baralho *ba, int num, int naipe);
int remove_carta(Baralho *ba, int num, int naipe);
int preenche_baralho(Baralho *ba);
void exibe_baralho(Baralho *ba, int *number, int *naipe);
void embaralha(Baralho *ba);
int insere_comeco_baralho(Baralho *ba, int num, int naipe);
int insere_remove_carta(Baralho *ba1, Baralho *ba2, int num, int naipe);
int distribui_carta(Baralho *ba1, Baralho *ba2, int qtd);
int maquina_jogada(Baralho *ba1, Baralho *ba2, Baralho *ba3);
int faz_jogada(Baralho *ba1, Baralho *ba2, Baralho *ba3, int pos_carta_j, int pos_carta_m);
void exibe_carta_descartada(Baralho *ba1, int pos);
void partida(Baralho *principal, Baralho *mesa, Baralho *maquina_b, Baralho *montante_m, Baralho *jogador_b, Baralho *montante_j, Pontuacao *p_jogador, Pontuacao *p_maquina);
int faz_jogada_multipla(Baralho *ba1, Baralho *ba2, Baralho *ba1_m, int pos_mao, int qtd_carta, int *jogada);
int maquina_jogada_multipla(Baralho *ba1, Baralho *ba2, Baralho *ba3);
void contagem_pontos(Pontuacao *p, Baralho *ba1);
void verifica_pontuacao(Pontuacao *p1, Pontuacao *p2, int *resp_j);

//Funções da parte gráfica
void entrada();
void menu_principal();
void partida_cima(int qtd_carta, int tam_bar);
void partida_meio();
void partida_baixo(Baralho *ba, int *number, int *naipe, int mont);
void desenha_naipe(int i, int j, int naipe);
void imprime_carta(int qtd_carta, int *carta, int *naipe, int mont);
void imprime_carta_v2(int qtd_carta, int *carta, int *naipe, int qtd_carta_c);
void quadro_contagem_pontos(Pontuacao *p1, Pontuacao *p2);
