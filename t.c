#include <stdio.h>
#include <limits.h>

#define SIZE 10

int queue[SIZE], front = -1, rear = -1;
int stack[SIZE], top = -1;
int v[SIZE] = {0};
int graph[SIZE][SIZE];

void push(int val)
{
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
        return stack[top--];
}

void enqueue(int val)
{
    if (rear == SIZE - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
        return queue[front++];
}

void bfs(int s, int n)
{
    int p, n;
    int i;
    enqueue(s);
    v[s] = 1;
    p = dequeue();

    if (p != 0)
    {
        printf("%d", p);
    }
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
        {
            if (graph[p][i] != 0 && v[i] == 0)
            {
                add(i);
                v[i] = 1;
            }
        }
        p = dequeue();
        if (p != 0)
        {
            print("%d", p);
        }
    }
    for (i = 0; i <= n; i++)
    {
        if (v[i] != 0)
            bfs(i, n);
    }
}