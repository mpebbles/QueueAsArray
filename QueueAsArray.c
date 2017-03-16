// QueueAsArray.c - Created by Mitchell Pebbles on 16 March 2017
// A simple program which implements a queue of ints as an array using modolo arithmetic
// User input can be easily implemented at later date
#include<stdio.h>
 
#define MAX_SIZE 4

int queue[MAX_SIZE]; 
int current_size = 0;
int back_index = -1;
int front_index = 0;

void enqueue(int num);
int dequeue();
int peek();

int main() 
{
    printf("queue size is %d\n", MAX_SIZE);
    printf("enqueue 5 elements\n");
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("should give error message: \n");
    enqueue(4);
    printf("dequeue in order: \n");
    while(current_size > 0) 
    {
        printf("%d\n", dequeue());
    }
    printf("should give error message: \n");
    dequeue();
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("peek: %d\n", peek());
    printf("dequeue in order: \n");
    while(current_size > 0) 
    {
        printf("%d\n", dequeue());
    }
    printf("should give error message: \n");
    dequeue(); 
    return 0;
}

void enqueue(int num) 
{
    if(current_size == MAX_SIZE)
    {
        printf("Unable to insert %d into queue - maximum capacity reached\n", num);
        return;
    }
    back_index = (back_index + 1)%MAX_SIZE;
    queue[back_index] = num; 
    current_size++;
}

int dequeue() 
{
    if(current_size == 0) 
    {
        printf("Unable to dequeue - current size of queue is 0\n");
        return -1;
    }
    int item = queue[front_index];
    front_index = (front_index + 1)%MAX_SIZE;
    current_size--;
    // if queue is empty, reset 
    if(current_size == 0)
    {
        //reset front_index
        front_index = 0;
        // reset back_index
        back_index = -1;
    }
    return item;
}

int peek() 
{
    if(current_size != 0)
        return queue[front_index];
    printf("Unable to peek - current size of queue is 0\n");
    return -1;
}


