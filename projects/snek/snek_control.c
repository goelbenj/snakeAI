#include "snek_api.h"

int turn_snake(int axis, int direction, GameBoard *board) {
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
  int movement_data[2] = {axis, direction};
  return movement_data;
}
