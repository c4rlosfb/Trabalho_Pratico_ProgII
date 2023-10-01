/*Desenvolva as estruturas para representar os contatos de uma agenda conforme a descrição a seguir:
1. endereço com char rua[50], int numero, char bairro[50] e char cidade[50];
2. telefone com char ddd[2] e char numero[9];
3. contato com char nome[50], char email[30], endereco e um array para armazenar 2 telefones um para o
xo e outro para o celular telefone[2].
Observação: Utilize a diretiva #dene para estabelecer os valores dos tamanhos de cada string.
Crie uma agenda com capacidade de armazenar 10 contatos através de um ponteiro com o nome agenda
para contato. Faça todo o gerenciamento de memória com alocação dinâmica calloc() ou malloc() e libere
a memória com free() quando não for mais necessária, para otimizar o uso da memória.
Crie uma lista simplesmente encadeada e utilize modularização por meio de funções para as seguintes
operações. Todas as operações é necessário fazer o uso das funções scanf() ou do fgets().
1. Adicionar um contato na primeira e na última posição;
2. Adicionar um contato em qualquer posição;
3. Remover um contato na primeira e na última posição;
4. Remover um contato em qualquer posição;
5. Editar um contato qualquer;
6. Listar todos os contatos;
7. Buscar um contato através do nome, se houver mais de um contato com o mesmo nome listar todos os
contatos encontrados;
8. Utilizar a função realloc() para realocar a memória caso o usuário queira aumentar ou diminuir o
tamanho da agenda. 
10. para exibir o menu de opções para o usuário utilize o comando switch/case.
Observação: Apenas para facilitar as correções pelo professor, armazene na memória da agenda os dados
de 5 contatos xos, faça uso das funções strcpy() ou do strncpy(), essas duas funções possibilitam armazenar
copiar um valor para os respectivos campos de um contato sem precisar utilizar a função scanf() para isso.*/

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

    
    int opcao = 0;

    do{
        printf( "\n------------------MENU------------------\n"
                "\n   1 - Adicionar um contato na primeira posicao\n"
                "   2 - Adicionar um contato na ultima posicao\n"
                "   3 - Adicionar um contato a qualquer posicao:\n"
                "   4 - Imprimir lista\n"
                "   5 - Remover o contato na primeira posicao\n"
                "   6 - Remover o contato na ultima posicao\n"
                "   7 - Remover o contato em qualquer posicao\n"
                "   8 - Editar um contato qualquer\n"
                "   9 - Buscar contato\n"
                "   0 - Sair.\n\n"
                "   Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                adicionarPrimeiro(&agenda, preencherContato());
                break;
            case 2:
                adicionarUltimo(&agenda, preencherContato());
                break;
            case 3:
                printf("Digite a posicao que deseja inserir o contato: ");
                int posicao = 0;
                scanf("%d", &posicao);
                adicionarQualquer(&agenda, preencherContato(), posicao);
                break;
            case 4:
                imprimirContatos(&agenda);
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
                buscarContato(&agenda);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(opcao != 0);

    return 0;

}