#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp = *head;
    unsigned int i;

    if (!head || !*head)
        return (-1);

    if (index == 0)
    {
        *head = temp->next;
        if (temp->next)
            temp->next->prev = NULL;
        free(temp);
        return (1);
    }

    for (i = 0; temp && i < index - 1; i++)
    {
        temp = temp->next;
    }

    if (!temp || !(temp->next))
        return (-1);

    temp->next = temp->next->next;
    if (temp->next)
        temp->next->prev = temp;
    free(temp->next);

    return (1);
}
