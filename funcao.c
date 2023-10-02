#include <stdio.h> //biblioteca padrao de entrada e saida
#include <stdlib.h> //biblioteca padrao de funções 
#include <string.h> //biblioteca para manipulação de strings
#include "funcao.h" //chamativa do arquivo funcao.h
#include "struct.h" //chamativa do arquivo struct.h

void imprimirContatos(Inicio * inicio) { //função para imprimir os contatos
    if(inicio->inicio == NULL) { //se o inicio for igual a NULL
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Agenda vazia!\n"); //imprime uma mensagem para o usuario
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        return; //retorna para a função main
    } 
    else { //senão
        Contato * aux = inicio->inicio; //cria um ponteiro auxiliar e inicia ele com o inicio

        if (aux == NULL) //se o aux for igual a NULL
        {
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Nao foi possivel alocar contato\n"); //imprime uma mensagem para o usuario
            exit(1); //encerra o programa
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        }
        
        do{ //inicia um laço de repetição
            printf("\n---------------Contato--------------\n"); //imprime a lista de contatos
            printf("Nome: %s\n", aux->nome); 
            printf("Email: %s\n", aux->email);
            printf("Endereco: %s, %s - n: %d, %s\n", aux->endereco.bairro, aux->endereco.rua, aux->endereco.numero, aux->endereco.cidade);
            printf("Celular: (%s) %s\n", aux->telefone[0].ddd, aux->telefone[0].numero);
            printf("Telefone: (%s) %s\n", aux->telefone[1].ddd, aux->telefone[1].numero);
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");

            aux = aux->proximo; //aux recebe o proximo
        }while(aux != NULL); //enquanto aux for diferente de NULL
    }
}

//função para criar contatos estaticos
void ContatosEstaticos(Inicio * agenda, Contato * contato1, Contato * contato2, Contato * contato3, Contato * contato4, Contato * contato5 ){
    
    contato1 = criador(contato1, "Carlos Felipe Barbosa", "carlos.barbosa@gmail.com", "Rua Goias", 100, "Country Club", "Pocos de Caldas", "35", "92934565", "19", "92939854"); //chama a função criador e cria um contato estatico
    contato2 = criador(contato2, "Maria Clara Martins Marinelli", "marialinda@gmail.com", "Rua Sao Paulo", 200, "Azaleias", "Pocos de Caldas", "16", "93457812", "35", "87460128"); //chama a função criador e cria um contato estatico
    contato3 = criador(contato3, "Celso Augusto de Oliveira Junior", "celso.oliveira@gmail.com", "Rua Guarapiraca", 300, "Jardim Paraiso", "Espirito Santo do Pinhal", "36", "87230912", "19", "93475901"); //chama a função criador e cria um contato estatico
    contato4 = criador(contato4, "Luca Samuel dos Santos", "lucaReidelas@gmail.com", "Rua Prefeito Clepf", 400, "Jardim Belo Horizonte", "Sao Goncalo", "19", "99374918", "35", "98345681"); //chama a função criador e cria um contato estatico
    contato5 = criador(contato5, "Kauan Felipe Simao", "kauanzinApelao@gmail.com", "Rua Finlandia do Sul", 500, "Barra da Tijuca", "Capitolio", "11", "98473018", "35", "89273801"); //chama a função criador e cria um contato estatico

    adicionarPrimeiro(agenda, contato1); //chama a função adicionarPrimeiro e adiciona o contato1
    adicionarUltimo(agenda, contato2); //chama a função adicionarUltimo e adiciona o contato2
    adicionarUltimo(agenda, contato3); //chama a função adicionarUltimo e adiciona o contato3
    adicionarUltimo(agenda, contato4); //chama a função adicionarUltimo e adiciona o contato4
    adicionarUltimo(agenda, contato5); //chama a função adicionarUltimo e adiciona o contato5

}


