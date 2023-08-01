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
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    if (n == 1)
    {
        cout << "-1\n";
        return;
    }
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        if (a[i] == v[i])
        {
            if (i < n - 1)
                swap(a[i], a[i + 1]);
            else
            {
                swap(a[i], a[i - 1]);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
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
