#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

/**
 *
 * func : linked_list new_list()
 *
 * args : void
 *
 * desc : Créer une nouvelle liste
 * 
 * return : NULL
 *        
**/    
linked_list new_list()
{
    return NULL;
}



/**
 *
 * func : Bool isEmpty(linked_list list)
 *
 * args : Pointeur sur la liste (la liste)
 *
 * desc : Vérifier si la liste est vide.
 * 
 * return : Bool ==> ture | false
 *        
**/    
Bool isEmpty(linked_list list)
{
    if(!list) 
        return true;

    return false;
}


/**
 *
 * func : int length_list(linked_list list)
 *
 * args : Pointeur sur la liste (la liste)
 *
 * desc : Calculer la taille d'une liste chainée et la retournée.
 * 
 * return : int ==> la taille de la liste
 *        
**/    
int length_list(linked_list list)
{
    int size = 0;

    if(!isEmpty(list))
    {
        while(list)
        {
            size++;
            list = list->next;
        }
    }

    return size;
}



/**
 *
 * func : void print_list(linked_list list)
 *
 * args : Pointeur sur la liste (la liste)
 *
 * desc : Afficher tous les éléments de la listes chianeé
 * 
 * return : void
 *        
**/    
void print_list(linked_list list)
{
    if(isEmpty(list))
    {
        printf("Rien à afficher, la liste est vide !\n");
        return;
    }

    linked_list l = list;
    while(l)
    {
        printf("[%d] -> ", l->value);
        l = l->next;
    }
    printf("NULL\n");
}


/**
 *
 * func : 
 *
 * args : 
 *
 * desc : 
 * 
 * return : 
 *        
**/
linked_list new_node(int data)
{
    linked_list node = (linked_list) malloc(sizeof(linked_list_node));
    if(!node)
    {
        printf("malloc __NEW_NODE__ error !\n");
        exit(0);
    }
    node->value = data;
    node->next = NULL;

    return node;
}


/**
 *
 * func : 
 *
 * args : 
 *
 * desc : 
 * 
 * return : 
 *        
**/    
linked_list push(linked_list list, int data)
{
    //Création d'un noeud 
    linked_list new_list = new_node(data);
    
    //Pointer sur le début de la list
    new_list->next = list;

    //Ancien pointeur est désormais unutil
    list = NULL;

    return new_list;
}



/**
 *
 * func : 
 *
 * args : 
 *
 * desc : 
 * 
 * return : 
 *        
**/
linked_list append(linked_list list, int data)
{
    //Si la liste est vide
    if(isEmpty(list))
    {
        list = new_node(data);
        return list;
    }

    //On créer un pointuer qui pointe sur la même liste
    linked_list current = list;

    //On parcourt la liste jsuqu'à la fin
    while(current->next != NULL)
    {
        current = current->next;
    }
    //On insert l'élément à la fin
    current->next = new_node(data);

    return list;
}



/**
 *
 * func : 
 *
 * args : 
 *
 * desc : 
 * 
 * return : 
 *        
**/    
linked_list pop_back(linked_list list)
{
    //Le cas où la liste est vide
    if(isEmpty(list))
        return list;

    //Le cas où on a un élément 
    if(length_list(list) == 1)
    {
        free(list);
        return list = NULL;
    }

    //Nous avons besoin de deux variables pour stocker le noeud courant et le noeud précédant
    linked_list current = list;
    linked_list before = list;

    //On parcourt la liste jsuqu'à la fin
    while(current->next != NULL)
    {
        before = current;
        current = current->next;
    }
    before->next = NULL;

    free(current);
    current = NULL;

    return list;
}



/**
 *
 * func : 
 *
 * args : 
 *
 * desc : 
 * 
 * return : 
 *        
**/    
linked_list pop_front(linked_list list)
{
    if(isEmpty(list))
        return list;

    linked_list new_list = list->next;

    free(list);
    list = NULL;

    return new_list;
}





