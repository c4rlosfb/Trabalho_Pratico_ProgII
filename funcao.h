#ifndef FUNCAO_H
#define FUNCAO_H
#include "struct.h"

Contato * criador( Contato * contato, char nome[], char email[], char rua[], int numero, char bairro[], char cidade[], char ddd1[], char numero1[], char ddd2[], char numero2[]);

Contato * preencherContato();

void imprimirContatos(Inicio * inicio);

void adicionarPrimeiro(Inicio * agenda, Contato * contato);

void adicionarUltimo(Inicio * agenda, Contato * contato);

void adicionarQualquer(Inicio * agenda, Contato * contato, int posicao);

void removerPrimeiro(Inicio * agenda);

void removerUltimo(Inicio * agenda);

void removerQualquer(Inicio * agenda);

void editarContato(Inicio * agenda);

void buscarContato(Inicio * agenda);

void ContatosEstaticos(Inicio * agenda, Contato * contato1, Contato * contato2, Contato * contato3, Contato * contato4, Contato * contato5); //complicado porém certo

#endif