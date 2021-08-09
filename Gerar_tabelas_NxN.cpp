#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N1 2
#define N2 3
#define LINHAS 32 //para 2^(N1+N2) // 16 // 64 // 256 // 1024
#define COLUNAS 5

void DecimalParaBinario(int bin[COLUNAS], int dec, int tam) {
    int j=0, i;
	int temp[tam];
	while( dec != 0){
		temp[j++] = dec%2;
		dec/=2;
	}
	for (; j < tam ; j++ )
        temp[j] = 0;
	for ( i = 0 ; i < tam ; i++ )
		bin[i] = temp[tam-i-1];
}

void PreencheTabelaVerdade(int AB[LINHAS][COLUNAS]){ 
    int i, valor = 0;
    for ( i = 0 ; i < LINHAS ; i++ )
        DecimalParaBinario(AB[i],valor++,COLUNAS);
}

void ImprimeVetor(int VetSolDec[LINHAS], int tam){
	int i;
	
	for (i = 0; i < tam; i++){
		printf("%d \n",VetSolDec[i]);
	}
}

void PreencheVetorSolucaoDecimal(int VetSolDec[LINHAS]){ 
	int i, j;
	
	for (i = 0; i < (LINHAS/pow(2, N1)); i++){
		for (j = 0; j < (LINHAS/pow(2, N1)); j++){
			VetSolDec[i*(LINHAS/(int)pow(2,N1))+j] = i * j;
		}
	}
	
}

void PreencheTabelaSolucao(int S[LINHAS][COLUNAS], int VetSolDec[LINHAS]){ 
	int i = 0, j = 0, cont = 0;
	
    for ( i = 0 ; i < LINHAS ; i++ )
		DecimalParaBinario(S[i],VetSolDec[i],COLUNAS);
	
}

void ImprimeMatriz(int AB[LINHAS][COLUNAS]){
    int i, j;
    printf("\n\n");
    for ( i = 0 ; i < LINHAS ; i++ ){
        for ( j = 0 ; j < COLUNAS ; j++ ){
            printf("%d ",AB[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void ImprimeABS(int AB[LINHAS][COLUNAS], int S[LINHAS][COLUNAS]){
    int i, j, num = 0;
    printf("\n\n");
    
    for ( j = 0 ; j < N1 ; j++ ){ // Apenas um cabecalho
    	printf("A ");
	}
    for( j = 0 ; j < N2-1 ; j++ ){
    	printf("B ");
	}
    for( j = 0 ; j < 1 ; j++ ){
    	printf("B |");
	}	
    for( j = 0 ; j < COLUNAS ; j++ ){
    	printf("S%d |", num++);
	}	
    printf("\n");
    for( j = 0 ; j < COLUNAS*2 ; j++ ){
    	if (j == COLUNAS*2-1){
			printf("---|");
		}else{
			printf("---");
		}
	}
	printf("\n");
    
	for ( i = 0 ; i < LINHAS ; i++ ){
        for ( j = 0 ; j < COLUNAS ; j++ ){
			if (j < COLUNAS){
            	if (j == COLUNAS-1){
            		printf("%d | ",AB[i][j]);
				}else{
					printf("%d ",AB[i][j]);
				}
			}
        }
        for( j = 0 ; j < COLUNAS ; j++ ){
			if (j < COLUNAS){
            	printf("%d | ",S[i][j]);
			}
        }
        printf("\n");
    }
    printf("\n\n");
}

void ContaUnsEZeros (int S[LINHAS][COLUNAS]){
	int i, s;
	int Zeros = 0, Uns = 0;
	
	for (s = 0; s < COLUNAS; s++){
		for (i = 0; i < LINHAS; i++){
			if (S[i][s] == 0){
				Zeros++;
			}else{
				Uns++;
			}
		}		
		printf("\nPara S%d : \n", s);
		printf("Uns : %d\n", Uns);
		printf("Zeros : %d\n", Zeros);
		Uns = 0;
		Zeros = 0;
	}
}

int main(){
	
	int AB[LINHAS][COLUNAS];
	int S[LINHAS][COLUNAS];
	int VetSolDec[LINHAS];
	PreencheTabelaVerdade(AB);
	PreencheVetorSolucaoDecimal(VetSolDec);
	PreencheTabelaSolucao(S, VetSolDec);
//	ImprimeMatriz(AB);
//	ImprimeVetor(VetSolDec, LINHAS);
//	ImprimeMatriz(S);
	ImprimeABS(AB, S);
	ContaUnsEZeros(S);
	
}
