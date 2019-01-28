#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>



int main() {

    linked_list list = new_list();

    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 4);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 7);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = push(list, 9);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = append(list, 17);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = append(list, 23);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = pop_back(list);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

    list = pop_front(list);
    printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);

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
    new_linked_list = linked_list_from_array(array, 5);

    print_list(new_linked_list);



    return 0;
}