#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_CEL 5

typedef struct {
    int id;
    int ano;
    float preco;
} Celular;

//int sair_menu();

int main(){

    Celular listaCelulares[TAMANHO_CEL];

    int sair = 0;
    int idAtual = 1;
    int qtdCelulares = 0;
    

    while (sair == 0){
        printf("\nDigite a opção: \n");
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
            if (qtdCelulares > TAMANHO_CEL){
                printf("\nLimite de celulares cadastrados atingido");
                break;
            }  

            printf("\nDigite o ano: ");
            scanf("%d", &listaCelulares[qtdCelulares].ano);
            printf("Digite o preço: ");
            scanf("%f", &listaCelulares[qtdCelulares].preco);
            listaCelulares[qtdCelulares].id = idAtual;     
            
            printf("Celular ID: %d - Ano: %d - Preço: %.2f Cadastrado com sucesso!\n", listaCelulares[qtdCelulares].id, listaCelulares[qtdCelulares].ano, listaCelulares[qtdCelulares].preco);

            qtdCelulares++;
            idAtual++;

            break;
        case 2:
            for(int i = 0; i < qtdCelulares; i++)
                printf("ID: %d - Ano: %d - Preço: %.2f\n", listaCelulares[i].id, listaCelulares[i].ano, listaCelulares[i].preco);
            break;
        case 3:
            // atualizar cadastro de um celular especifico, procurando pelo id (posição no vetor)
            break;
        case 4:
            // deletar celular pelo id.
            break;
        default:
            break;
        
        }
    }

    return 0;
}
