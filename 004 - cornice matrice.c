#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#define N 9

void riempi(int[][N]);
void stampa(int[][N]);

int main(){
  setlocale(LC_ALL,"");

  int matrice[N][N] = {0};
  riempi(matrice);
  stampa(matrice);

  return 0;
}

void riempi(int matrice[][N]){
  for(int x = 0; x < (N % 2) + N / 2; x++){
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        if ( ( (i == x) || (j == x) || (i + x == N - 1) || (j + x == N - 1)) && (!matrice[i][j]) ) matrice[i][j] = x + 1;
      }
    }
  }
}

void stampa(int matrice[][N]){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      printf("%d ",matrice[i][j]);
    }
    printf("\n");
  }
}
