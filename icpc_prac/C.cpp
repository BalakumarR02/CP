#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    vector<ll> v(n, 0);
    map<ll, ll> a, b, c;

    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i % 3 == 0)
        {
            a[v[i]]++;
        }
        else if (i % 3 == 1)
            b[v[i]]++;
        else
            c[v[i]]++;
    }
    ll max_a = -1, max_b = -1, max_c = -1, c_a = 0, c_b = 0, c_c = 0;
    for (i = 1; i <= n; i++)
    {
        if (c_a < a[i])
        {
            c_a = a[i];
            max_a = i;
        }
        if (c_b < b[i])
        {
            c_b = b[i];
            max_b = i;
        }
        if (c_c < c[i])
        {
            c_c = c[i];
            max_c = i;
        }
    }
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
