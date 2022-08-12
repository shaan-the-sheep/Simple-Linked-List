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

element* create(char val){
	struct element* p_elem;
	p_elem = (struct element*) calloc (1,sizeof(struct element));
	(*p_elem).val = val;
	return p_elem;
}	

struct element* getLast(struct element* l){
	while ((*l).next != NULL){
		l = (*l).next;
	} 
	return l;
}

struct element* append(char val, struct element* l){
	struct element* p_elem;
	p_elem = (struct element*) calloc (1,sizeof(struct element));
	(*p_elem).val = val;
	struct element* last_elem = getLast(l);
	(*last_elem).next = p_elem;
	(*p_elem).prev = last_elem;
	return p_elem;
}

void printList(struct element* l){
	while (1){
		printf("%c", (*l).val);
		if ((*l).next == NULL)
			return;
		l = (*l).next;
	}
}
