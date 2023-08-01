#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, sum = 0;

    cin >> n;
    vector<ll> a;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        sum += x;
    }
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }
    sort(a.begin(), a.end());
    ll k = 0, n1 = n, p = 1;
    while (p == 1)
    {
        p = 0;
        for (i = 1; i < n; i++)
        {
            if (a[i] == (a[i - 1] + 1))
            {
                a[i] = a[i - 1] + a[i];
                a.erase(a.begin() + i - 1);
                n--;
                i--;
                k++;
                p = 1;
            }
        }
        for (i = 1; i < n; i++)
        {
            if (a[i] == (a[i - 1]))
            {
                a[i] = a[i - 1] + a[i];
                a.erase(a.begin() + i - 1);
                n--;
                i--;
                k++;
                p = 1;
            }
        }
        sort(a.begin(), a.end());
    }
    if (a.size() > 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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
;