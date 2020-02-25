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
}