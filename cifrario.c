#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main ( )   {
  char playntext[128],chiave[128],ciphertext[128];
  int operazione,caratteri_chiave=0,caratteri_playntext=0;
  printf("benvenuto nell'algoritmo rc4 \n");
  printf("scrivi il playntext: ");
  fgets( playntext,128,stdin);
  /*prendo il numero di caratteri scritti come testo da cifrare e controllo che
  non siano più di 128 se superano questo limite costringo l'utente a riscriverla
  fino a che non rispetti la condizione,faccio il -1 per non contare il
  carattere finale /o */
  caratteri_playntext=strlen(playntext)-1;
  while (caratteri_playntext>127) {
    printf("ERRORE:la stringa supera i 128 caratteri riprova\n");
    printf("scrivi il playntext: ");
    fgets( playntext,128,stdin);
    caratteri_playntext=strlen(playntext)-1;
  }
  /*ho deciso di mettere qua la decisione dell'utente su quale dei 2 metodi da
  usare per proseguire così da ridurre la lunghezza del programma non dovendo
  riscrivere 2 volte la parte del playntext (1 volta se l'utente sceglieva 1 e
  un'altra se l'utente sceglieva 2)*/
  printf("ora hai 2 possibilità \n"
  "-premi 1 per scrivere la chiave \n"
  "-premi 2 per far generare casualmentela chiave \n");
  scanf( "%d", &operazione );
  /*ho messo il getchar() perchè il programma dava problemi stampandomi dopo
  aver fatto la scelta tutti i printf di fila*/
  getchar();
  if (operazione==1) {
    printf("scrivi la chiave di cifratura: ");
    fgets( chiave,128,stdin);
    caratteri_chiave=strlen(chiave)-1;
    /*simile al controllo del playntext solo che qua controllo anche che la
    chiave sia lunga almeno quanto il playntext*/
    while ((caratteri_chiave>128)||(caratteri_chiave<caratteri_playntext)) {
      printf("ERRORE:la stringa supera i 128 caratteri o è più piccola del testo riprova\n");
      printf("scrivi la chiave di cifratura: ");
      fgets( chiave,128,stdin);
      caratteri_chiave=strlen(chiave)-1;
    }
  }
  if (operazione==2) {
    /*genero i caratteri della chiave casualmente,ho deciso di fare il random
    tra i primi 96 e dopo sommare 32 per non avere i caratteri speciali tra
    0 e 31 che danno problemi di visualizzazione*/
    time_t t;
    srand ((unsigned) time(&t));
    for (int i = 0; i <=caratteri_playntext; i++) {
      chiave[i]=(rand() %96)+32;
    }
    caratteri_chiave=strlen(chiave)-1;
    printf("la tua chiave è: %s \n",chiave );
  }
  /*effettuo lo xor tra playntext e chiave per un numero di volte=al numero di
  caratteri del playntext perchè effettuarlo ulteriori volte dopo la fine dell
  playntext sarebbe risultato inutile*/
  for (int i = 0; i <=caratteri_playntext; i++) {
    ciphertext[i]=playntext[i]^chiave[i];
  }
  printf("il tuo testo cifrato è: ");
  puts(ciphertext);
  /*riporto il testo in chiaro con il metodo del commento precedente soltanto
  che effettuo lo xor tra il testo cifrato e la chiave*/
  char testo[128];
  for (int i = 0; i <=caratteri_playntext; i++) {
    testo[i]=ciphertext[i]^chiave[i];
  }
  printf("il tuo testo in chiaro è: ");
  puts(testo);
  return(0);
}
