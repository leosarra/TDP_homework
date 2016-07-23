#include <stdlib.h>
#include <stdio.h>

#include "esercizio3.h"

int count_vowels(TipoSCL l) {
  if(l == NULL) { 
    return 0;
  }
  else if(l->c == 'a' || l->c == 'e' || l->c == 'i' || l->c == 'o' || l->c == 'u') {
    return 1 + count_vowels(l->next);
  }
  else {
    return count_vowels(l->next);
  }
}
