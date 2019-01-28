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

    while(list)
    {
        printf("[%d] -> ", list->value);
        list = list->next;
    }
    printf("NULL\n");
}


/**
 *
 * func : linked_list new_node(int data)
 *
 * args : data : int ==> la valeur de la donnée à inserer
 *
 * desc : Créer un nouveau noeud avec la donnée pour l'insersion de donnée.
 * 
 * return : node : linked_list ==> Un pointer vers le noeud créé
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
 * func : linked_list push(linked_list list, int data)
 *
 * args : list : linked_list ==> pointeur vers la liste
 *        data : int ==> donnée à inserer
 *
 * desc : Insérer la donnée au début de la liste
 * 
 * return : new_list : linked_list ==> pointeur vers la nouvelle liste créé.
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
 * func : linked_list append(linked_list list, int data)
 *
 * args : list : linked_list ==> pointeur vers la liste
 *        data : int ==> donnée à inserer
 *
 * desc : Insérer la donnée à la fin de la liste
 * 
 * return : new_list : linked_list ==> pointeur vers la nouvelle liste créé.
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
 * func : linked_list pop_back(linked_list list)
 *
 * args : list : linked_list ==> pointeur vers la liste
 *
 * desc : Supprimer le dernier élément de la liste
 * 
 * return : list : linked_list ==> pointeur vers la nouvelle liste créé.
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
 * func : linked_list pop_front(linked_list list)
 *
 * args : list : linked_list ==> pointeur vers la liste
 *
 * desc : Supprimer le premier élément de la liste.
 * 
 * return : list | new_list : linked_list ==> pointeur vers la nouvelle liste créé.
 *        
**/  
linked_list pop_front(linked_list list)
{
    if(isEmpty(list))
        return list;

    //On pointe sur le next du premier élément
    linked_list new_list = list->next;

    //On libère le premier élément et on le met à null
    free(list);
    list = NULL;

    //On retourne la nouvelle liste à partir de la deuxième élément
    return new_list;
}



/**
 *
 * func : int sum_list(linked_list list)
 *
 * args : list : linked_list ==> pointeur vers la liste
 *
 * desc : Calculer la somme des éléments de la liste et la retourner.
 * 
 * return : count : int ==> la somme des éléments de la liste.
 *        
**/    
int sum_list(linked_list list)
{
    int count = 0;

    if(isEmpty(list))
        return 0;

    while(list)
    {
        count += list->value;
        list = list->next;
    }

    return count;
}



/**
 *
 * func : void clear_list(linked_list* list)
 *
 * args : list : linked_list* ==> Un pointeur sur le pointeur de la liste.
 *
 * desc :  Libérer la mémoire d'une liste chianée.
 *         On détruit chaque noeud avec la fonction free()
 *         Afin de libérer toute la structure il faut donner son adresse à la fonction.
 * 
 * return : void
 *        
**/    
void clear_list(linked_list* list)
{
    //Pointeur temporaire
    linked_list ptr;

    //Tant qu'on a encore de données
    while(*list != NULL)
    {
        //On mémorise l'adress pour la suppression
        ptr = *list;
        //On passe au noeud suivant
        *list = (*list)->next;
        //On libère
        free(ptr);
    }
    //On met à NULL
    *list = NULL;
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
linked_list find(linked_list list, int n)
{
    if(!list)
        return list;


    while(list)
    {
        if(list->value == n)
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
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
linked_list linked_list_from_array(int* array, int size)
{
    if(!array)
        return NULL;

    linked_list list = new_list();
    for(int i = 0; i < size; i++) 
    {
        list = append(list, array[i]);
    }

    return list;
}







