#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_put("chave1", "0");
    hash_table_put("chave2", "1");
    hash_table_put("chave3", "2");

    printf("Valor associado a chave 1: %s\n", hash_table_get("chave1"));
    printf("Valor associado a chave 2: %s\n", hash_table_get("chave2"));
    printf("Valor associado a chave 3: %s\n", hash_table_get("chave3"));

    hash_table_remove("chave2");

    if (hash_table_contains("chave2")) {
        printf("chave 2 ainda está na tabela.\n");
    } else {
        printf("chave 2 foi removida da tabela.\n");
    }

    return 0;
}
