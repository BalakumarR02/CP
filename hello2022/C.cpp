#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;
ll question(ll i)
{
    ll p;
    cout << "? " << i << endl;
    cin >> p;
    return p;
}
void solve()
{
    ll n, i, perm[10001] = {0}, x, y = 0, p, q, hash[10001] = {0};

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        if (hash[i] == 1)
            continue;

        x = question(i);
        p = y = x;
        while (1)
        {
            p = y;
            y = question(i);
            perm[p] = y;
            hash[p] = 1;
            if (y == x)
                break;
        }
    }
    cout << "! ";
    for (i = 1; i <= n; i++)
    {
        cout << perm[i] << " ";
    }
    cout << endl;
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
