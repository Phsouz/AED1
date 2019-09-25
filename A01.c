#include <stdio.h>

int potencia(int base, int exp);
void inverte(int num, int dig);
char conceito(float nota);
void data(int dia, int mes, int ano);
void calcula_cedula(int valor);

int main() {

    //Exercicio 1
	int base = 2, exp = 2, res;
	res = potencia(base, exp);
	printf("%d elevado a %d: %d\n", base, exp, res);

	//Exercicio 2
    int num=128, dig=3;
	inverte(num, dig);
	
    //Exercicio 3
	float nota = 9.0;
	char con;
	con = conceito(nota);
	printf("Conceito: %c\n", con);

	//Exercicio 4
    int dia = 2, mes = 4, ano = 2019;
	data(dia, mes, ano);

    //Exercicio 5
    int valor;
    valor=11;
    calcula_cedula(valor);
    valor=534;
    calcula_cedula(valor);

}

int potencia(int base, int exp) {
	int i,pot=1;
	for (i = 0; i < exp; i++) {
		pot = pot*base;
	}
	return pot;
}

void inverte (int num, int dig){
	int i, numin;
    printf("O inverso de %d é: ", num);
	for(i=0;i<dig;i++){
		numin=num%10;
		num=num/10;
		printf("%d", numin);
	}
    printf("\n");
}

char conceito(float nota) {
	if (nota >= 9.0) return 'A';
	else if (nota >= 7.0 && nota <= 9.0) return 'B';
	else if (nota >= 6.0 && nota <= 7.0) return 'C';
	else return 'I';
}

void data(int dia, int mes, int ano) {
	int i;
	char dias_sem[33][15] = { "", "Primeiro", "Dois", "Tr�s", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove",
						   "Vinte", "Vinte-um", "Vinte-dois", "Vinte-tr�s", "Vinte-quatro", "Vinte-cinco", "Vinte-seis", "Vinte-sete", "Vinte-oito", "Vinte-nove", "Trinta", "Trinta-um", "Trinta-dois" };

	char meses_ano[13][10] = { "", "Janeiro", "Fevereiro", "Mar�o", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };

    for (i = 1; i < 13; i++) {
		if (i==dia) {
			printf("%s de ", dias_sem[i]);
		}
	}

	for (i = 1; i < 33; i++) {
		if (i == mes) {
			printf("%s de %d\n", meses_ano[i], ano);
		}
	}
}

void calcula_cedula(int valor){
    int i, cedulas[]={100, 50, 20, 10, 5, 2}, num_cedulas[6], resto=valor;

    if(valor%2!=0){
        printf("Não foi possivel retirar o valor\n");
    }

    else{
    for(i=0;i<6;i++){
        num_cedulas[i]=resto/cedulas[i];
        resto=resto%cedulas[i];
        }

    printf("Quantidade de Cédulas:\n");
    for(i=0;i<6;i++){
        printf("R$ %d: %d\n",cedulas[i], num_cedulas[i]);
        }
    }
}