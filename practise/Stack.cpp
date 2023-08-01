#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node
{
    ll data;
    struct Node *next;
};

// void push(Node **head, ll x)
// {
//     Node *t = new Node;
//     Node *last;
//     t->data = x;
//     t->next = NULL;
//     last = *head;
//     if (*head)
//     {
//         for (ll i = 0; last->next != NULL; i++)
//             last = last->next;
//         last->next = t;
//     }
//     else
//     {
//         *head = t;
//     }
// }
// void display(Node *head)
// {
//     Node *p = head;
//     for (ll i = 0; p != NULL; i++)
//     {
//         cout << p->data << " ";
//         p = p->next;
//     }
// }

// void create_list(Node **head, ll a[])
// {
//     Node *t;
//     Node *last;
//     *head = new Node;
//     (*head)->data = a[0];
//     (*head)->next = NULL;
//     last = *head;

//     for (ll i = 1; i < 5; i++)
//     {
//         t = new Node;
//         t->data = a[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }

// void reverse(Node **ptr)
// {
//     Node *p, *q, *r;
//     p = *ptr;
//     q = r = NULL;
//     while (p)
//     {
//         r = q;
//         q = p;
//         p = p->next;
//         q->next = r;
//     }
//     *ptr = q;
// }

// void isPalindrome(Node *head)
// {
//     Node *slow, *speed, *first, *slow_prev;
//     slow = speed = first = head;

//     while (speed && speed->next)
//     {
//         slow_prev = slow;
//         slow = slow->next;
//         speed = speed->next->next;
//     }

//     if (speed != NULL)
//     {
//         slow = slow->next;
//     }

//     slow_prev->next = NULL;
//     reverse(&slow);
//     while (slow && first)
//     {
//         if (((slow->data) == (first->data)))
//         {
//             slow = slow->next;
//             first = first->next;
//         }
//         else
//         {
//             cout << "Not Palindrome";
//             return;
//         }
//     }
//     cout << "palindrome";
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     Node *head = NULL;
//     ll a[] = {1, 2, 3, 4, 1};
//     create_list(&head, a);

//     display(head);

//     isPalindrome(head);

//     return 0;
// }

// struct Node *newNode(int key)
// {
//     struct Node *temp =
//         (struct Node *)malloc(sizeof(struct Node));
//     temp->data = key;
//     temp->next = NULL;
//     return temp;
// }

// ll countNodesinLoop(Node *head)
// {
//     Node *s1, *s2;
//     ll count = 0;
//     s1 = s2 = head;
//     do
//     {
//         s1 = s1->next;
//         if (s2->next == NULL || s2->next->next == NULL)
//         {
//             count = 0;
//             return count;
//         }
//         s2 = s2->next->next;

//         count++;

//     } while (s1 != s2);
//     return count;
// }
// int main()
// {
//     Node *head = newNode(1);
//     head->next = newNode(2);
//     head->next->next = newNode(3);
//     head->next->next->next = newNode(4);
//     head->next->next->next->next = newNode(5);
//     head->next->next->next->next->next = newNode(6);
//     head->next->next->next->next->next->next = newNode(7);
//     head->next->next->next->next->next->next->next = newNode(8);
//     head->next->next->next->next->next->next->next->next = newNode(9);

//     /* Create a loop for testing */
//     head->next->next->next->next->next->next->next->next->next = head->next->next->next;

//     cout << countNodesinLoop(head) << endl;

//     return 0;
// }

void push(Node **head, ll x)
{
    Node *p, *temp;
    p = new Node;
    p->data = x;
    p->next = *head;

    if (*head)
    {
        temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    else
    {
        *head = p;
        (*head)->next = *head;
    }
}

void display(Node *head)
{
    Node *p;
    p = head;
    if (head)
    {
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (head != p);
    }
    cout << endl;
}

void split(Node *head, Node **head1, Node **head2)
{

    *head1 = *head2 = head;
    ll count = 0;
    do
    {
        *head1 = (*head1)->next->next;
        *head2 = (*head2)->next;
        count++;

    } while (*head1 != *head2);
    *head1 = *head2 = head;
    for (ll i = 0; i < ((count + 1) / 2) - 1; i++)
    {
        head = head->next;
    }
    *head2 = head->next;
    head->next = (*head1);
    head = (*head2);
    while ((head->next) != (*head1))
    {
        head = head->next;
    }
    head->next = (*head2);
}
int main()
{
    Node *head = NULL;
    ll n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(&head, x);
    }
    display(head);
    Node *head1 = NULL, *head2 = NULL;
    split(head, &head1, &head2);
    display(head1);
    display(head2);

    return 0;
}
