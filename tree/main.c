#include <stdio.h>
#include "tree.h"

int main(void) {
  	
	createRoot(5);

	add(3);
	add(1);
	add(4);
	add(2);
	add(8);
	removeTree(3);

	printf("-------------show from root-------\n");
    showFromRoot();
	printf("----------------------------------\n");
	printf("-------------show increasing------\n");
    showIncreasing();
	printf("----------------------------------\n");
	printf("-------------show descending------\n");
    showDescending();
	printf("----------------------------------\n");

  	return 0;
}