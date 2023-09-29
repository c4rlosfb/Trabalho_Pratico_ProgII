#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "struct.h"

void imprimirContatos(Inicio * inicio) {
    if(inicio->inicio == NULL) {
        printf("Agenda vazia!\n");
        return;
    } 
    else {
        Contato * aux = inicio->inicio;

        do
        {
            printf("Nome: %s\n", aux->nome);
            printf("Email: %s\n", aux->email);
            printf("Rua: %s\n", aux->endereco.rua);
            printf("Numero: %d\n", aux->endereco.numero);
            printf("Bairro: %s\n", aux->endereco.bairro);
            printf("Cidade: %s\n", aux->endereco.cidade);
            printf("DDD do celular: %s\n", aux->telefone[0].ddd);
            printf("Numero do celular: %s\n", aux->telefone[0].numero);
            printf("DDD do telefone: %s\n", aux->telefone[1].ddd);
            printf("Numero do telefone: %s\n", aux->telefone[1].numero);
            printf("\n");

            aux = aux->proximo;
        } while (aux != NULL);
    }
}

Contato * preencherContato(){

    Contato * novoContato = (Contato *) malloc(sizeof(Contato));

    printf("Digite o nome: ");
    scanf("%s", novoContato->nome);
    printf("Digite o email: ");
    scanf("%s", novoContato->email);
    printf("Digite o nome da sua rua: ");
    scanf("%s", novoContato->endereco.rua);
    printf("Digite o numero da sua casa: ");
    scanf("%d", &novoContato->endereco.numero);
    printf("Digite o seu bairro: ");
    scanf("%s", novoContato->endereco.bairro);
    printf("Digite a sua cidade: ");
    scanf("%s", novoContato->endereco.cidade);
    printf("Digite o seu celular (<ddd> <celular>): ");
    scanf("%s %s", novoContato->telefone[0].ddd, novoContato->telefone[0].numero);
    printf("Digite o seu telefone (<ddd> <telefone>): ");
    scanf("%s %s", novoContato->telefone[1].ddd, novoContato->telefone[1].numero);

    novoContato->proximo = NULL;

    return novoContato;
}

Contato * criador(){

    Contato * novoContato = (Contato *) calloc(1, sizeof(Contato));
    novoContato->proximo = NULL;

    strcmpi(novoContato->nome, "Celso Augusto de Oliveira Junior");
    strcmpi(novoContato->email, "celso.oliveira@alunos.ifsuldeminas.edu.br");
    strcmpi(novoContato->endereco.rua, "Jose Dias Campos");
    novoContato->endereco.numero = 455;
    strcmpi(novoContato->endereco.bairro, "Jardim Paraiso");
    strcmpi(novoContato->endereco.cidade, "Pocos de Caldas");
    strcmpi(novoContato->telefone[0].ddd, "35");
    strcmpi(novoContato->telefone[0].numero, "991186430");
    strcmpi(novoContato->telefone[1].ddd, "35");
    strcmpi(novoContato->telefone[1].numero, "937225238");
    novoContato->proximo = NULL;

    return novoContato;
}

void adicionarPrimeiro(Inicio * agenda, Contato * contato){

    Contato * novoContato = contato;

    if(agenda->inicio == NULL){
        agenda->inicio = novoContato;
    }else{
        novoContato->proximo = agenda->inicio;
        agenda->inicio = novoContato;
    }
    agenda->tamanho++;
}

void adicionarUltimo(Inicio * agenda, Contato * contato) {

    Contato * novoContato = agenda->inicio;

    if(agenda->inicio == NULL){
        agenda->inicio = novoContato;
    }else{
        while(novoContato->proximo != NULL){
            novoContato = novoContato->proximo;
        }
        novoContato->proximo = novoContato;
    }

    agenda->tamanho++;
}

