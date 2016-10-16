#include <stdio.h>
#include <stdlib.h>

#include "songnode.h"

song_node * insert_front(song_node *list, char *name, char *artist);
song_node * insert_order(song_node *list, song_node *insert);
void print_list(song_node *list);
song_node * find_song(song_node *list, char *name);
song_node * find_artist(song_node *list, char *artist);
song_node * random_song(song_node *list);
song_node * remove_song(song_node *list, song_node *remove);
song_node * free_list(song_node *lsit);


void print_list( node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%d ", n->data );
    n = n->next;
  }
  printf("]\n");
}


node * insert_front( node *n, int  d ) {

  node *new = (node *)malloc(sizeof(node));

  new->next = n;
  new->data = d;

  return new;
}

node * free_list( node *n ) {

  node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing node: %d\n", f->data );
    free(f);
    f = n;    
  }
  return n;
}
