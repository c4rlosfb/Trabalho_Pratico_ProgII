#include <stdlib.h>

/*Desenvolva as estruturas para representar os contatos de uma agenda conforme a descrição a seguir:
1. endereço com char rua[50], int numero, char bairro[50] e char cidade[50];
2. telefone com char ddd[2] e char numero[9];
3. contato com char nome[50], char email[30], endereco e um array para armazenar 2 telefones um para o fixo e outro para o celular telefone[2].*/
#define LIMIT_RUA 50
#define LIMIT_BAIRRO 50
#define LIMIT_CIDADE 50
#define LIMIT_DDD 2
#define LIMIT_NUMERO 9
#define LIMIT_NOME 50
#define LIMIT_EMAIL 30
typedef struct endereco{
    char rua[LIMIT_RUA];
    int numero;
    char bairro[LIMIT_BAIRRO];
    char cidade[LIMIT_CIDADE];
}Endereco;

typedef struct celular{
    char ddd[LIMIT_DDD];
    char numero[LIMIT_NUMERO]
}Celular;

typedef struct telefone{
    char ddd[LIMIT_DDD];
    char numero[LIMIT_NUMERO];
}Telefone;

typedef struct contato{
    char nome[LIMIT_NOME];
    char email[LIMIT_EMAIL];
    Endereco endereco;
    celular Celular[2];
    Telefone telefone[2];
    struct contato *proximo;
}Contato;

int main(){
    Contato contato;
    return 0;
}