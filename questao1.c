#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char algarismoDecimalParaHexadecimal(int algarismoDecimal){
	switch(algarismoDecimal){
		case 0:
			return '0';
			break;
		case 1:
			return '1';
			break;
		case 2:
			return '2';
			break;
		case 3:
			return '3';
			break;
		case 4:
			return '4';
			break;
		case 5:
			return '5';
			break;
		case 6:
			return '6';
			break;
		case 7:
			return '7';
			break;
		case 8:
			return '8';
			break;
		case 10:
			return 'a';
			break;
		case 11:
			return 'b';
			break;
		case 12:
			return 'c';
			break;
		case 13:
			return 'd';
			break;
		case 14:
			return 'e';
			break;
		case 15:
			return 'f';
	}
}

int romanoParaDecimal(char numeroRomano[]){
	int i=0;
	int numeroDecimal = 0;
	while(numeroRomano[i] != '\0'){
		//arrays de char em C terminam com o caractere '\0'
		//obs.: não é possível determinar o tamanho do array usando sizeof!
		if(algarismoRomanoParaDecimal(numeroRomano[i+1]) > algarismoRomanoParaDecimal(numeroRomano[i])){
			numeroDecimal -= algarismoRomanoParaDecimal(numeroRomano[i]);
		}else{
			numeroDecimal += algarismoRomanoParaDecimal(numeroRomano[i]);
		}
		i++;
	}
	return numeroDecimal;
}

int *decimalParaBinario(int digitosBinario,int numeroDecimal){
	int i;
	int *numeroBinario = (int*) malloc(digitosBinario * sizeof(int)); //alocação dinâmica de memória
	int binarioTemp[digitosBinario]; //número binário ao contrário
	int temp = numeroDecimal;
	for(i=0;i<digitosBinario;i++){
		binarioTemp[i] = temp % 2; //guarda o resto da divisão (0 ou 1)
		temp /= 2;
	}
	int j = digitosBinario;
	for(i=0;i<digitosBinario;i++){
		j--;
		numeroBinario[i] = binarioTemp[j]; //coloca o número binário na ordem certa
	}
	return numeroBinario;
}

char *binarioParaHexadecimal(int digitosBinario,int *numeroBinario){
	int i;
	//calcula a qtd de algarismos em hexadecimal
	int digitosHexadecimal;
	if(digitosBinario % 4 == 0){
		digitosHexadecimal = digitosBinario/4;	
	}else{
		digitosHexadecimal = (digitosBinario/4)+1;
	}
	char *numeroHexadecimal = (char*) malloc(digitosHexadecimal * sizeof(char)); //alocação dinâmica de memória
	//converte binario para hexadecimal (bin->dec->hex)
	if(digitosBinario % 4 == 0){
		int k = 0;
		for(i=0;i<digitosHexadecimal;i++){
			int temp = 0;
			int pos = 3;
			while(pos>=0){
				temp += numeroBinario[k] * pow(2,pos);
				pos--;
				k++;
			}
			numeroHexadecimal[i] = algarismoDecimalParaHexadecimal(temp);
		}
	}else{
		int digitosRestantes = digitosBinario % 4; //guarda a quantidade de dígitos que não formam uma sequência de 4 algarismos binários
		int espacosVazios = 4-digitosRestantes; //guarda a quantidade de espaços à esquerda para preencher com ZERO
		int k = 0;
		int temp = 0;
		for(i=3;i>(3-espacosVazios);i--){
			temp += 0 * pow(2,i);
		}
		for(i=3-espacosVazios;i>=0;i--){
			temp += numeroBinario[k] * pow(2,i);
			k++;
		}
		numeroHexadecimal[0] = algarismoDecimalParaHexadecimal(temp);
		for(i=1;i<digitosHexadecimal;i++){
			temp = 0;
			int pos = 3;
			while(pos>=0){
				temp += numeroBinario[k] * pow(2,pos);
				pos--;
				k++;
			}
			numeroHexadecimal[i] = algarismoDecimalParaHexadecimal(temp);
		}
	}
	return numeroHexadecimal;
}

int main(){
	
	int i;
	char numeroRomano[13];
	scanf("%[^\n]",numeroRomano);
	
	
	//REALIZA OS CÁLCULOS
	int numeroDecimal = romanoParaDecimal(numeroRomano); //converte romano para decimal
	//calcula a quantidade de algarismos em binário
	int aux = 2;
	int digitosBinario = 1;
	while(aux<=numeroDecimal){
		aux *= 2;
		digitosBinario += 1;
	}
	int *numeroBinario = decimalParaBinario(digitosBinario,numeroDecimal); //converte decimal para binário
	char *numeroHexadecimal = binarioParaHexadecimal(digitosBinario,numeroBinario); //converte binário para hexadecimal
	
	
	//EXIBE OS RESULTADOS
	printf("%s na base 2: ",numeroRomano);
	for(i=0;i<digitosBinario;i++){
		printf("%d",numeroBinario[i]);
	}
	printf("\n");
	printf("%s na base 10: %d",numeroRomano,numeroDecimal);
	printf("\n");
	printf("%s na base 16: %s",numeroRomano,numeroHexadecimal);
	printf("\n");
	
	
	return 0;
}
