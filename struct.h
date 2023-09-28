#ifndef STRUCT_H
#define STRUCT_H

#define LIMIT_RUA 50
#define LIMIT_BAIRRO 50
#define LIMIT_CIDADE 50
#define LIMIT_DDD 3
#define LIMIT_NUMERO 9
#define LIMIT_NOME 50
#define LIMIT_EMAIL 30


typedef struct endereco{
    char rua[LIMIT_RUA];
    int numero;
    char bairro[LIMIT_BAIRRO];
    char cidade[LIMIT_CIDADE];
}Endereco;

typedef struct telefone{
    char ddd[LIMIT_DDD];
    char numero[LIMIT_NUMERO];
}Telefone;

typedef struct contato{
    char nome[LIMIT_NOME];
    char email[LIMIT_EMAIL];
    Endereco endereco;
    Telefone telefone[2];
    struct contato * proximo;
}Contato;


typedef struct inicio{
    int tamanho;
    Contato * inicio;
}Inicio;

#endif