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

    ll x = 0;
    for (i = 1; i < n; i++)
    {
        if (s[i] == '0' && s[i - 1] == '0')
        {
            x += 2;
        }
        else if (i > 1 && s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '0')
        {
            x += 1;
        }
    }

    cout << x << "\n";
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
