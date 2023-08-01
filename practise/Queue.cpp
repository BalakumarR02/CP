#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// struct Queue
// {
//     int front, rear, size;
//     int *arr;
// };

// bool isFull(Queue *q)
// {
//     if ((q->rear + 1) % q->size == q->front)
//     {
//         return 1;
//     }
//     return 0;
// }
// bool isEmpty(Queue *q)
// {
//     if (q->front == q->rear)
//         return 1;
//     return 0;
// }
// Queue *createQueue(int size)
// {
//     Queue *q = new Queue();
//     q->front = q->rear = 0;
//     q->size = size;
//     q->arr = new int[size];
//     return q;
// }

// void enqueue(Queue *q, int data)
// {
//     if (isFull(q))
//     {
//         cout << "Queue is full";
//         return;
//     }
//     q->rear = (q->rear + 1) % q->size;
//     q->arr[q->rear] = data;
// }
// int dequeue(Queue *q)
// {
//     if (isEmpty(q))
//     {
//         cout << "Queue is empty";
//         return -1;
//     }
//     q->front = (q->front + 1) % q->size;
//     int x = q->arr[q->front];

//     return x;
// }
// int rear(Queue *q)
// {
//     if (isEmpty(q))
//     {
//         cout << "Queue is empty";
//         return -1;
//     }
//     return q->arr[q->rear];
// }
// int front(Queue *q)
// {
//     if (isEmpty(q))
//     {
//         cout << "Queue is empty";
//         return -1;
//     }
//     return q->arr[q->front + 1];
// }

// void display(Queue *q)
// {
//     if (isEmpty(q))
//     {
//         cout << "Queue is empty";
//         return;
//     }
//     for (int i = q->front + 1; i <= q->rear; i++)
//     {
//         cout << q->arr[i] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     Queue *queue = createQueue(1000);

//     enqueue(queue, 10);
//     enqueue(queue, 20);
//     enqueue(queue, 30);
//     enqueue(queue, 40);
//     display(queue);

//     printf("%d dequeued from queue\n\n",
//            dequeue(queue));
//     display(queue);
//     printf("Front item is %d\n", front(queue));
//     printf("Rear item is %d\n", rear(queue));

//     return 0;
// }

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front, *rear;
};

Node *newNode(int val)
{
    Node *t = new Node();
    t->data = val;
    t->next = NULL;
    return t;
}

bool isEmpty(Queue *q)
{
    if (q->rear == NULL)
        return 1;
    return 0;
}

Queue *createQueue()
{
    Queue *q = new Queue();
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int data)
{

    Node *t = newNode(data);

    if (q->rear == NULL)
    {
        q->front = q->rear = t;
    }
    else
    {
        (q->rear)->next = t;
        q->rear = t;
    }
}
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty";
        return -1;
    }
    int x = (q->front)->data;
    Node *p = q->front;
    q->front = (q->front)->next;
    p->next = NULL;
    delete (p);
    return x;
}
int rear(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty";
        return -1;
    }
    return (q->rear)->data;
}
int front(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty";
        return -1;
    }
    return (q->front)->data;
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty";
        return;
    }
    Node *p = q->front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);

    printf("%d dequeued from queue\n\n",
           dequeue(queue));
    display(queue);
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}