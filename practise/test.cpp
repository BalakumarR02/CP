#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// struct arran
// {
//     char a[1001];
//     int top;
// };

// void push(arran *c, char val)
// {
//     c->top++;
//     c->a[c->top] = val;
// }

// bool isEmpty(arran *c)
// {
//     if (c->top == -1)
//         return 1;
//     return 0;
// }
// char stackTop(arran *c)
// {
//     return c->a[c->top];
// }
// char pop(arran *c)
// {
//     if (isEmpty(c))
//         return -1;
//     char x = c->a[c->top];
//     c->top--;
//     return x;
// }

// void revst(arran *c)
// {
//     string s1;
//     ll j = 0, k;
//     pop(c);
//     while (stackTop(c) != '/')
//     {

//         s1.push_back(pop(c));
//         j++;
//     }
//     pop(c);
//     for (k = 0; k < j; k++)
//     {
//         push(c, s1[k]);
//     }
// }

ll digitSum(ll a)
{
    ll sum = 0;
    while (a)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, i, t, a[100001], vi, tv, flag = -1;
    cin >> n >> q;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        flag = -1;
        cin >> t;
        t--;
        vi = digitSum(a[t]);
        for (i = t + 1; i < n; i++)
        {
            tv = digitSum(a[i]);
            if (vi > tv && a[t] < a[i])
            {
                flag = i + 1;
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}