void adicionarQualquer(Inicio * agenda, Contato * contato){

    Contato * atual = agenda->inicio;
    Contato * proximo = atual;

    int posicao = 0;
    int contador = 0;
    printf("Digite a posicao que deseja inserir o contato: ");
    scanf("%d", &posicao);

    if(posicao > 1) {
        printf("Impossivel inserir elementos em posicoes negativas ou nulas!\n");
        return;
    }

    if(posicao == 1) {
        atual->proximo = agenda->inicio;
        agenda->inicio = atual;
        agenda->tamanho++;
        return;
    }

    if(posicao > agenda->tamanho) {
        printf("Posicao inexistente!\n");
        return;
    } 

    while(atual->proximo != NULL) {

        if(contador == posicao){
            atual->proximo = contato;
            contato->proximo = proximo;
            agenda->tamanho++;
            return;
        }
        atual = proximo;
        proximo = proximo->proximo;
        contador++;
    }
}

//void removerPrimeiro(Inicio * agenda){

//    if(agenda->inicio == NULL){
//        printf("Agenda vazia!\n");
//   }else{
//        Contato * aux = agenda->inicio;
//        agenda->inicio = aux->proximo;
//        free(aux);
//    }

//    agenda->tamanho--;

//}

// void removerUltimo(Inicio * agenda){

//     if(agenda->inicio == NULL){
//         printf("Agenda vazia!\n");
//     }else{
//         Contato * aux = agenda->inicio;
//         while(aux->proximo->proximo != NULL){
//             aux = aux->proximo;
//         }
//         free(aux->proximo);
//         aux->proximo = NULL;
//     }

//     agenda->tamanho--;

// }

// void removerQualquer(Inicio * agenda){

//     if(agenda->inicio == NULL){
//         printf("Agenda vazia!\n");
//     }else{
//         int posicao = 0;
//         printf("Digite a posicao que deseja remover o contato: ");
//         scanf("%d", &posicao);
//         getchar();

//         if(posicao == 0){
//             Contato * aux = agenda->inicio;
//             agenda->inicio = aux->proximo;
//             free(aux);
//         }else if(posicao == agenda->tamanho - 1){
//             Contato * aux = agenda->inicio;
//             while(aux->proximo->proximo != NULL){
//                 aux = aux->proximo;
//             }
//             free(aux->proximo);
//             aux->proximo = NULL;
//         }else{
//             Contato * aux = agenda->inicio;
//             for(int i = 0; i < posicao - 1; i++){
//                 aux = aux->proximo;
//             }
//             Contato * aux2 = aux->proximo;
//             aux->proximo = aux2->proximo;
//             free(aux2);
//         }
//     }

//     agenda->tamanho--;

// }

// void editarContato(Inicio * agenda){

//     if(agenda->inicio == NULL){
//         printf("Agenda vazia!\n");
//     }else{
//         int posicao = 0;
//         printf("Digite a posicao que deseja editar o contato: ");
//         scanf("%d", &posicao);
//         getchar();

//         Contato * aux = agenda->inicio;
//         for(int i = 0; i < posicao; i++){
//             aux = aux->proximo;
//         }

//         printf("Digite o nome: ");
//         gets(aux->nome);
//         printf("Digite o email: ");
//         gets(aux->email);
//         printf("Digite a rua: ");
//         gets(aux->endereco.rua);
//         printf("Digite o numero: ");
//         gets(aux->endereco.numero);
//         printf("Digite o bairro: ");
//         gets(aux->endereco.bairro);
//         printf("Digite a cidade: ");
//         gets(aux->endereco.cidade);
//         printf("Digite o DDD do celular: ");
//         gets(aux->celular[0].ddd);
//         printf("Digite o numero do celular: ");
//         gets(aux->celular[0].numero);
//         printf("Digite o DDD do telefone: ");
//         gets(aux->telefone[0].ddd);
//         printf("Digite o numero do telefone: ");
//         gets(aux->telefone[0].numero);

//     }

// }

// void listarContatos(Inicio * agenda){

