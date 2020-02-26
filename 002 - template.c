#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#define X 3

void inserisci (int[][X],int,int);
void biancoNero (int[][X],int[],int,int);
void cornice (int[],int,int);
void stampa (int[],int,int);

int main(){
  setlocale(LC_ALL,"");

  int n = 4, m = 3;
  int immagineRGB [n * m][X] = {
    {255, 255, 255},
    {0, 0, 0},
    {0, 0, 0},
    {127, 127, 127},
    {127, 127, 127},
    {127, 127, 127},
    {255, 0, 0},
    {0, 255, 0},
    {0, 255, 255},
    {0, 0, 255},
    {255, 255, 0},
    {255, 0, 255}
  };
  int immagineBW[n * m];
  inserisci(immagineRGB,n,m);
  biancoNero(immagineRGB,immagineBW,n,m);
  cornice(immagineBW,n,m);
  stampa(immagineBW,n,m);
}

void inserisci (int immagineRGB[][X], int n, int m){
  immagineRGB
}

void biancoNero (int immagineRGB[][X],int immagineBW[], int n, int m){
  for (i)
}

void cornice (int immagineBW[], int n, int m){

}

void stampa (int immagineBW[], int n, int m){

}
