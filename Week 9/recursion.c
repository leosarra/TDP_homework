#include "recursion.h"
#include <stdio.h>
int str_length(char* s) {
    if (s[0]==0){
        return 0;
        }
    else{
        return 1+str_length(s+1);
        }
}
int aid_length(char* bin_seq){
    if (bin_seq[0]==0) {
        return 0;}
    return 1+aid_length(bin_seq+1);
    }
int length(BinSeq* bin_seq) { 
    
    return aid_length((*bin_seq).data);

}



//FINE PRIMO ESERCIZIO 



void aid_copy(char* dest,char* src){
    if (src[0]==0) { //E' POSSIBILE FARE UN IF UTILIZZANDO IL PARAMETRO DIMENSION 
        //DELLA STRUTTURA A PATTO DI MODIFICARE ADEGUATAMENTE LA FUNZIONE AUSILIARIA
        ;
        }
    else {
    dest[0]=src[0];
    aid_copy(dest+1,src+1);
        }
    }
void copy(BinSeq* dest, BinSeq* src) {
    aid_copy((*dest).data,(*src).data);
    dest->dimension=src->dimension;

}



// FINE ES 2



void aid_concatenate(char* dest, char* src){
    if (src[0]==0) { 
        printf("Ciao \n");
        ;
        }
    else {
    
    dest[0]=src[0];
    printf("Il valore è %c \n",dest[0]);
    aid_concatenate(dest+1,src+1);
        }
     }
void concatenate(BinSeq* dest, BinSeq* src) {
    int len=length(dest);
 aid_concatenate((*dest).data + len,src->data);
}



// FINE ES 3



int aid_indexOf(char* s, char c) {
    int lunghezza=str_length(s);
    if (lunghezza==0){
        return -1;}
    if (s[0]==c){
        return 0;}
    int res=aid_indexOf(s+1,c);
    if (res==-1){
        return -1;
    }
    else{
        return (1+aid_indexOf(s+1,c));
    }
}
int indexOf(BinSeq* bin_seq, char c) { 
    int ris=aid_indexOf(bin_seq->data,c);
    return ris;

	
	}
	
	
	
// FINE ESERCIZIO 4


int aid_equal(char* s1, char* s2) {
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
    return aid_equal(s1+1,s2+1);
}

int equal(BinSeq* bin_seq1, BinSeq* bin_seq2) {
    int ris=aid_equal(bin_seq1->data,bin_seq2->data);
    return ris; 

}



// FINE ESERCIZIO 5



int aid_prefix(char* s1,char* s2){ 
    int len1=str_length(s1);
    int len2=str_length(s2);
    if (len1<=len2){
        return 0;
        }
    if (s2[0]==0){
        return 1;}
    if (s1[0]!=s2[0]){
        return 0;}

    return aid_prefix(s1+1,s2+1);
    }
int prefix(BinSeq* bin_seq, BinSeq* prefix) {
    int ris=aid_prefix(bin_seq->data,prefix->data); 
    return ris;
}



//FINE ESERCIZIO 6



int aid_lengthMaxSequence(char* src, char c, int max, int len, int index, int check){
   if(src[index] == c && index != len){
    check+=1;
      if(max < check){
         max=check; //SALVIAMO IL VALORE DEL CONTATORE IN MAX 
      }

      aid_lengthMaxSequence(src, c, max, len, index+1, check);
   }
   else{
      if(src[index] != c && index != len){
         aid_lengthMaxSequence(src, c, max, len, index+1,0); //RESETTIAMO IL CONTATORE
      }
      else if(index == len){
         return max; // QUANDO LA STRINGA RAGGIUNGE LA FINE LA RICORSIONE TERMINA
      }
   }
}

int lengthMaxSequence(BinSeq* bin_seq, char c) {
    int len=length(bin_seq);
    int ris=aid_lengthMaxSequence(bin_seq->data, c, 0, len,0,0);
   return ris;
}



// FINE ESERCITAZIONE -- CREDI NELL'ORACOLO RICORSIVO 
