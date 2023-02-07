#include "main.h"

void	init_queue(t_queue *queue)
{
	ft_printf("init q start\n");
    queue->front = NULL;
	queue->rear = NULL; 
    queue->count = 0;    // 큐 안의 노드 개수를 0으로 설정
	ft_printf("init q end\n");
}

int is_empty(t_queue *queue)
{
    return (queue->count == 0);    // 큐안의 노드 개수가 0이면 빈 상태
}

void enqueue(t_queue *queue, int x, int y)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node)); // newNode 생성
    new_node->pos.x = x;
	new_node->pos.y = y;
    new_node->next = NULL;
 
    if (is_empty(queue))    // 큐가 비어있을 때
    {
        queue->front = new_node;       
    }
    else    // 비어있지 않을 때
    {
        queue->rear->next = new_node;    //맨 뒤의 다음을 newNode로 설정
    }
    queue->rear = new_node;    //맨 뒤를 newNode로 설정   
    queue->count++;    //큐안의 노드 개수를 1 증가
}

t_pos dequeue(t_queue *queue)
{
    t_pos	data;
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
