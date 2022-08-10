#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

struct element { 
	char val; 
	struct element* prev; 
	struct element* next; 
};

struct element* create(char val); 

int append(char value);

int add(int index, char value); 

int del(int index);

int change(int index, char value);

void deleteList(); 

void printList(); 

#endif
