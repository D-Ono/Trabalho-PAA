#include <stdio.h>
#include <locale.h>

typedef struct item{
        int valor;
        int kg;
}ITEM;

int knapsack(int W, ITEM prod[],int n){
    /// tabela que será preenchida com os valores e tabela com 0-1
	int V[n + 1][W + 1], Itens[n+1][W+1];

	/// inicializando a primeira linha e primeira coluna com 0
	for(int w = 0; w <= W; w++){
		V[0][w] = 0;
        Itens[0][w] = 0;
		}
	for(int i = 1; i <= n; i++){
		V[i][0] = 0;
		Itens[i][0] = 0;
    }

	for(int i = 1; i <= n; i++)
	{
		for(int w = 1; w <= W; w++)
		{
			/// elemento pode fazer parte da solução
			if(prod[i-1].kg <= w)
			{
				/// max...
				if((prod[i-1].valor + V[i - 1][w - prod[i-1].kg]) > V[i - 1][w]){
					V[i][w] = prod[i-1].valor + V[i - 1][w - prod[i-1].kg];
					Itens[i][w] = 1;
                }
				else{
					V[i][w] = V[i - 1][w];
					Itens[i][w] = 0;
				}
			}
			else{
				V[i][w] = V[i - 1][w]; // wi > w
				Itens[i][w] = 0;
			}
		}
	}

	int i=n, j=W;
	system("cls");
	printf("\t\t Os itens que compõe a Mochila são: \n");
	while (i!=0){
        if (Itens[i][j]==1){
            printf("\n Item %d com Valor %d e Peso %d \n", i, prod[i-1].valor, prod[i-1].kg);
            j = j - prod[i-1].kg;
        }
        i--;
	}


	/// retorna o valor máximo colocado na mochila
	return V[n][W];
}

void ColocandoItens(ITEM PROD[], int tam){
    int i;
    system("cls");

    for (i=0; i<tam; i++){
        printf("\n\n\t\t\t ITEM %d \n\n\n", i+1);
        printf("\t Valor do Item: ");
        scanf("%d",&PROD[i].valor);
        printf("\n\n\t Peso do Item: ");
        scanf("%d",&PROD[i].kg);
        system("cls");
    }
}

int main (){
    int tam, valorMax;
    float w;

    setlocale(LC_ALL, "Portuguese");
    printf("\n\t Digite o número de itens disponíveis: ");
    scanf("%d", &tam);
    printf("\n\n\t Digite a capacidade total da Mochila: ");
    scanf("%f", &w);

    ITEM prod[tam];

    ColocandoItens(prod, tam);

    valorMax = knapsack(w, prod, tam);

    printf("\n\n O valor Máximo da Mochila é %d \n\n", valorMax);

    return;
}
