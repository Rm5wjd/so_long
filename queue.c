/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:42:54 by junglee           #+#    #+#             */
/*   Updated: 2023/02/15 21:19:23 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_queue(t_queue *queue)
{
	ft_printf("init q start\n");
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
	ft_printf("init q end\n");
}

int	is_empty(t_queue *queue)
{
	return (queue->count == 0);
}

void	enqueue(t_queue *queue, int x, int y)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->pos.x = x;
	new_node->pos.y = y;
	new_node->next = NULL;
	if (is_empty(queue))
	{
		queue->front = new_node;
	}
	else
	{
		queue->rear->next = new_node;
	}
	queue->rear = new_node;
	queue->count++;
}

t_pos	dequeue(t_queue *queue)
{
	t_pos		data;
	t_node		*ptr;

	data.x = 0;
	data.y = 0;
	if (is_empty(queue))
	{
		ft_printf("Error : Queue is empty!\n");
		return (data);
	}
	ptr = queue->front;
	data = ptr->pos;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;
	return (data);
}
