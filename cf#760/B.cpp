#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, f = 0;

    cin >> n;
    string s[n + 1], s2 = "";
    for (i = 0; i < (n - 2); i++)
    {
        cin >> s[i];
    }
    s2.push_back(s[0][0]);
    for (i = 1; i < (n - 2); i++)
    {
        if (s[i - 1][1] == s[i][0])
        {
            s2.push_back(s[i - 1][1]);
        }
        else
        {
            f = 1;
            s2.push_back(s[i - 1][1]);
            s2.push_back(s[i][0]);
        }
    }
    s2.push_back(s[n - 3][1]);
    if (f != 1)
    {
        s2.push_back('a');
    }
    cout << s2 << endl;
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
