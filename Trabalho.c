#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct // Struct sobre as informacoes das jogadas
{
    char posicaoY;
    int posicaoX;
    char nomeDoNavio[10];
    int idDoNavio;
    int agua;
    
}tJogada;

typedef struct // Struct sobre a informacao do jogador
{
    char nome[17];
    int id;
    int qtdTirosAgua;
    int qtdTirosNavio;
}tJogador;

typedef struct // Struct sobre as informacoes dos navios
{
    char nome[10]; 
    int identificacao;
    int orientacao;
    int tamanho;//Utilizado para descobrir se o navio caiu
    char posicaoY;
    int posicaoX;
    int nJogada;

}tNavios;

typedef struct // Struct sobre as informacoes do tabuleiro
{
    char tabuleiro[10][10];
    char tabuleiroAtingido[10][10];
    char tabuleiroGuia[10][10];//Tabuleiro que guarda as posicoes no vetor dos navios
    tNavios navio[50];
    tNavios navioEstatisticas[50];
    int qtdNaviosEstatisticas;
    int posVetorDoNavio;   
    int ehInvalido;
    int contSub;
    int contCarr;
    int contDest;
    int contBattle;
    int contCruis;

}tTabuleiro;

typedef struct // Struct possuindo os conteudos principais do jogo
{
    tJogador jogador_1;
    tJogador jogador_2;
    tTabuleiro tabuleiroJog_1;
    tTabuleiro tabuleiroJog_2;
    tJogada jogadasJog_1[100];
    tJogada jogadasJog_2[100];
    int numJogadasJog_1;
    int numJogadasJog_2;
    int vencedor;

}tJogo;

tJogo InicializaJogo(char diretorio[]);
tTabuleiro LeTabuleiro(tTabuleiro tabuleiro,int ntab, char diretorio[]);
tTabuleiro InicializaTabuleiro();
tJogador InicializaJogador();
tJogador LeJogador(int num);
int VerificaSeOsNaviosTocamTabuleiro(tTabuleiro tabuleiro, int posicaox, int posicaoy);
tJogo RealizaJogo(tJogo jogo);
void GeraEstatisticas(tJogo jogo, char diretorio[]);
tTabuleiro GeraTabuValido();
tNavios LeNavio(FILE *pTabu);
int VerificaValidezPosicaoNavio(tNavios navio);// Verifica se a posicao inicial ultrapassa a borda do tabuleiro
tTabuleiro PosicionaNavioNosTabuleiros(tTabuleiro tabuleiro, int n);
tTabuleiro IncrementaTipNaviTabuleiro(tTabuleiro tabuleiro, tNavios navio);
tTabuleiro TornaInvalidoTabuleiro(tTabuleiro tabuleiro);
int VerificaSeTemNavioTabuleiro(tTabuleiro tabuleiro);
int VerificaSeTemOMesmTipNavio(tTabuleiro tabuleiro1, tTabuleiro tabuleiro2);//Verifica se tem a mesma qtd de navios e tipos de navios.
int VerificaSeEhHorizontal(tNavios navio);
int ObtemPosicaoXDoNavio(tNavios navio);
int ObtemPosicaoYDoNavio(tNavios navio);
int ObtemTamanhoDoNavio(tNavios navio);
int VerificaSeTemNavioTab(tTabuleiro tabuleiro);
void ImprimeValidezTabs(tTabuleiro tabuleiro1, tTabuleiro tabuleiro2, FILE *validacao);
void ImprimeJogador(tJogador jogador, FILE *saida);
void ImprimeTabuleiro(tTabuleiro tabuleiro, FILE *saida);
void ImprimeInicializacao(FILE *inicializacao,tJogo jogo);
void PedeJogadaJogador(tJogador jogador);//Imprime o pedido da jogada
tJogada LeJogada(tJogador jogador);
void ImprimeJogadaInvalida(tJogada jogada, tJogador jogador);
tJogada MarcaSeEhAguaOuNao(tTabuleiro tabuleiro, tJogada jogada);
tTabuleiro MarcaJogadaTabuleiro(tTabuleiro tabuleiro, tJogada jogada);//Marca no tabuleiro se a jogada atingiu a agua ou nao
int VerificaSeJaTemJogada(tJogada jogada, tTabuleiro tabuleiro);
void ImprimeResultadoDaJogada(tTabuleiro tabuleiro, tJogador jogadorAtirou, tJogador jogadorRecebeuTiro);
void ImprimeTabuleiroAtingido(tTabuleiro tabuleiro);
void ImprimeVencedorJogo(tJogo jogo);//Descobre qual vencedor e imprime
void ImprimeVencedorJogador(tJogador jogador);
tNavios DestroiNavio(tNavios navio);
void ImprimeJogada(tJogada jogada, tTabuleiro tabuleiro);
int VerificaSeDestruiuNavio(tNavios navio);
void ImprimeAfundouNavio(tNavios navio);
tJogador MudaAcertoTirosJogador(tJogador jogador, tJogada jogada);
void GeraResultadoJogo(tJogo jogo, char diretorio[]);
void ImprimeVencedorJogoResultado(tJogo jogo, FILE *saida);//Descobre qual vencedor e imprime
void ImprimeVencedorJogadorResultado(tJogador jogador, FILE *saida);
tTabuleiro ObtemVetorDoNavioResultado(tTabuleiro tabuleiro, tJogada jogada);
void ImprimeJogadaResultado(tJogada jogada, tTabuleiro tabuleiro, FILE *saida);
void ImprimeNavioAtingidoResultado(tNavios navio, FILE *saida);
void ImprimeAcertoeErroTirosJogador(tJogador jogador, FILE *saida,int qtdDeJogadas);
int ObtemPosicaoXDoTiroJogada(tJogada jogada);
int ObtemPosicaoYDoTiroJogada(tJogada jogada);
float CalculaDesvioPadrao(tJogo jogo,float mediax,float mediay, int numeroJogador);
tTabuleiro OrganizaVetorNavioEstatTabuleiro(tTabuleiro tabuleiro, tJogada jogada, int posAnterior, int nJogadaAtual);
void ImprimeNavioAtingidoEstatisticas(tTabuleiro tabuleiro,FILE *saida);
tTabuleiro LimpaTabuleiroGuia(tTabuleiro tabuleiro, tJogada jogada);//Limpa o tabuleiro para que o navio nao se repita
int VerificaSeEhTiro(tJogada jogada);
int ObtemPosAnterior(tTabuleiro tabuleiro);
void ImprimeAFraseNaviosDeJogador(tJogador jogador, FILE *saida);
tTabuleiro AdicionaAoVetorNavioEstatisticas(tTabuleiro tabuleiro, int nJogada);
tNavios AjustaNumJogadaNavio(tNavios navio,int nJogada);
void ImprimeNavioEst(tNavios navios, FILE *saida);
void OrdenaCrescenteNavios(tNavios vet[], int qtd);
tTabuleiro AjustaParametroPosNavio(tTabuleiro tabuleiro);//Ajusta o vetor posicao do navio para nao quebrar o codigo

int main(int argc, char * argv[]){
    if(argc<=1){
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }
    char diretorio[1001];
    sprintf(diretorio,"%s",argv[1]);
    tJogo jogo;
    jogo=InicializaJogo(diretorio);
    jogo=RealizaJogo(jogo);
    GeraResultadoJogo(jogo, diretorio);
    GeraEstatisticas(jogo, diretorio);
    return 0;
}

tJogo InicializaJogo(char diretorio[]){
    tJogo jogo;
    char caminho_val[1040];
    FILE *pValidacao;
    sprintf(caminho_val,"%s/saida/validacao_tabuleiros.txt",diretorio);
    pValidacao=fopen(caminho_val,"w");
    if(!pValidacao){
        printf("Nao conseguiu ler %s\n",caminho_val);
        fclose(pValidacao);
        exit(1);
    }
    jogo.tabuleiroJog_1=InicializaTabuleiro();
    jogo.tabuleiroJog_2=InicializaTabuleiro();
    jogo.jogador_1=InicializaJogador();
    jogo.jogador_2=InicializaJogador();
    jogo.tabuleiroJog_1=LeTabuleiro(jogo.tabuleiroJog_1,1, diretorio);
    jogo.tabuleiroJog_2=LeTabuleiro(jogo.tabuleiroJog_2,2, diretorio);
    ImprimeValidezTabs(jogo.tabuleiroJog_1,jogo.tabuleiroJog_2, pValidacao);
    jogo.jogador_1=LeJogador(1);
    jogo.jogador_2=LeJogador(2);
    FILE *pInicializao;
    char caminho[1040];
    sprintf(caminho,"%s/saida/inicializacao.txt",diretorio);
    pInicializao=fopen(caminho,"w");
    if(!pInicializao){
        printf("Nao conseguiu ler %s\n",caminho);
        fclose(pInicializao);
        exit(1);
    }
    ImprimeInicializacao(pInicializao, jogo);
    fclose(pInicializao);
    fclose(pValidacao);
    return jogo;
}

tTabuleiro LeTabuleiro(tTabuleiro tabuleiro,int ntab, char diretorio[]){
    int n=0;
    char caminho[1040];
    FILE *pTabule;
    if(ntab==1){
        sprintf(caminho,"%s/tabu_1.txt",diretorio);
        pTabule=fopen(caminho,"r");
        if(!pTabule){
            printf("Nao conseguiu ler %s\n",caminho);
            fclose(pTabule);
            exit(1);
        }
    }
    if(ntab==2){
        sprintf(caminho,"%s/tabu_2.txt",diretorio);
        pTabule=fopen(caminho,"r");
        if(!pTabule){
            printf("Nao conseguiu ler %s\n",caminho);
            fclose(pTabule);
            exit(1);
        }
    }
    while(!feof(pTabule)){
        tabuleiro.navio[n]=LeNavio(pTabule);
        if(!VerificaValidezPosicaoNavio(tabuleiro.navio[n])){
            tabuleiro=TornaInvalidoTabuleiro(tabuleiro);
        }
        tabuleiro=IncrementaTipNaviTabuleiro(tabuleiro, tabuleiro.navio[n]);
        tabuleiro=PosicionaNavioNosTabuleiros(tabuleiro,n);
        n++;
    }
    if(!VerificaSeTemNavioTabuleiro(tabuleiro)){
        tabuleiro=TornaInvalidoTabuleiro(tabuleiro);
    }
    fclose (pTabule);
    return tabuleiro;
}

tNavios LeNavio(FILE *pTabu){
    tNavios navio;
    fscanf(pTabu,"%[^;];",navio.nome);
    fscanf(pTabu, "%d;", &navio.identificacao);
    fscanf(pTabu, "%d;", &navio.orientacao);
    fscanf(pTabu, "%c%d", &navio.posicaoY, &navio.posicaoX);
    fscanf(pTabu,"\n");
    navio.tamanho=ObtemTamanhoDoNavio(navio);
    return navio;
}

int VerificaValidezPosicaoNavio(tNavios navio){
    if(navio.posicaoX>10){
        return 0;
    }
    if(navio.posicaoX<=0){
        return 0;
    }
    if(navio.posicaoY>'j'){
        return 0;
    }
    return 1;
}

