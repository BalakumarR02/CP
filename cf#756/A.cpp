#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n = -1, i;
    string s;
    cin >> s;

    for (i = 0; i < s.length(); i++)
    {
        if ((ll)(s[i] - '0') % 2 == 0)
        {
            n = i;
            break;
        }
    }
    if (n == -1)
    {
        cout << -1 << endl;
    }
    else if ((s[s.length() - 1] - '0') % 2 == 0)
    {
        cout << 0 << endl;
    }
    else if (n == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
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
