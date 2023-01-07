#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct nodo{
	int value;
	struct nodo *left;
	struct nodo *right;
};

typedef struct nodo Nodo;

Nodo* create(int value);
void createRoot(int value);
void add(int value);
void showFromRoot();
void showIncreasing();
void showDescending();
void removeTree(int value);

#endif
