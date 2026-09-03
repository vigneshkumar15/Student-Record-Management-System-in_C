#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} SLL;

void add_middle(SLL **ptr);
void print_node(SLL *ptr);
int count_node(SLL *ptr);
void save_file(SLL *ptr);
void read_file(SLL **ptr);
void delete_node(SLL **ptr);
void delete_all(SLL **ptr);
void sort_data(SLL *ptr);
void reverse_links(SLL **ptr);

#endif
