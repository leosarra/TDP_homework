#pragma once

#include "utils.h"

// calcola in modo ricorsivo la lunghezza della sequenza binaria bin_seq
int length(BinSeq* bin_seq);

// copia in modo ricorsivo la sequenza binaria src in dest
void copy(BinSeq* dest, BinSeq* src);

// concatena in modo ricorsivo la sequenza binaria src a dest e la memorizza in dest
void concatenate(BinSeq* dest, BinSeq* src);

// calcola in modo ricorsivo la posizione del primo carattere c nella sequenza bin_seq oppure -1 se 
// esso non e' presente e la restituisce in output
int indexOf(BinSeq* bin_seq, char c);

// verifica in modo ricorsivo se le due sequenze binarie in input, bin_seq1 e bin_seq2, sono uguali
// ritorna 1 se sono uguali, 0 altrimenti
int equal(BinSeq* bin_seq1, BinSeq* bin_seq2);

// verifica in modo ricorsivo se la sequenza binaria prefix e' un prefisso della sequenza binaria bin_seq
// ritorna 1 se è un prefisso, 0 altrimenti
int prefix(BinSeq* bin_seq, BinSeq* prefix);

// calcola in modo ricorsivo la lunghezza della sequenza piu' lunga di caratteri consecutivi uguali a c
// e la restituisce in output
int lengthMaxSequence(BinSeq* bin_seq, char c);
