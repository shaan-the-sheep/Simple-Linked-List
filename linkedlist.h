#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

struct element { 
	char val; 
	struct element* prev; 
	struct element* next; 
};

typedef struct element element;

element* create(char val); //done

element* append(char value, struct element* l); //done

element* add(element* l, int index, char value); 

element* del(element* l, int index);

element* change(element* l, int index, char value); //done

void deleteList(); 

void printList(struct element* l); //done

element* getLast(struct element* l);

#endif
