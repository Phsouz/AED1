#include <stdio.h>

float potencia_valor (float base, float expoente);
void potencia_referencia (float base, float expoente, float *res);

int inverte_pvalor(int);
void invete_preferencia(int num, int*p);

char conceito_pvalor(float nota);
void conceito_preferencia(float nota, char *con);


int main(){
    
    //Exercicio 1
    float res=0;
    printf("Passagem por valor:\n");
    printf("%.2f\n", potencia_valor(2,2));
    printf("%.2f\n", potencia_valor(2,1));
    printf("%.2f\n", potencia_valor(2,0));
    printf("%.2f\n", potencia_valor(2,-2));
    printf("%.2f\n\n", potencia_valor(-2,2));

    printf("Passagem por referência:\n");
    potencia_referencia(2,2, &res);
    printf("%.2f\n", res);
    potencia_referencia(2,1, &res);
    printf("%.2f\n", res);
    potencia_referencia(2,0, &res);
    printf("%.2f\n", res);
    potencia_referencia(2,-2, &res);
    printf("%.2f\n", res);
    potencia_referencia(-2,2, &res);
    printf("%.2f\n\n", res);

    //Exercicio 2
    int valor=0;
    printf("Passagem por valor:\n");
    printf("%d\n",inverte_pvalor(10));
    printf("%d\n",inverte_pvalor(152));
    printf("%d\n\n",inverte_pvalor(-2542));

    printf("Passagem por referência:\n");
    invete_preferencia(10, &valor);
    printf("%d\n", valor);
    invete_preferencia(152, &valor);
    printf("%d\n", valor);
    invete_preferencia(-2542, &valor);
    printf("%d\n\n", valor);



    //Exercicio 3
    char con=0;
    printf("Passagem por valor:\n");
    printf("%c\n", conceito_pvalor(9));
    printf("%c\n", conceito_pvalor(7));
    printf("%c\n", conceito_pvalor(6));
    printf("%c\n", conceito_pvalor(5.2));
    printf("%c\n\n", conceito_pvalor(-1));

    printf("Passagem por referência:\n");
    conceito_preferencia(9,&con);
    printf("%c\n", con);
    conceito_preferencia(7,&con);
    printf("%c\n", con);
    conceito_preferencia(6,&con);
    printf("%c\n", con);
    conceito_preferencia(5.2,&con);
    printf("%c\n", con);
    conceito_preferencia(-1,&con);
    printf("%c\n", con);

}

float potencia_valor (float base, float expoente){
    int i, multiplicador=(expoente>0 ? expoente : expoente*-1);
    float res=1;

    for(i=0;i<multiplicador;i++){
        res*=base;
    }

    if(expoente<=-1) return 1/res;
    return res;   
}

void potencia_referencia (float base, float expoente, float *res){
    int i, multiplicador=(expoente>0 ? expoente : expoente*-1);
    float total=1;

    for(i=0;i<multiplicador;i++){
        total*=base;
    }

    if(expoente<=-1) *res=1/total;
    else *res=total;
}

int inverte_pvalor(int num){
    int resto=0,inverso=0;
    int numero=(num>0)?num:num*-1;

    while(numero>0){
        resto=numero%10;
        inverso=(inverso*10)+resto;
        numero=numero/10;
        
    }
    if(num>0) return inverso;
    else return inverso*-1;
}

void invete_preferencia(int num, int*p){
    int resto=0,inverso=0;
    int numero=(num>0)?num:num*-1;

    while(numero>0){
        resto=numero%10;
        inverso=(inverso*10)+resto;
        numero=numero/10;
        
    }

    if (num>0) *p=inverso;
    else *p=inverso*-1;
}

char conceito_pvalor(float nota){
    if (nota>=9.0) return 'A';
    else if (nota>=7.0 && nota<9.0) return 'B';
    else if (nota>=6.0 && nota<7.0) return 'C';
    else if(nota>=0 && nota<6.0) return 'I';
    else return 'X';
}

void conceito_preferencia(float nota, char *con){
     if (nota>=9.0) *con='A';
    else if (nota>=7.0 && nota<9.0) *con='B';
    else if (nota>=6.0 && nota<7.0) *con= 'C';
    else if(nota>=0 && nota<6.0) *con= 'I';
    else *con='X';
}




