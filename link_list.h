typedef struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

int len(song_node *node);

void print_node(song_node *node);
void print_list(song_node *list);

// all four return first link in the list
song_node * insert_front(song_node *list, char *artist, char *name);
song_node * insert_order(song_node *list, char *artist, char *name);
song_node * remove_song(song_node *list, char *artist, char *name);
song_node * free_list(song_node *list);

song_node * find_song(song_node *list, char *name);
song_node * find_artist(song_node *list, char *artist);
song_node * find_random(song_node *list);
