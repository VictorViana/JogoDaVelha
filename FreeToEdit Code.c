#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#define T 3
#define t 21
void DoisJogadores(char matriz[][T],char player1[], char player2[], int z);//PLAYER VS PLAYER ---------- OK
char ganhou(char matriz[][T],char y);//VERIFICA SE ALGUÉM GANHOU APOS A JOGADA ---------- OK
void verifica(char matriz[][T], int *l, int *c);//VERIFICA SE O LOCAL ESCOLHIDO JA ESTA PREENCHIDO ---------- OK
void Facil(char matriz[][T],char player1[t], int z, int comp);//PLAYER VS CPU//MODO FACIL ---------- OK
void maquinaAleatorio(char matriz[][T], char letra);//SORTEIA UM LOCAL ALEATORIO ---------- OK
void printJogo(char matriz[][T]);// PRINTA O JOGO NA TELA ---------- OK
void Dificil(char matriz[][T],char player1[t], int z, int comp);//NIVEL DIFICIL, NÃO FUNCIONANDO
void maquinaD(char matriz[][T], char g, int A);//NIVEL DIFICIL, NÃO FUNCIONANDO
void BuscaLinha(char matriz[][T],int A, char *g);//NIVEL DIFICIL, NÃO FUNCIONANDO
void BuscaColuna(char matriz[][T], int A, char *g);//NIVEL DIFICIL, NÃO FUNCIONANDO
void BuscaDiagonalP(char matriz[][T], int A, char *g);//NIVEL DIFICIL, NÃO FUNCIONANDO
void BuscaDiagonalS(char matriz[][T], int A, char *g);//NIVEL DIFICIL, NÃO FUNCIONANDO
int main () {// INICIO MAIN
    int z, i, j, comp=0;
    char jVelha[T][T]={0}, nome1[t], nome2[t]={'c','o','m','p','u','t','a','d','o','r'}, matriz[T][T], n1='X', op;
    srand(time(NULL));
    do{
 
        printf("Bem vindo ao JOGO DA VELHA!\n1-Jogar\n2-Sair\n");fflush(stdin);
        op=getchar();fflush(stdin);
        system("cls");
        while(op!='1'&&op!='2'){
            printf("OPCAO INVALIDA!\nSelecione uma opcao valida:\n1-Jogar\n2-Sair\n");fflush(stdin);
            op=getchar();fflush(stdin);
            system("cls");
        }
        switch(op){
        case'1'://INICIO CASO UM // ---------- OK
            for(i=0;i<T;i++){
                for(j=0;j<T;j++){
                    jVelha[i][j]=' ';
                }
            }
            printf("Digite sua opcao\n1-Dois jogadores\n2-Um jogador\n");
            scanf("%d",&z);fflush(stdin);
            system("cls");
            while(z!=1&&z!=2){
                printf("OPCAO INVALIDA!\nSelecione uma opcao valida:\n1-Dois jogadores\n2-Um jogador\nDigite sua opcao: ");fflush(stdin);
                scanf("%d",&z);fflush(stdin);
                system("cls");
            }
            if(z==1){
                system("cls");
                printf("Digite o nome do primeiro jogador(a)\n");fflush(stdin);
                gets(nome1);
                printf("Digite o nome do segundo jogador(a)\n");
                gets(nome2);
                system("cls");
                printf("%s - 'X'\n",nome1);
                printf("%s - 'O'\n",nome2);
                printf("Sorteando quem vai comecar....\n");
                Sleep(1500);
                system("cls");
                z=rand()%2;
                if(z==0){
                    printf("%s COMECA!!\n",nome1);
                    Sleep(1500);
                    system("cls");
                    DoisJogadores(jVelha,nome1,nome2,z);
                }
                else{
                    printf("%s COMECA!!\n",nome2);
                    Sleep(1500);
                    system("cls");
                    DoisJogadores(jVelha,nome2,nome1,z);
                }
            }
            else{//INICIO UM JOGADOR // ---------- OK
                printf("Dificuldade\n1-Facil\n2-Dificil\n");
                scanf("%d",&z);
                while(z!=1&&z!=2){
                    printf("OPCAO INVALIDA!\nSelecione uma opcao valida:\n1-Facil\n2-Dificil\nDigite sua opcao: ");fflush(stdin);
                    scanf("%d",&z);fflush(stdin);
                    system("cls");
                }
                if(z==1){//INICIO UM JOGADOR - FACIL // ---------- OK
                    printf("Digite o seu nome\n");fflush(stdin);
                    gets(nome1);
                    system("cls");
                    printf("%s - 'X'\n",nome1);
                    printf("%s - 'O'\n",nome2);
                    printf("Sorteando quem vai comecar....\n");
                    Sleep(1500);
                    system("cls");
                    z=rand()%2;
                    if(z==0){
                        printf("%s comeca\n",nome1);
                        Sleep(1500);
                        Facil(jVelha,nome1, z, comp);
                    }
                    else{
                        printf("%s comeca\n",nome2);
                        Sleep(1500);
                        Facil(jVelha,nome1, z, comp=1);
                    }
                }
                else{//INICIO UM JOGADOR - DIFICIL // NÃO FUNCIONANDO
                    printf("Digite o seu nome\n");fflush(stdin);
                    gets(nome1);
                    system("cls");
                    printf("%s - 'X'\n",nome1);
                    printf("%s - 'O'\n",nome2);
                    printf("Sorteando quem vai comecar....\n");
                    Sleep(1500);
                    system("cls");
                    z=rand()%2;
                    if(z==0){
                        printf("%s comeca\n",nome1);
                        Sleep(1500);
                        Dificil(jVelha,nome1, z, comp);
                    }
                    else{
                        printf("%s comeca\n",nome2);
                        Sleep(1500);
                        Dificil(jVelha,nome1, z, comp=1);
                    }
                }
            }
            break;//FIM CASO UM
        case'2'://SAIR
            break;
        default:printf("Opcao invalida\n");
        }
    }while(op!='2');//FIM DO
    system("pause");
    return 0;
    }//FIM MAIN