//     if(agenda->inicio == NULL){
//         printf("Agenda vazia!\n");
//     }else{
//         Contato * aux = agenda->inicio;
//         while(aux != NULL){
//             printf("Nome: %s\n", aux->nome);
//             printf("Email: %s\n", aux->email);
//             printf("Rua: %s\n", aux->endereco.rua);
//             printf("Numero: %s\n", aux->endereco.numero);
//             printf("Bairro: %s\n", aux->endereco.bairro);
//             printf("Cidade: %s\n", aux->endereco.cidade);
//             printf("DDD do celular: %s\n", aux->celular[0].ddd);
//             printf("Numero do celular: %s\n", aux->celular[0].numero);
//             printf("DDD do telefone: %s\n", aux->telefone[0].ddd);
//             printf("Numero do telefone: %s\n", aux->telefone[0].numero);
//             printf("\n");
//             aux = aux->proximo;
//         }
//     }

// }

// void buscarContato(Inicio * agenda){

//     if(agenda->inicio == NULL){
//         printf("Agenda vazia!\n");
//     }else{
//         char nome[LIMIT_NOME];
//         printf("Digite o nome que deseja buscar: ");
//         gets(nome);

//         Contato * aux = agenda->inicio;
//         while(aux != NULL){
//             if(strcmpi(aux->nome, nome) == 0){
//                 printf("Nome: %s\n", aux->nome);
//                 printf("Email: %s\n", aux->email);
//                 printf("Rua: %s\n", aux->endereco.rua);
//                 printf("Numero: %s\n", aux->endereco.numero);
//                 printf("Bairro: %s\n", aux->endereco.bairro);
//                 printf("Cidade: %s\n", aux->endereco.cidade);
//                 printf("DDD do celular: %s\n", aux->celular[0].ddd);
//                 printf("Numero do celular: %s\n", aux->celular[0].numero);
//                 printf("DDD do telefone: %s\n", aux->telefone[0].ddd);
//                 printf("Numero do telefone: %s\n", aux->telefone[0].numero);
//                 printf("\n");
//                 break;
//             }
//             aux = aux->proximo;
//         }
//     }

// }

// void aumentarDiminuir(Inicio * agenda){

//     int tamanho = 0;
//     printf("Digite o tamanho que deseja aumentar ou diminuir: ");
//     scanf("%d", &tamanho);
//     getchar();

//     if(tamanho > agenda->tamanho){
//         for(int i = 0; i < tamanho - agenda->tamanho; i++){
//             adicionarUltimo(agenda);
//         }
//     }else if(tamanho < agenda->tamanho){
//         for(int i = 0; i < agenda->tamanho - tamanho; i++){
//             removerUltimo(agenda);
//         }
//     }

// }

// void salvar(Inicio * agenda){

//     FILE * arquivo = fopen("agenda.txt", "w");

//     if(arquivo == NULL){
//         printf("Erro ao abrir o arquivo!\n");
//     }else{
//         Contato * aux = agenda->inicio;
//         while(aux != NULL){
//             fprintf(arquivo, "%s\n", aux->nome);
//             fprintf(arquivo, "%s\n", aux->email);
//             fprintf(arquivo, "%s\n", aux->endereco.rua);
//             fprintf(arquivo, "%s\n", aux->endereco.numero);
//             fprintf(arquivo, "%s\n", aux->endereco.bairro);
//             fprintf(arquivo, "%s\n", aux->endereco.cidade);
//             fprintf(arquivo, "%s\n", aux->celular[0].ddd);
//             fprintf(arquivo, "%s\n", aux->celular[0].numero);
//             fprintf(arquivo, "%s\n", aux->telefone[0].ddd);
//             fprintf(arquivo, "%s\n", aux->telefone[0].numero);
//             fprintf(arquivo, "\n");
//             aux = aux->proximo;
//         }
//     }

//     fclose(arquivo);

// }

