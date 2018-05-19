#include <stdio.h>
#include <stdlib.h>
#include "node.h"


void push_begining_list(struct node *head, int new_element_value){
    struct node *next_element;
    struct node *new_element;

    next_element = head->next;
    new_element = malloc(sizeof(struct node));
    new_element->info = new_element_value;
    new_element->next = head->next;
    head->next = new_element;
}

int pop_end_list(struct node *head){
    struct node *deleted_element;
    struct node *iterator;
    int aux;

    if (head->next != NULL) {
        for (iterator = head; iterator->next->next != NULL; iterator = iterator->next);
        deleted_element = iterator->next;
        aux = deleted_element->info;
        iterator->next = deleted_element->next;
        free(deleted_element);
        return aux;
    } else {
        printf("\n The list is empty");
        return -1; //the list is empty
    }


}
