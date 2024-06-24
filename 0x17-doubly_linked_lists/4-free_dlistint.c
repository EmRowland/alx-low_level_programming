#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list to be freed
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *temp;

    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}
