#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, l[2] = {0}, r[2] = {0}, c[3] = {0}, x, y, z, cost = 0;

    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        if (l[0] == 0)
        {
            l[0] = l[1] = x;
            r[0] = r[1] = y;
            c[0] = c[1] = c[2] = z;

            v.push_back(c[0]);
            continue;
        }
        if (x < l[0])
        {
            l[0] = x;
            c[0] = z;
        }
        else if (x == l[0])
        {
            c[0] = min(c[0], z);
        }

        if (y > r[0])
        {
            r[0] = y;
            c[1] = z;
        }
        else if (y == r[0])
        {
            c[1] = min(c[1], z);
        }
        cost = c[0] + c[1];
        if (x == l[0] && y == r[0])
            cost = min((cost), z);
        if (l[1] == l[0] && r[1] == r[0])
        {
            cost = min(c[2], cost);
        }
        v.push_back(cost);
        c[2] = cost;
        l[1] = l[0];
        r[1] = r[0];
    }
    for (i = 0; i < n; i++)
    {
        cout << v[i] << "\n";
    }
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
