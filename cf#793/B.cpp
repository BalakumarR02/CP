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
    vector<ll> a;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        ll x;

        cin >> x;
        a.push_back(x);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    ll x = -1;
    for (i = 0; i < n; i++)
    {
        if (a[i] != v[i])
        {
            if (x == -1)
                x = (a[i] & a[a[i]]);
            else
            {
                x = x & (a[i] & a[a[i]]);
            }
            swap(a[i], a[a[i]]);
        }
    }

    cout << x << "\n";
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
