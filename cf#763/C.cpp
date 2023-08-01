#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, min_tot = 1e9, min_here = 1e9, h[200001], min_ind;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
        if (min_here > h[i])
        {
            min_here = h[i];
            min_ind = i;
        }
    }
    if (i == n - 1)
    {
        cout << min_here << "\n";
        return;
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
