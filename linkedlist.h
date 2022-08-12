#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

struct element { 
	char val; 
	struct element* prev; 
	struct element* next; 
};

typedef struct element element;

element* create(char val); 

struct element* append(char value, struct element* l);

int add(int index, char value); 

int del(int index);

int change(int index, char value);

void deleteList(); 

void printList(struct element* l); 

struct element* getLast(struct element* l);

#endif
