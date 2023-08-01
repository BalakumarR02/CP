#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[1001];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll n1 = n;
    for (ll j = 0; j < n1; j++)
    {
        ll le;
        string s;
        cin >> le >> s;
        ll coun = 0;
        for (i = 0; i < le; i++)
        {
            if (s[i] == 'D')
            {
                coun++;
            }
            else
                coun--;
        }

        a[j] = (10 + a[j] + coun) % 10;
    }
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
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
