#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001], x = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            break;
        }
    }
    if (i == n)
    {
        cout << "YES\n";
        return;
    }

    sort(a, a + n);
    x = 0;
    if (a[0] == 0)
    {
        x = 1;
    }
    for (i = 0; i < n; i++)
    {

        if (a[i] == 1 && x == 1)
        {
            cout << "NO\n";
            return;
        }
        if (a[i] == 1)
        {
            x = 2;
        }
        if (i < n - 1 && a[i] == a[i + 1])
        {
            a[i] = -1;
        }
    }

    if (x == 2)
    {
        sort(a, a + n);
        for (i = n - 1; i > 0; i--)
        {
            if (a[i] >= 0)
            {
                if (a[i] == (a[i - 1] + 1))
                {
                    cout << "NO\n";
                    return;
                }
            }
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
