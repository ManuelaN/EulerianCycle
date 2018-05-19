#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct node{
    int info;
    struct node *next;
};
void push_begining_list(struct node *head, int new_element_value);
int pop_end_list(struct node *head);


#endif // NODE_H_INCLUDED
