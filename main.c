#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "List.h"
#include "Sort.h"

void main() {

    srand(time(0));

    int size = 10;

    IORBPtr head;

    int (*priority) (int)=priComp;

    int userInput = -1;

    while(userInput != 0) {

        printf("\nPlease enter your choice: \n 0: Exit\n 1: Build List\n 2: Sort list\n 3: Display list\n");

        scanf("%d", &userInput);

        switch(userInput) {
        
            case 1:
            buildList(&head,size);
            break;
            case 2:
            sortList(&head,priority);
            break;
            case 3:
            printList(head,priority);
            break;
        }
    }

}