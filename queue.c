#include<stdio.h>
#include<limits.h>
#include "queue.h"
//initialize the queue
void init(queue *q,int len){
    q->size=len;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(sizeof(int)*len);
}

//checking the queue is full or not
int isFull(queue q){
    if((q.rear==q.size-1 && q.front==0) || (q.front == q.rear+1)){
        printf("Queue is Full");
        return 1;
    }
    else
        return 0;
}

//checking the queue is empty or not
int isEmpty(queue q){
    if(q.front==-1){
        return 1;
    }
    else
        return 0;

}

//inserting the element into the queue from the rear end
void enqueue(queue *q,int x)
{
    if(isFull(*q)){
        return;
    }
    else{
        if(q->rear==q->size-1){
            q->rear=0;
        }
        else if(q->rear==-1){
            q->rear=q->front=0;
        }
        else{
            q->rear++;//increment the rear by 1 after inserting the element
        }
        q->Q[q->rear] = x;
    }
    return;
}


//deleting the element from the queue from front end
int dequeue(queue *q)
{
    int x;
    if(isEmpty(*q)){
        return INT_MIN;
    }
    else{
        x=q->Q[q->front];
        if(q->front==q->rear){
            q->front=q->rear=-1;

        }
        else if(q->front==q->size-1){
            q->front= 0;

        }
        else{
            q->front++;//increment the front by 1

        }
        return x;
    }
}
