#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int algarismoRomanoParaDecimal(char algarismoRomano){
	switch(algarismoRomano){
		case 'I':
			return 1;
			break;
		case 'V':
			return 5;
			break;
		case 'X':
			return 10;
			break;
		case 'L':
			return 50;
			break;
		case 'C':
			return 100;
			break;
		case 'D':
			return 500;
			break;
		case 'M':
			return 1000;
			break;
		default:
			return 0;
	}
}

int romanoParaDecimal(char numeroRomano[]){
	int i;
	int qtdLetras = sizeof(numeroRomano)/sizeof(numeroRomano[0]);
	int numeroDecimal = 0;
	for(i=0;i<qtdLetras;i++){
		if(algarismoRomanoParaDecimal(numeroRomano[i+1]) > algarismoRomanoParaDecimal(numeroRomano[i])){
			numeroDecimal -= algarismoRomanoParaDecimal(numeroRomano[i]);
		}else{
			numeroDecimal += algarismoRomanoParaDecimal(numeroRomano[i]);
		}
	}
	return numeroDecimal;
}

int *decimalParaBinario(int qtdDigitos,int numeroDecimal){
	
	int i;

	int *numeroBinario = (int*) malloc(qtdDigitos * sizeof(int)); //alocação dinâmica de memória
	int binarioTemp[qtdDigitos]; //número binário ao contrário
	
	int temp = numeroDecimal;
	for(i=0;i<qtdDigitos;i++){
		binarioTemp[i] = temp % 2;
		temp /= 2;
	}
	
	int j = qtdDigitos;
	for(i=0;i<qtdDigitos;i++){
		j--;
		numeroBinario[i] = binarioTemp[j];
	}
	
	return numeroBinario;
}

char *binarioParaHexadecimal(int digitosBinario,int *numeroBinario){
	
	int i;
	
	int n;
	if(digitosBinario % 4 == 0){
		n = digitosBinario/4;	
	}else{
		n = (digitosBinario/4)+1;
	}
	
	char *numeroHexadecimal = (char*) malloc(n * sizeof(char)); //alocação dinâmica de memória
	
	if(digitosBinario % 4 == 0){
		int k = 0;
		for(i=0;i<n;i++){
			int temp = 0;
			int pos = 3;
			printf("\nbin para decimal: ");
			while(pos>=0){
				printf("(%d x 2^%d) ",numeroBinario[k],pos);
				temp += numeroBinario[k] * pow(2,pos);
				pos--;
				k++;
			}
			printf("\nresultado = %d",temp);
			switch(temp){
				case 0:
					numeroHexadecimal[i] = '0';
					break;
				case 1:
					numeroHexadecimal[i] = '1';
					break;
				case 2:
					numeroHexadecimal[i] = '2';
					break;
				case 3:
					numeroHexadecimal[i] = '3';
					break;
				case 4:
					numeroHexadecimal[i] = '4';
					break;
				case 5:
					numeroHexadecimal[i] = '5';
					break;
				case 6:
					numeroHexadecimal[i] = '6';
					break;
				case 7:
					numeroHexadecimal[i] = '7';
					break;
				case 8:
					numeroHexadecimal[i] = '8';
					break;
				case 10:
					numeroHexadecimal[i] = 'a';
					break;
				case 11:
					numeroHexadecimal[i] = 'b';
					break;
				case 12:
					numeroHexadecimal[i] = 'c';
					break;
				case 13:
					numeroHexadecimal[i] = 'd';
					break;
				case 14:
					numeroHexadecimal[i] = 'e';
					break;
				case 15:
					numeroHexadecimal[i] = 'f';
				}
		}
	}
	
	printf("\nhexadecimal: ");
	for(i=0;i<n;i++){
		printf("%c",numeroHexadecimal[i]);
	}
	printf("\n");
	
	return numeroHexadecimal;
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i;
	
	char numeroRomano[255];
	scanf("%[^\n]",numeroRomano);
	
	int numeroDecimal = romanoParaDecimal(numeroRomano);
	
	//define a quantidade de algarismos em binário
	int aux = 2;
	int qtdDigitos = 1;
	while(aux<=numeroDecimal){
		aux *= 2;
		qtdDigitos += 1;
	}
	int *numeroBinario = decimalParaBinario(qtdDigitos,numeroDecimal);
	
	int *numeroHexadecimal = binarioParaHexadecimal(qtdDigitos,numeroBinario);
	
	//EXIBE OS RESULTADOS
	printf("M na base 2: ");
	for(i=0;i<qtdDigitos;i++){
		printf("%d",numeroBinario[i]);
	}
	printf("\n");
	printf("M na base 10: %d",numeroDecimal);
	
	return 0;
}
