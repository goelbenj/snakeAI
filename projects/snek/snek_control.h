#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  int axis;
  int direction;
  struct Node * next;
} Node;

Node *create_direction_sequence(int axis, int direction);
void add_move(int axis, int direction, Node *head);
void delete_direction_sequence(Node *head);
