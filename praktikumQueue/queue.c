/* Nama: Farras Mohammad Hibban Faddila */
/* NIM: 13518017 */

#include "queue.h"


/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
	return (Head(Q) == Nil && Tail(Q)==Nil);
}

boolean IsFull (Queue Q){
	return ( (Tail(Q)%(Q.MaxEl) + 1) == Head(Q) );
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (Queue Q){
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
void CreateEmpty (Queue * Q, int Max){
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
	(*Q).T = (int *) malloc ((Max+1) * sizeof(int));
	MaxEl(*Q) = Max;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
	free((*Q).T);
	MaxEl(*Q)=0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
	if(IsEmpty(*Q)){
		Head(*Q)++;
		Tail(*Q)++;
		InfoTail(*Q) = X;
	} else {
		Tail(*Q) = Tail(*Q)%(*Q).MaxEl + 1;
		InfoTail(*Q) = X;
	}
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

void Del (Queue * Q, infotype * X){
	(*X) = InfoHead(*Q);
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