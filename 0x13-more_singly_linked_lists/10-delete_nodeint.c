#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Delete a node at espcified index (idx).
 * @head: head of the linked list.
 * @index: index nth node.
 *
 * Return: 1 if it succedded, -1 it it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *aux;
	listint_t *temp;
	unsigned int idx;

	idx = 0;
	temp = *head;
	if (*head == NULL)
		return (-1);
	if (temp->next == NULL && index == 0)
	{
		free(*head);
		return (1);
	}
	if (temp->next == NULL && index > 0)
		return (-1);
	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}
	while (idx != (index - 1))
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (-1);
		idx++;
	}
	aux = temp->next;
	temp->next = aux->next;
	free(aux);
	return (1);
}