/* Nama: Farras Mohammad Hibban Faddila/
/* NIM: 13518017*/

#include<stdio.h>
#include "prioqueuechar.h"

int main(){

	int N,pri;
	char inf;
	PrioQueueChar pq;
	infotype X,Y;
	int cur=1;
	boolean masih;

	scanf("%d", &N);
	CreateEmpty(&pq,N);

	for(int i=1; i<=N; i++){
		scanf("%d %c", &pri, &inf);
		X.prio = pri;
		X.info = inf;
		Add(&pq,X);
		printf("sekarang topnya adalah %d  ", Prio(InfoHead(pq)));

		for(int j=1; j<=i; j++){
			printf( "%d " ,Elmt(pq,j).prio);
		}
		printf("\n");
	}

	return 0;
}