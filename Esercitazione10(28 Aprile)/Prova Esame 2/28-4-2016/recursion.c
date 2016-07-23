#include <stdio.h>
#include <string.h>

// *** Svolgere tutte le seguenti funzioni in modo ricorsivo ***

// Suggerimento: la ricorsione sulle stringhe si effettua seguendo questo schema:
// - caso base: il primo carattere è il carattere '\0', cioè la stringa è vuota
// - caso ricorsivo: la chiamata ricorsiva viene effettuata sulla parte restante
//        della stringa, escluso il primo carattere; tale parte restante della stringa 
//        si può ottenere mediante una operazione opportuna con l'aritmetica dei puntatori.


// Restituisce la lunghezza della stringa di input s. 
int str_length(char* s) {
    if (s[0]==0){
        return 0;
        }
    else{
        return 1+str_length(s+1);
        }
}
/* QUESTA E' UNA ALTERNATIVA AL SECONDO ESERCIZIO CHE UTILIZZA UNA FUNZIONE AUSILIARIA 
str_check(char* s, char c) {
    if (str_length(s)==0){
        return 0;}
    if (s[0]==c){
        return 0;}
    else {
        return 1+str_check(s+1,c);
    }

}

int str_index_of(char* s, char c) {
    int ris=str_check(s,c);
    int len=str_length(s);
    if (str_length(s)==0){
        return -1;}
    if (ris==len && s[len]!=c){
        return -1;}
    if (s[0]==c){
        return 0;}
    else {
        return 1+str_index_of(s+1,c);
    }

}*/
// Restituisce l'indice della prima occorrenza del carattere c in s.
int str_index_of(char* s, char c) {
    int lunghezza=str_length(s);
    if (lunghezza==0){
        return -1;}
    if (s[0]==c){
        return 0;}
    int res=str_index_of(s+1,c);
    if (res==-1){
        return -1;
    }
    else{
        return (1+str_index_of(s+1,c));
    }
}




// Verifica se le due stringhe in input s1 e s2 sono uguali.
// La funzione resituisce 1 se le due stringhe sono uguali, 0 altrimenti.
int str_compare(char* s1, char* s2) {
    int len1;
    len1=str_length(s1);
    int len2;
    len2=str_length(s2);
    if (len1!=len2){
        return 0;
        }
    if (s1[0]!=s2[0]){
        return 0;}
    if (s1[0]==0){
        return 1;}
    return str_compare(s1+1,s2+1);
}





int main(int argc, char** argv) {
  char* str1 = "Ciao Paperopoli!"; 
  printf("str1: %s\n", str1);
  char* str2 = "I nipoti di paperino sono..."; 
  printf("str2: %s\n", str2);
  char* str3 = "Qui, Quo e Qua"; 
  printf("str3: %s\n", str3);
  char* str4 = ""; 
  printf("str4: %s\n", str4);
  printf("----------------------------------------------------\n\n");
  
  // test str_length
  printf("Test str_length\n");
  printf("La lunghezza di str1 e': %d\n", str_length(str1));
  printf("La lunghezza di str2 e': %d\n", str_length(str2));
  printf("La lunghezza di str3 e': %d\n", str_length(str3));
  printf("La lunghezza di str4 e': %d\n", str_length(str4));
  printf("----------------------------------------------------\n\n");
  
  // test str_index_of
  printf("Test str_index_of\n");
  printf("l'indice del primo carattere p in str1 e': %d\n", str_index_of(str1, 'p'));
  printf("l'indice del primo carattere z in str2 e': %d\n", str_index_of(str2, 'z'));
  printf("l'indice del primo carattere , in str3 e': %d\n", str_index_of(str3, ','));
  printf("l'indice del primo carattere j in str4 e': %d\n", str_index_of(str4, 'j'));
  printf("----------------------------------------------------\n\n");
  
  // test str_compare
  printf("Test str_comapre\n");
  printf("Il risultato di str_compare tra str1 e str2 e': %d\n", str_compare(str1, str2));
  printf("Il risultato di str_compare tra str3 e \"Qui, Quo e Qua\" e': %d\n", str_compare(str3, "Qui, Quo e Qua"));
  printf("Il risultato di str_compare tra str3 e str4 e': %d\n", str_compare(str3, str4));
  printf("Il risultato di str_compare tra str4 e str4 e': %d\n", str_compare(str4, str4));
}

