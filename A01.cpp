#include <stdio.h>

int potencia(int base, int exp);
void inverte(int num, int dig);
char conceito(float nota);
void data(int dia, int mes, int ano);
int calculaCedulas(int valor, int *vetor);
void imprimeQtdCedulas(int valor, int *cedulas);

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

	// Exercicio 5
    int valor;
    int cedulas[6];
	valor = 11;
    if (calculaCedulas(valor, cedulas))
    {
        imprimeQtdCedulas(valor, cedulas);
    }
    else
    {
        printf("Valor: %d \nNao eh possivel retirar esse valor\n", valor);
    }
    valor = 534;
    if (calculaCedulas(valor, cedulas))
    {
        imprimeQtdCedulas(valor, cedulas);
    }
    else
    {
        printf("Valor: %d \n Nao eh possivel retirar esse valor\n", valor);
    }

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

int calculaCedulas(int valor, int *vetor){
    if (valor % 10 == 1)
        return 0;
    if (valor % 10 == 3)
        return 0;

    int resto = valor;

    vetor[0] = resto / 100;
    resto = resto % 100;
    vetor[1] = resto / 50;
    resto = resto % 50;
    vetor[2] = resto / 20;
    resto = resto % 20;
    vetor[3] = resto / 10;
    resto = resto % 10;
    vetor[4] = 0;
    if (resto % 2 == 1)
    {
        vetor[4] = resto / 5;
        resto = resto % 5;
    }
    vetor[5] = resto / 2;

    return 1;
}

void imprimeQtdCedulas(int valor, int *cedulas){
    printf("\nValor: %d\n", valor);
    printf("Cedulas: \n");
    printf("R$ 100,00: %d \n", cedulas[0]);
    printf("R$  50,00: %d \n", cedulas[1]);
    printf("R$  20,00: %d \n", cedulas[2]);
    printf("R$  10,00: %d \n", cedulas[3]);
    printf("R$   5,00: %d \n", cedulas[4]);
    printf("R$   2,00: %d \n", cedulas[5]);
}