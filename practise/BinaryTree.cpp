#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct TreeNode
{
    TreeNode *lchild;
    int data;
    TreeNode *rchild;
};

//queue

struct Node
{
    TreeNode *data;
    Node *next;
};

struct Queue
{
    Node *front, *rear;
};

Node *newNode(TreeNode *val)
{
    Node *t = new Node();
    t->data = val;
    t->next = NULL;
    return t;
}

bool isEmpty(Queue *q)
{
    if (q->rear == NULL || q->front == NULL)
        return 1;
    return 0;
}

Queue *createQueue()
{
    Queue *q = new Queue();
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, TreeNode *data)
{

    Node *t = newNode(data);

    if (q->rear == NULL || q->front == NULL)
    {
        q->front = q->rear = t;
    }
    else
    {
        (q->rear)->next = t;
        q->rear = t;
    }
}
TreeNode *dequeue(Queue *q)
{
    TreeNode *x = (q->front)->data;
    Node *p = q->front;
    q->front = (q->front)->next;
    p->next = NULL;
    delete (p);
    return x;
}

//Binary tree
Queue *q = createQueue();

TreeNode *newtNode(int val)
{
    TreeNode *t = new TreeNode();
    t->data = val;
    t->lchild = t->rchild = NULL;
    return t;
}
TreeNode *createTree(int data)
{
    TreeNode *root = newtNode(data);
    return root;
}
void insertNode(TreeNode *root)
{
    int data;

    enqueue(q, root);
    while (!(isEmpty(q)))
    {
        TreeNode *p = dequeue(q);
        cout << "Enter lchild of " << p->data << " ";
        cin >> data;
        if (!(data == -1))
        {
            TreeNode *t = newtNode(data);
            p->lchild = t;
            enqueue(q, p->lchild);
        }
        else
        {
            p->lchild = NULL;
        }
        cout << "Enter rchild of " << p->data << " ";
        cin >> data;
        if (!(data == -1))
        {
            TreeNode *t = newtNode(data);
            p->rchild = t;
            enqueue(q, p->rchild);
        }
        else
        {
            p->rchild = NULL;
        }
    }
}

void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}
void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->lchild);
    cout << root->data << " ";
    inOrder(root->rchild);
}
void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout << root->data << " ";
}
int countLn(TreeNode *root)
{
    int x, y;
    if (root)
    {
        x = countLn(root->lchild);
        y = countLn(root->rchild);
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
int Rsearch(TreeNode *root, int key)
{
    if (root->data == key)
    {
        return 1;
    }
    else if (root->data > key)
    {
        return Rsearch(root->lchild, key);
    }
    else if (root->data < key)
    {
        return Rsearch(root->rchild, key);
    }
    return 0;
}
void insertBST(TreeNode *root, int key)
{
    TreeNode *t, *p;
    while (root)
    {
        if (root->data == key)
        {
            return;
        }
        else if (root->data > key)
        {
            t = root;
            root = root->lchild;
        }
        else if (root->data < key)
        {
            t = root;
            root = root->rchild;
        }
    }
    p = newtNode(key);
    if (p->data < t->data)
    {
        t->lchild = p;
    }
    else
    {
        t->rchild = p;
    }
}
int height(TreeNode *root)
{
    int x, y;
    if (root)
    {
        x = height(root->lchild);
        y = height(root->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

TreeNode *inPred(TreeNode *root)
{
    while (root && root->rchild)
    {
        root = root->rchild;
    }
    return root;
}
TreeNode *inSuces(TreeNode *root)
{
    while (root && root->lchild)
    {
        root = root->lchild;
    }
    return root;
}
TreeNode *deleteBST(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
    {
        root->lchild = deleteBST(root->lchild, key);
    }
    else if (key > root->data)
    {
        root->rchild = deleteBST(root->rchild, key);
    }
    else
    {
        if (root->lchild == NULL)
        {
            TreeNode *t = root->rchild;
            delete (root);
            return t;
        }
        else if (root->rchild == NULL)
        {
            TreeNode *t = root->lchild;
            delete (root);
            return t;
        }

        TreeNode *p = inSuces(root->rchild);
        root->data = p->data;
        root->rchild = deleteBST(root->rchild, p->data);
    }
    return root;
}
int main()
{

    int data;
    cout << "Enter root value: ";
    cin >> data;
    TreeNode *root = createTree(data);
    insertNode(root);

    cout << "Preorder ";
    preOrder(root);
    cout << endl;
    cout << "Inorder ";
    inOrder(root);
    cout << endl;
    cout << "Postorder ";
    postOrder(root);
    cout << endl;
    cout << countLn(root) << endl;

    cout << "Enter data to be deleted " << endl;
    cin >> data;
    root = deleteBST(root, data);
    cout << endl;

    cout << "Preorder ";
    preOrder(root);
    cout << endl;
    cout << "Inorder ";
    inOrder(root);
    cout << endl;
    cout << "Postorder ";
    postOrder(root);
    cout << endl;
    cout << countLn(root) << endl;

    return 0;
}
