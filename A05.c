#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void imprime_vetor(int *v, int tam);
int *vetor_clone_valor(int *p, int tam);
void vetor_clone_referencia(int *p, int tam, int **copia);
int *vetor_aleatorio(int tam);
void vetor_incrementa(int *p, int tam);
void vetor_dobra(int *p, int tam);
int vetor_dobraTamanho(int **p, int tam);
char *string_clone(char *c);


int main(){
    //Exercicio 1
    int v[5]={2,4,6,8,10};
    int *copia1, *copia2;
    copia1=vetor_clone_valor(v, 5);
    imprime_vetor(copia1, 5);
    vetor_clone_referencia(v, 5, &copia2);
    imprime_vetor(copia2, 5);

    /*Exercicio 2
    int *v1=vetor_aleatorio(10);
    imprime_vetor(v1, 10);
    int *v2=vetor_aleatorio(100);
    imprime_vetor(v2,100);*/

    //Exercicio 3
    int v3[5]={10, 20, 30, 40, 50};
    vetor_incrementa(v3, 5);
   

    //Exercicio 4
    int v4[5]={10, 20, 30, 40, 50};
    vetor_dobra(v4, 5);

    //Exercio 5
    int *v5=(int*)calloc(3, sizeof(int));
    v5[0]=2;
    v5[1]=4;
    v5[2]=6;
    //int novoTamanho=vetor_dobraTamanho(&v5, 3);
    //printf("%d\n", novoTamanho);

    //Exercico 6
    char str[20]={"ABC"};
    char *copia=string_clone(str);
    printf("%sz\n", copia);

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

int *vetor_clone_valor(int *p, int tam){
    int i;
    int *copia=(int*)malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        copia[i]=p[i];
    }
    return copia;
}

void vetor_clone_referencia(int *p, int tam, int **copia){
    int i;
    *copia=(int*)malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        (*copia)[i]=p[i];
    }
}

int *vetor_aleatorio(int tam){
    int i;
    int *p=(int*)malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        scanf("%d", &p[i]);
    }
    return p;
}

void vetor_incrementa(int *p, int tam){
    int i;
    for(i=0;i<tam;i++){
        p[i]+=1;
    }
     imprime_vetor(p, tam);
}

void vetor_dobra(int *p, int tam){
    int i;
    for(i=0;i<tam;i++){
        p[i]=p[i]*2;
    }
     imprime_vetor(p, tam);
}

int vetor_dobraTamanho(int **p, int tam){
    int i;
    int *novo_vetor=(int*)calloc(tam*2, sizeof(int));
    
    for(i=0;i<tam;i++){
        novo_vetor[i]=(*p)[i];
    }

    free(p);
    *p=novo_vetor;

    return tam*2;
}

char *string_clone(char *c){
    int i=0;
    char *p=(char*)malloc(strlen(c)+1);

    while(c!='\0'){
        p[i]=c[i];
        i++;
    }
    return p;
}










