/**************************************/
/* Description : main.c               */
/* Author      : Mahmoud Nabil        */
/* Date        : 16 Dec 2022          */
/**************************************/

#include <stdio.h>
#include <stdlib.h>

#include"schoollist.h"


int main(void)
{
    int infi=1,ID=0;
    while (infi ==1)
    {
        int choose;
        printf("                             =====================================================\n");
        printf("                                          Wellcome to ITI School\n");
        printf("                                            Mahmoud Nabil Saber \n");
        printf("                             =====================================================\n");
        printf("                             To Add new Studen                          choose '1'\n");
        printf("                             To Print the list                          choose '2'\n");
        printf("                             To Delete student                          choose '3'\n");
        printf("                             To Edit (update) student data              choose '4'\n");
        printf("                             To sort the students based on the score    choose '5'\n");
        printf("                             To edite score                             choose '6'\n");
        printf("                             To Close the system                        choose '7'\n");
        printf("                             =====================================================\n");
		printf("---> Your choice is : ");
        scanf("%d",&choose);

        switch (choose)
        {
        case 1:
            insertAtLast();
            break;
        
        case 2:
            /*print the list*/
            printList();
            break;

        case 3:
            /*Delete student*/

            DeleteStudent ();
            break;

        case 4:
            /*update data of student*/
            editeData ();
            break;

        case 5:
            /*rank students*/
			SortList();
            break;
        case 6:
            /*to edite score*/
            editeScore();
            break;
        case 7:
        /*to close the system*/
            infi = 0;
            break;

        default:
            printf("Invalide choice\n");
            break;
        }
    }

	return 0;
}
