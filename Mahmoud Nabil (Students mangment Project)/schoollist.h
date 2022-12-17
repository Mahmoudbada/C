/**************************************/
/* Description : schoollist.h         */
/* Author      : Mahmoud Nabil        */
/* Date        : 16 Dec 2022          */
/**************************************/



#ifndef SCHOOLLIST_H
#define SCHOOLLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



struct student
{
   int ID;
   int score;
   char Address[25];
   char name[25] ;
   char number[20];
   int day,month,year;

   struct student *next;
};

void insertAtLast();
void printList(void);
void editeData();
void editeScore();
void DeleteStudent();
void SortList();
static void swap(struct student* a,struct student* b);


#endif