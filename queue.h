
typedef struct queue{
    int rear;
    int front;
    int size;
    int *Q;
}queue;

void init(queue *q,int len);

int isFull(queue q);

int isEmpty(queue q);

void enqueue(queue *q,int x);

int dequeue(queue *q);

void display(queue *q);
