#include <stdio.h>

int v[1000];

int comparisonsBinary = 0;
int comparasonsSequential = 0;

void startArray(){
    for (int i = 0; i < 1000; i++){
        v[i] = i+1;
    }
}

int searchSequential(int num){
	for(int i = 0; i < 1000; i++){
        comparasonsSequential++;
		if(v[i] == num){
			return i;
		}
	}
    printf("Elemento não encontrado\n");
}

int searchBinary(int num){
    int proceed = 1;

    int begin = 0;
    int end = 999;

    while (proceed){
        comparisonsBinary++;
        int pivot = (begin + end) /2;
        if(v[pivot] == num){
            int procced = 0;
            return pivot;
        }else {
           if (num > v[pivot]){
                begin = pivot+1;
            }else{
                end = pivot - 1;
            }
        }
        if(begin > end){
            printf("Elemento não encontrado\n");
            proceed = 0;
        }
    }
}


int main(void) {
    startArray();

    int number = 734;
    
    printf("Busca sequencial\n");
	printf("Elemento encontrado na posição: %d\n",searchSequential(number));
    printf("numero de comparações: %d\n",comparasonsSequential);
    printf("------------------------------------------------------------\n");
    printf("Busca binaria\n");
	printf("Elemento encontrado na posição: %d\n",searchBinary(number));
    printf("numero de comparações: %d\n",comparisonsBinary);

	return 0;
}