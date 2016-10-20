#include <stdio.h>
#include <stdlib.h>

#include "library.h"

int main() {
  
  char *a1 = "abba";
  char *s1 = "dancing queen";
  add_song(a1, s1);
  print_letter_entries('a');
  return 0;
}
