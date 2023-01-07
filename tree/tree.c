#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Nodo *root;

Nodo* create(int value){
	Nodo *n = malloc(sizeof(Nodo));
	n->value = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void createRoot(int value){
	root = create(value);
}

void addPrivate(Nodo *n, int value){
	if ( value< n->value){
		if (n->left == NULL){
			n->left = create(value);
		}else{
			addPrivate(n->left, value);
		}
	}else{
		if (n->right == NULL){
			n->right = create(value);
		}else{
			addPrivate(n->right, value);
		}
	}
}

void add(int value){
	addPrivate(root,value);
}

void showFromRootPrivate(Nodo *n){
    if(n == NULL){
        return ;
    }else{
		printf("\n%d\n",n->value);
		showFromRootPrivate(n->left);
        showFromRootPrivate(n->right);
    }
}

void showFromRoot(){
	showFromRootPrivate(root);
}

void showIncreasingPrivate(Nodo *n){
    if(n == NULL){
        return ;
    }else{
		showIncreasingPrivate(n->left);
        printf("\n%d\n",n->value);
        showIncreasingPrivate(n->right);
    }
}

void showIncreasing(){
	showIncreasingPrivate(root);
}

void showDescendingPrivate(Nodo *n){
    if(n == NULL){
        return ;
    }else{
		showDescendingPrivate(n->right);
        printf("\n%d\n",n->value);
        showDescendingPrivate(n->left);
    }
}

void showDescending(){
	showDescendingPrivate(root);
}


void removePrivate(Nodo *n,int value){
	Nodo *child = n;
	Nodo *father;
	do{
		father = child;
		if(value < child->value){
			child = child->left;
		}
		else if(value > child->value){
			child = child->right;
		}
	} while (child != NULL && child->value != value);

	if (child != NULL){
		if(child->left == NULL && child->right == NULL){
			if(father->left == child){
				father->left = NULL;
			}
			else if(father->right == child){
				father->right = NULL;
			}else{
				printf("Exeption in tree");
			}
		}else if (child->left != NULL && child->right == NULL) {
			if(father->left == child){
				father->left = child->left;
			}
			else if(father->right == child){
				father->right = child->left;
			}else{
				printf("Exeption in tree");
			}
		}else if (child->left == NULL && child->right != NULL) {
			if(father->left == child){
				father->left = child->right;
			}
			else if(father->right == child){
				father->right = child->right;
			}else{
				printf("Exeption in tree");
			}
		}else if (child->left != NULL && child->right != NULL) {
			if(child->left->right == NULL){
				child->value = child->left->value;
				child->left = NULL;
			}else{
				Nodo *p =child->left;
				Nodo *assistant =p;
				while (p->right != NULL){
					assistant = p;
					p = p->right;
				}
				assistant->right = NULL;
				child->value = p->value;
			}
		}else{
			printf("Exeption in tree");
		}
	}
}

void removeTree(int value){
	removePrivate(root,value);
}