#ifndef LIST_H_
#define LIST_H_

typedef struct iorb {
    int base_pri; // base priority
    char filler[100]; // description about block
    struct iorb *link; // pointer to next block
} IORB, *IORBPtr;

void sortList(IORB **head,int(*prio)(int)) {
}

int priComp(int basepriority) {

    return basepriority%7; //to be properly implemented. Currently just a filler.

}

void buildList(IORB** head,int size) {

    IORBPtr last = NULL;
    *head = NULL;

    for(int i = 0; i < size; i++) {
        IORBPtr current = (IORBPtr)malloc(sizeof(IORB));

        current->link = NULL;

        char buffer[33];
        itoa(i, buffer,10);

        strcpy(current->filler,buffer);

        current->base_pri = rand() % 100 + 1;

        if(*head == NULL) {
           *head = current;
        }
        else {
            last->link = current;
        }
        last = current;
        

    }



}

void printList(IORBPtr head, int (*prio)(int)) {

    IORBPtr current = head;

    while(current != NULL) {
        printf("Block Description: %s, ", current->filler);
        printf("Base Priority: %d, ", current->base_pri);
        printf("Priority: %d, \n",(prio)(current->base_pri));
        current = current->link;
    }

}

#endif
