#include <stdio.h>
#include <locale.h>

typedef struct item{
        float valor;
        float kg;
        float ValorPorKilo;
}ITEM;

void ColocandoItens(ITEM PROD[], int tam){
    int i;
    system("cls");

    for (i=0; i<tam; i++){
        printf("\n\n\t\t\t ITEM %d \n\n\n", i+1);
        printf("\t Valor do Item: ");
        scanf("%f",&PROD[i].valor);
        printf("\n\n\t Peso do Item: ");
        scanf("%f",&PROD[i].kg);
        system("cls");
    }
}

void quicksort(ITEM A[] , int n){
    ordena(0,n-1,A);
}

void ordena(int esq, int dir, ITEM A[]){
    int i,j;
    particao(esq,dir,&i,&j,A);
    if(esq<j)
        ordena(esq,j,A);
    if(i<dir)
        ordena(i,dir,A);
}

void particao(int esq, int dir, int *i, int *j, ITEM A[]){
    float pivo;
    float tmp1, tmp2, tmp3;
    *i=esq;
    *j=dir;
    pivo=A[(*i+*j)/2].ValorPorKilo;
    do{
        while(pivo < A[*i].ValorPorKilo)
            (*i)++;
        while(pivo > A[*j].ValorPorKilo)
            (*j)--;
        if(*i<=*j){
            tmp1 = A[*i].ValorPorKilo;
            tmp2 = A[*i].valor;
            tmp3 = A[*i].kg;
            A[*i].ValorPorKilo = A[*j].ValorPorKilo;
            A[*i].valor = A[*j].valor;
            A[*i].kg = A[*j].kg;
            A[*j].ValorPorKilo = tmp1;
            A[*j].valor = tmp2;
            A[*j].kg = tmp3;
            (*i)++;
            (*j)--;
        }

    }while(*i<=*j);
}

void MochilaFracionaria(ITEM prod[], int tam, float capacidade){
    int i=0;
    float peso = 0, faltaPeso, ValorTotal=0, valorParcial;
    system("cls");
    while ((i < tam) && (peso < capacidade)){
        if (peso+prod[i].kg < capacidade){
            peso = peso + prod[i].kg;
            printf("\n O Item %d tem valor %.2f e peso %.2f, Bolsa ocupada é de %.2f/%.2f \n", i+1, prod[i].valor,
                   prod[i].kg, peso, capacidade);
            ValorTotal = ValorTotal + prod[i].valor;
            printf("O valor até agora é de %.2f \n", ValorTotal);
        }
        else{
            faltaPeso = capacidade - peso;
            valorParcial = faltaPeso * prod[i].ValorPorKilo;
            printf("\n Usando uma fração do Item %d, com um valor fracionário de %.2f e um peso fracionário de %.2f, \n"
                   " Bolsa ocupada é de %.2f/%.2f ", i+1, valorParcial, faltaPeso, capacidade, capacidade);
            peso = faltaPeso + peso;
            ValorTotal = ValorTotal + valorParcial;
        }
        i++;
    }
    printf("\n\n\n\t O valor Total na Mochila é %.2f \n\n", ValorTotal);

}

int main (){
    int tam;
    float w;

    setlocale(LC_ALL, "Portuguese");
    printf("\n\t Digite o número de itens disponíveis: ");
    scanf("%d", &tam);
    printf("\n\n\t Digite a capacidade total da Mochila: ");
    scanf("%f", &w);

    ITEM prod[tam];

    ColocandoItens(prod, tam);

    for (int i=0; i<tam; i++)
        prod[i].ValorPorKilo = prod[i].valor/prod[i].kg;

    quicksort(prod, tam);

    MochilaFracionaria(prod, tam, w);

    return;
}
