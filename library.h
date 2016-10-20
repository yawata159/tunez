#include "link_list.h"



void add_song(char* artist, char* name);
void delete_song(char *artist, char *name);
void delete_all();

song_node *search_song(char* name);
song_node *search_artist(char* artist);

void print_letter_entries(char c);
void print_artist_entries(char *artist);
void print_library();
void shuffle(int i);

