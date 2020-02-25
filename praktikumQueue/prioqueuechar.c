/* Nama: Farras Mohammad Hibban Faddila*/
/* NIM: 13518017*/

#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
	return (Head(Q) == Nil && Tail(Q)==Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFull (PrioQueueChar Q){
	return ( (Tail(Q)%(Q.MaxEl) + 1) == Head(Q) );
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (PrioQueueChar Q){
	int ans;
	if(IsEmpty(Q)){
		ans = 0;
	} else {
		ans = Tail(Q)-Head(Q)+1;
		if(ans<=0) ans += Q.MaxEl;
	}
	return ans;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max){
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
	(*Q).T = (int *) malloc ((Max+1) * sizeof(infotype));
	MaxEl(*Q) = Max;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
	free((*Q).T);
	MaxEl(*Q)=0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X){

	int j,i;
	infotype temp;

	if(IsEmpty(*Q)){
		Head(*Q)++;
		Tail(*Q)++;
		InfoTail(*Q).prio = X.prio;
		InfoTail(*Q).info = X.info;
	} else {
		i = Tail(*Q);
		j = (i%MaxEl(*Q))+1;
		Tail(*Q) = (Tail(*Q)%MaxEl(*Q))+1;
		InfoTail(*Q).prio = X.prio;
		InfoTail(*Q).info = X.info;
		while (Prio(Elmt(*Q,i)) > Prio(X) && j!=Head(*Q)){
			temp.prio = Elmt(*Q,i).prio;
			temp.info = Elmt(*Q,i).info;
			Elmt(*Q,i).prio = X.prio;
			Elmt(*Q,i).info = X.info;
			Elmt(*Q,j).prio = temp.prio;
			Elmt(*Q,j).info = temp.info;
			j = i;
			i--;
			if(i==0) i+= MaxEl(*Q);
		}
	}
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void Del (PrioQueueChar * Q, infotype * X){
	(*X).info = InfoHead(*Q).info;
	(*X).prio = InfoHead(*Q).prio;
	if(NBElmt(*Q)==1){
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	} else {
		Head(*Q)= (Head(*Q)%(*Q).MaxEl + 1);
	}
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */


/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){

	int i=1;
	int idx=Head(Q);
	while(i<=NBElmt(Q)){
		printf("%d %c\n", Prio(Elmt(Q,idx)), Info(Elmt(Q,idx)));
		idx %= MaxEl(Q);
		idx++;
		i++;
	}
	printf("#\n");

}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/