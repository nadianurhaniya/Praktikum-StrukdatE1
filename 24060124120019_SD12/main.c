/*Nama file: main.c */
/*Deskripsi: aplikasi ADT bintree3 berkait dengan representasi fisik pointer */
/*Tanggal  : 12 Desember 2025 */
/*Pembuat  : Nadia Azura Nurhaniya - 24060124120019 */

#include "pohon3.h"
int main() {
	//kamus
	bintree3 W;
      List1 L, L1, L2, L3;
      
	//algoritma
	//bukalah komentar ini untuk menguji (aplikasi) Tree3
      W = Tree3(NIL,'A',false,
              Tree3(W,'B',false, 
                    NIL, 
                    Tree3(left(W),'D',false,NIL,NIL)),
              Tree3(W,'C',false, 
                    Tree3(right(W),'E',false,NIL,NIL),
                    Tree3(right(W),'F',false,NIL,NIL)));
	
	
      /*---------Penelusuran------------ */
      printf("DFS Pohon W: ");
      printDFS(W);

	//aplikasi max2 dan Tinggi
      printf("\n\nTinggi pohon W adalah %d", Tinggi(W));
      
      //aplikasi PrintLevel
      printf("\n\nNode pada level 2: ");
      PrintLevel(W, 2);

      //aplikasi BFS
      printf("\n\nBFS Pohon W: ");
      PrintBFS(W);

      //aplikasi IsEmptyTree
      if (IsEmptyTree(W)) {
            printf("\n\nPohon W Kosong");
      } else {
            printf("\n\nPohon W Tidak Kosong");
      }

      //aplikasi IsDaun
      if (IsDaun(W)) {
            printf("\nPohon W hanya memiliki satu elemen (akar)");
      } else {
            printf("\nPohon W memiliki lebih dari satu elemen");
      }

      //aplikasi IsBiner
      if (IsBiner(W)) {
            printf("\nPohon W adalah pohon biner");
      } else {
            printf("\nPohon W bukan pohon biner");
      }

      //aplikasi IsUnerLeft
      if (IsUnerLeft(W)) {
            printf("\nPohon W adalah pohon unerleft");
      } else {
            printf("\nPohon W bukan pohon unerleft");
      }

     //aplikasi IsUnerRight
      if (IsUnerRight(W)) {
            printf("\nPohon W adalah pohon unerright");
      } else {
            printf("\nPohon W bukan pohon unerright");
      }

	//aplikasi resetVisited
      resetVisited(W);
      printf("\n\nStatus visited semua node di-reset.");

      //aplikasi printPathX
      printf("\n\nPath dari akar ke node D: ");
      printPathX(W, 'D');

      //aplikasi printPathDaunX
      printf("\nPath dari akar ke daun E: ");
      printPathDaunX(W, 'E');

      //aplikasi printAllPaths
      printf("\nSemua path akar ke daun:");
      printAllPaths(W);

      //aplikasi NbElmTree
      printf("\n\nJumlah elemen pohon W : %d", NbElmTree(W));

      //aplikasi NbDaun
      printf("\nJumlah daun pohon W : %d", NbDaun(W));

      //aplikasi Level
      printf("\nLevel pohon W : %d", Level(W));

      //aplikasi CountLevelT
      printf("\n\nJumlah node level 2 : %d", CountLevelT(W, 2));
      printf("\nJumlah node level 3 : %d", CountLevelT(W, 3));


      /*** operator khusus List1 ***/
      //aplikasi Pconcat
      CreateList(&L1);
      CreateList(&L2);

      InsertVLast(&L1, 'A');
      InsertVLast(&L1, 'B');
      InsertVLast(&L2, 'C');
      InsertVLast(&L2, 'D');

      printf("\n\nList L1 sebelum Pconcat : ");
      PrintList(L1);
      printf("\nList L2 : ");
      PrintList(L2);

      Pconcat(&L1, L2);
      printf("\nList L1 sesudah Pconcat: ");
      PrintList(L1);

      //aplikasi Fconcat
      CreateList(&L1);
      CreateList(&L2);

      InsertVLast(&L1, 'X');
      InsertVLast(&L1, 'Y');
      InsertVLast(&L2, 'Z');

      L3 = Fconcat(L1, L2);

      printf("\n\nList L1 (tidak berubah): ");
      PrintList(L1);
      printf("\nList L2 (tidak berubah) : ");
      PrintList(L2);
      printf("\nList L3 hasil Fconcat L1 dan L2 : ");
      PrintList(L3);

      /*** LINEARISASI POHON ***/
      //aplikasi LinearPrefix
      printf("\n\nLinear Prefix  : ");
      L = LinearPrefix(W);
      PrintList(L);

      //aplikasi LinearPosfix
      printf("\nLinear Posfix : ");
      L = LinearPosfix(W);
      PrintList(L);

      //aplikasi LinearInfix
      printf("\nLinear Infix   : ");
      L = LinearInfix(W);
      PrintList(L);

      //aplikasi LevelTree
      printf("\n\nLevelTree level 1 : ");
      L = LevelTree(W, 1);
      PrintList(L);

      printf("\nLevelTree level 2 : ");
      L = LevelTree(W, 2);
      PrintList(L);

      printf("\nLevelTree level 3 : ");
      L = LevelTree(W, 3);
      PrintList(L);

      //aplikasi LinearBreadthFS
      printf("\n\nLinear BFS : ");
      L = LinearBreadthFS(W);
      PrintList(L);

	return 0;
}