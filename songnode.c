#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "songnode.h"

void print_list(song_node *list) {
  printf("| ");
  while(list) {
    printf("%s - %s | ", list->artist, list->name );
    list = list->next;
  }
  printf("\n");
}

song_node * insert_front(song_node *list, char *name, char *artist) {
  song_node *new = (song_node *)malloc(sizeof(song_node));
  new->next = list;
  new->name = name;
  new->artist = artist;
  return new;
}

song_node * insert_order(song_node *list, char *name, char *artist) {

  // front
  if (list == 0 ||
      strcmp(artist, list->artist) < 0 ||
      (strcmp(artist, list->artist) == 0 && strcmp(name, list->name) < 0) )
    return insert_front(list,name,artist);

  // middle
  song_node ret = list;
  while (list->next != 0) {
    int artistComp = strcmp(artist, (list->next)->artist);
    int nameComp = strcmp(name, (list->next)->name);
    
    if (artistComp < 0 || (artistComp == 0 && nameComp < 0)) { 
      list->next = insert_front(list->next,name,artist);
      return list;
    }
    
    else {
      list = list->next;
    }
  }

  // end
  song_node *last = (song_node *)malloc(sizeof(song_node));
  list->next = last;
  last->name = name;
  last->artist = artist;  
  return ret;
  
}


song_node * find_song(song_node *list, char *name) {
  while (list) {
    if (strcmp(name, list->name) == 0)
      return list;
    else
      list=list->next;
  }
  return 0;
}

song_node * find_artist(song_node *list, char *artist) {
  while (list) {
    if (strcmp(artist, list->artist) == 0)
      return list;
    else
      list=list->next;
  }
  return 0;
}

song_node * random_song(song_node *list) {
  
}

song_node * remove_song(song_node *list, song_node *remove) {
  
}

song_node * free_list(song_node *list) {
  song_node *temp = list;
  while ( list ) {
    list = list->next;
    free(temp);
    temp = list;    
  }
  return list;
}
