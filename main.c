#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#include "List.h"

void main() {
    
    srand(time(0));

    int size = 9;

    IORBPtr head;

    buildList(&head,size);

    int (*priority) (int)=priComp;

    printList(head,priority);

}