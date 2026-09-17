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
            if (qtdCelulares >= TAMANHO_CEL){
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
            int idBusca;
            int encontrado = 0;
            printf("Informe o ID do celular a ter o cadastro atualizado: ");
            scanf("%d", &idBusca);

            for (int i = 0; i < qtdCelulares; i++){
                if (listaCelulares[i].id == idBusca){
                    encontrado = 1;
                    printf(
                        "ID: %d - Ano: %d - Preço: %.2f\n",
                        listaCelulares[i].id,
                        listaCelulares[i].ano,
                        listaCelulares[i].preco
                    );
                    printf("\nDigite o ano: ");
                    scanf("%d", &listaCelulares[i].ano);
                    printf("Digite o preço: ");
                    scanf("%f", &listaCelulares[i].preco); 

                    printf("Atualizado com sucesso!\n");
                    break;
                }// if
            }//for geral
            if (encontrado == 0) {
                printf("Celular não encontrado.\n");
            }// if
            break;
        case 4:
            int idDeletar;
            int opcaoDeletar;
            int encontradoDeletar = 0;
            printf("Informe o ID do celular a ser deletado: ");
            scanf("%d", &idDeletar);
            
            for (int i = 0; i < qtdCelulares; i++){
                if(listaCelulares[i].id == idDeletar){
                    encontradoDeletar = 1;
                    printf(
                        "ID: %d - Ano: %d - Preço: %.2f\n",
                        listaCelulares[i].id,
                        listaCelulares[i].ano,
                        listaCelulares[i].preco
                    );
                    printf("Deseja deletar este celular?\n");
                    printf("[0 - SIM] [1 - NÃO]\n");
                    scanf("%d", &opcaoDeletar);

                    if (opcaoDeletar == 0){
                        for (int j = i; j < qtdCelulares - 1; j++){
                            listaCelulares[j] = listaCelulares[j + 1];
                        }
                        qtdCelulares--;
                        printf("Celular deletado com sucesso!\n");
                        break;
                    } else {
                        printf("Operação cancelada.\n");
                        break;
                    }
                }
            }
            if (encontradoDeletar == 0) {
                printf("Celular não encontrado.\n");
            }//for geral
            break;
        default:
            break;
        } //switch
    }//while
    return 0;
}//main