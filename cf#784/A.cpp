#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    string s;
    cin >> n >> s;
    ll r = 0, b = 0;

    for (i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            r = 1;
        }
        else if (s[i] == 'B')
        {
            b = 1;
        }
        else if (s[i] == 'W')
        {
            if (r != b)
            {
                cout << "NO\n";
                return;
            }
            r = 0;
            b = 0;
        }
    }
    if (r != b)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
