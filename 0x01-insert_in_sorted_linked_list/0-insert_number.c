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
	listint_t *new, *prev, *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	prev = NULL;
	current = *head;

	if (*head == NULL || new->n < current->n)
	{
		new->next = current;
		*head = new;
		return (new);
	}
	else
	{
		while (current)
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