void DoisJogadores(char matriz[][T],char player1[t], char player2[t], int z){//FUNCIONANDO ---------- OK
    int  l, c, k, ganha;
    for(k=0;k<9;k++){
        printJogo(matriz);
        if(k%2==0){
            printf("%s eh sua vez de jogar.\n",player1);
            printf("Informe a linha: \n");
            scanf("%d",&l);fflush(stdin);
            printf("Informe a coluna: \n");
            scanf("%d",&c);fflush(stdin);
            while(l>T-1||c>T-1||l<0||c<0){
                printf("Opcao invalida, escolha o local da jogada entre 0<=linha<=2  e  0<=coluna<=2\n");
                printf("\n%s jogue novamente.\n",player1);
                printf("Informe a linha: \n");
                scanf("%d",&l);fflush(stdin);
                printf("Informe a coluna: \n");
                scanf("%d",&c);fflush(stdin);
            }
            verifica(matriz, &l, &c);
            system("cls");
            if(z==0)
                matriz[l][c]='X';
            else
                matriz[l][c]='O';
            ganha=ganhou(matriz,matriz[l][c]);
            if(ganha==1){
                printf("%s GANHOU!!!\n",player1);
                system("pause");
                system("cls");
                break;
            }
            if(ganha==2){
                printf("DEU VELHA!!\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else{
            printf("%s eh sua vez de jogar.\n",player2);
            printf("Informe a linha: \n");
            scanf("%d",&l);fflush(stdin);
            printf("Informe a coluna: \n");
            scanf("%d",&c);fflush(stdin);
            while(l>T-1||c>T-1||l<0||c<0){
                printf("Opcao invalida, escolha o local da jogada entre 0<=linha<=2  e  0<=coluna<=2\n");
                printf("\n%s eh sua vez de jogar.\n",player2);
                printf("Informe a linha: \n");
                scanf("%d",&l);fflush(stdin);
                printf("Informe a coluna: \n");
                scanf("%d",&c);fflush(stdin);
            }
            verifica(matriz, &l, &c);
            system("cls");
            if(z==0)
                matriz[l][c]='O';
            else
                matriz[l][c]='X';
            ganha=ganhou(matriz,matriz[l][c]);
            if(ganha==1){
                printf("%s GANHOU!!!\n",player2);
                system("pause");
                system("cls");
                break;
            }
            if(ganha==2){
                printf("DEU VELHA!!\n");
                system("pause");
                system("cls");
                break;
            }
        }
    }
}
void Facil(char matriz[][T],char player1[t], int z, int comp){//FUNCIONANDO ---------- OK
    int  l, c, k, ganha;
    char letra;
    for(k=0;k<9;k++){
        printJogo(matriz);
        if(comp==1){
            comp=0;
            letra='O';
            printf("eh a vez do computador jogar.\n");
            Sleep(1000);
            printf("*pensando...*\n");
            Sleep(1500);
            printf("\t\t...\n");
            Sleep(1500);
            printf("\t\t  ...\n");
            Sleep(1500);
            maquinaAleatorio(matriz, letra);
            ganha=ganhou(matriz, letra);
            if(ganha==1){
                printf("O COMPUTADOR GANHOU!!!\n");
                system("pause");
                system("cls");
                break;
            }
            if(ganha==2){
                printf("DEU VELHA!!\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else{
            comp=1;
            printf("%s eh sua vez de jogar.\n",player1);
            printf("Informe a linha: \n");
            scanf("%d",&l);fflush(stdin);
            printf("Informe a coluna: \n");
            scanf("%d",&c);fflush(stdin);
            while(l>T-1||c>T-1||l<0||c<0){
                printf("Opcao invalida, escolha o local da jogada entre 0<=linha<=2  e  0<=coluna<=2\n");
                printf("\n%s eh sua vez de jogar.\n",player1);
                printf("Informe a linha: \n");
                scanf("%d",&l);fflush(stdin);
                printf("Informe a coluna: \n");
                scanf("%d",&c);fflush(stdin);
            }
            verifica(matriz, &l, &c);
            system("cls");
            matriz[l][c]='X';
            ganha=ganhou(matriz,matriz[l][c]);
            if(ganha==1){
                printf("%s GANHOU!!!\n",player1);
                system("pause");
                system("cls");
                break;
            }
            if(ganha==2){
                printf("DEU VELHA!!\n");
                system("pause");
                system("cls");
                break;
            }
        }
    }
}
void Dificil(char matriz[][T],char player1[t], int z, int comp){//NIVEL DIFICIL, NÃO FUNCIONANDO
    char g='0';
    int l, c, k, ganha, A=2;
    for(k=0;k<9;k++){
        printJogo(matriz);
        if(comp==1){
            comp=0;
            printf("eh a vez do computador jogar.\n");
            Sleep(1000);
            printf("*pensando...*\n");
            Sleep(1500);
            printf("...\n");
            Sleep(1500);
            printf("  ...\n");
            Sleep(1500);
            maquinaD(matriz, g, A);
            if(g='0')
                maquinaD(matriz, g, A=0);
            if(g=='0')
                maquinaAleatorio(matriz, g);
            ganha=ganhou(matriz, g);
            if(ganha==1){
                printf("O COMPUTADOR GANHOU!!!\n");
                system("pause");
                system("cls");
                break;
            }
            if(ganha==2){
                printf("DEU VELHA!!\n");
                system("pause");
                system("cls");
                break;
                }
        }
        else{
            comp=1;
            printf("%s eh sua vez de jogar.\n",player1);
            printf("Informe a linha: \n");
            scanf("%d",&l);fflush(stdin);
            printf("Informe a coluna: \n");
            scanf("%d",&c);fflush(stdin);
            while(l>T-1||c>T-1||l<0||c<0){
                printf("Opcao invalida, escolha o local da jogada entre 0<=linha<=2  e  0<=coluna<=2\n");
                printf("\n%s eh sua vez de jogar.\n",player1);
                printf("Informe a linha: \n");
                scanf("%d",&l);fflush(stdin);
                printf("Informe a coluna: \n");
                scanf("%d",&c);fflush(stdin);
            }
            verifica(matriz, &l, &c);
            system("cls");
            matriz[l][c]='X';
            ganha=ganhou(matriz,matriz[l][c]);
            if(ganha==1){
                printf("%s GANHOU!!!\n",player1);
                system("pause");
                system("cls");
                break;
            }
            if(ganha==2){
                printf("DEU VELHA!!\n");
              system("pause");
              system("cls");
              break;
            }
        }
    }
}
void maquinaAleatorio(char matriz[][T], char letra){//FUNCIONANDO ---------- OK
    int i, j, ganha=1;
    while (ganha == 1) {
        i = rand() % 3;
        j = rand() % 3;
        if (matriz[i][j] == ' ') {
            matriz[i][j] = letra;
            break;
        }
    }
    system("cls");
}
void maquinaD(char matriz[][T], char g, int A){//NIVEL DIFICIL, NÃO FUNCIONANDO
    if(A==2){
        BuscaLinha(matriz, A, &g);
        if(g='1')
            return;
        BuscaColuna(matriz, A, &g);
        if(g='1')
            return;
        BuscaDiagonalP(matriz, A, &g);
        if(g='1')
            return;
        BuscaDiagonalS(matriz, A, &g);
        if(g='1')
            return;
    }
    else{
        BuscaLinha(matriz, A, &g);
        if(g='1')
            return;
        BuscaColuna(matriz, A, &g);
        if(g='1')
            return;
        BuscaDiagonalP(matriz, A, &g);
        if(g='1')
            return;
        BuscaDiagonalS(matriz, A, &g);
        if(g='1')
            return;
    }
}
void BuscaLinha(char matriz[][T],int A, char *g){//NIVEL DIFICIL, NÃO FUNCIONANDO
    int  i, j, contO=2, contX=2;
    for(i=0;i<T;i++){
        for(j=0;j<T;j++){
            if(matriz[i][j]=='O')
                contO=contO-1;
            if(matriz[i][j]=='X')
                contX=contX-1;
            if(A==2){
                if(contO==0&&contX==2){
                    for(j=2;j>=0;j--){
                        if(matriz[i][j]==' '){
                            matriz[i][j]='O';
                            *g='1';
                            break;
                        }
                    }
                    break;
                }
            }
            else{
                if(contO==2&&contX==0){
                    for(j=2;j>=0;j--){
                        if(matriz[i][j]==' '){
                            matriz[i][j]='O';
                            *g='1';
                            break;
                        }
                    break;
                    }
                }
            }
        }
    }
}
void BuscaColuna(char matriz[][T], int A, char *g){//NIVEL DIFICIL, NÃO FUNCIONANDO
    int  i, j, contCO=2, contCX=2;
    for(i=0;i<T;i++){
        for(j=0;j<T;j++){
            if(matriz[j][i]=='O')
                contCO=contCO-1;
            if(matriz[j][i]=='X')
                contCX=contCX-1;
            if(A==2){
                if(contCO==0&&contCX==2){
                    for(j=2;j>=0;j--){
                        if(matriz[j][i]==' '){
                            matriz[j][i]='O';
                            *g='1';
                            break;
                        }
                    }
                    break;
                }
            }
            else{
                if(contCO==2&&contCX==0){
                    for(j=2;j>=0;j--){
                        if(matriz[j][i]==' '){
                            matriz[j][i]='O';
                            *g='1';
                            break;
                        }
                    break;
                    }
                }
            }
        }
    }
}
void BuscaDiagonalP(char matriz[][T], int A, char *g){//NIVEL DIFICIL, NÃO FUNCIONANDO
    int j, contDPO=2, contDPX=2;
    for(j=0;j<T;j++){
        if(matriz[j][j]=='O')
            contDPO=contDPO-1;
        if(matriz[j][j]=='X')
            contDPX=contDPX-1;
        if(A==2){
            if(contDPO==0&&contDPX==2){
                for(j=2;j>=0;j--){
                    if(matriz[j][j]==' '){
                        matriz[j][j]='O';
                        *g='1';
                        break;
                    }
                }
                break;
            }
        }
        else{
            if(contDPO==2&&contDPX==0){
                for(j=2;j>=0;j--){
                    if(matriz[j][j]==' '){
                        matriz[j][j]='O';
                        *g='1';
                        break;
                    }
                }
                break;
            }
        }
    }
}
void BuscaDiagonalS(char matriz[][T], int A, char *g){//NIVEL DIFICIL, NÃO FUNCIONANDO
    int  i, j, DS, contDSO=2, contDSX=2;
    if(matriz[0][2]=='O')
        contDSO=contDSO-1;
    else if(matriz[0][2]=='X')
        contDSX=contDSX-1;
    else if(matriz[1][1]=='X')
        contDSX=contDSX-1;
    else if(matriz[1][1]=='O')
        contDSO=contDSO-1;
    else if(matriz[2][0]=='X')
        contDSX=contDSX-1;
    else if(matriz[2][0]=='O')
        contDSO=contDSO-1;
    if(A==2){
        for(i=0;i<T;i++){
            for(j=0;j<T;j++){
                DS=i+j;
                if(DS==2){
                    if(contDSO==0&&contDSX==2){
                        if(matriz[i][j]==' '){
                            matriz[i][j]='O';
                            *g='1';
                            break;
                        }
                    }
                }
            }
        }
    }
    else{
        for(i=0;i<T;i++){
            for(j=0;j<T;j++){
                DS=i+j;
                if(contDSO==2&&contDSX==0){
                    if(matriz[i][j]==' '){
                        matriz[i][j]='O';
                        *g='1';
                        break;
                    }
                }
            }
        }
    }
}
char ganhou(char matriz[][T], char y){// FUNCIONANDO ---------- OK
    int i, j,contC=0, contL=0, contDP=0, DS, contDS=0, contVelha=0;
    for(i=0;i<T;i++){
        for(j=0;j<T;j++){
            DS=i+j;
            if(matriz[i][j]==y)
                contL=contL+1;
            if(matriz[j][i]==y)
                contC=contC+1;
            if(matriz[j][j]==y)
                contDP=contDP+1;
            if(DS==2)
                if(matriz[i][j]==y)
                    contDS=contDS+1;
        }
        if(contC==3||contL==3||contDP==3||contDS==3)
            return 1;
        contC=0;
        contL=0;
        contDP=0;
    }
    for(i=0;i<T;i++){
        for(j=0;j<T;j++){
            if(matriz[i][j]=='X'||matriz[i][j]=='O')
                contVelha=contVelha+1;
        }
    }
    if(contVelha==9)
        return 2;
    return 0;
}
void verifica(char matriz[][T], int *l, int *c){//FUNCIONANDO ---------- OK
    while(matriz[*l][*c]=='X'||matriz[*l][*c]=='O'){
        printf("Este local ja esta preenchido, por favor escolha outro local\n");
        printf("Informe a linha: \n");
        scanf("%d",&*l);fflush(stdin);
        printf("Informe a coluna: \n");
        scanf("%d",&*c);fflush(stdin);
    }
}
void printJogo(char matriz[][T]){//FUNCIONANDO ---------- OK
    int i,j;
    for(i=0;i<T;i++){
        for(j=0;j<T;j++){
            if(matriz[i][j]=='X'||matriz[i][j]=='O')
                printf("%c",matriz[i][j]);
            else
            if(i<T-1)
                printf("_");
            else
                printf(" ");
            if(j<T-1)
                printf("|");
        }
        printf("\n");
    }
}
