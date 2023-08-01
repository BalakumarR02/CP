#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, m, j;

    cin >> n >> m;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            v.push_back(max(i, n - i - 1) + max(j, m - j - 1));
        }
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n * m; i++)
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