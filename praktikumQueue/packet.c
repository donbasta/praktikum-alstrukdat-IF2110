// /* Nama: Farras Mohammad Hibban Faddila/
// /* NIM: 13518017*/

// #include<stdio.h>
// #include "prioqueuechar.h"

// int main(){

// 	int N,pri;
// 	char inf;
// 	PrioQueueChar pq;
// 	infotype X,Y;
// 	int cur=1;
// 	boolean masih;

// 	scanf("%d", &N);
// 	CreateEmpty(&pq,N);

// 	for(int i=1; i<=N; i++){
// 		scanf("%d %c", &pri, &inf);
// 		X.prio = pri;
// 		X.info = inf;
// 		Add(&pq,X);

// 		masih = true;
// 		while(Prio(InfoHead(pq)) <= cur && masih){
// 			Del(&pq,&Y);
// 			printf("%d %c\n", i, Info(Y), cur);
// 			cur++;
// 			if(IsEmpty(pq)) masih = false;
// 		}
// 	}

// 	return 0;
// }

/* Nama: Farras Mohammad Hibban Faddila */
/* NIM: 13518017*/

#include <stdio.h>
#include "prioqueuechar.h"

typedef struct {
    char info[101];
    int prio[101];
} packet;

int main() {
    int N, cur, pri;
    char inf, belum_masuk;
    packet p;
    belum_masuk = '.';
    scanf("%d", &N);
    for (int i = 1; i <= 100; i++) {
        p.info[i] = belum_masuk;
    }
    cur = 1;
    for (int i = 1; i <= N; i++) {
        scanf("%d %c", &pri, &inf);
        p.info[pri] = inf;
        while(p.info[cur] != belum_masuk){
            printf("%d %c\n", i, p.info[cur]);
            cur++;
        }
    }
    return 0;
}