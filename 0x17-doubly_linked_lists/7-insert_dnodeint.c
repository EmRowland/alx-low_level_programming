#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: integer to be included in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    unsigned int i;
    dlistint_t *new_node, *temp = *h;

    new_node = malloc(sizeof(dlistint_t));
    if (!new_node || !h)
        return (NULL);

    new_node->n = n;

    if (idx == 0)
    {
        new_node->next = *h;
        new_node->prev = NULL;
        if (*h)
            (*h)->prev = new_node;
        *h = new_node;
        return (new_node);
    }

    for (i = 0; temp && i < idx - 1; i++)
    {
        temp = temp->next;
    }

    if (!temp || !(temp->next))
        return (NULL);

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;

    return (new_node);
}
