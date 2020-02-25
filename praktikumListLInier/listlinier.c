/* Nama: Farras Mohammad Hibban Faddila */
/* NIM: 13518017 */

#include "listlinier.h"
#define Nil 0

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	/* ALGORITMA */
	return (First(L)==Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	/* ALGORITMA */
	First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

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
void Dealokasi (address *P){
	/* ALGORITMA */
	free(*P);
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
	while( Info(P) != X && Next(P) != Nil){
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
	address P, PNew;
	/* ALGORITMA */
	P = First(*L);
	PNew = Alokasi(X);
	Next(PNew) = P;
	First(*L) = PNew;

}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	/* KAMUS LOKAL */
	address P, PNew;
	/* ALGORITMA */
	P = First(*L);
	PNew = Alokasi(X);
	if(P==Nil){
		First(*L) = PNew;
	} else {
		while(Next(P) != Nil){
			P = Next(P);
		}
		Next(P) = PNew;
	}
	Next(PNew) = Nil;

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
	P = First(*L);
	*X = Info(P);
	First(*L) = Next(P);
	Dealokasi(&P);

}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	/* KAMUS LOKAL */
	address P,Prev;
	/* ALGORITMA */
	P = First(*L);

	if(Next(P)==Nil){
		First(*L) = Nil;
	} else {
		while(Next(P) != Nil){
			if(Next(Next(P))==Nil) Prev=P;
			P = Next(P);
		}
		Next(Prev) = Nil;
	}

	*X = Info(P);
	Dealokasi(&P);
	


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
	First(*L) = P;
	Next(P) = Q;

}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	Q = First(*L);
	while(Q != Prec){
		Q = Next(Q);
	}
	Next(P) = Next(Q);
	Next(Q) = P;

}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	Q = First(*L);
	if(Q == Nil){
		First(*L) = P;
	} else {
		while(Next(Q) != Nil){
			Q = Next(Q);
		}
		Next(Q) = P;
		Next(P) = Nil;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	/* ALGORITMA */
	*P = First(*L);
	First(*L) = Next(*P);

}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
	/* KAMUS LOKAL */
	address Q, QPrev;
	/* ALGORITMA */
	Q = First(*L);

	if(!IsEmpty(*L)){
		
		if(Info(Q)==X) {First(*L) = Next(Q); if(Q != Nil) Dealokasi(&Q);}
		else {
			QPrev = Q;
			Q = Next(Q);
			while(Q != Nil && Info(Q) != X){
				QPrev = Q;
				Q = Next(Q);
			}
			if(Q != Nil){
				if(Info(Q) == X) {Next(QPrev) = Next(Q); if(Q != Nil) Dealokasi(&Q);}
			}
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
	/* KAMUS LOKAL */
	address Q, QPrev;
	/* ALGORITMA */
	Q = First(*L);
	if(Next(Q)==Nil){
		*P = Q;
		First(*L) = Nil;
	} else {
		QPrev = Q;
		Q = Next(Q);
		while (Next(Q) != Nil){
			QPrev = Q;
			Q = Next(Q);
		}
		*P = Q;
		Next(QPrev) = Nil;
	}

}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	Q = First(*L);
	while(Q != Prec){
		Q = Next(Q);
	}
	*Pdel = Next(Q);
	if(*Pdel != Nil){
		Next(Q) = Next(*Pdel);
	}

}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

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
		while(Q != Nil){
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
int NbElmt (List L){
	/* KAMUS LOKAL */
	int ans;
	address Q;
	/* ALGORITMA */
	ans = 0;
	Q = First(L);
	while(Q != Nil){
		ans++;
		Q = Next(Q);
	}
	return ans;

}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
	/* KAMUS LOKAL */
	infotype maks;
	address Q;
	/* ALGORITMA */
	Q = First(L);
	maks = Info(Q);
	Q = Next(Q);
	while(Q != Nil){
		if(Info(Q)>maks) maks = Info(Q);
		Q = Next(Q);
	}
	return maks;
}
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
	/* KAMUS LOKAL */
	address Q;
	/* ALGORITMA */
	if(IsEmpty(*L1)){
		First(*L3) = First(*L2); First(*L2) = Nil;
	} else if (IsEmpty(*L2)){
		First(*L3) = First(*L1); First(*L1) = Nil;
	} else if (IsEmpty(*L1) && IsEmpty(*L2)){
		First(*L3) = Nil;
	} else {
		Q = First(*L1); First(*L3) = Q; First(*L1) = Nil;
		while (Next(Q) != Nil){
			Q = Next(Q);
		}
		Next(Q) = First(*L2);
		First(*L2) = Nil;
	}
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */