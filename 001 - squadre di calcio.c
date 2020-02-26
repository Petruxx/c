/*
  * Vettori paralleli e Stringhe
  * Gestione squadre di calcio
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100


void inizializzaSquadre(char[][30], char[], int[], int );
void visualizzaSerie(char[][30], char[], int[], char ,int);
void informazioniSquadra(char[][30], char[], int[], int );
void campione(char[][30], char[], int[], char ,int );
void visualizzaClassifica (char V[][30], char [], int [], char, int);
void ordina (char[][30], int[], int );
void ordinaNome (char[][30], char[], int[], char, int);


int main(){

  char nomeS[MAX_N][30];	//vettore di stringhe con i momi delle squadre
  char serie[MAX_N];		//vettore di char che contiene la serie dove gioca la squadra
  int punti[MAX_N];		//vettore di interi col punteggio della sqradra
  char s;
  int N = 6, k;
  printf ("\nInserisci il numero totale di squadre serie A + serie B: \n");
  scanf ("%d",&N);
  N = 6;
  inizializzaSquadre(nomeS,serie,punti,N);

  do{
	  printf ("\nInserisci 1 per  elenco squadre serie A:\n");
	  printf ("Inserisci 2 per  elenco squadre serie B:\n");
	  printf ("Inserisci 3 per informazioni squadra :\n");
	  printf ("Inserisci 4 per classifica squadre serie richiesta:\n");
	  printf ("Inserisci 5 per ricerca squadra campione serie richiesta:\n");
	  printf ("Inserisci 6 per ordinare le squadre della serie richiesta in ordine alfabetico:\n");
	  printf ("Inserisci 0 per terminare:\n");
	  printf ("Inserisci la tua scelta :\n");
	  scanf ("%d",&k);
	  fflush(stdin);
	  switch (k){
  		case 1:
  			visualizzaSerie(nomeS, serie ,punti,'A',N );
  	    break;
  	  case 2:
    		visualizzaSerie(nomeS, serie ,punti,'B',N );
  	    break;
  	  case 3:
  			informazioniSquadra(nomeS, serie ,punti,N);
  	    break;
  	  case 4:
  			printf ("Inserisci la serie che vuoi visualizzare :\n");
  			scanf("%c",&s);
  			visualizzaClassifica (nomeS, serie ,punti,s,N);
  	    break;
  	  case 5:
  	    printf ("Inserisci la serie che vuoi visualizzare :\n");
  			scanf("%c",&s);
  			campione(nomeS, serie ,punti,s,N);
  	    break;
  	  case 6:
  			printf ("Inserisci la serie che vuoi visualizzare :\n");
  			scanf("%c",&s);
  			ordinaNome(nomeS,serie,punti,s,N);
  	    break;
  	  case 0:
  	    break;
  	  default :
  	    printf ("ERRORE: scelta inesistente!\n");
  	}

	} while(k != 0 );

  return (0);
 // system("PAUSE");
}


void visualizzaSerie (char V[6][30], char S[], int P[], char cat, int n){
	for ( int i = 0; i < n; i++){
    if (S[i] == cat){
      printf ("%s --> %d punti\n", V[i], P[i]);
    }
  }
}

void visualizzaClassifica (char V[][30], char S[],int P[], char cat , int n){
	//Crea un nuovo vettore che conterrà solo le squadre della  serie richiesta, lo ordina e visualizza la classifica.
  char classifica[n][30];
  int puntiClassifica[n], x = 0;
  for ( int i = 0; i < n; i++){
    if (S[i] == cat){
      strcpy(classifica[x], V[i]);
      puntiClassifica[x] = P[i];
      x++;
    }
  }
  ordina (classifica, puntiClassifica, x);

  for (int i = 0; i < x; i++){
    printf ("%d %s --> %d punti\n",i + 1, classifica[i], puntiClassifica[i]);
  }
}

void ordina (char V [][30], int punti[], int n){
	// effettua l'ordinamento delle squadre in base al punteggio decrescente
  char temp[30];
  int tempo;
  for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
      if (punti[i] < punti[j]){
        strcpy(temp,V[j]);
        strcpy(V[j],V[i]);
        strcpy(V[i],temp);
        tempo = punti[j];
        punti[j] = punti[i];
        punti[i] = tempo;
      }
    }
  }
}

void ordinaNome (char V [][30], char serie[], int punti[],char s, int n){
	// effettua l'ordinamento delle squadre della serie S in ordine alfabetico
  char ordinato[n][30], temp[30];
  int puntiOrdinato[n], tempo;
  int x = 0;
  for ( int i = 0; i < n; i++){
    if (serie[i] == s){
      strcpy(ordinato[x], V[i]);
      puntiOrdinato[x] = punti[i];
      x++;
    }
  }

  for (int i = 0; i < x - 1; i++){
    for (int j = i + 1; j < x; j++){
      if (strcmp(ordinato[i],ordinato[j]) > 0){
        strcpy(temp,ordinato[j]);
        strcpy(ordinato[j],ordinato[i]);
        strcpy(ordinato[i],temp);
        tempo = puntiOrdinato[j];
        puntiOrdinato[j] = puntiOrdinato[i];
        puntiOrdinato[i] = tempo;
      }
    }
  }

  for (int i = 0; i < x; i++){
    printf ("%s --> %d punti\n",ordinato[i], puntiOrdinato[i]);
  }

}

void informazioniSquadra(char V[][30], char S[], int P[], int n ){
	// dato il nome di una squadra, se compare tra quelle inserite nell'elenco ne stampa
	// la serie e i punti, altrimenti da un messaggio di errore
  char temp[30];
  int boole = 1;
  printf("Di quale squadra vuoi avere informazioni? >> ");
  scanf("%s",temp);

  for (int i = 0; i < n; i++){
    if (!strcmp(temp,V[i])){
      printf ("%s e' in serie %c e ha %d punti\n",temp,S[i],P[i]);
      boole = 0;
    }
  }

  if (boole) printf("Squadra non trovata\n");
}

void campione (char V[][30], char S[], int P[], char s, int n ){
	// ricerca tra le squadre della serie richiesta quella con punteggio massimo
	// senza creare nessun vettore di appoggio (SENZA NESSUNA COPIA, ne dei nomi delle squadre ne dei punteggi)
  int max;
  for (int i = 0; i < n; i++){
    if (S[i] == s){
      max = i;
      i = n;
    }
  }

  for (int i = max + 1; i < n; i++){
    if (S[i] == s && P[i] > P[max]){
      max = i;
    }
  }

  printf("La squadra campione della serie %c è %s con %d punti",s,V[max],P[max]);
}

void inizializzaSquadre (char V[6][30], char S[], int P[],int N){
	// inizializza i vettori nomesquadre, serie e punti e  N


	strcpy(V[0],"Fiore");
	strcpy(V[1],"Juve");
	strcpy(V[2],"Napule");
	strcpy(V[3],"Bari");
	strcpy(V[4],"Pescia");
	strcpy(V[5],"Livorno");

	S[0]='A';
	S[1]='B';
	S[2]='A';
	S[3]='A';
	S[4]='B';
	S[5]='B';

	P[0]=12;
	P[1]=2;
	P[2]=3;
	P[3]=4;
	P[4]=31;
	P[5]=3;
}
