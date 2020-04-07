#include "snek_api.h"
#include "snek_control.h"

int *turn_snake(int axis, int direction, GameBoard *board) {
  if (axis == AXIS_Y && direction == UP  && board->snek->head->coord[y] != (BOARD_SIZE-1) && board->snek->head->coord[x] != 1) {
    //&& gameBoard->snek->head->coord[x] > (int)(BOARD_SIZE/2)
    axis = AXIS_X;
    direction = LEFT;
  }
  if (axis == AXIS_Y && direction == UP  && board->snek->head->coord[x] == 1) {
    axis = AXIS_X;
    direction = RIGHT;
  }
  if (axis == AXIS_X && direction == LEFT  && board->snek->head->coord[x] == 1) {
    //&& gameBoard->snek->head->coord[x] > (int)(BOARD_SIZE/2)
    if ( board->snek->head->coord[y] != 0) {
      axis = AXIS_Y;
      direction = UP;
    }
  }
  static int movement[2] = {0,0};
  movement[0] = axis;
  movement[1] = direction;
  return movement;
}

Node *create_direction_sequence(int axis, int direction) {
  Node *head = malloc(sizeof(Node));
  head->axis = axis;
  head->direction = direction;
  head->next = NULL;
  return head;
}

void add_move(int axis, int direction, Node *head) {
  Node *next_move = create_direction_sequence(axis, direction);
  head->next = next_move;
}

void delete_direction_sequence(Node *head) {
  Node *curr_node = head;
  while (head) {
    head = head->next;
    free(curr_node);
    curr_node = head;
  }
}
