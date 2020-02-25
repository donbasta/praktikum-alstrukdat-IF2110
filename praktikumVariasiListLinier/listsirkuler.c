/* Nama: Farras Mohammad Hibban Faddila */
/* NIM: 13518017 */

#include "listsirkuler.h"
#define Nil 0

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return First(L) == Nil;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	/* KAMUS LOKAL */
	address P;
	/* ALGORITMA */
	P = (infotype *) malloc (sizeof(infotype));
	Info(P) = X;
	Next(P) = Nil;
	return P; 
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P){
	/* ALGORITMA */
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	/* KAMUS LOKAL */
	address P;
	/* ALGORITMA */
	P = First(L);
	while( Info(P) != X && Next(P) != First(L)){
		P = Next(P);
	}

	if (Info(P)==X) return P;
	else return Nil;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	/* KAMUS LOKAL */
	address P, Q, PNew;
	/* ALGORITMA */
	P = First(*L);
	PNew = Alokasi(X);
	First(*L) = PNew;
	if(P!=Nil){
		Next(PNew) = P;
		Q = P;
		while(Next(Q)!=P){
			Q = Next(Q);
		}
		Next(Q) = PNew;
	} else {
		Next(PNew) = PNew;
	}
	
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address P,Q,PNew;
	P = First(*L);
	PNew = Alokasi(X);
	Q = P;
	while(Next(Q)!=P){
		Q = Next(Q);
	}
	Next(Q) = PNew;
	Next(PNew) = P;
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){

	address P,Q;

	P = First(*L);
	*X = Info(P);
	if(Next(P)==P){
		First(*L) = Nil;
		Dealokasi(P);
	} else {
		Q = First(*L);
		while(Next(Q)!=First(*L)){
			Q = Next(Q);
		}
		First(*L) = Next(P);
		Next(Q) = First(*L);
		Dealokasi(P);
	}
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X){

	address P;

	// P = First(*L);
	// Q = P;
	// if(Next(Q)==P){
	// 	First(*L) = Nil;
	// 	Dealokasi(P);
	// } else {
	// 	QPrev = Q;
	// 	Q = Next(Q);
	// 	while(Next(Q)!=P){
	// 		QPrev = Q;
	// 		Q = Next(Q);
	// 	}
	// 	Next(QPrev) = P;
	// 	Dealokasi(Q);
	// }

	DelLast(L,&P);
	*X = Info(P);
	Dealokasi(P);
	
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	/* KAMUS LOKAL */
	address P1, Q;
	/* ALGORITMA */
	P1 = First(*L);
	if(P1==Nil){	
		Next(P) = P;
		First(*L) = P;
	} else {
		First(*L) = P;
		Next(P) = P1;
		Q = P1;
		while(Next(Q)!=P1){
			Q = Next(Q);
		}
		Next(Q) = First(*L);
	}
	
	
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
	address Q;
	if (IsEmpty(*L)) {
	    First(*L) = P;
	    Next(P)=P;
	} else {
	    Q = First(*L);
	    while (Next(Q) != First(*L)) {
	      Q = Next(Q);
	    }
    	Next(Q) = P;
    	Next(P) = First(*L);  
 	}

	
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
	// address Q;
	// Q = First(*L);
	// while(Q!=Prec){
	// 	Q = Next(Q);
	// }
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){

	address Q;

	*P = First(*L);
	
	if(Next(*P)==*P){
		First(*L) = Nil;
		// Dealokasi(P);
	} else {
		Q = *P;
		while(Next(Q)!=*P){
			Q = Next(Q);
		}
		First(*L) = Next(*P);
		Next(Q) = First(*L);

		// Dealokasi(P);
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){

	address Q,QPrev;

	Q = First(*L);
	QPrev = Nil;
	while(Next(Q)!=First(*L)){
		QPrev = Q;
		Q = Next(Q);
	}
	*P = Q;
	if(QPrev==Nil) First(*L)=Nil;
	else Next(QPrev) = First(*L);
	// if(Next(First(*L))==First(*L)){
	// 	*P = First(*L);
	// 	First(*L) = Nil;
	// 	// Dealokasi(P);
	// } else {
	// 	QPrev = First(*L);
	// 	Q = Next(First(*L));
	// 	while(Next(Q)!=First(*L)){
	// 		QPrev = Q;
	// 		Q = Next(Q);
	// 	}
	// 	Next(QPrev) = First(*L);
	// 	// Dealokasi(Q);
	// }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){

	// address Q;

	// Q = First(*L);

	// if(Next(Q)==Q){
	// 	*Pdel = Q;
	// 	First(*L) = Nil;
	// } else {
	// 	while(Q != Prec){
	// 		Q = Next(Q);
	// 	}

	// 	if(Next(Q)==First(*L)){
	// 		*Pdel = First(*L);
	// 		First(*L) = Next(*Pdel);
	// 		Next(Q) = Next(*Pdel);
	// 	} else {
	// 		*Pdel = Next(Q);
	// 		Next(Q) = Next(*Pdel);
	// 	}
	// }

	if (Next(Prec) != First(*L)) {

	    *Pdel = Next(Prec);
	    Next(Prec) = Next(Next(Prec));
	    Next(*Pdel) = Nil;

  	} else {

	    *Pdel = Next(Prec);
	    Next(Prec) = Next(Next(Prec));
	    First(*L) = Prec;
	    Next(*Pdel) = Nil;

  }

}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X){

	address Q,T;

	// Q = First(*L);
	// if(Q != Nil){
	// 	if(Info(Q)==X){
	// 		if(Next(Q)==Q){
	// 			First(*L)=Nil;
	// 		} else {
	// 			T = First(*L);
	// 			First(*L)=Next(T);
	// 			while(Next(Q)!=T){
	// 				Q = Next(Q);
	// 			}
	// 			Next(Q)=First(*L);
	// 		}
	// 		Dealokasi(Q);o
	// 	} else {
	// 		T = Q;
	// 		Q = Next(Q);
	// 		while(Q!=First(*L) && Info(Q) != X){
	// 			T = Q;
	// 			Q = Next(Q);
	// 		}
	// 		if(Info(Q)==X){
	// 			Next(T) = Next(Next(Q));
	// 			Dealokasi(Q);
	// 		}
	// 	}
	// }

	if(Search(*L,X)!=Nil){
		if(Info(First(*L))==X) DelVFirst(L,&X);
		else{
			T = First(*L);
			while(Info(Next(T))!=X) T = Next(T);
			Q = Next(T);
			Next(T) = Next(Q);
			Dealokasi(Q);
		}

		
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	if(IsEmpty(L)) printf("[]");
	else {
		Q = First(L);
		printf("[%d", Info(Q));
		Q = Next(Q);
		while(Q != First(L)){
			printf(",%d", Info(Q));
			Q = Next(Q);
		}
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */