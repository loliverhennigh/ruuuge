all:
	gcc main.c map.c unit.c print.c curser.c -lncurses -o test
clean:
	rm test
