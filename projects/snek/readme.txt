** WORKING WITH C ** --------------------
The sample main.c code has been pre-compiled for you.
You may run (1): 

	gcc -o snek_AI main.o snek_api.o
	./snek_AI

To test it out.

As you modify main.c, you will need to recompile using (2):
	
	gcc main.c -o main.o -c

Then re-link using (1). Alternatively, the makefile enables you to run:
	
	make snek_AI


** WORKING WITH PYTHON ** -----------------
If you want to change the board size, 
you will have to modify both snek.py and
snek_api.h

you will need to recompile the shared library,

	make libsnek_py.so

and then you 
	
	python3 main.py

should work.
