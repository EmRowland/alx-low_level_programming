#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: integer to be included in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i;
    listint_t *new_node, *temp = *head;

    new_node = malloc(sizeof(listint_t));
    if (!new_node || !head)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    for (i = 0; temp && i < idx; i++)
    {
        if (i == idx - 1)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            return (new_node);
        }
        else
            temp = temp->next;
    }

    return (NULL);
}
