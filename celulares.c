#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_CEL 3
#define TAMANHO_NOME 20

typedef struct {
    int id;
    int ano;
    float preco;
    char nome[TAMANHO_NOME];
} Celular;

int sair_menu();

int main(){

    Celular listaCelulares[TAMANHO_CEL];

    int sair = 0;
    int idAtual = 1;
    int qtdCelulares = 0;
    

    while (sair == 0){
        printf("Digite a opção: \n");
        printf("0 - Sair \n");
        printf("1 - Inserir \n");
        printf("2 - Listar \n");
        printf("3 - Atualizar \n");
        printf("4 - Deletar \n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao){
        case 0:
            
            printf("\nSaindo...\n");
            sair = 1;
            break;
        
        case 1:
            printf("\nDigite o nome do modelo: ");
            fgets(listaCelulares[qtdCelulares].nome, TAMANHO_NOME, stdin);
            printf("\nDigite o ano: ");
            scanf("%d", &listaCelulares[qtdCelulares].ano);
            printf("\nDigite o preço: ");
            scanf("%f", &listaCelulares[qtdCelulares].preco);
            listaCelulares[qtdCelulares].id = idAtual;            

            qtdCelulares++;
            idAtual++;

        default:
            break;
        }



    }






    
}
