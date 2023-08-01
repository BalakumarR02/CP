#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, q;

    cin >> n >> q;
    map<ll, ll> r, c;
    set<ll> a, b;
    for (i = 1; i <= n; i++)
    {
        r[i] = 0, c[i] = 0;
        a.insert(i);
        b.insert(i);
    }
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            r[x]++, c[y]++;
            a.erase(x);
            b.erase(y);
        }
        else if (t == 2)
        {
            ll x, y;
            cin >> x >> y;
            r[x]--, c[y]--;
            if (!r[x])
                a.insert(x);
            if (!c[y])
                b.insert(y);
        }
        else
        {
            ll x[2], y[2], f = 0;
            cin >> x[0] >> y[0] >> x[1] >> y[1];
            ll k = *(a.lower_bound(x[0]));
            ll m = *(b.lower_bound(y[0]));
            if ((k >= x[0] && k <= x[1]) && (m >= y[0] && m <= y[1]))
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
