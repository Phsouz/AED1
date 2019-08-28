#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *v, int tam);
int *cria_vetor_pvalor(int tam, int valor);
void cria_vetor_preferencia(int tam, int valor, int **p);
int maior_elem(int *p, int tam);
int *intercala_vetor_pvalor(int *v1, int tam1, int *v2, int tam2);
void intercala_vetor_preferencia(int *v1, int tam1, int *v2, int tam2, int *v3);

int main() {

	//Exercicio 1
	int a1[4] = { 0,1,2,3 }, a2[] = { -2,-1,0,1,2 }, a3[5] = {1,2, 4};
	imprime_vetor(a1, 4);
	imprime_vetor(a2, 5);
	imprime_vetor(a3, 5);

	//Exercicio 2
	int *p1, *p2;
	p1 = cria_vetor_pvalor(4, 8);
	imprime_vetor(p1, 4);

	p1 = cria_vetor_pvalor(3, -1);
	imprime_vetor(p1, 3);

	p1 = cria_vetor_pvalor(5, 8);
	imprime_vetor(p1, 5);

	cria_vetor_preferencia(4, 0, &p2);
	imprime_vetor(p2, 4);

	//Exercicio 3
	int a[4] = { 1,2,3,4 }, b[4] = { 4,3,2,1 }, c[4] = { 3,9,5,10 }, d[4] = {1, -4, 53, 0};
	printf("%d\n", maior_elem(a, 4));
	printf("%d\n", maior_elem(b, 4));
	printf("%d\n", maior_elem(c, 4));
	printf("%d\n", maior_elem(d, 4));

	//Exercicio 4
	int v1[3] = { 2,4,6 }, v2[4] = { 3,5,7,9 }, v3[7], *v4;
	
	v4 = intercala_vetor_pvalor(v1, 3, v2, 4);
	imprime_vetor(v4, 7);

	intercala_vetor_preferencia(v1, 3, v2, 4, &v3);
	imprime_vetor(v3, 7);

	system("Pause");
}

void imprime_vetor(int *v, int tam) {
	int i;
	printf("[");
	for (i = 0; i < tam; i++) {
		if (i < tam - 1) {
			printf("%d, ", v[i]);
		}
		else {
			printf("%d", v[i]);
		}
	}
	printf("]\n");
}

int *cria_vetor_pvalor(int tam, int valor) {
	int i;
	int *p = (int*)malloc(tam * sizeof(int));

	for (i = 0; i < tam; i++) {
		p[i] = valor;
	}

	return p;
}

void cria_vetor_preferencia(int tam, int valor, int **p) {
	int i;
	*p = (int*)malloc(tam * sizeof(int));

	for (i = 0; i < tam; i++) {
		(*p)[i] = valor;
	}
}

int maior_elem(int *p, int tam) {
	int i, j, indice=0;
	for (i = 0; i < tam; i++) {
		for (j = 0; j < tam; j++) {
			if (p[i] > p[j]) {
				indice = i;
			}
			else {
				j++;
			}
		}
	}
	return indice;
}

int *intercala_vetor_pvalor(int *v1, int tam1, int *v2, int tam2) {
	int i=0, j=0, k=0;
	int *p = (int*)malloc((tam1 + tam2) * sizeof(int));

	while (j < tam1 && k < tam2) {
		if (v1[j] < v2[k]) {
			p[i++] = v1[j++];
		}
		else {
			p[i++] = v2[k++];
		}
	}

	while (j<tam1){
		p[i++] = v1[j++];
	}
	while (k < tam2) {
		p[i++] = v2[k++];
	}

	return p;
}

void intercala_vetor_preferencia(int *v1, int tam1, int *v2, int tam2, int *v3) {
	int i = 0, j = 0, k = 0;
	
	while (j < tam1 && k < tam2) {
		if (v1[j] < v2[k]) {
			v3[i++] = v1[j++];
		}
		else {
			v3[i++] = v2[k++];
		}
	}

	while (j < tam1) {
		v3[i++] = v1[j++];
	}
	while (k < tam2) {
		v3[i++] = v2[k++];
	}
}


