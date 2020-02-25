/* Nama: Farras Mohammad Hibban Faddila */
/* NIM: 13518017 */


#include "listdp.h"
#define Nil 0

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return (First(L)==Nil && Last(L)==Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
	Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	/* KAMUS LOKAL */
	address P;
	/* ALGORITMA */
	P = (address) malloc (sizeof(address));
	Info(P) = X;
	Next(P) = Nil;
	Prev(P) = Nil;
	return P; 
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
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
	if(P==Nil) return Nil;
	while( Info(P) != X && Next(P) != Nil){
		P = Next(P);
	}

	if (Info(P)==X) return P;
	else return Nil;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	/* KAMUS LOKAL */
	address P, PNew;
	/* ALGORITMA */
	// P = First(*L);
	PNew = Alokasi(X);
	// Next(PNew) = P;
	// Prev(PNew) = Nil;
	// First(*L) = PNew;
	// if(P!=Nil) Prev(P) = PNew;
	// if(P==Nil) Last(*L) = PNew;
	if(PNew!=Nil) InsertFirst(L,PNew);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	/* KAMUS LOKAL */
	address P, PNew;
	/* ALGORITMA */
	// P = Last(*L);
	PNew = Alokasi(X);
	// Prev(PNew) = P;
	// Last(*L) = PNew;
	// if(P!=Nil) Next(P) = PNew;
	// Next(PNew) = Nil;
	// if(P==Nil) First(*L) = PNew;
	if(PNew!=Nil) InsertLast(L,PNew);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	/* KAMUS LOKAL */
	address P;
	/* ALGORITMA */
	// P = First(*L);
	DelFirst(L,&P);
	*X = Info(P);
	// First(*L) = Next(P);
	// if(Next(P)!=Nil) Prev(Next(P))==Nil;
	// if(Next(P)==Nil) Last(*L)=Nil;
	Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	/* KAMUS LOKAL */
	address P;
	/* ALGORITMA */
	// P = Last(*L);
	DelLast(L,&P);
	*X = Info(P);
	// Last(*L) = Prev(P);
	// if(Prev(P)!=Nil) Next(Prev(P))==Nil;
	// if(Prev(P)==Nil) First(*L)=Nil;
	Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	Q = First(*L);
	Next(P) = Q;
	if(IsEmpty(*L)) Last(*L) = P;
	else {
		Prev(Q) = P;
	}
	First(*L) = P;
	Prev(P) = Nil;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	Q = Last(*L);
	Prev(P) = Q;
	if(IsEmpty(*L)) First(*L) = P;
	else {
		Next(Q) = P;
	}
	Last(*L) = P;
	Next(P) = Nil;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	Q = First(*L);
	while(Q != Prec){
		Q = Next(Q);
	}
	if(Last(*L)==Q) Last(*L) = P;
	if(Next(Q)!=Nil) Prev(Next(Q)) = P;
	Next(P) = Next(Q);
	Next(Q) = P;
	Prev(P) = Q;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	Q = Last(*L);
	while(Q != Succ){
		Q = Prev(Q);
	}
	if(First(*L)==Q) First(*L) = P;
	if(Prev(Q)!=Nil) Next(Prev(Q)) = P;
	Prev(P) = Prev(Q);
	Prev(Q) = P;
	Next(P) = Q;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	/* ALGORITMA */
	*P = First(*L);
	if(*P == Last(*L)) Last(*L) = Prev(*P);
	First(*L) = Next(*P);
	if(Next(*P)!=Nil) Prev(Next(*P)) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
	/* ALGORITMA */
	*P = Last(*L);
	if(*P == First(*L)) First(*L) = Next(*P);
	Last(*L) = Prev(*P);
	if(Prev(*P)!=Nil) Next(Prev(*P)) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
	/* KAMUS LOKAL */
	address Q, P;
	/* ALGORITMA */

	// if(!IsEmpty(*L)){
	// 	Q = First(*L);

	// 	if(Info(Q)==X) {First(*L) = Next(Q); if(Next(Q)!=Nil) Prev(Next(Q))=Nil; if(Q != Nil) Dealokasi(Q);}
	// 	else {
	// 		QPrev = Q;
	// 		Q = Next(Q);
	// 		while(Q != Nil && Info(Q) != X){
	// 			QPrev = Q;
	// 			Q = Next(Q);
	// 		}
	// 		if(Q != Nil){
	// 			if(Info(Q) == X) {
	// 				Next(QPrev) = Next(Q); 
	// 				if(Next(Q)!=Nil) Prev(Next(Q))=QPrev; 
	// 				if(Last(*L)==Q) Last(*L) = QPrev;
	// 				if(Q != Nil) Dealokasi(Q);
	// 			}
	// 		}
	// 	}

	// }

	if(Search(*L,X)!=Nil){
		Q = First(*L);
		if(X == Info(Q)) DelVFirst(L,&X);
		else {
			while(Info(Next(Q))!=X){
				Q = Next(Q);
			}
			DelAfter(L,&P,Q);
			Dealokasi(P);
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	// Q = First(*L);
	// if(Q!=Nil){
	// 	while(Q != Prec){
	// 		Q = Next(Q);
	// 	}
	// 	*Pdel = Next(Q);
	// 	if(Last(*L)==*Pdel) Last(*L) = Q;
	// 	if(Last(*L)!=Q){
	// 		if(*Pdel != Nil){
	// 			Next(Q) = Next(*Pdel);
	// 			if(Next(*Pdel)!=Nil) Prev(Next(*Pdel)) = Q;
	// 		}
	// 	}
		
	// }
	*Pdel = Next(Prec);
	if(*Pdel!=Nil){
		if(Next(*Pdel)==Nil) Last(*L)=Prec;
		else {
			Prev(Next(*Pdel)) = Prec;
		}
		Next(Prec) = Next(*Pdel);
	}
	
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	// Q = Last(*L);
	// if(Q!=Nil){
	// 	while(Q != Succ){
	// 		Q = Prev(Q);
	// 	}
	// 	*Pdel = Prev(Q);
	// 	if(First(*L)==*Pdel) First(*L) = Q;
	// 	if(First(*L)!=Q){
	// 		if(*Pdel != Nil){
	// 			Prev(Q) = Prev(*Pdel);
	// 			if(Prev(*Pdel)!=Nil) Next(Prev(*Pdel)) = Q;
	// 		}
	// 	}
	// }
	*Pdel = Prev(Succ);
	if(*Pdel!=Nil){
		if(Prev(*Pdel)==Nil) First(*L)=Succ;
		else {
			Next(Prev(*Pdel)) = Succ;
		}
		Prev(Succ) = Prev(*Pdel);
	}
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	if(IsEmpty(L)) printf("[]");
	else {
		Q = First(L);
		printf("[%d", Info(Q));
		Q = Next(Q);
		while(Q != Nil){
			printf(",%d", Info(Q));
			Q = Next(Q);
		}
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	if(IsEmpty(L)) printf("[]");
	else {
		Q = Last(L);
		printf("[%d", Info(Q));
		Q = Prev(Q);
		while(Q != Nil){
			printf(",%d", Info(Q));
			Q = Prev(Q);
		}
		printf("]");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */