#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "link_list.h"

// length of linked_list
int len(song_node *node) {
  int ret = 0;
  while (node) {
    ret++;
    node = node->next;
  }
  return ret;
}

// print one node
void print_node(song_node *node) {
  printf("%s - %s\n", node->artist, node->name);
}

// print all nodes (sep. by |)
void print_list(song_node *list) {
  if (list) {
    printf("|");
    while(list) {
      printf(" %s - %s |", list->artist, list->name );
      list = list->next;
    }
    printf("\n");  
  }  
}

// insert node at front of list (returns first node)
song_node * insert_front(song_node *list, char *artist, char *name) {
  song_node *new = (song_node *)malloc(sizeof(song_node));
  new->next = list;
  strcpy(new->artist, artist);
  strcpy(new->name, name);
  return new;
}

// insert node in order (returns first node)
song_node * insert_order(song_node *list, char *artist, char *name) {
  // front
  if (list == 0 ||
      strcmp(artist, list->artist) < 0 ||
      (strcmp(artist, list->artist) == 0 && strcmp(name, list->name) < 0) )
    return insert_front(list,artist,name);

  // middle
  song_node *ret = list;
  while (list->next) {
    int artistComp = strcmp(artist, (list->next)->artist);
    int nameComp = strcmp(name, (list->next)->name);
    if (artistComp < 0 || (artistComp == 0 && nameComp < 0)) { 
      list->next = insert_front(list->next,artist,name);
      return ret;
    }
    else
      list = list->next;
  }

  // end
  song_node *last = (song_node *)malloc(sizeof(song_node));
  list->next = last;
  strcpy(last->artist, artist);  
  strcpy(last->name, name);
  return ret;
}

// remove song from linked_list (returns first node)
song_node * remove_song(song_node *list, char *artist, char *name) {
  // front
  if (strcmp(name, list->name) == 0 && strcmp(artist, list->artist) == 0)
    return list->next;
  
  // middle or end
  song_node *ret = list; 
  while (list->next) {
    if (strcmp(name, (list->next)->name) == 0 && 
	strcmp(artist, (list->next)->artist) == 0) {
      list->next = (list->next)->next;
      return ret;
    }
    else
      list=list->next;
  }
  return ret;
}

// delete all nodes (returns first node - now null)
song_node * free_list(song_node *list) {
  song_node *temp = list;
  while ( list ) {
    list = list->next;
    free(temp);
    temp = list;    
  }
  return list;
}

// find song by name (first occurrence)
song_node * find_song(song_node *list, char *name) {
  while (list) {
    if (strcmp(name, list->name) == 0)
      return list;
    else
      list=list->next;
  }
  return 0;
}

// find song by artist (first occurrence)
song_node * find_artist(song_node *list, char *artist) {
  while (list) {
    if (strcmp(artist, list->artist) == 0)
      return list;
    else
      list=list->next;
  }
  return 0;
}

// find random song
song_node * find_random(song_node *list) {
  song_node *copy = list;
  while (copy) {
    copy = copy->next;
  }
  srand(time(NULL));
  int randindex = (int)(len(list) * ((double)rand()/RAND_MAX));
  while (randindex) {
    list = list->next;
    randindex--;
  }
  return list;
}

/*
int main() {
  song_node *p_list = 0;
  p_list = insert_order(p_list, "pearl jam", "yellow");
  p_list = insert_order(p_list, "pink floyd", "time");
  p_list = insert_order(p_list, "pearl jam", "even");
  p_list = insert_order(p_list, "pearl jam", "alive");
  print_list(p_list);
  print_node(find_random(p_list));
  return 0;
}

*/
