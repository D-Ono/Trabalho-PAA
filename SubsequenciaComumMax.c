#include <stdio.h>
#include <locale.h>

int main (){
    int tamX, tamZ;
    int i, j, tamSub, aux;

    setlocale(LC_ALL, "Portuguese");
    printf("\n\t Digite o tamanho da Sequencia X: ");
    scanf("%d", &tamX);
    printf("\n\n\t Digite o tamanho da Sequencia Z: ");
    scanf("%d", &tamZ);
    system("cls");

    char X[tamX], Z[tamZ];
    int MatrizResposta[tamZ][tamX], MatrizVolta[tamZ][tamX];

    printf("\n\t Digite a sequencia de X: ");
    scanf("%s", &X);
    printf("\n\n\t Digite a sequencia de Z: ");
    scanf("%s", &Z);
    system("cls");

    for(i=0; i<tamZ; i++)
        MatrizResposta[0][i]=0;

    for(i=0; i<tamX; i++)
        MatrizResposta[i][0]=0;

    for (i=1; i<=tamX; i++){
        for (j=1; j<=tamZ; j++){
            if (X[i-1] == Z[j-1]){
                MatrizResposta[i][j] = MatrizResposta[i-1][j-1] + 1;
                MatrizVolta[i][j] = 0;        /// 0 representa a soma com a diagonal
            }
            else {
                if (MatrizResposta[i-1][j] >= MatrizResposta[i][j-1]){
                    MatrizResposta[i][j] = MatrizResposta[i-1][j];
                    MatrizVolta[i][j] = 1;          /// 1 Pegamos o elemento superior
                }
                else{
                    MatrizResposta[i][j] = MatrizResposta[i][j-1];
                    MatrizVolta[i][j] = 2;            /// 2 Pega o elemento a esquerda
                }

            }

        }
    }
    i--; j--;
    tamSub = MatrizResposta[i][j];
    aux = tamSub;


    char Subsquencia [tamSub];

    while (aux){
        if (MatrizVolta[i][j] == 0){
            Subsquencia[aux] = X[i-1];
            i--; j--;
            aux-=1;
        }
        else{
            if (MatrizVolta[i][j] == 1){
                i--;
            }
            else j--;
        }
    }
    printf("\n\n\t O tamanho máximo da Subsequência é: \t");
    for (i=1; i<= tamSub; i++){
        printf("%c", Subsquencia[i]);
    }
    printf("\n\n");

    return;
}
