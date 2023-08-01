#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<ll> fir, las;
    for (i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
        {
            fir.push_back(a[i]);
        }
        else
        {
            las.push_back(a[i]);
        }
    }
    vector<ll> v;
    ll j = -1;
    for (i = 0; i < (n + 1) / 2; i++)
    {
        v.push_back(fir[i]);
        if (i != (ll)las.size())
            v.push_back(las[i]);
    }
    for (i = 0; i < n; i++)
    {
        if ((v[i] > v[(i + 1) % n] && v[i] > v[(n + i - 1) % n]) || (v[i] < v[(i + 1) % n] && v[i] < v[(n + i - 1) % n]))
        {
            continue;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
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
