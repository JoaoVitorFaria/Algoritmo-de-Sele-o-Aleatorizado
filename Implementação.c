#include<stdio.h>
#include<stdlib.h>

int particao(int vetor[], int l, int r){
	int pivot =vetor[l];
	int i=l+1;
	int j;
	for( j=l+1;j<=r;j++){
		if(vetor[j]<pivot){
			int temp=vetor[j];
			vetor[j]=vetor[i];
			vetor[i]=temp;
			i=i+1;
		}
	}
	int temp=vetor[l];
	vetor[l]=vetor[i-1];
	vetor[i-1]=temp;
	return i-1;
	
}


int selecao(int vetor[],int l, int r, int procura){
	if(l==r)return vetor[l];
	int p=particao(vetor, l,r);
	int j=p-l+1;
	if(j==procura)return vetor[p];
	else if(j>procura)return selecao(vetor,l, p-1, procura);
	else if (j<procura)return selecao(vetor, p+1, r, procura-j);
	return 0;
}

int main(){
	int tamanho;
	scanf("%d", &tamanho);
	int * vetor;
	vetor = (int*) malloc(tamanho*sizeof(int));
	int l, r, procura;
	procura = tamanho/2;
    if(tamanho%2==1)procura = procura+1;
    srand(48+tamanho);
	l=0;
	r=tamanho-1;
	int j;
	for(j=0;j<tamanho;j++)vetor[j]=rand();
	int resposta=selecao(vetor, l, r, procura);
	printf("%d\n", resposta);
	return 0;
}