tTabuleiro InicializaTabuleiro(){
    int i, j;
    tTabuleiro tabuleiro;
    tabuleiro.posVetorDoNavio=0;
    tabuleiro.ehInvalido=0;
    tabuleiro.contSub=0;
    tabuleiro.contCarr=0;
    tabuleiro.contDest=0;
    tabuleiro.contBattle=0;
    tabuleiro.contCruis=0;
    tabuleiro.qtdNaviosEstatisticas=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro.tabuleiro[i][j]='o';
            tabuleiro.tabuleiroAtingido[i][j]='.';
            tabuleiro.tabuleiroGuia[i][j]='-';
        }
    }
    return tabuleiro;
}

tJogador InicializaJogador(){
    tJogador jogador;
    jogador.qtdTirosAgua=0;
    jogador.qtdTirosNavio=0;
    return jogador;
}

tTabuleiro PosicionaNavioNosTabuleiros(tTabuleiro tabuleiro, int n){
    int x, y, i=0,j=0, tam=0, a=0;
    x=ObtemPosicaoXDoNavio(tabuleiro.navio[n]);
    y=ObtemPosicaoYDoNavio(tabuleiro.navio[n]);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(j==x && i==y){
                if(VerificaSeEhHorizontal){//ORIENTACAO HORIZONTAL
                    tam=ObtemTamanhoDoNavio(tabuleiro.navio[n]);
                    for(a=0;a<tam;a++){
                        if(j+a>=10){
                            tabuleiro=TornaInvalidoTabuleiro(tabuleiro);
                            return tabuleiro;
                        }
                        tabuleiro.tabuleiro[i][j+a]='a';//CARACTERE SO PRA TESTAR A FUNCAO QUE SE TOCAM
                        if(VerificaSeOsNaviosTocamTabuleiro(tabuleiro, i, j+a)){
                            tabuleiro=TornaInvalidoTabuleiro(tabuleiro);
                            return tabuleiro;
                        }
                    }
                    for(a=0;a<tam;a++){
                        tabuleiro.tabuleiro[i][j+a]='X';
                        tabuleiro.tabuleiroGuia[i][j+a]='A'+ n;
                    }
                }
                else{//ORIENTACAO VERTICAL
                    tam=ObtemTamanhoDoNavio(tabuleiro.navio[n]);
                    for(a=0;a<tam;a++){
                        if(i+a>=10){
                           tabuleiro=TornaInvalidoTabuleiro(tabuleiro);
                            return tabuleiro;
                        }
                        tabuleiro.tabuleiro[i+a][j]='a';//CARACTERE SO PRA TESTAR A FUNCAO QUE SE TOCAM
                        if(VerificaSeOsNaviosTocamTabuleiro(tabuleiro, i+a, j)){
                            tabuleiro=TornaInvalidoTabuleiro(tabuleiro);
                            return tabuleiro;
                        }
                    }
                    for(a=0;a<tam;a++){
                        tabuleiro.tabuleiro[i+a][j]='X';
                        tabuleiro.tabuleiroGuia[i+a][j]='A'+ n;
                    }
                }
            }
        }
    }
    return tabuleiro;
}

tTabuleiro IncrementaTipNaviTabuleiro(tTabuleiro tabuleiro, tNavios navio){
    if(!strcmp(navio.nome,"Submarine")){
        tabuleiro.contSub++;
    }
    if(!strcmp(navio.nome,"Battleship")){
        tabuleiro.contBattle++;
    }
    if(!strcmp(navio.nome,"Cruiser")){
        tabuleiro.contCruis++;
    }
    if(!strcmp(navio.nome,"Carrier")){
        tabuleiro.contCarr++;
    }
    if(!strcmp(navio.nome,"Destroyer")){
        tabuleiro.contDest++;
    }
    else{
        tabuleiro.ehInvalido;//SE ENTRAR AQUI O NOME DO NAVIO EH INVALIDO
    }
    return tabuleiro;
}

int VerificaSeTemOMesmTipNavio(tTabuleiro tabuleiro1, tTabuleiro tabuleiro2){
    if(tabuleiro1.contBattle==tabuleiro2.contBattle && tabuleiro1.contCarr==tabuleiro2.contCarr){
        if(tabuleiro1.contCruis==tabuleiro2.contCruis && tabuleiro1.contDest==tabuleiro2.contDest){
            if(tabuleiro1.contSub==tabuleiro2.contSub){
                return 1;
            }
        }
    }
    return 0;
}

int VerificaSeTemNavioTabuleiro(tTabuleiro tabuleiro){
    if(tabuleiro.contBattle==0 && tabuleiro.contCarr==0){
        if(tabuleiro.contCruis==0 && tabuleiro.contDest==0){
            if(tabuleiro.contSub==0){
                return 0;
            }
        }
    }
    return 1;
}

tTabuleiro TornaInvalidoTabuleiro(tTabuleiro tabuleiro){
    tabuleiro.ehInvalido=1;
    return tabuleiro;
}

tJogador LeJogador(int num){
    tJogador jogador;
    jogador.id=num;
    printf("Nome do Jogador %d:\n",num);
    scanf("%16s",jogador.nome);
    return jogador;
}

int VerificaSeEhHorizontal(tNavios navio){
    if(navio.orientacao==1){
        return 1;
    }
    else return 0;
}

int ObtemPosicaoXDoNavio(tNavios navio){
    return (navio.posicaoX-1);
}

