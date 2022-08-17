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

element* addAtIndex(element* l, int index, char value); //done

int delAtIndex(element* l, int index); //done

element* changeAtIndex(element* l, int index, char value); //done

int deleteList(element* l); 

void printList(struct element* l); //done

element* getLast(struct element* l); //done

element* getAtIndex(element* l, int index);

#endif
