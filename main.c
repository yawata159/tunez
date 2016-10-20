#include <stdio.h>
#include <stdlib.h>

#include "library.h"

int main() {
  

  char *a1 = "beatles";
  char *a2 = "queen";
  char *s1 = "lucy in the sky";
  char *s2 = "yesterday";
  char *s3 = "we are the champions";
  add_song(a1, s1);
  add_song(a1, s2);
  add_song(a2, s3);
  print_library();
  return 0;
}
