#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int value;
	struct nodo *left;
	struct nodo *right;
};

typedef struct nodo Nodo;

Nodo* create(int value){
	Nodo *n = malloc(sizeof(Nodo));
	n->value = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void add(Nodo *n, int value){
	if ( value< n->value){
		if (n->left == NULL){
			n->left = create(value);
		}else{
			add(n->left, value);
		}
	}else{
		if (n->right == NULL){
			n->right = create(value);
		}else{
			add(n->right, value);
		}
	}
}

void showFromRoot(Nodo *n){
    if(n == NULL){
        return ;
    }else{
		printf("\n%d\n",n->value);
		showFromRoot(n->left);
        showFromRoot(n->right);
    }
}

void showIncreasing(Nodo *n){
    if(n == NULL){
        return ;
    }else{
		showIncreasing(n->left);
        printf("\n%d\n",n->value);
        showIncreasing(n->right);
    }
}

void showDescending(Nodo *n){
    if(n == NULL){
        return ;
    }else{
		showDescending(n->right);
        printf("\n%d\n",n->value);
        showDescending(n->left);
    }
}

int main(void) {
  	
	Nodo *root = create(5);

	add(root,10);
	add(root,1);
	add(root,3);
	add(root,7);
	add(root,9);
	add(root,2);

	printf("-------------show from root-------\n");
    showFromRoot(root);
	printf("----------------------------------\n");
	printf("-------------show increasing------\n");
    showIncreasing(root);
	printf("----------------------------------\n");
	printf("-------------show descending------\n");
    showDescending(root);
	printf("----------------------------------\n");

  	return 0;
}