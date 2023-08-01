#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, j;
    string s;
    cin >> s;
    n = s.length();
    if (n % 2 != 0)
    {
        cout << "NO\n";
    }
    else
    {
        j = n / 2;
        for (i = 0; j < n; i++, j++)
        {
            if (s[i] != s[j])
            {
                cout << "NO\n";
                return;
            }
        }
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
