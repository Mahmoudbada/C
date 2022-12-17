/**************************************/
/* Description : schoollist.c         */
/* Author      : Mahmoud Nabil        */
/* Date        : 16 Dec 2022          */
/**************************************/

#include "schoollist.h"


struct student *head = NULL;
struct student *current = NULL;
struct student *prev = NULL;

void insertAtLast()
{
   struct student *new = (struct student*) malloc(sizeof(struct student));
    printf("please enter the Student Name\n");
    fflush(stdin);
    fgets(new->name, 25, stdin);


    printf("please enter the Student ID\n");
    scanf("%d",&(new->ID));
    fflush(stdin);
	
    printf("please enter the Student number\n");
    fgets(new->number, 20, stdin);
    fflush(stdin);

    printf("please enter the Student Date like day month year\n");
    scanf("%d %d %d",&(new->day),&(new->month),&(new->year));
    fflush(stdin);
    // scanf(" %d",&(new->month));
    // fflush(stdin);
    // scanf(" %d",&(new->year));
    // fflush(stdin);

    printf("please enter the Student address\n");
    fgets(new->Address, 25, stdin);
    fflush(stdin);

    printf("please enter the Student Score\n");
    scanf("%d",&(new->score));

    while(0>(new->score) || (new->score)>100)
    {
        printf(" score is out of range choose number form 0:100 \n:");
         scanf(" %d",&(new->score));
    }

    fflush(stdin);


   new->next = NULL;

   // If head is empty, create new list
   if(head==NULL)
   {
      head = new;
      return;
   }

   current = head;

   // loop until reach the last student in the old list
   while(current->next != NULL)
   {
	   current = current->next;
   }

   // Make the last student in the old list point to new student
   current->next = new;
   printf ("The student added successfully\n");
}


void printList(void)
{   
   int counter=0;
   struct student *ptr = head;

   if(head==NULL)
   {
       printf("                                              *********************\n");
	   printf("                                              ( The List is empty )\n");
       printf("                                              *********************\n");
   }
   else
   {
    printf("-------------------------------------------------List of Students------------------------------------------------------\n");

   //start looping from the head until the last student
   while(ptr != NULL)
   {
      counter++;
      printf("student number : %d\n",counter);
      printf("---------------------------------------------------------------------------------------------------------------------\n");
      printf("                Student Name                      : %s",ptr->name);
      printf("                Student Date                      : %d/%d/%d\n",ptr->day,ptr->month,ptr->year);
      printf("                Student ID                        : %d\n",ptr->ID);  
      printf("                Student Address                   : %s",ptr->Address);
      printf("                Student Phone Number              : %s",ptr->number);
      printf("                Student Score in computer_science : %d\n",ptr->score);
      printf("----------------------------------------------------------------------------------------------------------------------\n");
      ptr = ptr->next;
      
   }

   printf(" end of list\n");
   }
}


void editeData()
{
   int pos = 0,ID;

   if(head==NULL)
   {
       printf("                                              *********************\n");
	   printf("                                              ( The List is empty )\n");
       printf("                                              *********************\n");
   }

   else 
   {
    printf("the ID to change the Data = ");
    scanf("%d",&ID);


   // start checking from the first student
   current = head;
   while(current != NULL)
   {
      if(current->ID == ID)
      {
        // printf("\nNewscore = ");
        // scanf("%d",&(current->score));
        //  printf("student ID %d new Scoure = %d\n",ID,current->score);

            printf("please enter the Student Name\n");
            fflush(stdin);
            fgets(current->name, 25, stdin);


            printf("please enter the Student ID\n");
            scanf("%d",&(current->ID));
            fflush(stdin);

            printf("please enter the Student number\n");
            fgets(current->number, 20, stdin);
            fflush(stdin);

            printf("please enter the Student Date like day month year\n");
            scanf(" %d",&(current->day));
            fflush(stdin);
            scanf(" %d",&(current->month));
            fflush(stdin);
            scanf(" %d",&(current->year));
            fflush(stdin);

            printf("please enter the Student address\n");
            fgets(current->Address, 25, stdin);
            fflush(stdin);

            printf("please enter the Student Score\n");
            scanf("%d",&(current->score));

            while(0>(current->score) || (current->score)>100)
            {
                printf(" score is out of range choose number form 0:100 \n:");
                scanf(" %d",&(current->score));
            }

            fflush(stdin);
        
      }
      current = current->next;
      pos++;
   }
   // item not found in the list
   printf("%d does not exist in the list\n", ID);
   }
}

