#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#define T 3
#define t 21
void jogo(char matriz[][T],char player1[], char player2[], int z);//Print do jogo + jogadas de cada jogador
char ganhou(char matriz[][T],char y);//Verifica se alguem ganhou
void verifica(char matriz[][T], int *l, int *c);
int main () {
    int z, i, j;
    char jVelha[T][T]={0}, nome1[t], nome2[t]={'c','o','m','p','u','t','a','d','o','r'}, matriz[T][T], n1='X', op;
    srand(time(NULL));
    do{
 
        printf("Bem vindo ao JOGO DA VELHA!\n\n1-Jogar\n2-Sair\n");fflush(stdin);
        op=getchar();fflush(stdin);
        system("cls");
        while(op!='1'&&op!='2'){
            printf("OPCAO INVALIDA!\nSelecione uma opcao valida:\n1-Jogar\n2-Sair\n");fflush(stdin);
            op=getchar();fflush(stdin);
            system("cls");
        }
        switch(op){
        case'1':
            for(i=0;i<T;i++){
                for(j=0;j<T;j++){
                    jVelha[i][j]=' ';
                }
            }
            printf("1-Dois jogadores\n2-Um jogador\n\nDigite sua opcao:");
            scanf("%d",&z);fflush(stdin);
            system("cls");
            while(z!=1&&z!=2){
                printf("OPCAO INVALIDA!\nSelecione uma opcao valida:\n1-Dois jogadores\n2-Um jogador\nDigite sua opcao:");fflush(stdin);
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
                    jogo(jVelha,nome1,nome2,z);
                }
                else{
                    printf("%s COMECA!!\n",nome2);
                    Sleep(1500);
                    system("cls");
                    jogo(jVelha,nome2,nome1,z);
                }
            }
            else{
                printf("Digite o seu nome\n");fflush(stdin);
                gets(nome1);
                system("cls");
                printf("%s - 'X'\n",nome1);
                printf("%s - 'O'\n",nome2);
                printf("Sorteando quem vai comecar....\n");
                system("pause");
                system("cls");
                z=rand()%2;
                if(z==0){
                    printf("%s comeca\n",nome1);
                    jogo(jVelha,nome1,nome2,z);
                }
                else{
                    printf("%s comeca\n",nome2);
                    jogo(jVelha,nome2,nome1,z);
                }
            }
            break;
        case'2':
            break;
        default:printf("Opcao invalida\n");
        }
    }while(op!='2');
    system("pause");
    return 0;
    }
void jogo(char matriz[][T],char player1[t], char player2[t], int z){
    int i, j, l, c, k, ganha;
    for(k=0;k<9;k++){
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
        if(k%2==0){
            printf("%s eh sua vez de jogar.\n",player1);
            printf("Informe a linha: \n");
            scanf("%d",&l);
            printf("Informe a coluna: \n");
            scanf("%d",&c);
            while(l>T-1||c>T-1||l<0||c<0){
                printf("Opcao invalida, escolha o local da jogada entre 0<=linha<=2  e  0<=coluna<=2\n");
                printf("\n%s jogue novamente.\n",player1);
                printf("Informe a linha: \n");
                scanf("%d",&l);
                printf("Informe a coluna: \n");
                scanf("%d",&c);
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
            scanf("%d",&l);
            printf("Informe a coluna: \n");
            scanf("%d",&c);
            while(l>T-1||c>T-1||l<0||c<0){
                printf("Opcao invalida, escolha o local da jogada entre 0<=linha<=2  e  0<=coluna<=2\n");
                printf("\n%s eh sua vez de jogar.\n",player2);
                printf("Informe a linha: \n");
                scanf("%d",&l);
                printf("Informe a coluna: \n");
                scanf("%d",&c);
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
char ganhou(char matriz[][T], char y){
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
void verifica(char matriz[][T], int *l, int *c){
    if(matriz[*l][*c]=='X'||matriz[*l][*c]=='O'){
        printf("Este local ja esta preenchido, por favor escolha outro local\n");
        printf("Informe a linha: \n");
        scanf("%d",&*l);
        printf("Informe a coluna: \n");
        scanf("%d",&*c);
    }
}
