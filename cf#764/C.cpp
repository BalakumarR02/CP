#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[100], h[100] = {0};

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        if (a[i] <= n && h[a[i]] != 1)
        {
            h[a[i]]++;
        }
        else
        {
            while (a[i])
            {
                a[i] /= 2;
                if (a[i] <= n && h[a[i]] != 1)
                {
                    h[a[i]]++;
                    break;
                }
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (h[i] == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
