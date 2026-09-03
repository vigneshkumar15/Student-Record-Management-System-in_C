target=main.o add.o delete.o show.o modify.o file.o sort.o reverse.o
CC=cc

student:$(target)
	$(CC) $(target) -o student

main.o:main.c
	$(CC) -c main.c

add.o:add.c
	$(CC) -c add.c

delete.o:delete.c
	$(CC) -c delete.c

show.o:show.c
	$(CC) -c show.c

modify.o:modify.c
	$(CC) -c modify.c

file.o:file.c
	$(CC) -c file.c

sort.o:sort.c
	$(CC) -c sort.c

reverse.o:reverse.c
	$(CC) -c reverse.c

clean:
	rm -f *.o student
