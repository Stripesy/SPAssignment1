#ifndef SORT_H_
#define SORT_H_

void sortList(IORB **head,int(*prio)(int)) {

    IORBPtr current = *head;
    IORBPtr largest = NULL;
    IORBPtr beforeLargest = NULL;
    IORBPtr before = current;
    IORBPtr next = NULL;
    IORBPtr lastSorted = NULL;

    while(current != NULL) {
        largest = current;
        next = current->link;

        while(next != NULL) {
            if(((prio)(next->base_pri) > (prio)(largest->base_pri))) {
                largest = next;
                beforeLargest = before;
            }
            before = next;
            next = next->link;
        }
    
        if(largest != current) {

            IORB savedLink = *current;

            
            current->link = largest->link;   

            if(largest != savedLink.link) {
                largest->link = savedLink.link; // if not adjacent
                beforeLargest->link = current; 
            }
            else { // if adjacent
                largest->link = current;
            }
            
            if(current == *head)
                *head = largest; 
            else
                lastSorted->link = largest;
            

        }
        lastSorted = largest;
        current = largest->link;
        }
}

#endif
