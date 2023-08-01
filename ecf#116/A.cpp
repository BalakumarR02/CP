#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n = 0, i, a = 0, b = 0;
    string s;

    cin >> s;
    if (s[0] == 'a' && s[s.length() - 1] == 'b')
    {
        for (i = 0; i < s.length() - 1; i++)
        {
            cout << s[i];
        }
        cout << 'a';
        cout << endl;
    }
    else if (s[0] == 'b' && s[s.length() - 1] == 'a')
    {
        for (i = 0; i < s.length() - 1; i++)
        {
            cout << s[i];
        }
        cout << 'b';
        cout << endl;
    }
    else
    {
        cout << s << endl;
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
