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
    ll e = 0, o = 0, odd = 0;
    ll s = 0;
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] % 2 == 0)
        {
            e++;
        }
        else
        {
            if (a[i] > 1)
                o++;
            odd++;
        }
    }
    if (e == 0 && ((odd == 1) || (o == 0 && odd > 0)))
    {
        cout << -1 << "\n";
        return;
    }
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] % 2 == 0)
        {
            s += (a[i] / 2);
        }
        else
        {
            s += ((a[i] + 1) / 2);
        }
    }

    cout << s << "\n";
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
