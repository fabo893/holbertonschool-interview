#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer
 * @number: number to be insert
 *
 * Return: the address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *prev;
    listint_t *current;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    prev = NULL;
    current = *head;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next)
        {
            if (current->n >= new->n)
            {
                prev->next = new;
                new->next = current;
                return (new);
            }
            prev = current;
            current = current->next;
        }
        prev->next = new;
        return (new);
    }
    return (NULL);
}