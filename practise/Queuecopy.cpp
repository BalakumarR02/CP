#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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