#include "snek_api.h"
#include "snek_control.h"
#include <unistd.h>

void play_game() {
	printf("starting\n");
	//board initialized, struct has pointer to snek
	GameBoard* board = init_board();
	show_board(board);

	int axis = AXIS_INIT;
	int direction = DIR_INIT;

	int play_on = 1;
	int coord[2];

	while (play_on){
		coord[x] = board->snek->head->coord[x];
		coord[y] = board->snek->head->coord[y];
		unsigned short go_x = (axis == AXIS_Y && direction == 1 && coord[y] == (BOARD_SIZE - 1)) || (axis == AXIS_Y && direction == -1 && coord[y] == 0);
		unsigned short go_y = (axis == AXIS_X && direction == 1 && coord[x] == (BOARD_SIZE - 1)) || (axis == AXIS_X && direction == -1 && coord[x] == 0);

		//TURNING
		int *p = turn_snake(axis, direction, board);
		axis = p[0];
		direction = p[1];

		// printf("Barrier Status: %d %d\n", go_x, go_y);

		if (go_x) {
			// going to hit the bottom or top
			// go right or left
			axis = AXIS_X;
			if (coord[x] < (int)(BOARD_SIZE / 2)){
				direction = RIGHT;
			} else {
				direction = LEFT;
			}
		} else if (go_y) {
			axis = 	AXIS_Y;
			if (coord[y] < (int)(BOARD_SIZE / 2)){
				direction = UP;
			} else {
				direction = UP;
			}
		}

		if (board->snek->head->coord[y] == 0 && board->snek->head->coord[x] == 0) {
			axis = AXIS_Y;
			direction = DOWN;
		}

		show_board(board);
		play_on = advance_frame(axis, direction, board);
		// printf("Going ");

		// if (axis == AXIS_X){
		// 	if (direction == RIGHT){
		// 		printf("RIGHT");
		// 	} else {
		// 		printf("LEFT");
		// 	}
		// } else {
		// 	if (direction == UP){
		// 		printf("UP\n\n\n");
		// 	} else {
		// 		printf("DOWN\n\n\n");
		// 	}
		// } printf("\n");
		usleep(25550);
	}
	end_game(&board);
	CURR_FRAME = 0;
	MOOGLE_FLAG = 0;
}

void output_scores() {
  FILE *output_stream = fopen("hamiltonianV1.txt","w");
	for (int i = 0; i < 1; i++) {
		play_game();
		fprintf(output_stream, "%d\n", SCORE);
		SCORE = 0;

	}
	fclose(output_stream);
}

int main(){
	// int scores[100];
	output_scores();
	return 0;
}
