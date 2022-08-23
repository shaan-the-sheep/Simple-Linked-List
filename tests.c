/*
 * tests.c
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

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include <stdio.h>
#include "linkedlist.h"

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, Create)
{
	element* p = create('a');
	CHECK(p != NULL);
	CHECK_EQUAL(p->val,'a');
	CHECK_EQUAL(p->prev, (element*)NULL);
	CHECK_EQUAL(p->next, (element*)NULL);
    free(p);
}

TEST(FirstTestGroup, Append)
{
	element* p = create('a');
	element* new_elem = append('b', p);
	CHECK_EQUAL(new_elem->val,'b');
	free(p);
	free(new_elem);
}	

TEST(FirstTestGroup, printList)
{
	element* p = create('a');
	element* new_elem = append('b', p);
	printList(p);
	free(p);
	free(new_elem);
}

TEST(FirstTestGroup, getLast)
{
	element* p = create('a');
	element* last = getLast(p);
	CHECK_EQUAL(last->val,'a');
	(void)append('b', p);
	(void)append('c', p);
	(void)append('d', p);
	last = getLast(p);
	CHECK_EQUAL(last->val,'d');
	free(p);
}

TEST(FirstTestGroup, change)
{
	element* p = create('a');
	append('b', p);
	append('c', p);
	append('d', p);
	element* l = changeAtIndex(p, 3, '!');
	CHECK_FALSE(l == NULL);
	CHECK_EQUAL(l->val, '!');
}

TEST(FirstTestGroup, addAtIndex)
{
	element* a;
	element* p = create('a');
	append('b', p);
	append('c', p);
	append('d', p);
	append('e', p);		// count = 5
	a = addAtIndex(p, 2, '!');		// count = 6
	CHECK_FALSE(a == NULL);
	element* z = getAtIndex(p, 2);
	CHECK_EQUAL(z->val, '!');
	a = addAtIndex(p, 6, '?');		// count = 7
	CHECK_FALSE(a == NULL);
	z = getAtIndex(p, 6);
	CHECK_EQUAL(z->val, '?');

	// Try to add elem at very end, which should fail
	a = addAtIndex(p, 8, '/');
	CHECK(a == NULL);
}

TEST(FirstTestGroup, deleteAtIndex)
{
	element* p = create('a');
	append('b', p);
	append('c', p);
	append('d', p);
	CHECK_EQUAL(delAtIndex(p, 3), 0);
	element* e = getAtIndex(p, 3);
	CHECK_EQUAL(e->val, 'd');

    CHECK_EQUAL(delAtIndex(p, 99), -1);
}

TEST(FirstTestGroup, deleteList)
{
	element* p = create('a');
	append('b', p);
	append('c', p);
	append('d', p);
	CHECK(deleteList(p) == 0);

	CHECK(deleteList(NULL) == 0);
}


TEST(FirstTestGroup, printReverse)
{	
	element* p = create('a');
	append('b', p);
	append('c', p);
	append('d', p);
	printf("List to reverse: \n");
	printList(p);
	printf("\nReversed list: ");
	printReverse(p);
	printf("\n");

}	

					
int main(int ac, char** av){
	return CommandLineTestRunner::RunAllTests(ac,av);
}
