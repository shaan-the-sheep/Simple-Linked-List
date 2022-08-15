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
	CHECK_EQUAL((*p).val,'a');
	CHECK((*p).prev == NULL);
	CHECK((*p).next == NULL);
    free(p);
}

TEST(FirstTestGroup, Append)
{
	element* p = create('a');
	element* new_elem = append('b', p);
	CHECK_EQUAL((*new_elem).val,'b');
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
	CHECK_EQUAL((*last).val,'a');
	(void)append('b', p);
	(void)append('c', p);
	(void)append('d', p);
	last = getLast(p);
	CHECK_EQUAL((*last).val,'d');
	free(p);
}

TEST(FirstTestGroup, change)
{
	element* p = create('a');
	append('b', p);
	append('c', p);
	append('d', p);
	change(p, 3, '!');
	printf("Changed list: ");
	printList(p);
	printf("\n");
}

TEST(FirstTestGroup, add)
{
	element* p = create('a');
	append('b', p);
	append('c', p);
	append('d', p);
	add(p, 2, '!');
	printf("Testing add: ");
	printList(p);
	printf("\n");
}
				
int main(int ac, char** av){
	return CommandLineTestRunner::RunAllTests(ac,av);
}
