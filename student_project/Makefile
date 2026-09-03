target=stud_main.o stud_show.o stud_add.o stud_del.o stud_save.o stud_sort.o stud_reverse.o
CC=cc

student:$(target)
	$(CC) $(target) -o student
stud_main.o:stud_main.c
	$(CC) -c stud_main.c
stud_show.o:stud_show.c
	$(CC) -c stud_show.c
stud_add.o:stud_add.c
	$(CC) -c stud_add.c
stud_del.o:stud_del.c
	$(CC) -c stud_del.c
stud_save.o:stud_save.c
	$(CC) -c stud_save.c
stud_sort.o:stud_sort.c
	$(CC) -c stud_sort.c
stud_reverse.o:stud_reverse.c
	$(CC) -c stud_reverse.c
clean:
	@echo "cleaning object file...."
	@rm -vr *.o student
