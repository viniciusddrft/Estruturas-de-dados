#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
  int key;
  int value;
} HashTableEntry;

typedef struct {
  HashTableEntry *entries;
} HashTable;

// Função de hash que mapeia um inteiro para uma posição na tabela
int hash(int key) {
  return key % TABLE_SIZE;
}

// Inicializa a tabela hash
void initHashTable(HashTable *table) {
  table->entries = malloc(TABLE_SIZE * sizeof(HashTableEntry));
}

// Adiciona um novo elemento à tabela hash
void addToHashTable(HashTable *table, int key, int value) {
  int index = hash(key);
  table->entries[index].key = key;
  table->entries[index].value = value;
}

// Recupera um elemento da tabela hash
int getFromHashTable(HashTable *table, int key) {
  int index = hash(key);
  return table->entries[index].value;
}


int main(void){
    HashTable table;
    initHashTable(&table);
    addToHashTable(&table,1,215);
    printf("-> %d\n",getFromHashTable(&table,1));
    return 0;
}