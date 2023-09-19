#include <stdlib.h>

/*Desenvolva as estruturas para representar os contatos de uma agenda conforme a descrição a seguir:
1. endereço com char rua[50], int numero, char bairro[50] e char cidade[50];
2. telefone com char ddd[2] e char numero[9];
3. contato com char nome[50], char email[30], endereco e um array para armazenar 2 telefones um para o fixo e outro para o celular telefone[2].*/

typedef struct endereco{
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
}Endereco;

typedef struct celular{
    char ddd[2];
    char numero[9]
}Celular;

typedef struct telefone{
    char ddd[2];
    char numero[9];
}Telefone;

typedef struct contato{
    char nome[50];
    char email[30];
    Endereco endereco;
    celular Celular[2];
    Telefone telefone[2];
    struct contato *proximo;
}Contato;

int main(){
    Contato contato;
    return 0;
}