//função para criar contatos
Contato * criador( Contato * contato, char nome[], char email[], char rua[], int numero, char bairro[], char cidade[], char ddd1[], char numero1[], char ddd2[], char numero2[]){

    contato = (Contato *) malloc(sizeof(Contato)); //aloca memoria para o contato

    if (contato == NULL) //se o contato for igual a NULL
    {
         printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Nao foi possivel alocar contato\n"); //imprime uma mensagem para o usuario
         printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        exit(1); //encerra o programa
    }

    strcpy(contato->nome, nome); //copia o nome para o contato
    strcpy(contato->email, email); //copia o email para o contato
    strcpy(contato->endereco.rua, rua); //copia a rua para o contato
    contato->endereco.numero = numero; //copia o numero para o contato
    strcpy(contato->endereco.bairro, bairro); //copia o bairro para o contato
    strcpy(contato->endereco.cidade, cidade); //copia a cidade para o contato
    strcpy(contato->telefone[0].ddd, ddd1); //copia o ddd1 para o contato
    strcpy(contato->telefone[0].numero, numero1); //copia o numero1 para o contato 
    strcpy(contato->telefone[1].ddd, ddd2); //copia o ddd2 para o contato 
    strcpy(contato->telefone[1].numero, numero2); //copia o numero2 para o contato
 
    contato->proximo = NULL; //o proximo do contato recebe NULL

    return contato; //retorna o contato

}

Contato *preencherContato() //função para preencher o contato
{

    Contato * novoContato = (Contato *) malloc(sizeof(Contato)); //aloca memoria para o novoContato

    //imprime uma mensagem para o usuario para preencher o contato
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Digite o nome: "); 
    scanf(" %50[^\n]s", novoContato->nome); //le o nome do contato limitando a 50 caracteres e ignorando o \n do buffer
    printf("Digite o email: ");
    scanf(" %30[^\n]s", novoContato->email); //le o email do contato limitando a 30 caracteres e ignorando o \n do buffer
    printf("Digite o seu bairro: ");
    scanf(" %50[^\n]s", novoContato->endereco.bairro); //le o bairro do contato limitando a 50 caracteres e ignorando o \n do buffer
    printf("Digite o nome da sua rua: ");
    scanf(" %50[^\n]s", novoContato->endereco.rua); //le a rua do contato limitando a 50 caracteres e ignorando o \n do buffer
    printf("Digite o numero da sua casa: ");
    scanf("%d", &novoContato->endereco.numero); //le o numero da casa do contato
    printf("Digite a sua cidade: "); 
    scanf(" %50[^\n]s", novoContato->endereco.cidade); //le a cidade do contato limitando a 50 caracteres e ignorando o \n do buffer
    printf("Digite o seu celular (<xx> <xxxxxxxxx>): ");
    scanf("%2s %s", novoContato->telefone[0].ddd, novoContato->telefone[0].numero); //le o ddd e o numero do celular limitando a 2 e 9 caracteres respectivamente
    printf("Digite o seu telefone (<xx> <xxxxxxxxx>): ");
    scanf("%2s %s", novoContato->telefone[1].ddd, novoContato->telefone[1].numero); //le o ddd e o numero do telefone limitando a 2 e 9 caracteres respectivamente
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");

    novoContato->proximo = NULL; //o proximo do novoContato recebe NULL

    return novoContato; //retorna o novoContato

}

void adicionarPrimeiro(Inicio * agenda, Contato * contato){ //função para adicionar um contato na primeira posição

    Contato * novoContato = contato; //cria um ponteiro novoContato e inicia ele com o contato

    if(agenda->inicio == NULL){ //se o inicio for igual a NULL
        agenda->inicio = novoContato; //o inicio recebe o novoContato
    }else{ //senão
        novoContato->proximo = agenda->inicio; //o proximo do novoContato recebe o inicio
        agenda->inicio = novoContato; //o inicio recebe o novoContato
    }
    agenda->tamanho++; //incrementa o tamanho da agenda
}

void adicionarUltimo(Inicio * agenda, Contato * contato){ //função para adicionar um contato na ultima posição

    Contato * novoContato = contato; //cria um ponteiro novoContato e inicia ele com o contato

    if(agenda->inicio == NULL){ //se o inicio for igual a NULL
        agenda->inicio = novoContato; //o inicio recebe o novoContato
    }else{ //senão
        Contato * aux = agenda->inicio; //cria um ponteiro auxiliar e inicia ele com o inicio
        while(aux->proximo != NULL){ //enquanto o proximo do aux for diferente de NULL
            aux = aux->proximo; //aux recebe o proximo
        }
        aux->proximo = novoContato; //o proximo do aux recebe o novoContato
    }

    agenda->tamanho++; //incrementa o tamanho da agenda
}

