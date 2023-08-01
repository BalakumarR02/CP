#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, j, a[26] = {0};
    string s, T;
    cin >> s;
    cin >> T;
    for (i = 0; i < s.length(); i++)
    {
        a[(ll)(s[i] - 'a')]++;
    }

    sort(s.begin(), s.end());
    if (a[0] == 0 || a[1] == 0 || a[2] == 0)
    {
        cout << s << "\n";
        return;
    }
    j = 0;
    if (T[0] == 'a' && T[1] == 'b')
    {
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == 'b' && j == 0)
            {
                j = i;
            }
            else if (s[i] == 'c')
            {
                n = i;
            }
        }
        reverse(s.begin() + j, s.begin() + n + 1);
    }
    cout << s << "\n";
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
