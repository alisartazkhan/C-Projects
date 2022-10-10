arrayz.o: arrayz.c
	gcc -Wall -Werror -std=c11 -c arrayz.c
basketball: basketball.c
	gcc -Wall -Werror -std=c11 -o basketball basketball.c arrayz.o -lm
clean:
	rm -f arrayz.o basketball