void adicionarQualquer(Inicio * agenda, Contato * contato, int posicao){ //função para adicionar um contato em qualquer posição

    if(posicao < 1) //se a posição for menor que 1
    {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Impossivel inserir elementos em posicoes negativas ou nulas!\n"); //imprime uma mensagem para o usuario
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        return; //retorna para a função main
    }

    Contato * atual = agenda->inicio; //cria um ponteiro atual e inicia ele com o inicio
    Contato * proximo = atual; //cria um ponteiro proximo e inicia ele com o atual
    
    if(posicao == 1) //se a posição for igual a 1
    {
        if(agenda->inicio == NULL){ //se o inicio for igual a NULL
            agenda->inicio = contato; //o inicio recebe o contato
        }else{ //senão
            contato->proximo = agenda->inicio; //o proximo do contato recebe o inicio
            agenda->inicio = contato; //o inicio recebe o contato
        }
        agenda->tamanho++; //incrementa o tamanho da agenda

        return; //retorna para a função main
    }

    if(posicao > agenda->tamanho) { //se a posição for maior que o tamanho da agenda
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Posicao inexistente!\n"); //imprime uma mensagem para o usuario
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        return; //retorna para a função main
    } 
    
    int contador = 1; //cria uma variavel do tipo inteiro e inicia ela com 1
    
    while(atual->proximo != NULL) { //enquanto o proximo do atual for diferente de NULL

        if(contador == posicao){ //se o contador for igual a posição
            atual->proximo = contato; //o proximo do atual recebe o contato
            contato->proximo = proximo; //o proximo do contato recebe o proximo
            agenda->tamanho++; //incrementa o tamanho da agenda
            return; //retorna para a função main
        }
        atual = proximo; //atual recebe o proximo
        proximo = proximo->proximo; //proximo recebe o proximo
        contador++; //incrementa o contador
    }
}

void removerPrimeiro(Inicio * agenda){ //função para remover o primeiro contato

   if(agenda->inicio == NULL){ //se o inicio for igual a NULL
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Agenda vazia!\n"); //imprime uma mensagem para o usuario
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
  }else{ //senão
    Contato * aux = agenda->inicio; //cria um ponteiro auxiliar e inicia ele com o inicio
    agenda->inicio = aux->proximo; //o inicio recebe o proximo do aux
    free(aux); //libera o aux
   }

   agenda->tamanho--; //decrementa o tamanho da agenda

}

void removerUltimo(Inicio * agenda){ //função para remover o ultimo contato

    if(agenda->inicio == NULL){ //se o inicio for igual a NULL
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Agenda vazia!\n"); //imprime uma mensagem para o usuario
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }else{ //senão
        Contato * aux = agenda->inicio; //cria um ponteiro auxiliar e inicia ele com o inicio
        while(aux->proximo->proximo != NULL){ //enquanto o proximo do proximo do aux for diferente de NULL
            aux = aux->proximo; //aux recebe o proximo
        }
        free(aux->proximo); //libera o proximo do aux
        aux->proximo = NULL; //o proximo do aux recebe NULL
    }

    agenda->tamanho--; //decrementa o tamanho da agenda

}

void removerQualquer(Inicio * agenda){ //função para remover um contato em qualquer posição

    if(agenda->inicio == NULL){ //se o inicio for igual a NULL
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Agenda vazia!\n"); //imprime uma mensagem para o usuario
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }else{ //senão
        int posicao = 0; //cria uma variavel do tipo inteiro e inicia ela com 0
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("(OBS: A primeira posicao eh 0)\n " //imprime uma mensagem para o usuario
        "Digite a posicao que deseja remover o contato: "); //imprime uma mensagem para o usuario
        scanf("%d", &posicao); //le a posição escolhida pelo usuario

        Contato * aux = agenda->inicio; //cria um ponteiro auxiliar e inicia ele com o inicio
        Contato * aux2 = aux->proximo; //cria um segundo ponteiro auxiliar e inicia ele com o proximo do aux
        for(int i = 0; i < posicao - 1; i++){ //inicia um laço de repetição
            aux = aux->proximo; //aux recebe o proximo
            aux2 = aux2->proximo; //aux2 recebe o proximo
        }
        aux->proximo = aux2->proximo; //o proximo do aux recebe o proximo do aux2
        free(aux2); //libera o aux2
    }

    agenda->tamanho--; //decrementa o tamanho da agenda

}

