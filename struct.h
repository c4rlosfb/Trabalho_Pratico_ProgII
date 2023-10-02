#ifndef STRUCT_H //verifica se o arquivo struct.h ja foi chamado
#define STRUCT_H //define o arquivo struct.h 

#define LIMIT_RUA 50 //define o limite de caracteres para a rua
#define LIMIT_BAIRRO 50 //define o limite de caracteres para o bairro
#define LIMIT_CIDADE 50 //define o limite de caracteres para a cidade
#define LIMIT_DDD 3 //define o limite de caracteres para o ddd
#define LIMIT_NUMERO 9 //define o limite de caracteres para o numero
#define LIMIT_NOME 50 //define o limite de caracteres para o nome
#define LIMIT_EMAIL 30 //define o limite de caracteres para o email

typedef struct endereco{ //cria uma struct do tipo endereco
    char rua[LIMIT_RUA]; //cria uma variavel do tipo char e define o limite de caracteres para ela
    int numero; //cria uma variavel do tipo inteiro
    char bairro[LIMIT_BAIRRO]; //cria uma variavel do tipo char e define o limite de caracteres para ela
    char cidade[LIMIT_CIDADE]; //cria uma variavel do tipo char e define o limite de caracteres para ela
}Endereco; //define o nome da struct
typedef struct telefone{ //cria uma struct do tipo telefone
    char ddd[LIMIT_DDD]; //cria uma variavel do tipo char e define o limite de caracteres para ela
    char numero[LIMIT_NUMERO]; //cria uma variavel do tipo char e define o limite de caracteres para ela
}Telefone; //define o nome da struct
typedef struct contato{ //cria uma struct do tipo contato
    char nome[LIMIT_NOME]; //cria uma variavel do tipo char e define o limite de caracteres para ela
    char email[LIMIT_EMAIL]; //cria uma variavel do tipo char e define o limite de caracteres para ela
    Endereco endereco; //cria uma variavel do tipo Endereco
    Telefone telefone[2]; //cria uma variavel do tipo Telefone
    struct contato * proximo; //cria um ponteiro do tipo contato
}Contato; //define o nome da struct
typedef struct inicio{ //cria uma struct do tipo inicio
    int tamanho; //cria uma variavel do tipo inteiro
    Contato * inicio; //cria um ponteiro do tipo contato
}Inicio; //define o nome da struct

#endif //fecha o ifndef