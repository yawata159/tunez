#include <stdio.h>
#include <stdlib.h>

#include "library.h"

int main() {

  printf("TESTING add_song\n");
  add_song("the who", "baba o'riley");
  add_song("gorillaz", "stylo");
  add_song("the beatles", "hey jude");
  add_song("modest mouse", "float on");
  add_song("the beatles", "let it be");
  add_song("metallica", "enter sandman");
  add_song("the beatles", "help!");
  add_song("modest mouse", "missed the boat");
  printf("\n");
  
  printf("TESTING print_library\n");
  print_library();
  printf("\n");

  printf("TESTING print_artist\n");
  print_artist("modest mouse");
  print_artist("queen");
  printf("\n");

  printf("TESTING print_letter\n");
  print_letter('t');
  print_letter('a');
  printf("\n");
  
  printf("TESTING print_song\n");
  print_song("the who", "baba o'riley");
  print_song("the who", "pinball wizard");
  print_song("queen", "don't stop me now");
  printf("\n");

  printf("TESTING shuffle (3 songs)\n");
  shuffle(3);
  printf("\n");
  
  printf("TESTING delete_song\n");
  delete_song("the beatles", "hey jude");
  delete_song("gorillaz", "stylo");
  delete_song("modest mouse", "float on");
  print_library();
  printf("\n");
  
  printf("TESTING delete_all\n");
  delete_all();
  print_library();

}
