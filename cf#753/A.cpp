#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n = 0, i;
    map<char, ll> m;
    string s, s1;
    cin >> s >> s1;
    for (i = 0; i < s.length(); i++)
    {
        m[s[i]] = i + 1;
    }

    for (i = 1; i < s1.length(); i++)
    {
        n += (ll)abs(m[s1[i]] - m[s1[i - 1]]);
    }
    cout << n << endl;
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
