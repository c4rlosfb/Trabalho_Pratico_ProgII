#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "struct.h"

//certa, editar exibição para ser mais bonita e organizada
void imprimirContatos(Inicio * inicio) {
    if(inicio->inicio == NULL) {
        printf("Agenda vazia!\n");
        return;
    } 
    else {
        Contato * aux = inicio->inicio;

        if (aux == NULL)
        {
            printf("Nao foi possivel alocar contato\n");
            exit(1);
        }
        
        do{        
            printf("---------Contato----------\n"); //colocar um numero que identifique cada contado para melhor exibição
            printf("Nome: %s\n", aux->nome);
            printf("Email: %s\n", aux->email);
            printf("Endereco: %s, %s - n: %d, %s\n", aux->endereco.bairro, aux->endereco.rua, aux->endereco.numero, aux->endereco.cidade);
            printf("Celular: (%s) %s\n", aux->telefone[0].ddd, aux->telefone[0].numero);
            printf("Telefone: (%s) %s\n", aux->telefone[1].ddd, aux->telefone[1].numero);
            printf("\n");

            aux = aux->proximo;
        }while(aux != NULL);
    }
}

//dúvida sobre essa função
void ContatosEstaticos(Inicio * agenda, Contato * contato1, Contato * contato2, Contato * contato3, Contato * contato4, Contato * contato5 ){
    
    contato1 = criador(contato1, "Joao", "gmail.com", "Rua A", 1, "Bairro A", "Cidade A", "11", "111111111", "11", "111111111 ");
    contato2 = criador(contato2, "Maria", "gmail.com", "Rua B", 2, "Bairro B", "Cidade B", "22", "222222222", "22", "222222222 ");
    contato3 = criador(contato3, "Jose", "gmail.com", "Rua C", 3, "Bairro C", "Cidade C", "33", "333333333", "33", "333333333 ");
    contato4 = criador(contato4, "Ana", "gmail.com", "Rua D", 4, "Bairro D", "Cidade D", "44", "444444444", "44", "444444444 ");
    contato5 = criador(contato5, "Pedro", "gmail.com", "Rua E", 5, "Bairro E", "Cidade E", "55", "555555555", "55", "555555555 ");

    adicionarPrimeiro(agenda, contato1);
    adicionarUltimo(agenda, contato2);
    adicionarUltimo(agenda, contato3);
    adicionarUltimo(agenda, contato4);
    adicionarUltimo(agenda, contato5);


}

//dúvida sobre essa função
Contato * criador( Contato * contato, char nome[], char email[], char rua[], int numero, char bairro[], char cidade[], char ddd1[], char numero1[], char ddd2[], char numero2[]){

     contato = (Contato *) malloc(sizeof(Contato));

    if (contato == NULL)
    {
        printf("Nao foi possivel alocar contato\n");
        exit(1);
    }

    strcpy(contato->nome, nome);
    strcpy(contato->email, email);
    strcpy(contato->endereco.rua, rua);
    contato->endereco.numero = numero;
    strcpy(contato->endereco.bairro, bairro);
    strcpy(contato->endereco.cidade, cidade);
    strcpy(contato->telefone[0].ddd, ddd1);
    strcpy(contato->telefone[0].numero, numero1);
    strcpy(contato->telefone[1].ddd, ddd2);
    strcpy(contato->telefone[1].numero, numero2);

    contato->proximo = NULL;

    return contato;

}

//sem erros
Contato *preencherContato()
{

    Contato * novoContato = (Contato *) malloc(sizeof(Contato));

    printf("Digite o nome: ");
    scanf(" %50[^\n]s", novoContato->nome);
    printf("Digite o email: ");
    scanf(" %30[^\n]s", novoContato->email);
    printf("Digite o seu bairro: ");
    scanf(" %50[^\n]s", novoContato->endereco.bairro);
    printf("Digite o nome da sua rua: ");
    scanf(" %50[^\n]s", novoContato->endereco.rua);
    printf("Digite o numero da sua casa: ");
    scanf("%d", &novoContato->endereco.numero);
    printf("Digite a sua cidade: ");
    scanf(" %50[^\n]s", novoContato->endereco.cidade);
    printf("Digite o seu celular (<xx> <xxxxxxxxx>): ");
    scanf("%2s %9s", novoContato->telefone[0].ddd, novoContato->telefone[0].numero);
    printf("Digite o seu telefone (<xx> <xxxxxxxxx>): ");
    scanf("%2s %9s", novoContato->telefone[1].ddd, novoContato->telefone[1].numero);

    novoContato->proximo = NULL;

    return novoContato;
}

//certa
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

