#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "link_list.h"
#include "library.h"

song_node *table[26];

// add songs
void add_song(char *artist, char *name) {
  table[artist[0] - 'a'] = insert_order(table[artist[0] - 'a'], artist, name);
  printf(">> Added %s - %s \n", artist, name);
}

// delete a song (assumes song is in table)
void delete_song(char *artist, char *name) {
  table[artist[0] - 'a'] = remove_song(table[artist[0] - 'a'], artist, name);
  printf(">> Removed %s - %s \n", artist, name);
}

// delete all the nodes
void delete_all() {
  int i = 0;
  for (; i < 26; i++)
    table[i] = free_list(table[i]);
  printf(">> Removed all songs\n");
}

// search for a song
song_node *search_song(char *artist, char* name) {
  song_node *letter_node = table[artist[0] - 'a'];
  song_node *potential_find = find_song(letter_node, artist, name);
  if (potential_find)
    return potential_find;
  return 0;
}

// search for an artist (first node if found)
song_node *search_artist(char* artist) {
  song_node *letter_node = table[artist[0] - 'a'];
  song_node *potential_find = find_artist(letter_node, artist);
  if (potential_find)
    return potential_find;
  return 0;
}

// prints song node if found (uses search_song)
void print_song(char *artist, char *name) {
  printf(">> Looking for *%s - %s*\n\t", artist, name); 
  song_node *potential_find = search_song(artist, name);
  if (potential_find)
    printf("%s - %s\n", artist, name);
  else
    printf("Song not found\n");
}

// print out all the songs of a certain artist (uses search_artist)
void print_artist(char *artist) {
  printf(">> Looking for *%s*\n", artist);
  song_node *potential_find = search_artist(artist);
  if (potential_find) {
    while (potential_find) {
      if (strcmp(artist, potential_find->artist) == 0) {
	printf("\t");
	print_node(potential_find);
      }
      else 
	break;
      potential_find = potential_find->next;
    }
  }
  else
    printf("\tArtist not found\n");
}

// print out all the entries under a certain letter
void print_letter(char c) {
  song_node *letter_node = table[c - 'a'];
  printf(">> Songs under '%c'\n", c);
  if (letter_node)
    while (letter_node) {
      printf("\t");
      print_node(letter_node);
      letter_node = letter_node->next;
    }
  else
    printf("\tNothing here\n");
}

// print out the entire library
void print_library() {
  printf(">> All Songs\n");
  char any_songs = 0;
  char c = 'a';
  for (; c <= 'z'; c++) {
    song_node *letter_node = table[c -'a'];
    if (letter_node) {
      any_songs = 1;
      printf("  ");
      print_letter(c);
    }
  }
  if (!any_songs)
    printf("\tNothing here\n");
}

// shuffle
void shuffle(int i) {
  printf(">> Shuffle Player (%d songs)\n", i);
  srand(time(NULL));

  char has_songs[26]; 
  int node_lens[26]; 
  int total_num = 0; //total number of songs 3
  int k = 0; // num of table nodes with songs in them 2
  int j = 0; // 'table' indexes with song nodes in them 

  for (; j < 26; j++)
    if (table[j]) {
      has_songs[k] = j;
      node_lens[k] = len(table[j]);
      total_num += len(table[j]);
      k++;
    }
  if (k == 0) return; //no songs at all in 'table'

  while (i) {
    int rand_count = (int)(total_num * (double)rand()/RAND_MAX);
    int curr_ind = 0;
    for (; curr_ind < k; curr_ind++) {
      if (rand_count - node_lens[curr_ind] < 0)
	break;
      else
	rand_count = rand_count - node_lens[curr_ind];
    }
    song_node *song_node = table[has_songs[curr_ind]];
    while (rand_count) {
      song_node = song_node->next;
      rand_count--;
    }
    printf("\t");
    print_node(song_node);
    i--;
  }
}

