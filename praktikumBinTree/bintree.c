/* Nama: Farras Mohammad Hibban Faddila */
/* NIM: 13518017 */

#include<stdio.h>
#include "bintree.h"
#include<stdlib.h>
#define Nil 0

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R){
  addrNode P = AlokNode(Akar);
  if(P==Nil) return P;
  else {
    Akar(P) = Akar;
    Left(P) = L;
    Right(P) = R;
    return P;
  }
  
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
  *P = Tree(Akar, L, R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
//BinTree BuildBalanceTree(int n){
 // if(n==0) return Nil;
 // else {
 //   int akar;
 //   BinTree P;
 //   scanf("%d", &akar);
 //   MakeTree(akar, Nil, Nil, &P);
 //   Left(P) = BuildBalanceTree(n-n/2);
 //   Right(P) = BuildBalanceTree(n/2);
 //   return P;

//  }
//}

BinTree BuildBalanceTree(int n)
{
    if (n == 0) return Nil;
    infotype X;
    scanf("%d", &X);
    addrNode temp = AlokNode(X);
    if (temp != Nil) {
        int l, r;
        BinTree L, R;
        l = (n / 2);
        r = (n - n / 2 - 1);
        L = BuildBalanceTree(l);
        R = BuildBalanceTree(r);
        Left(temp) = L;
        Right(temp) = R;
    }
    return temp;
}


/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/* Jika n == 0, kembalikan Nil.
   Mula-mula, baca nilai dari root dari stdin, lalu bangun pohon biner di kiri
   (dengan membaca dari stdin) lalu di tree kanan (dengan membaca dari stdin). 
   misal dari stdin: 1, 2, 3, 4, 5, 6, 7, hasilnya:
       1
     2   5
    3 4 6 7
  */

/* Manajemen Memory */
addrNode AlokNode(infotype X){
  addrNode P;
  P = (addrNode) malloc (sizeof(infotype));
  if(P==Nil) return Nil;
  else {
    Akar(P)=X;
    Left(P)=Nil;
    Right(P)=Nil;
    return P;
  }
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P){
  free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
  return P==Nil;
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
  return (!IsTreeEmpty(P)) && (Left(P)==Nil) && (Right(P)==Nil);
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
  return (!IsTreeEmpty(P)) && (Right(P)==Nil) && Left(P)!=Nil;
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
  return (!IsTreeEmpty(P)) && (Left(P)==Nil) && Right(P)!=Nil;
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
  return (!IsTreeEmpty(P)) && (Right(P)!=Nil) && (Left(P)!=Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintPreorder(BinTree P){
  if(IsTreeEmpty(P)) printf("()");
  else {
    printf("(%d", Akar(P));
    PrintPreorder(Left(P));
    PrintPreorder(Right(P));
    printf(")");
  }
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
  if(IsTreeEmpty(P)) printf("()");
  else {
    printf("(");
    PrintInorder(Left(P));
    printf("%d", Akar(P));
    PrintInorder(Right(P));
    printf(")");
  }
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
  if(IsTreeEmpty(P)) printf("()");
  else {
    printf("(");
    PrintPostorder(Left(P));
    PrintPostorder(Right(P));
    printf("%d)", Akar(P));
  }
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void PrintTreeRecur(BinTree P, int depth, int h){
  if(!IsTreeEmpty(P)){
    for(int i=0; i<depth*h; i++){
      printf(" ");
    }
    printf("%d\n", Akar(P));
    PrintTreeRecur(Left(P),depth+1,h);
    PrintTreeRecur(Right(P),depth+1,h);
  }
}


void PrintTree(BinTree P, int h){
  PrintTreeRecur(P,0,h);
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
  if(IsTreeEmpty(P)) return false;
  else{
    return (Akar(P)==X || SearchTree(Left(P),X) || (SearchTree(Right(P),X)) );
  }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
  if(IsTreeEmpty(P)) return 0;
  else {
    return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
  }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P){
  if(IsTreeEmpty(P)) return 0;
  else if (IsTreeOneElmt(P)) return 1;
  else return NbDaun(Left(P)) + NbDaun(Right(P));
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
  if(IsTreeEmpty(P)) return true;
  else {
    return (IsSkewLeft(Left(P)) && Right(P)==Nil);
  }
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P){
  if(IsTreeEmpty(P)) return true;
  else {
    return (IsSkewRight(Right(P)) && Left(P)==Nil);
  }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotype X){
  if(Akar(P)==X) return 1;
  else {
    if(SearchTree(Left(P),X)) return 1 + Level(Left(P),X);
    else return 1 + Level(Right(P),X);
  }
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P){
  if(IsTreeEmpty(P)) return 0;
  else {
    if(Tinggi(Left(P))>Tinggi(Right(P))){
      return 1 + Tinggi(Left(P));
    } else {
      return 1 + Tinggi(Right(P));
    }
  }

}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X){
  if(IsTreeEmpty(*P)) *P = Tree(X,Nil,Nil);
  else {
    AddDaunTerkiri(&Left(*P), X);
  }
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
  if(Akar(*P)==X && IsTreeOneElmt(*P)){
    if(Kiri) Left(*P) = Tree(Y,Nil,Nil);
    else Right(*P) = Tree(Y,Nil,Nil);
  } else {
    if(SearchTree(Left(*P),X)) AddDaun(&Left(*P),X,Y,Kiri);
    else AddDaun(&Right(*P),X,Y,Kiri);
  }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotype *X){
  if(IsTreeOneElmt(*P)){
    *X = Akar(*P);
    DealokNode(*P);
    *P = Nil;
  } else {
    if(Left(*P)!=Nil){
      DelDaunTerkiri(&Left(*P), X);
    } else {
      DelDaunTerkiri(&Right(*P), X);
    }
  }
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotype X){
  if(IsTreeOneElmt(*P) && Akar(*P)==X){
    DealokNode(*P);
    *P = Nil;
  } else {
    if(!IsTreeEmpty(*P)){
      if(SearchTree(Left(*P),X)){
        DelDaun(&Left(*P),X);
      }
      if(SearchTree(Right(*P),X)){
        DelDaun(&Right(*P),X);
      }
    }
  }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
List MakeListDaun(BinTree P){
  List L;
  if(IsTreeEmpty(P)) return Nil;
  else if(IsTreeOneElmt(P)) {
    L = Alokasi(Akar(P));
    return L;
  }
  else {
    return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
;  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListPreorder(BinTree P){
  List L,T;
  if(IsTreeEmpty(P)) return Nil;
  else {
    T = Concat(MakeListPreorder(Left(P)), MakeListPreorder(Right(P)));
    return Konso(Akar(P),T);
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListLevel(BinTree P, int N){
  if(IsTreeEmpty(P)) return Nil;
  else {
    if(N==1) return Alokasi(Akar(P));
    else if(N>1) return Concat(MakeListLevel(Left(P),N-1), MakeListLevel(Right(P),N-1));
  }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X){
  if(IsTreeEmpty(P)) return false;
  else{
    return (Akar(P)==X || SearchTree(Left(P),X) || (SearchTree(Right(P),X)) );
  }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotype X){
  if(IsTreeEmpty(*P)) {
    *P = Tree(X,Nil,Nil);
  } else {
    if(X > Akar(*P)) {
      InsSearch(&Right(*P), X);
    } else {
      InsSearch(&Left(*P), X);
    }
  }
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

//void DelBtree(BinTree *P, infotype X){
//  infotype Y;
//  addrNode Z;
//  if(!IsTreeEmpty(*P)){
//    if(Akar(*P)==X){
//      if(IsTreeOneElmt(*P)){
//        DelDaun(P,X);
//      } else {
//        if(Right(*P)!=Nil){
//          DelDaunTerkiri(&Right(*P),&Y);
//          Akar(*P) = Y;
//        } else if(Right(*P)==Nil){
//          Z = *P;
//          *P = Left(*P);
//          DealokNode(Z);
//        }
//      }
//    } else if(X < Akar(*P)){
//      DelBtree(&Left(*P),X);
//   } else if(X > Akar(*P)){
//      DelBtree(&Right(*P),X);
//    }
//  }
//}

void DelBtree(BinTree *P, infotype X)
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
{
    addrNode temp;
    if (IsTreeOneElmt(*P) && Akar(*P) == X) {
        temp = *P;
        DealokNode(temp);
        *P = Nil;
        return;
    }
    if (X < Akar(*P)) {
        DelBtree(&Left(*P), X);
    } else {
        DelBtree(&Right(*P), X);
    }
}

  
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