int ObtemPosicaoYDoNavio(tNavios navio){
    return (navio.posicaoY-'a');
}

int ObtemTamanhoDoNavio(tNavios navio){
    if(!strcmp(navio.nome,"Submarine")){
        return 3;
    }
    if(!strcmp(navio.nome,"Battleship")){
        return 4;
    }
    if(!strcmp(navio.nome,"Cruiser")){
        return 3;
    }
    if(!strcmp(navio.nome,"Carrier")){
        return 5;
    }
    if(!strcmp(navio.nome,"Destroyer")){
        return 2;
    }
}

void ImprimeJogador(tJogador jogador, FILE *saida){
    fprintf(saida, "%s\n", jogador.nome);
}

void ImprimeTabuleiro(tTabuleiro tabuleiro, FILE *saida){
    int i=0, j=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            fprintf(saida,"%c", tabuleiro.tabuleiro[i][j]);
            if(j<9){
                fprintf(saida," ");
            }
        }
        if(i<9){
            fprintf(saida,"\n");
        }
    }
}

int VerificaSeOsNaviosTocamTabuleiro(tTabuleiro tabuleiro, int posicaox, int posicaoy){
    int n=0;
    if(posicaox-1>=0){
        if((tabuleiro.tabuleiro[posicaox-1][posicaoy])=='X'){
            return 1;
        }
        if(posicaoy+1<10){
            if((tabuleiro.tabuleiro[posicaox-1][posicaoy+1])=='X'){
                return 1;
            }
        }
    }
    if(posicaoy-1>=0){
        if((tabuleiro.tabuleiro[posicaox][posicaoy-1])=='X'){
            return 1;
        }
        if(posicaox-1>=0){
            if((tabuleiro.tabuleiro[posicaox-1][posicaoy-1])=='X'){
                return 1;
        }
        }
    }
    if(posicaox+1<10){
        if((tabuleiro.tabuleiro[posicaox+1][posicaoy])=='X'){
            return 1;
        }
        if(posicaoy-1>=0){
            if((tabuleiro.tabuleiro[posicaox+1][posicaoy-1])=='X'){
                return 1;
            }
        }
    }
    if(posicaoy+1<10){
        if((tabuleiro.tabuleiro[posicaox][posicaoy+1])=='X'){
            return 1;
        }
        if(posicaox+1<10){
            if((tabuleiro.tabuleiro[posicaox+1][posicaoy+1])=='X'){
                return 1;
            }
        }
    }
    return 0;
}

void ImprimeInicializacao(FILE *inicializacao, tJogo jogo){
    ImprimeJogador(jogo.jogador_1, inicializacao);
    ImprimeTabuleiro(jogo.tabuleiroJog_1, inicializacao);
    fprintf(inicializacao,"\n\n");
    ImprimeJogador(jogo.jogador_2, inicializacao);
    ImprimeTabuleiro(jogo.tabuleiroJog_2,inicializacao);
}

void ImprimeValidezTabs(tTabuleiro tabuleiro1, tTabuleiro tabuleiro2, FILE *validacao){
    if(tabuleiro1.ehInvalido){
       fprintf(validacao,"tabu_1.txt;invalido\n"); 
    }
    else{
        fprintf(validacao,"tabu_1.txt;valido\n");
    }
    if(tabuleiro2.ehInvalido){
        fprintf(validacao,"tabu_2.txt;invalido");
    }
    else{
        fprintf(validacao,"tabu_2.txt;valido");
    }
    if(tabuleiro1.ehInvalido||tabuleiro2.ehInvalido){
        exit(1);
    }
    if(VerificaSeTemOMesmTipNavio(tabuleiro1, tabuleiro2)){
        fprintf(validacao,"\nTabuleiros compativeis entre si");
    }
    else {
        fprintf(validacao,"\nTabuleiros incompativeis entre si");
        exit(1);
    }
}

tJogo RealizaJogo(tJogo jogo){
    int n=0;
    int cont=1;//IMPEDE DE IMPRIMIR MAIS UMA VEZ O PEDE JOGADA
    printf("\n");
    while(VerificaSeTemNavioTab(jogo.tabuleiroJog_2)){
        if(cont){
            PedeJogadaJogador(jogo.jogador_1);//PARTE RELACIONADA AS JOGADAS DO JOG 1
        }
        jogo.jogadasJog_1[jogo.numJogadasJog_1]=LeJogada(jogo.jogador_1);
        if(VerificaSeJaTemJogada(jogo.jogadasJog_1[jogo.numJogadasJog_1], jogo.tabuleiroJog_2)){
            ImprimeJogadaInvalida(jogo.jogadasJog_1[jogo.numJogadasJog_1], jogo.jogador_1);
            cont=0;
            continue;
        }
        jogo.jogadasJog_1[jogo.numJogadasJog_1]=MarcaSeEhAguaOuNao(jogo.tabuleiroJog_2,jogo.jogadasJog_1[jogo.numJogadasJog_1]);
        jogo.tabuleiroJog_2=MarcaJogadaTabuleiro(jogo.tabuleiroJog_2,jogo.jogadasJog_1[jogo.numJogadasJog_1]);
        jogo.jogador_1=MudaAcertoTirosJogador(jogo.jogador_1,jogo.jogadasJog_1[jogo.numJogadasJog_1]);
        ImprimeJogada(jogo.jogadasJog_1[jogo.numJogadasJog_1], jogo.tabuleiroJog_2);
        ImprimeResultadoDaJogada(jogo.tabuleiroJog_2, jogo.jogador_1, jogo.jogador_2);
        jogo.numJogadasJog_1++;
        cont=1;

        //PARTE RELACIONADA AS JOGADAS DO JOG 2
        PedeJogadaJogador(jogo.jogador_2);
        while (1){        
            jogo.jogadasJog_2[jogo.numJogadasJog_2]=LeJogada(jogo.jogador_2);
            if(VerificaSeJaTemJogada(jogo.jogadasJog_2[jogo.numJogadasJog_2], jogo.tabuleiroJog_1)){
                ImprimeJogadaInvalida(jogo.jogadasJog_2[jogo.numJogadasJog_2], jogo.jogador_2);
                continue;
            }
            break;
        }
        jogo.jogadasJog_2[jogo.numJogadasJog_2]=MarcaSeEhAguaOuNao(jogo.tabuleiroJog_1,jogo.jogadasJog_2[jogo.numJogadasJog_2]);
        jogo.tabuleiroJog_1=MarcaJogadaTabuleiro(jogo.tabuleiroJog_1,jogo.jogadasJog_2[jogo.numJogadasJog_2]);
        jogo.jogador_2=MudaAcertoTirosJogador(jogo.jogador_2,jogo.jogadasJog_2[jogo.numJogadasJog_2]);
        ImprimeJogada(jogo.jogadasJog_2[jogo.numJogadasJog_2], jogo.tabuleiroJog_1);
        ImprimeResultadoDaJogada(jogo.tabuleiroJog_1, jogo.jogador_2, jogo.jogador_1);
        jogo.numJogadasJog_2++;
        if(!VerificaSeTemNavioTab(jogo.tabuleiroJog_1)){
            jogo.vencedor=2;
            break;
        }
    }
    if(!VerificaSeTemNavioTab(jogo.tabuleiroJog_2)){
        if(jogo.vencedor==2){//JOGADOR 2 VENCEU
            jogo.vencedor=3;//EMPATE
        }
        else{
            jogo.vencedor=1;//JOGADOR 1 VENCEU
        }
    }
    ImprimeVencedorJogo(jogo);
    return jogo;
}

int VerificaSeTemNavioTab(tTabuleiro tabuleiro){
    int i=0, j=0;
     for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(tabuleiro.tabuleiro[i][j]=='X'){
                return 1;
            }
        }
    }
    return 0;
}

void PedeJogadaJogador(tJogador jogador){
    printf("Jogada de %s:\n\n",jogador.nome);
}

tJogada LeJogada(tJogador jogador){
    tJogada jogada;
    char jog[30]="\0";
    int cont=1;
        while(1){
            scanf("%29s",jog);
            sscanf(jog,"%c%d",&jogada.posicaoY, &jogada.posicaoX);
            if(jogada.posicaoY<='j'&& jogada.posicaoX<=10 && jogada.posicaoX>0 && jogada.posicaoY>='a' && strlen(jog)<=3){
                cont=0;
            }
            if(jog[2]>=58||jog[2]<=47){
                cont=1;
            }
            if(cont==1){
                if(strlen(jog)>2||strlen(jog)<=1){
                    printf("%s:Jogada invalida! Jogue novamente %s:\n\n", jog, jogador.nome);
                    continue;
                }
            }
            sscanf(jog,"%c%d",&jogada.posicaoY, &jogada.posicaoX);
            if((jogada.posicaoY>'j'|| jogada.posicaoX>10) || jogada.posicaoX<0 || jogada.posicaoY<'a'){
                ImprimeJogadaInvalida(jogada, jogador);
                cont=1;
                continue;
            }
            break;
        }
        return jogada;
}

void ImprimeJogadaInvalida(tJogada jogada, tJogador jogador){
    printf("%c%d:Jogada invalida! Jogue novamente %s:\n\n",jogada.posicaoY,jogada.posicaoX,jogador.nome);
}

int VerificaSeJaTemJogada(tJogada jogada, tTabuleiro tabuleiro){
    int x, y, i=0,j=0;
    x=jogada.posicaoX - 1;
    y=jogada.posicaoY - 'a';
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(j==x && i==y){
                if(tabuleiro.tabuleiroAtingido[i][j]!='.'){
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
     }
}

tJogada MarcaSeEhAguaOuNao(tTabuleiro tabuleiro, tJogada jogada){
    int x, y, i=0,j=0;
    x=jogada.posicaoX - 1;
    y=jogada.posicaoY - 'a';
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(j==x && i==y){
                if(tabuleiro.tabuleiro[i][j]=='X'){
                    jogada.agua=0;
                }
                else {
                jogada.agua=1;
                }
            }
        }
     }
     return jogada;
}

tTabuleiro MarcaJogadaTabuleiro(tTabuleiro tabuleiro, tJogada jogada){
    int x, y, i=0,j=0, posVetor=0;
    x=jogada.posicaoX - 1;
    y=jogada.posicaoY - 'a';
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(j==x && i==y){
                if(tabuleiro.tabuleiro[i][j]=='X'){
                    tabuleiro.tabuleiroAtingido[i][j]='X';
                    tabuleiro.tabuleiro[i][j]='o';
                    tabuleiro.posVetorDoNavio=tabuleiro.tabuleiroGuia[i][j]-'A';
                    tabuleiro.navio[tabuleiro.posVetorDoNavio]=DestroiNavio(tabuleiro.navio[tabuleiro.posVetorDoNavio]);
                }
                else {
                tabuleiro.tabuleiroAtingido[i][j]='o';
                }
            }
        }
     }
     return tabuleiro;
}

void ImprimeResultadoDaJogada(tTabuleiro tabuleiro, tJogador jogadorAtirou, tJogador jogadorRecebeuTiro){
    printf("Tabuleiro atual de %s apos a jogada de %s\n",jogadorRecebeuTiro.nome, jogadorAtirou.nome);
    ImprimeTabuleiroAtingido(tabuleiro);
}

void ImprimeTabuleiroAtingido(tTabuleiro tabuleiro){
    int i=0, j=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%c", tabuleiro.tabuleiroAtingido[i][j]);
            if(j<9){
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void ImprimeVencedorJogo(tJogo jogo){
    if(jogo.vencedor==1){
        ImprimeVencedorJogador(jogo.jogador_1);
    }
    if(jogo.vencedor==2){
        ImprimeVencedorJogador(jogo.jogador_2);
    }
    else if(jogo.vencedor==3){
        printf("Empate\n");
    }
}

void ImprimeVencedorJogador(tJogador jogador){
    printf("Vencedor: %s\n",jogador.nome);
}

tNavios DestroiNavio(tNavios navio){
    navio.tamanho--;
    return navio;
}

void ImprimeJogada(tJogada jogada, tTabuleiro tabuleiro){
    printf("%c%d:",jogada.posicaoY,jogada.posicaoX);
    if(jogada.agua==1){
        printf("Agua\n\n");
    }
    else if(VerificaSeDestruiuNavio(tabuleiro.navio[tabuleiro.posVetorDoNavio])==1){
        ImprimeAfundouNavio(tabuleiro.navio[tabuleiro.posVetorDoNavio]);
    }
    else printf("Tiro!\n\n");
}

int VerificaSeDestruiuNavio(tNavios navio){
    if(navio.tamanho==0){
        return 1;
    }
    else return 0;
}

void ImprimeAfundouNavio(tNavios navio){
    printf("Afundou %s\n\n", navio.nome);
}

tJogador MudaAcertoTirosJogador(tJogador jogador, tJogada jogada){
    if(jogada.agua==1){
        jogador.qtdTirosAgua++;
    }
    else jogador.qtdTirosNavio++;
    return jogador;
}

void GeraResultadoJogo(tJogo jogo,char diretorio[]){
    int n=0;
    char caminho[1040];
    sprintf(caminho,"%s/saida/resultado.txt",diretorio);
    FILE *pResultado;
    pResultado=fopen(caminho,"w");
    if(!pResultado){
        printf("Nao conseguiu ler %s\n",caminho);
        fclose(pResultado);
        exit(1);
    }
    ImprimeJogador(jogo.jogador_1, pResultado);
    for(n=0;n<jogo.numJogadasJog_1;n++){
        jogo.tabuleiroJog_2=ObtemVetorDoNavioResultado(jogo.tabuleiroJog_2, jogo.jogadasJog_1[n]);
        ImprimeJogadaResultado(jogo.jogadasJog_1[n], jogo.tabuleiroJog_2, pResultado);
    }
    fprintf(pResultado,"\n");
    ImprimeJogador(jogo.jogador_2, pResultado);
    for(n=0;n<jogo.numJogadasJog_2;n++){
        jogo.tabuleiroJog_1=ObtemVetorDoNavioResultado(jogo.tabuleiroJog_1, jogo.jogadasJog_2[n]);
        ImprimeJogadaResultado(jogo.jogadasJog_2[n], jogo.tabuleiroJog_1, pResultado);
    }
    fprintf(pResultado,"\n");
    ImprimeVencedorJogoResultado(jogo, pResultado);
    fclose(pResultado);
}

void ImprimeVencedorJogoResultado(tJogo jogo, FILE *saida){
    if(jogo.vencedor==1){
        ImprimeVencedorJogadorResultado(jogo.jogador_1, saida);
    }
    if(jogo.vencedor==2){
        ImprimeVencedorJogadorResultado(jogo.jogador_2, saida);
    }
    else if(jogo.vencedor==3){
        fprintf(saida,"Empate");
    }
}

void ImprimeVencedorJogadorResultado(tJogador jogador, FILE *saida){
    fprintf(saida,"Vencedor: %s",jogador.nome);
}

tTabuleiro ObtemVetorDoNavioResultado(tTabuleiro tabuleiro, tJogada jogada){
    int x, y, i=0,j=0, posVetor=0;
    x=jogada.posicaoX - 1;
    y=jogada.posicaoY - 'a';
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(j==x && i==y){
                if(tabuleiro.tabuleiroAtingido[i][j]=='X'){
                    tabuleiro.posVetorDoNavio=tabuleiro.tabuleiroGuia[i][j]-'A';
                }
            }
        }
     }
     return tabuleiro;
}

void ImprimeJogadaResultado(tJogada jogada, tTabuleiro tabuleiro, FILE *saida){
    fprintf(saida,"%c%d - ",jogada.posicaoY,jogada.posicaoX);
    if(jogada.agua==1){
        fprintf(saida,"Agua\n");
    }
    else{
        fprintf(saida,"Tiro - ");
        ImprimeNavioAtingidoResultado(tabuleiro.navio[tabuleiro.posVetorDoNavio], saida);
    }
}

void ImprimeNavioAtingidoResultado(tNavios navio,FILE *saida){
    fprintf(saida, "%s - ID %02d\n",navio.nome, navio.identificacao);
}

