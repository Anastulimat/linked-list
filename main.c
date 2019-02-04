#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>



int main() {


    /* Début d'opérations */

    linked_list list = new_list();

    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    printf("\n");

    list = push(list, 4);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 7);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 9);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 17);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 17);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 17);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 17);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 17);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = append(list, 17);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = append(list, 23);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    /*
    list = pop_back(list);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = pop_front(list);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);
    */

    printf("\n");


    /* La somme de la liste */


    printf("La somme des éléments de la liste est = %d\n", sum_list(list));

    //clear_list(&list);
    //printf("*************************************************\n");
    //printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    int valeur = 4;

    if(find(list, valeur) != NULL)
        printf("La valeur %d est présente dans la liste !\n", valeur);
    else
        printf("La valeur %d n'existe pas dnas la liste !\n", valeur);

    int array[5] = {3, 7, 14, 17, 23};

    for (int j = 0; j < 5; j++ ) {
      printf("Element[%d] = %d\n", j, array[j] );
    }


    linked_list new_linked_list = new_list();
    linked_list inverse_new_list = new_list();
    linked_list copie_new_list = new_list();

    new_linked_list = linked_list_from_array(array, 5);
    inverse_new_list = inverse_list(new_linked_list);
    copie_new_list = copy_list(new_linked_list);

    printf("\n");

    printf("*** Linked_list_from_array ***\n");
    print_list(new_linked_list);
    printf("*** Inverse_Linked_list ***\n");
    print_list(inverse_new_list);
    printf("*** Copie_new_list ***\n");
    print_list(copie_new_list);

    list = remove_first_occurence(list, 14);
    printf("\n");
    printf("*** list REMOVE 14 ***\n");
    print_list(list);


    list = remove_first_occurence(list, 3);
    printf("\n");
    printf("*** list REMOVE 3 ***\n");
    print_list(list);

    /*
    list = remove_first_occurence(list, 17);
    printf("\n");
    printf("*** list REMOVE 17 ***\n");
    print_list(list);
    */


    list = remove_first_occurence(list, 15);
    printf("\n");
    printf("*** list REMOVE 15 ***\n");
    print_list(list);

    list = remove_all_occurence(list, 17);
    printf("\n");
    printf("*** list REMOVE 17 ***\n");
    print_list(list);

    printf("\n");

    int* new_array = array_from_linked_list(new_linked_list);

    for (int i = 0; i < length_list(new_linked_list); ++i)
    {
        printf("array[%d] = %d\n",i, new_array[i] );
    }

    printf("\n");




    return 0;
}