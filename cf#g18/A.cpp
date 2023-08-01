#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, k, a[101], x, h[200001] = {0}, j, c = 0;

    cin >> n >> k;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        x = a[i];
        while (x)
        {
            v.push_back(x);
            x /= 2;
        }
    }
    for (auto pos : v)
    {
        for (j = 0; j < n; j++)
        {
            x = a[j];
            c = 0;
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