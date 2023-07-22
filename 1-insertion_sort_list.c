#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - insert sort implementation
 * @list: double linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *next_to_sort, *before;

if (!list || !*list || !(*list)->next)
return;

for (current = (*list)->next; current; current = next_to_sort)
{
next_to_sort = current->next;

for (before = current->prev;
before && current->n < before->n;
before = current->prev)
{
/* swap current with before */
/* remove current from old place */
before->next = current->next;
if (current->next)
current->next->prev = before;

/* put current in new place */
current->prev = before->prev;
current->next = before;
if (current->prev)
current->prev->next = current;
else
*list = current;
before->prev = current;

print_list(*list);
}
}
}
