#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t list
 * @head: double pointer to the head of the list
 *
 * Return: the head node's data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int n;

    if (!head || !*head)
        return (0);

    n = (*head)->n;
    temp = (*head)->next;
    free(*head);
    *head = temp;

    return (n);
}
