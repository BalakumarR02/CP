#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
const int N = 1e6; // limit for array size

// Normal Segment Tree
class Segtree
{
public:
    ll n; // array size
    ll t[2 * N];
    void build(ll _n)
    { // build the tree
        n = _n;
        for (int i = n - 1; i > 0; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void modify(int p, int value)
    { // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    ll query(int l, int r)
    { // sum on interval [l, r)
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }

    void push()
    {
        for (int i = 1; i < n; ++i)
        {
            t[i << 1] += t[i];
            t[i << 1 | 1] += t[i];
            t[i] = 0;
        }
    }
};

// Lazy propagation
class LazySeg
{
    int h = sizeof(int) * 8 - __builtin_clz(n);
    int d[N];
    int n; // array size
    int t[2 * N];
    void apply(int p, int value)
    {
        t[p] += value;
        if (p < n)
            d[p] += value;
    }

    void build(int p)
    {
        while (p > 1)
            p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
    }

    void push(int p)
    {
        for (int s = h; s > 0; --s)
        {
            int i = p >> s;
            if (d[i] != 0)
            {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }

    void inc(int l, int r, int value)
    {
        l += n, r += n;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                apply(l++, value);
            if (r & 1)
                apply(--r, value);
        }
        build(l0);
        build(r0 - 1);
    }

    int query(int l, int r)
    {
        l += n, r += n;
        push(l);
        push(r - 1);
        int res = -2e9;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = max(res, t[l++]);
            if (r & 1)
                res = max(t[--r], res);
        }
        return res;
    }
};

void solve()
{
    ll n, i;

    cin >> n;

    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
