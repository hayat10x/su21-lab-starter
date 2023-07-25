// Copyright 2023 Muhammad Hayat
#include <string.h>
#include "/home/hayat/C_programming/su21-lab-starter/lab01/exercise1/ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: All strings end in a null terminator */
// Online C compiler to run C program online
  int num_occurrences(char *str, char letter) {
  int i = 0;
  int  count = 0;
  while (str[i] != '\0') {
        if (str[i] == letter)
            count = count+1;
        i++;
    }
    return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */

void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    /* TODO: implement compute_nucleotide_occurances */
int i = 0;
dna_seq->A_count = 0;
dna_seq->C_count = 0;
dna_seq->G_count = 0;
dna_seq->T_count = 0;

        while (dna_seq->sequence[i] != '\0') {
        if (dna_seq->sequence[i] == 'A')
            dna_seq->A_count = dna_seq->A_count+1;
        if (dna_seq->sequence[i] == 'C')
            dna_seq->C_count = dna_seq->C_count+1;
        if (dna_seq->sequence[i] == 'G')
            dna_seq->G_count = dna_seq->G_count+1;
        if (dna_seq->sequence[i] == 'T')
            dna_seq->T_count = dna_seq->T_count+1;
        i++;
    }
    return;
}

