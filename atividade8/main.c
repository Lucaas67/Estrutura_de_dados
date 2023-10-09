#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);

     No* minhaLista = lista_criar();

    lista_inserir_final(minhaLista, 'A');
    lista_inserir_final(minhaLista, 'B');
    lista_inserir_final(minhaLista, 'C');
    lista_inserir_final(minhaLista, 'A');

    printf("Existência de 'B': %d\n", lista_verificar_existencia(minhaLista, 'B'));
    printf("Existência de 'D': %d\n", lista_verificar_existencia(minhaLista, 'D'));
    printf("Quantidade de 'A's: %d\n", lista_verificar_ocorrencias(minhaLista, 'A'));

    printf("Lista na ordem inversa: ");
    lista_imprimir_inversa(minhaLista);

    lista_inserir_no_i(minhaLista, 2, 'D');
    printf("Lista após inserção na posição 2: ");
    lista_imprimir(minhaLista);

    lista_remover_no_i(minhaLista, 1);
    printf("Lista após remoção da posição 1: ");
    lista_imprimir(minhaLista);

    lista_remover_no(minhaLista, 'A');
    printf("Lista após remoção de 'A's: ");
    lista_imprimir(minhaLista);

    lista_destruir(minhaLista); 

    exit(0);
}