void GeraEstatisticas(tJogo jogo, char diretorio[]){
    char caminho[1040];
    int n=0, posicaoAnterior=-9000;
    float somax=0, somay=0, mediax=0, mediay=0, desviopadrao=0;
    sprintf(caminho,"%s/saida/estatisticas.txt",diretorio);
    FILE *pEstatisticas;
    pEstatisticas=fopen(caminho, "w");
    if(!pEstatisticas){
        printf("Nao conseguiu ler %s\n",caminho);
        fclose(pEstatisticas);
        exit(1);
    }
    ImprimeJogador(jogo.jogador_1, pEstatisticas);
    ImprimeAcertoeErroTirosJogador(jogo.jogador_1, pEstatisticas, jogo.numJogadasJog_1);
    for(n=0;n<jogo.numJogadasJog_1;n++){
        somax=somax + ObtemPosicaoXDoTiroJogada(jogo.jogadasJog_1[n]);//COLUNA
        somay=somay + ObtemPosicaoYDoTiroJogada(jogo.jogadasJog_1[n]);//LINHA
    }
    mediax=1+somax/(float)jogo.numJogadasJog_1;//soma 1 pq obtem comecando da posicao 0, mas o tabuleiro eh pra comecar do 1
    mediay=1+somay/(float)jogo.numJogadasJog_1;//soma 1 pq obtem comecando da posicao 0, mas o tabuleiro eh pra comecar do 1
    fprintf(pEstatisticas,"Localizacao Media: (%.2f,%.2f)\n", mediay, mediax);
    desviopadrao=CalculaDesvioPadrao(jogo, mediax, mediay,1);
    fprintf(pEstatisticas,"Desvio Padrao da Localizacao: %.2f\n", desviopadrao);
    ImprimeAFraseNaviosDeJogador(jogo.jogador_1,pEstatisticas);
    jogo.tabuleiroJog_1=AjustaParametroPosNavio(jogo.tabuleiroJog_1);
    for(n=0;n<jogo.numJogadasJog_2;n++){
        jogo.tabuleiroJog_1=ObtemVetorDoNavioResultado(jogo.tabuleiroJog_1, jogo.jogadasJog_2[n]);
        jogo.tabuleiroJog_1=LimpaTabuleiroGuia(jogo.tabuleiroJog_1, jogo.jogadasJog_2[n]);
        jogo.tabuleiroJog_1=OrganizaVetorNavioEstatTabuleiro(jogo.tabuleiroJog_1, jogo.jogadasJog_2[n], posicaoAnterior,n);
        posicaoAnterior=ObtemPosAnterior(jogo.tabuleiroJog_1);
    }
    ImprimeNavioAtingidoEstatisticas(jogo.tabuleiroJog_1, pEstatisticas);
    posicaoAnterior=-8000;
    somax=0;
    somay=0;
    fprintf(pEstatisticas,"\n");
    //PARTE SOBRE O JOGADOR DOIS
    ImprimeJogador(jogo.jogador_2, pEstatisticas);
    ImprimeAcertoeErroTirosJogador(jogo.jogador_2, pEstatisticas, jogo.numJogadasJog_2);
     for(n=0;n<jogo.numJogadasJog_2;n++){
        somax=somax + ObtemPosicaoXDoTiroJogada(jogo.jogadasJog_2[n]);//COLUNA
        somay=somay + ObtemPosicaoYDoTiroJogada(jogo.jogadasJog_2[n]);//LINHA
    }
    mediax=1+somax/(float)jogo.numJogadasJog_2;//soma 1 pq obtem comecando da posicao 0, mas o tabuleiro eh pra comecar do 1
    mediay=1+somay/(float)jogo.numJogadasJog_2;//soma 1 pq obtem comecando da posicao 0, mas o tabuleiro eh pra comecar do 1
    fprintf(pEstatisticas,"Localizacao Media: (%.2f,%.2f)\n", mediay, mediax);
    desviopadrao=CalculaDesvioPadrao(jogo, mediax, mediay,2);
    fprintf(pEstatisticas,"Desvio Padrao da Localizacao: %.2f\n", desviopadrao);
    ImprimeAFraseNaviosDeJogador(jogo.jogador_2,pEstatisticas);
    jogo.tabuleiroJog_2=AjustaParametroPosNavio(jogo.tabuleiroJog_2);
    for(n=0;n<jogo.numJogadasJog_1;n++){
        jogo.tabuleiroJog_2=ObtemVetorDoNavioResultado(jogo.tabuleiroJog_2, jogo.jogadasJog_1[n]);
        jogo.tabuleiroJog_2=LimpaTabuleiroGuia(jogo.tabuleiroJog_2, jogo.jogadasJog_1[n]);
        jogo.tabuleiroJog_2=OrganizaVetorNavioEstatTabuleiro(jogo.tabuleiroJog_2, jogo.jogadasJog_1[n], posicaoAnterior, n);
        posicaoAnterior=ObtemPosAnterior(jogo.tabuleiroJog_2);
    }
    ImprimeNavioAtingidoEstatisticas(jogo.tabuleiroJog_2, pEstatisticas);
    fclose(pEstatisticas);
}

void ImprimeAcertoeErroTirosJogador(tJogador jogador, FILE *saida,int qtdDeJogadas){
    fprintf(saida,"Tiros Errados: %d\n", qtdDeJogadas-jogador.qtdTirosNavio);
    fprintf(saida,"Tiros Acertados: %d\n", jogador.qtdTirosNavio);
}

int ObtemPosicaoXDoTiroJogada(tJogada jogada){
    return (jogada.posicaoX-1);
}

int ObtemPosicaoYDoTiroJogada(tJogada jogada){
    return (jogada.posicaoY-'a');
}

