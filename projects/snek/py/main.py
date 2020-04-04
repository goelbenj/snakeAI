from snek import *
from time import sleep

if __name__ == "__main__":
	#ptr to board
	board = init_board()
	
	play_on = 1
	show_board(board)
	axis = AXIS_INIT
	direction = DIR_INIT
			
	while (play_on):
		#indexing at 0 dereferences the pointer
		x_coord, y_coord = board[0].snek[0].head[0].coord[x], \
						   board[0].snek[0].head[0].coord[y]
		
		#I just realized this is redundantly written
		#Oh well...
		go_x = (axis == AXIS_Y and direction == 1 and y_coord == (BOARD_SIZE - 1)) or \
			   (axis == AXIS_Y and direction == -1 and y_coord == 0)
		
		go_y = (axis == AXIS_X and direction == 1 and x_coord == (BOARD_SIZE - 1)) or \
			   (axis == AXIS_X and direction == -1 and x_coord == 0)
			   
		if go_x:
			axis = AXIS_X
			direction = RIGHT if x_coord < BOARD_SIZE // 2 else LEFT
		elif go_y:
			axis = AXIS_Y
			direction = DOWN if y_coord < BOARD_SIZE // 2 else UP
			
		play_on = advance_frame(axis, direction, board)
		show_board(board)
		sleep(0.65)
	
	#pass by reference to clean memory	
	end_game(byref(board))
