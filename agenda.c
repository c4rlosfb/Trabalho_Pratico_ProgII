#include <stdio.h> //biblioteca padrao de entrada e saida
#include <stdlib.h> //biblioteca padrao de funções
#include <string.h> //biblioteca para manipulação de strings
#include "struct.h" //chamativa do arquivo struct.h
#include "funcao.h" //chamativa do arquivo funcao.h

int main(){ 

    //comente todo o código 
    Inicio agenda; //cria uma variavel do tipo Inicio
    agenda.inicio = NULL; //inicia o ponteiro inicio com NULL
    agenda.tamanho = 0; //inicia o tamanho com 0

    Contato * contato1 = (Contato *) calloc(1, sizeof(Contato)); //cria um ponteiro do tipo Contato e aloca memoria para ele
    Contato * contato2 = (Contato *) calloc(1, sizeof(Contato)); //cria um ponteiro do tipo Contato e aloca memoria para ele
    Contato * contato3 = (Contato *) calloc(1, sizeof(Contato)); //cria um ponteiro do tipo Contato e aloca memoria para ele
    Contato * contato4 = (Contato *) calloc(1, sizeof(Contato)); //cria um ponteiro do tipo Contato e aloca memoria para ele
    Contato * contato5 = (Contato *) calloc(1, sizeof(Contato)); //cria um ponteiro do tipo Contato e aloca memoria para ele

    ContatosEstaticos(&agenda, contato1, contato2, contato3, contato4, contato5); //chama a função ContatosEstaticos

    int opcao = 0; //cria uma variavel do tipo inteiro e inicia ela com 0

    do{ //inicia um laço de repetição
        printf( "\n------------------MENU------------------\n" //imprime o menu
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

        printf("Escolha uma opcao: "); //imprime uma mensagem para o usuario escolher uma opção
        scanf("%d", &opcao); //le a opção escolhida pelo usuario


        switch (opcao){ //inicia um switch case para cada opção
            case 1: //caso a opção seja 1
                adicionarPrimeiro(&agenda, preencherContato()); //chama a função adicionarPrimeiro
                break; //para o switch case
            case 2: //caso a opção seja 2
                adicionarUltimo(&agenda, preencherContato()); //chama a função adicionarUltimo
                break; //para o switch case
            case 3: //caso a opção seja 3
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("(OBS: A posicao 0 eh a primeira posicao da lista)\n" //imprime uma mensagem para o usuario
                "Digite a posicao que deseja inserir o contato: ");
                int posicao = 0; //cria uma variavel do tipo inteiro e inicia ela com 0
                scanf("%d", &posicao); //le a posição escolhida pelo usuario
                adicionarQualquer(&agenda, preencherContato(), posicao); //chama a função adicionarQualquer
                break; //para o switch case
            case 4: //caso a opção seja 4
                buscarContato(&agenda); //chama a função buscarContato
                break; //para o switch case
            case 5: //caso a opção seja 5
               removerPrimeiro(&agenda); //chama a função removerPrimeiro
                break; //para o switch case 
            case 6: //caso a opção seja 6
                removerUltimo(&agenda); //chama a função removerUltimo
                break; //para o switch case 
            case 7: //caso a opção seja 7
                removerQualquer(&agenda); //chama a função removerQualquer
                break; //para o switch case
            case 8: //caso a opção seja 8 
                editarContato(&agenda); //chama a função editarContato
                break; //para o switch case
            case 9: //caso a opção seja 9
                imprimirContatos(&agenda); //chama a função imprimirContatos
                break; //para o switch case
            case 0: //caso a opção seja 0
                printf("\n------------------------------------------------------------------------------------------------------------------------\n");
                printf("Saindo...\n");  //imprime uma mensagem para o usuario
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                break; //para o switch case
            default: //caso a opção seja diferente de 0, 1, 2, 3, 4, 5, 6, 7, 8 e 9
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Opcao invalida!\n"); //imprime uma mensagem para o usuario
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                break; //para o switch case
        }
    }while(opcao != 0); //enquanto a opção for diferente de 0 executa o laço de repetição

    return 0; //retorna 0

}