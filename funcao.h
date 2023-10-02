#ifndef FUNCAO_H //verifica se o arquivo funcao.h ja foi chamado
#define FUNCAO_H //define o arquivo funcao.h
#include "struct.h" //chamativa do arquivo struct.h

//cria um contato e preenche ele com os dados passados por parametro
//retorna um ponteiro do tipo Contato com os dados preenchidos 
Contato * criador( Contato * contato, char nome[], char email[], char rua[], int numero, char bairro[], char cidade[], char ddd1[], char numero1[], char ddd2[], char numero2[]); 

//cria um ponteiro do tipo Contato e aloca memoria para ele
Contato * preencherContato();

void imprimirContatos(Inicio * inicio); //imprime todos os contatos da lista

void adicionarPrimeiro(Inicio * agenda, Contato * contato); //adiciona um contato na primeira posição da lista

void adicionarUltimo(Inicio * agenda, Contato * contato); //adiciona um contato na ultima posição da lista

void adicionarQualquer(Inicio * agenda, Contato * contato, int posicao); //adiciona um contato em qualquer posição da lista

void removerPrimeiro(Inicio * agenda); //remove o primeiro contato da lista

void removerUltimo(Inicio * agenda); //remove o ultimo contato da lista

void removerQualquer(Inicio * agenda); //remove um contato em qualquer posição da lista

void editarContato(Inicio * agenda); //edita um contato em qualquer posição da lista

void buscarContato(Inicio * agenda); //busca um contato em qualquer posição da lista

//cria 5 contatos estaticos e preenche eles com os dados passados por parametro
void ContatosEstaticos(Inicio * agenda, Contato * contato1, Contato * contato2, Contato * contato3, Contato * contato4, Contato * contato5);

#endif //fecha o ifndef