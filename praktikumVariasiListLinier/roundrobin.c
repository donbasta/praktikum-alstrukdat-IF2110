#include<stdio.h>
#include "listsirkuler.h"

void DeleteRR (List *L, infotype TQ){

	address last;

	if(IsEmpty(*L)){
		printf("List kosong");
		printf("\n");
	} else {
		last = First(*L);
		while(Next(last)!=First(*L)){
			last = Next(last);
		}
		if(Info(last) <= TQ){
			DelLast(L,&last);
			printf("%d", Info(last));
			printf("\n");
		} else {
			Info(last) -= TQ;
			First(*L) = last;
			printf("%d", TQ);
			printf("\n");
		}
	}
}

float Average (List L){

	float total;
	float average;
	float nbElmt;
	address Q;

	Q = First(L);
	total = Info(Q);
	nbElmt = 1;
	Q = Next(Q);
	while(Q != First(L)){
		total += Info(Q);
		nbElmt++;
		Q = Next(Q);
	}
	average = total/nbElmt;
	return average;
}

void cetak(){
	printf("Kode salah");
	printf("\n");
}

int T, proses;
char c;
List RR;

int main(){

	CreateEmpty(&RR);
	scanf("%d", &T);
	while(T<=0){
		scanf("%d", &T);
	}

	boolean benar = true;

	while (benar){

		scanf("%s", &c);

		if(c=='A'){
			scanf("%d", &proses);
			if(proses>0){
				InsVFirst(&RR, proses);
			}
		} 

		else if (c=='D'){
			DeleteRR (&RR, T);
		} 

		else if (c=='F'){
			benar = false;
		} 

		else {
			cetak();
		}

		
	}
	
	if(!IsEmpty(RR)) {printf("%.2f", Average(RR));}
	else {printf("Proses selesai");}

	printf("\n");

	return 0;
}