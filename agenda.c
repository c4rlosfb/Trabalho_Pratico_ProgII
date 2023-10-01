#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "funcao.h"

int main(){

    Inicio agenda;
    agenda.inicio = NULL;
    agenda.tamanho = 0; 

    Contato * contato1 = (Contato *) calloc(1, sizeof(Contato));
    Contato * contato2 = (Contato *) calloc(1, sizeof(Contato));
    Contato * contato3 = (Contato *) calloc(1, sizeof(Contato));
    Contato * contato4 = (Contato *) calloc(1, sizeof(Contato));
    Contato * contato5 = (Contato *) calloc(1, sizeof(Contato));

    ContatosEstaticos(&agenda, contato1, contato2, contato3, contato4, contato5);

    //imprimirContatos(&agenda);

    int opcao = 0;

    do{
        printf( "\n------------------MENU------------------\n"
                "\n   1 - Adicionar um contato na primeira posicao\n"
                "   2 - Adicionar um contato na ultima posicao\n"
                "   3 - Adicionar um contato a qualquer posicao:\n"
                "   4 - Buscar contato\n"
                "   5 - Remover o contato na primeira posicao\n"
                "   6 - Remover o contato na ultima posicao\n"
                "   7 - Remover o contato em qualquer posicao\n"
                "   8 - Editar um contato qualquer\n"
                "   9 - Imprimir lista\n"
                "   0 - Sair.\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        //certo
        switch (opcao){
            case 1:
                adicionarPrimeiro(&agenda, preencherContato());
                break;
            case 2:
                adicionarUltimo(&agenda, preencherContato());
                break;
            case 3:
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("(OBS: A posicao 0 eh a primeira posicao da lista)\n)"
                "Digite a posicao que deseja inserir o contato: ");
                int posicao = 0;
                scanf("%d", &posicao);
                adicionarQualquer(&agenda, preencherContato(), posicao);
                break;
            case 4:
                buscarContato(&agenda);
                break;
            case 5:
               removerPrimeiro(&agenda);
                break;
            case 6:
                removerUltimo(&agenda);
                break;
            case 7:
                removerQualquer(&agenda);
                break;
            case 8:
                editarContato(&agenda);
                break;
            case 9:
                imprimirContatos(&agenda);
                break;
            case 0:
                printf("\n------------------------------------------------------------------------------------------------------------------------\n");
                printf("Saindo...\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                break;
            default:
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Opcao invalida!\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                break;
        }
    }while(opcao != 0);

    return 0;

}