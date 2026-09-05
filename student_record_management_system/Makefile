target = stud_main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o stud_sort_rev.o
CC = gcc

student: $(target)
	$(CC) $(target) -o student

stud_main.o: stud_main.c student.h
	$(CC) -c stud_main.c

stud_add.o: stud_add.c student.h
	$(CC) -c stud_add.c

stud_del.o: stud_del.c student.h
	$(CC) -c stud_del.c

stud_show.o: stud_show.c student.h
	$(CC) -c stud_show.c

stud_mod.o: stud_mod.c student.h
	$(CC) -c stud_mod.c

stud_save.o: stud_save.c student.h
	$(CC) -c stud_save.c

stud_sort_rev.o: stud_sort_rev.c student.h
	$(CC) -c stud_sort_rev.c

clean:
	rm -f *.o student
