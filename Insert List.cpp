#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string>

int HEAP[100000],N;

void Init(){
	N = 0;
	HEAP[0]= -1;
}

int insert (int val){
	int PAR, temp;
	N=N+1;
	HEAP[N]=val;
	int POS=N;
	
	while(POS>1){
		PAR=POS/2;
		if (HEAP[POS] <= HEAP[PAR]){
			goto x;
		}
		else{
			temp = HEAP[POS];
			HEAP[POS]=HEAP[PAR];
			HEAP[PAR]=temp;
		}
		x:return(N);
	}
}

int main(){
	int val,N;
	int Nilai;
	char hasil;
	N=0;
	while (val!=-1){
		printf("Input nilai node: ");
		scanf("%d", &val);
		insert(val);
		N=N+1;
	}
	for(int i=1;i<N;i++){
		Nilai=HEAP[i];
		printf("Hasil= %i\n", Nilai);
	}
}