//certa
void adicionarUltimo(Inicio * agenda, Contato * contato){

    Contato * novoContato = contato;

    if(agenda->inicio == NULL){
        agenda->inicio = novoContato;
    }else{
        Contato * aux = agenda->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novoContato;
    }

    agenda->tamanho++;
}

//certa
void adicionarQualquer(Inicio * agenda, Contato * contato, int posicao){


    if(posicao < 1) 
    {
        printf("Impossivel inserir elementos em posicoes negativas ou nulas!\n");
        return;
    }

    Contato * atual = agenda->inicio;
    Contato * proximo = atual;
    
    if(posicao == 1) 
    {
        if(agenda->inicio == NULL)
        {
        agenda->inicio = contato;
        }
        else
        {
        contato->proximo = agenda->inicio;
        agenda->inicio = contato;
        }
        agenda->tamanho++;

        return;
    }

    if(posicao > agenda->tamanho) {
        printf("Posicao inexistente!\n");
        return;
    } 
    
    int contador = 1;
    
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

//certa
void removerPrimeiro(Inicio * agenda){

   if(agenda->inicio == NULL){
       printf("Agenda vazia!\n");
  }else{
       Contato * aux = agenda->inicio;
       agenda->inicio = aux->proximo;
       free(aux);
   }

   agenda->tamanho--;

}

//certa
void removerUltimo(Inicio * agenda){

    if(agenda->inicio == NULL){
        printf("Agenda vazia!\n");
    }else{
        Contato * aux = agenda->inicio;
        while(aux->proximo->proximo != NULL){
            aux = aux->proximo;
        }
        free(aux->proximo);
        aux->proximo = NULL;
    }

    agenda->tamanho--;

}

//certa - mudar observação da agenda, começa em 0, porém tinha que ser em 1 para não confundir o usuário
void removerQualquer(Inicio * agenda){

    if(agenda->inicio == NULL){
        printf("Agenda vazia!\n");
    }else{
        int posicao = 0;
        printf("Digite a posicao que deseja remover o contato: ");
        scanf("%d", &posicao);

        Contato * aux = agenda->inicio;
        Contato * aux2 = aux->proximo;
        for(int i = 0; i < posicao - 1; i++){
            aux = aux->proximo;
            aux2 = aux2->proximo;
        }
        aux->proximo = aux2->proximo;
        free(aux2);
    }

    agenda->tamanho--;

}

//corrigir essa função
void editarContato(Inicio *agenda){

    if(agenda->inicio == NULL){
        printf("Agenda vazia!\n");
    }else{
        char nome[LIMIT_NOME];
        printf("Digite o nome que deseja editar: ");
        scanf(" %50[^\n]s", nome);

        Contato * aux = agenda->inicio;
        while(aux != NULL){
            if(strcmpi(aux->nome, nome) == 0){
                printf("Digite o novo nome: ");
                scanf(" %50[^\n]s", aux->nome);
                printf("Digite o novo email: ");
                scanf(" %30[^\n]s", aux->email);
                printf("Digite o novo bairro: ");
                scanf(" %50[^\n]s", aux->endereco.bairro);
                printf("Digite o novo nome da rua: ");
                scanf(" %50[^\n]s", aux->endereco.rua);
                printf("Digite o novo numero da casa: ");
                scanf("%d", &aux->endereco.numero);
                printf("Digite a nova cidade: ");
                scanf(" %50[^\n]s", aux->endereco.cidade);
                printf("Digite o novo celular (<xx> <xxxxxxxxx>): ");
                scanf("%2s %9s", aux->telefone[0].ddd, aux->telefone[0].numero);
                printf("Digite o novo telefone (<xx> <xxxxxxxxx>): ");
                scanf("%2s %9s", aux->telefone[1].ddd, aux->telefone[1].numero);
                break;
            }
            aux = aux->proximo;
        }
    }

}

//corrigir os segundo IF para que volte para o menu caso não encontre o contato
void buscarContato(Inicio * agenda){

    if(agenda->inicio == NULL){
        printf("Agenda vazia!\n");
    }else{
        char nome[LIMIT_NOME];
        printf("Digite o nome que deseja buscar: ");
        scanf(" %50[^\n]s", nome);

        Contato * aux = agenda->inicio;

        if(strcmpi(aux->nome, nome) != 0){ //corrigir apartir daqui
            printf("Contato nao encontrado!\n");
        }else{
            while(aux != NULL){
                for(int i = 0; i <= agenda->tamanho; i++){
                    if(strcmpi(aux->nome, nome) == 0){
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
                    }
                aux = aux->proximo;
            }
        }
    }
    }
}


