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

    clear_list(&list);
    printf("*************************************************\n");
    //printf("La taille de la liste est = %d\n", length_list(list));
    print_list(list);




    return 0;
}