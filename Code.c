#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#define T 3
#define t 21
void jogo(char matriz[][T],char player1[], char player2[], int z);//PRINT DO JOGO +JOGADAS DE CADA JOGADOR
char ganhou(char matriz[][T],char y);//VERIFICA SE ALGUÉM GANHOU APOS A JOGADA
void verifica(char matriz[][T], int *l, int *c);//VERIFICA SE O LOCAL ESCOLHIDO JA ESTA PREENCHIDO
void jogo1(char matriz[][T],char player1[t], int z, int comp);//PLAYER VS CPU MODO FACIL
void maquina(char matriz[][T], char letra);//CPU NIVEL FACIL
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
        case'1'://INICIO CASO UM
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
                    jogo(jVelha,nome1,nome2,z);
                }
                else{
                    printf("%s COMECA!!\n",nome2);
                    Sleep(1500);
                    system("cls");
                    jogo(jVelha,nome2,nome1,z);
                }
            }//FIM 2 JOGADORES
            else{//INICIO UM JOGADOR
				printf("Dificuldade\n1-Facil\n2-Dificil\n");
				scanf("%d",&z);
				while(z!=1&&z!=2){
					printf("OPCAO INVALIDA!\nSelecione uma opcao valida:\n1-Facil\n2-Dificil\nDigite sua opcao: ");fflush(stdin);
					scanf("%d",&z);fflush(stdin);
					system("cls");
				}
				if(z==1){//INICIO UM JOGADOR - FACIL
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
						jogo1(jVelha,nome1, z, comp);
					}
					else{
						printf("%s comeca\n",nome2);
						Sleep(1500);
						jogo1(jVelha,nome1, z, comp=1);
					}
				}
				else{//INICIO UM JOGADOR - DIFICIL
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
						jogo2(jVelha,nome1, z, comp);
					}
					else{
						printf("%s comeca\n",nome2);
						Sleep(1500);
						jogo2(jVelha,nome1, z, comp=1);
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
void jogo1(char matriz[][T],char player1[t], int z, int comp){
	int i, j, l, c, k, ganha;
	char letra;
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
		if(comp==1){
			comp=0;
			letra='O';
			printf("eh a vez do computador jogar.\n");
			Sleep(1000);
			printf("*pensando...*\n");
			Sleep(1500);
			printf("...\n");
			Sleep(1500);
			printf("  ...\n");
			Sleep(1500);
			maquina(matriz, letra);
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
            scanf("%d",&l);
            printf("Informe a coluna: \n");
            scanf("%d",&c);
            while(l>T-1||c>T-1||l<0||c<0){
                printf("Opcao invalida, escolha o local da jogada entre 0<=linha<=2  e  0<=coluna<=2\n");
                printf("\n%s eh sua vez de jogar.\n",player1);
                printf("Informe a linha: \n");
                scanf("%d",&l);
                printf("Informe a coluna: \n");
                scanf("%d",&c);
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
void jogo2(char matriz[][T],char player1[t], int z, int comp){
	//Tentar fazer no jogo1 passando mais uma variavel como condição para o jogo mandar para os dois niveis
}
void maquina(char matriz[][T], char letra){
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
