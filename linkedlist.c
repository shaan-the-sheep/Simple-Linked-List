/*
 * linkedlist.c
 * 
 * Copyright 2022 Shaan <shaan@shaan-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

static int getLength(element* l){
	if (l == NULL)
		return -1;
	int length = 1;
	while (l->next != NULL){
		length++;
		l = l->next;
	}
	return length;
}

element* getAtIndex(element* l, int index){
	if (l == NULL)
		return NULL;

	int n = getLength(l);
	if (n == -1 || index > n)
		return NULL;
		
	for(int i = 0; i < index - 1; i++){
		l = l->next;
	}
	return l;
}	
	
element* create(char val){
	element* p_elem;
	p_elem = (element*) calloc (1,sizeof(element));
	p_elem->val = val;
	return p_elem;
}	

element* getLast(element* l){
	if (l == NULL)
		return NULL;
	while (l->next != NULL){
		l = l->next;
	} 
	return l;
}

element* append(char val, element* l){
	if (l == NULL)
		return NULL;	
	struct element* p_elem;
	p_elem = (struct element*) calloc (1,sizeof(struct element));
	p_elem->val = val;
	struct element* last_elem = getLast(l);
	(*last_elem).next = p_elem;
	(*p_elem).prev = last_elem;
	return p_elem;
}

void printList(element* l){	
	while (1){
		printf("%c", (*l).val);
		if (l->next == NULL)
			return;
		l = (*l).next;
	}
}

element* changeAtIndex(element* l, int index, char value){
	element* p = getAtIndex(l, index);
	if (p == NULL)
		return NULL;
	p->val = value;
	return p;
}

element* addAtIndex(element* l, int index, char value){
	if (l == NULL)
		return NULL;

	int n = getLength(l);
	if (n == -1 || index > n)
		return NULL;
		
	for(int i = 0; i < index - 1; i++){
		l = l->next;
	}
	element* new_elem = (element*) calloc (1,sizeof(element));
	new_elem->next = l;
	new_elem->val = value;
	new_elem->prev = (*l).prev;
	l->prev->next = new_elem;
	l->prev = new_elem;
	return l;
}

int delAtIndex(element* l, int index){
	if (l == NULL)
		return -1;

	int n = getLength(l);
	if (n == -1 || index > n)
		return -1;
		
	for(int i = 0; i < index - 1; i++){
		l = (*l).next;
	}
	l->prev->next = l->next;
	l->next->prev = l->prev;
	free(l);
	return 0;
}		

int deleteList(element*l){
	if (l == NULL)
		return 0;
	element* next, *head = l;
	while (head->next != NULL){
		next = head->next;
		free(head);
		head = next;
	}
	free(head);
	return 0;
}
		

