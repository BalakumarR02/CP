#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001], s = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll c = (n + 2) / 2, s1 = a[0];
    for (i = 1; i < (n + 1) / 2; i++)
    {
        if (s <= s1)
        {
            s1 += a[i];
            s += a[n - i];
        }
        else
        {
            break;
        }
    }

    if (s > s1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
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
