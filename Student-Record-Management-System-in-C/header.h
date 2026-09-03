#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct student
{
	int rollno;
	char name[50];
	float percentage;
	struct student *next;
}SLL;

void add_student(SLL **);
void delete_student(SLL **);
void delete_all(SLL **);
void print_node(SLL *);
void modify_student(SLL *);
void save_file(SLL *);
void read_file(SLL **);
void sort_student(SLL *);
void reverse_list(SLL **);
void free_all(SLL **);
int roll_exists(SLL *,int);
int get_roll(SLL *);

#endif
