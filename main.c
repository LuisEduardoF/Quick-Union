#include <stdio.h>
#define TAM 10
int root(int atual, int vetor[TAM]){
	if(vetor[atual] == atual)
		return atual;
	else
		return root(vetor[atual], vetor);
}
void connect(int atual, int target, int vetor[TAM]){
	vetor[root(atual, vetor)] = root(target, vetor);
}
int isConnected(int A, int B, int vetor[TAM]){
	if(root(A, vetor) == root(B, vetor)){
		return 1;
	}
	else{
		return 0;
	}
}
void printArray(int vetor[TAM]){
	for(int i = 0; i < TAM; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}
int main() {
  int vetor[TAM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  connect(4, 3, vetor);
  connect(3, 8, vetor);
  connect(6, 5, vetor);
  connect(9, 4, vetor);
  connect(2, 1, vetor);
  connect(5, 0, vetor);
  connect(7, 2, vetor);
  connect(6, 1, vetor);
  connect(7, 3, vetor);
  
  for(int i = 0; i < TAM; i++){
	  for(int j = 0; j < TAM; j++){
		  if(i != j){
		  printf("Is %d connected with %d ? ", i, j);
		  if(isConnected(i, j, vetor))
		  	printf("YES\n");
		  else
		  	printf("NO\n");
		  }
	  }
  }
}