#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

bool eLetra(char input){
	switch(input){
	    case 'A':
			return true;
			break;
	    case 'B':
			return true;
			break;
	    case 'C':
			return true;
			break;
	    case 'D':
			return true;
			break;
	    case 'E':
			return true;
			break;
	    case 'F':
			return true;
			break;
	    case 'G':
			return true;
			break;
	    case 'H':
			return true;
			break;
	    case 'I':
			return true;
			break;
	    case 'J':
			return true;
			break;
	    case 'K':
			return true;
			break;
	    case 'L':
			return true;
			break;
	    case 'M':
			return true;
			break;
	    case 'N':
			return true;
			break;
	    case 'O':
			return true;
			break;
	    case 'P':
			return true;
			break;
	    case 'Q':
			return true;
			break;
	    case 'R':
			return true;
			break;
	    case 'S':
			return true;
			break;
	    case 'T':
			return true;
			break;
	    case 'U':
			return true;
			break;
	    case 'V':
			return true;
			break;
	    case 'W':
			return true;
			break;
	    case 'X':
			return true;
			break;
	    case 'Y':
			return true;
			break;
	    case 'Z':
			return true;
			break;
		default:
			return false;
	}
}

bool validaDiaDaSemana(char diaDaSemana[]){
	if(strcmp(diaDaSemana,"SEGUNDA-FEIRA") == 0 || strcmp(diaDaSemana,"TERCA-FEIRA") == 0 || strcmp(diaDaSemana,"QUARTA-FEIRA") == 0 || strcmp(diaDaSemana,"QUINTA-FEIRA") == 0 || strcmp(diaDaSemana,"SEXTA-FEIRA") == 0 || strcmp(diaDaSemana,"SABADO") == 0 || strcmp(diaDaSemana,"DOMINGO") == 0){
		return true;
	}else{
		return false;
	}
}

bool validaPlacaFormatoAntigo(int tamanhoPlaca,char placa[]){
	//Formato antigo: LLL-NNNN
	int i;
	//verifica se a placa tem exatamente 8 dígitos
	if(tamanhoPlaca != 8){
		return false;
	}
	//verifica se os 3 primeiros dígitos são letras
	for(i=0;i<3;i++){
		if(eLetra(placa[i]) == false){
			return false;
		}
	}
	//verifica se o quarto dígito é o símbolo "-"
	if(placa[3] != '-'){
		return false;
	}
	// isdigit(int arg) tenta converter um valor para inteiro
	// retorna 0 se o valor não é numérico
	// retorna >0 se o valor é numérico
	for(i=4;i<8;i++){
		if(isdigit(placa[i]) == 0){
			return false;
		}
	}
	return true;
}

bool validaPlacaFormatoNovo(int tamanhoPlaca,char placa[]){
	//Formato novo: LLLNLNN
	int i;
	//verifica se a placa tem exatamente 7 dígitos
	if(tamanhoPlaca != 7){
		return false;
	}
	//verifica se os 3 primeiros dígitos são letras
	for(i=0;i<3;i++){
		if(eLetra(placa[i]) == false){
			return false;
		}
	}
	//verifica se o quarto dígito é número
	if(isdigit(placa[3]) == 0){
		return false;
	}
	//verifica se o quinto dígito é letra
	if(eLetra(placa[4]) == false){
		return false;
	}
	//verifica se os dois últimos dígitos são números
	for(i=5;i<7;i++){
		if(isdigit(placa[i]) == 0){
			return false;
		}
	}
	return true;
}

void podeTransitar(int tamanhoPlaca,char placa[],char diaDaSemana[]){
	char diaDaSemanaLower[20];
	//passa a string para lower case
	int i = 0;
	while(diaDaSemana[i] != '\0'){
		diaDaSemanaLower[i] = tolower(diaDaSemana[i]);
		i++;
	}
	diaDaSemanaLower[i] = '\0';
	
	//verifica se a placa pode circular
	if(strcmp(diaDaSemana,"SEGUNDA-FEIRA") == 0){
		if(placa[tamanhoPlaca-1] == '0' || placa[tamanhoPlaca-1] == '1'){
			printf("%s nao pode circular %s\n",placa,diaDaSemanaLower);
		}else{
			printf("%s pode circular %s\n",placa,diaDaSemanaLower);
		}
	}
	if(strcmp(diaDaSemana,"TERCA-FEIRA") == 0){
		if(placa[tamanhoPlaca-1] == '2' || placa[tamanhoPlaca-1] == '3'){
			printf("%s nao pode circular %s\n",placa,diaDaSemanaLower);
		}else{
			printf("%s pode circular %s\n",placa,diaDaSemanaLower);
		}
	}
	if(strcmp(diaDaSemana,"QUARTA-FEIRA") == 0){
		if(placa[tamanhoPlaca-1] == '4' || placa[tamanhoPlaca-1] == '5'){
			printf("%s nao pode circular %s\n",placa,diaDaSemanaLower);
		}else{
			printf("%s pode circular %s\n",placa,diaDaSemanaLower);
		}
	}
	if(strcmp(diaDaSemana,"QUINTA-FEIRA") == 0){
		if(placa[tamanhoPlaca-1] == '6' || placa[tamanhoPlaca-1] == '7'){
			printf("%s nao pode circular %s\n",placa,diaDaSemanaLower);
		}else{
			printf("%s pode circular %s\n",placa,diaDaSemanaLower);
		}
	}
	if(strcmp(diaDaSemana,"SEXTA-FEIRA") == 0){
		if(placa[tamanhoPlaca-1] == '8' || placa[tamanhoPlaca-1] == '9'){
			printf("%s nao pode circular %s\n",placa,diaDaSemanaLower);
		}else{
			printf("%s pode circular %s\n",placa,diaDaSemanaLower);
		}
	}
	if(strcmp(diaDaSemana,"SABADO") == 0 || strcmp(diaDaSemana,"DOMINGO") == 0){
		printf("Nao ha proibicao no fim de semana\n");
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	//VARIÁVEIS
	char placa[9]; //guarda 9 espaços, pois um espaço é reservado para o caracter '\0'
	char diaDaSemana[20];
	scanf("%s %s",placa,diaDaSemana);
	
	//calcula o tamanho da placa
	int tamanhoPlaca=0;
	int i = 0;
	while(placa[i] != '\0'){
		tamanhoPlaca++;
		i++;
	}
	
	//valida a placa
	if(validaPlacaFormatoAntigo(tamanhoPlaca,placa) || validaPlacaFormatoNovo(tamanhoPlaca,placa)){
		if(validaDiaDaSemana(diaDaSemana)){
			podeTransitar(tamanhoPlaca,placa,diaDaSemana);
		}
	}else{
		printf("Placa invalida\n");
	}
	
	//valida o dia da semana
	if(validaDiaDaSemana(diaDaSemana) == false){
		printf("Dia da semana invalido\n");
	}
	
	return 0;
}
