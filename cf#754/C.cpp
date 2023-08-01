#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a = 0, b = 0, c = 0;
    string s;

    cin >> n;
    cin >> s;

    for (i = 1; i < n; i++)
    {
        if (s[i] == 'a' && s[i - 1] == 'a')
        {
            cout << 2 << endl;
            return;
        }
    }
    for (i = 2; i < n; i++)
    {
        if (s[i] == 'a' && s[i - 2] == 'a')
        {
            cout << 3 << endl;
            return;
        }
    }

    for (i = 3; i < n; i++)
    {
        if (s[i] == 'a' && (s[i - 1] != s[i - 2]) && s[i - 3] == 'a')
        {
            cout << 4 << endl;
            return;
        }
    }
    for (i = 6; i < n; i++)
    {
        if (s[i] == 'a' && s[i - 3] == 'a' && s[i - 6] == 'a' && s[i - 1] == s[i - 2] && s[i - 4] == s[i - 5] && s[i - 1] != s[i - 4])
        {
            cout << 7 << endl;
            return;
        }
    }
    cout << -1 << endl;
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