void editeScore()
{
   int pos = 0,ID;

   if(head==NULL)
   {
       printf("                                              *********************\n");
	   printf("                                              ( The List is empty )\n");
       printf("                                              *********************\n");
   }
   else 
   {
    printf("the ID to change the scoure = ");
    scanf("%d",&ID);

   // start checking from the first student
   current = head;
   while(current != NULL)
   {
      if(current->ID == ID)
      {
        printf("\nNewscore = ");
        scanf("%d",&(current->score));
        while(0>(current->score) || (current->score)>100)
        {
            printf(" score is out of range choose number form 0:100 \n:");
            scanf(" %d",&(current->score));
        }
         printf("student ID %d new Scoure = %d\n",ID,current->score);
         return;
      }
      current = current->next;
      pos++;
   }
   // item not found in the list
   printf("%d does not exist in the list\n", ID);
   }
}


void DeleteStudent()
{
   int pos = 0,ID;
   struct student * delete_node = NULL;

   //check if the linked list is empty
   if(head==NULL)
   {
	   printf("                                              *********************\n");
	   printf("                                              ( The List is empty )\n");
       printf("                                              *********************\n");
   }
    else
    {
    printf("the ID to Delete the student= ");
    scanf("%d",&ID);

   //check the first node in the linked list
    if (head->ID == ID)
   {
	   delete_node = head;
	   // move head to next node
	   head = head->next;
	   printf("%d was found and deleted \n",ID);
	   free(delete_node);
	   return;
   }

   //check the rest of nodes in the linked list
   pos++;
   current = head->next;
   prev = head;
   while(current != NULL)
   {
	   if(current->ID == ID)
	   {
		   //element found
		   delete_node = current;
		   prev->next = current->next;
		   printf("%d was found and deleted \n", ID);
		   free(delete_node);
		   return;
	   }
	   prev = current;
	   current = current->next;
	   pos++;
   }

   //in case the data not found in the linked list
   if(delete_node == NULL)
   {
	   printf("%d not found in the List.",ID);
   }
    }
}

void SortList()
{
	int swapped, i;
    int temp;
    struct student * Sptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
    {
       printf("                                              *********************\n");
	   printf("                                              ( The List is empty )\n");
       printf("                                              *********************\n");
    }
	else 
	{
		do {
			swapped = 0;
			current = head;
			while (current->next != Sptr)
			{
				if (current->score < current->next->score)
				{
					swap(current, current->next);
					swapped = 1;
				}
				current = current->next;
			}
			Sptr = current;
		} while (swapped);

		printf("Sorting is done:)\n");
	}
	
}

static void swap(struct student* a,struct student* b)
{
	struct student* temp = (struct student*)malloc(sizeof(struct student));

    /*swap the Address*/
    strcpy(temp->Address, a->Address);
    strcpy(a->Address, b->Address);
    strcpy(b->Address, temp->Address);

    /*swap the name*/
    strcpy(temp->name, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, temp->name);

    /*swap the number*/
    strcpy(temp->number, a->number);
    strcpy(a->number, b->number);
    strcpy(b->number, temp->number);

    /*swap the score*/
    temp->score = a->score;
    a->score = b->score;
    b->score = temp->score;

    /*swap the day*/
    temp->day = a->day;
    a->day = b->day;
    b->day = temp->day;

    /*swap the month*/
    temp->month = a->month;
    a->month = b->month;
    b->month = temp->month;

    /*swap the year*/
    temp->year = a->year;
    a->year = b->year;
    b->year = temp->year;

    /*swap the ID*/
    temp->ID = a->ID;
    a->ID = b->ID;
    b->ID = temp->ID;

    free(temp);
	
}
