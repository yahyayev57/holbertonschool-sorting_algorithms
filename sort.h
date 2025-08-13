#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - doubly linked list node
 * @n: integer stored in the node
 * @prev: points to the previous element of the list
 * @next: points to the next element of the list
 *
 * Description: doubly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);

#endif /* SORT_H */
