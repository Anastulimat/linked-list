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
void				clear_list(linked_list* list);
int                 length_list(linked_list list);
void                print_list(linked_list list);
linked_list 		push(linked_list list, int data);
linked_list 		append(linked_list list, int data);
linked_list 		pop_back(linked_list list);
linked_list 		pop_front(linked_list list);
int 				sum_list(linked_list list);
linked_list 		find(linked_list list, int n);
linked_list 		linked_list_from_array(int* array, int size);
int* 				array_from_linked_list(linked_list list);
linked_list 		inverse_list(linked_list list);
linked_list 		copy_list(linked_list list);

#endif