float CalculaDesvioPadrao(tJogo jogo,float mediax,float mediay, int numeroJogador){
    float desviopadrao=0, somax=0, somay=0, divisao=0,  subtrx=0, subtry=0;
    int n=0;
    if(numeroJogador==1){
        for(n=0;n<jogo.numJogadasJog_1;n++){
            subtrx= 1 + ObtemPosicaoXDoTiroJogada(jogo.jogadasJog_1[n]) - mediax; 
            subtry=1 + ObtemPosicaoYDoTiroJogada(jogo.jogadasJog_1[n]) - mediay;
            somax=somax + pow(subtrx,2);//COLUNA
            somay=somay + pow(subtry,2);//LINHA
        }
        divisao=(somax+somay)/(float)jogo.numJogadasJog_1;
        desviopadrao=sqrt(divisao);
    }

    if(numeroJogador==2){
        for(n=0;n<jogo.numJogadasJog_2;n++){
            subtrx= 1 + ObtemPosicaoXDoTiroJogada(jogo.jogadasJog_2[n]) - mediax; 
            subtry=1 + ObtemPosicaoYDoTiroJogada(jogo.jogadasJog_2[n]) - mediay;
            somax=somax + pow( subtrx,2);//COLUNA
            somay=somay + pow( subtry,2);//LINHA
        }
        divisao=(somax+somay)/(float)jogo.numJogadasJog_2;
        desviopadrao=sqrt(divisao);
    }
    return desviopadrao;
}

tTabuleiro OrganizaVetorNavioEstatTabuleiro(tTabuleiro tabuleiro, tJogada jogada, int posAnterior, int nJogadaAtual){
    if(jogada.agua==1){
        return tabuleiro;
    }
    else if(tabuleiro.posVetorDoNavio!= posAnterior){
        tabuleiro=AdicionaAoVetorNavioEstatisticas( tabuleiro, nJogadaAtual);
        return tabuleiro;
    }
}

void ImprimeNavioAtingidoEstatisticas(tTabuleiro tabuleiro,FILE *saida){
    int n=0;
    OrdenaCrescenteNavios(tabuleiro.navioEstatisticas, tabuleiro.qtdNaviosEstatisticas);
    for(n=0;n<tabuleiro.qtdNaviosEstatisticas;n++){
        ImprimeNavioEst(tabuleiro.navioEstatisticas[n], saida);
    }
}

int ObtemPosAnterior(tTabuleiro tabuleiro){
    return tabuleiro.posVetorDoNavio;
}

int VerificaSeEhTiro(tJogada jogada){
    if(jogada.agua==1){
        return 0;
    }
    else return 1;
}

tTabuleiro LimpaTabuleiroGuia(tTabuleiro tabuleiro, tJogada jogada){
    int x, y, i=0,j=0, posVetor=0, cont=1;
    char caract;
    x=jogada.posicaoX - 1;
    y=jogada.posicaoY - 'a';
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(j==x && i==y){
                if(tabuleiro.tabuleiroAtingido[i][j]=='X' && cont==1){
                    caract=tabuleiro.tabuleiroGuia[i][j];
                    break;
                }
            }
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(tabuleiro.tabuleiroGuia[i][j]==caract){
                tabuleiro.tabuleiroGuia[i][j]='-';
                tabuleiro.tabuleiroAtingido[i][j]='.';
            }
        }
    }
    return tabuleiro;
}

void ImprimeAFraseNaviosDeJogador(tJogador jogador, FILE *saida){
    fprintf(saida,"Navios de %s:\n",jogador.nome);
}

tTabuleiro AdicionaAoVetorNavioEstatisticas(tTabuleiro tabuleiro, int njogada){
    tabuleiro.navioEstatisticas[tabuleiro.qtdNaviosEstatisticas]=tabuleiro.navio[tabuleiro.posVetorDoNavio];
    tabuleiro.navioEstatisticas[tabuleiro.qtdNaviosEstatisticas]=AjustaNumJogadaNavio
    (tabuleiro.navioEstatisticas[tabuleiro.qtdNaviosEstatisticas], njogada);
    tabuleiro.qtdNaviosEstatisticas++;
    return tabuleiro;
}

tNavios AjustaNumJogadaNavio(tNavios navio, int nJogada){
    navio.nJogada=nJogada+1;
    return navio;
}

void ImprimeNavioEst(tNavios navio, FILE *saida){
    fprintf(saida, "%02d - %s - ID %02d\n", navio.nJogada ,navio.nome, navio.identificacao);
}

void OrdenaCrescenteNavios(tNavios vet[], int qtd)
{
    int i = 0, n = 0, a = 0, cont = 0;
    tNavios auxiliar;
    for (a = 0; a < qtd; a++)
    {
        n = 0;
        auxiliar = vet[a];
        i = a + 1;
        while (i < qtd)
        {
            n = 0;
            while (vet[i].nome[n] != '\0')
            {
                if (vet[i].nome[n] < vet[a].nome[n])
                {
                    vet[a] = vet[i];
                    vet[i] = auxiliar;
                    auxiliar = vet[a];
                    cont = 2;
                    break;
                }
                else if (vet[i].nome[n] == vet[a].nome[n])
                {
                    n++;
                }
                else
                {
                    cont = 3;
                    break;
                }
            }
            if (cont == 3)
            {
                i++;
                continue;
            }
            if (cont == 2)
            {
                cont = 1;
                i++;
                continue;
            }
            n = 0;
            if(!strcmp(vet[i].nome,vet[a].nome)){
                if(vet[i].nJogada<vet[a].nJogada){
                    vet[a] = vet[i];
                    vet[i] = auxiliar;
                    auxiliar = vet[a];
                }
            }
            i++;
        }
        cont = 0;
    }
}

tTabuleiro AjustaParametroPosNavio(tTabuleiro tabuleiro){
    tabuleiro.posVetorDoNavio=-1;
    return tabuleiro;
}