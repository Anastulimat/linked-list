#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
}Bool;


/*
    Déclaration d'un noeud de la liste chainée
*/
struct linked_list
{
    int value;
    struct linked_list* next;
};

/*
    Rénommage du noeud de la liste chainé
*/
typedef struct linked_list linked_list_node;


/*
    Pointeur sur le premier noued de la liste
*/
typedef linked_list_node* linked_list;

/*====================================================
                        METHODES
====================================================*/
linked_list         new_list();
Bool                isEmpty(linked_list list);
int                 length_list(linked_list list);
void                print_list(linked_list list);
linked_list 		push(linked_list list, int data);
linked_list 		append(linked_list list, int data);
linked_list 		pop_back(linked_list list);
linked_list 		pop_front(linked_list list);

#endif