void editarContato(Inicio *agenda){ //função para editar um contato

    if(agenda->inicio == NULL){ //se o inicio for igual a NULL
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Agenda vazia!\n"); //imprime uma mensagem para o usuario
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }else{ //senão
        char nome[LIMIT_NOME]; //cria uma variavel do tipo string
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Digite o nome que deseja editar: "); //imprime uma mensagem para o usuario
        scanf(" %50[^\n]s", nome); //le o nome do contato limitando a 50 caracteres e ignorando o \n do buffer
        printf("------------------------------------------------------------------------------------------------------------------------\n");

        Contato * aux = agenda->inicio; //cria um ponteiro auxiliar e inicia ele com o inicio
        int encontrado = 0; //cria uma variavel do tipo inteiro e inicia ela com 0
        while(aux != NULL){ //enquanto o aux for diferente de NULL
            if(strcmpi(aux->nome, nome) == 0){ //se o nome do aux for igual ao nome
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Digite o novo nome: ");
                scanf(" %50[^\n]s", aux->nome); //le o nome do contato limitando a 50 caracteres e ignorando o \n do buffer
                printf("Digite o novo email: ");
                scanf(" %30[^\n]s", aux->email); //le o email do contato limitando a 30 caracteres e ignorando o \n do buffer
                printf("Digite o novo bairro: ");
                scanf(" %50[^\n]s", aux->endereco.bairro); //le o bairro do contato limitando a 50 caracteres e ignorando o \n do buffer
                printf("Digite o novo nome da rua: "); 
                scanf(" %50[^\n]s", aux->endereco.rua); //le a rua do contato limitando a 50 caracteres e ignorando o \n do buffer
                printf("Digite o novo numero da casa: ");
                scanf("%d", &aux->endereco.numero); //le o numero da casa do contato
                printf("Digite a nova cidade: "); 
                scanf(" %50[^\n]s", aux->endereco.cidade); //le a cidade do contato limitando a 50 caracteres e ignorando o \n do buffer
                printf("Digite o novo celular (<xx> <xxxxxxxxx>): "); 
                scanf("%2s %9s", aux->telefone[0].ddd, aux->telefone[0].numero); //le o ddd e o numero do celular limitando a 2 e 9 caracteres respectivamente
                printf("Digite o novo telefone (<xx> <xxxxxxxxx>): ");
                scanf("%2s %9s", aux->telefone[1].ddd, aux->telefone[1].numero); //le o ddd e o numero do telefone limitando a 2 e 9 caracteres respectivamente
                printf("------------------------------------------------------------------------------------------------------------------------\n\n");
                encontrado = 1; //encontrado recebe 1
            }
            aux = aux->proximo; //aux recebe o proximo
        }
        if (!encontrado) { //se não encontrado
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Contato nao encontrado!\n"); //imprime uma mensagem para o usuario
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        }
    }
}

void buscarContato(Inicio * agenda){ //função para buscar um contato

    if(agenda->inicio == NULL){ //se o inicio for igual a NULL
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Agenda vazia!\n"); //imprime uma mensagem para o usuario
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    }else{ //senão
        char nome[LIMIT_NOME]; //cria uma variavel do tipo string
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Digite o nome (completo) que deseja buscar: "); //imprime uma mensagem para o usuario
        scanf(" %50[^\n]s", nome); //le o nome do contato limitando a 50 caracteres e ignorando o \n do buffer

        Contato * aux = agenda->inicio; //cria um ponteiro auxiliar e inicia ele com o inicio
        int encontrado = 0; //cria uma variavel do tipo inteiro e inicia ela com 0

        while(aux != NULL){ //enquanto o aux for diferente de NULL
            if(strcmpi(aux->nome, nome) == 0){ //se o nome do aux for igual ao nome existente na agenda
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Nome: %s\n", aux->nome); //imprime o nome do contato
                printf("Email: %s\n", aux->email); //imprime o email do contato
                printf("Endereco: %s, %s - n: %d, %s\n", aux->endereco.bairro, aux->endereco.rua, aux->endereco.numero, aux->endereco.cidade); //imprime o endereco do contato
                printf("Celular: (%s) %s\n", aux->telefone[0].ddd, aux->telefone[0].numero); //imprime o celular do contato
                printf("Telefone: (%s) %s\n", aux->telefone[1].ddd, aux->telefone[1].numero); //imprime o telefone do contato
                printf("\n"); 
                encontrado = 1; //encontrado recebe 1
            }
            aux = aux->proximo; //aux recebe o proximo
        }
        if (!encontrado) { //se não encontrado
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Contato nao encontrado!\n"); //imprime uma mensagem para o usuario
            printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        }
    }
}