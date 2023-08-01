#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, x, f = 0, m, j = -1;
    string s;
    cin >> s;
    n = s.length();
    for (i = n - 1; i > 0; i--)
    {
        x = ((ll)(s[i] - '0')) + ((ll)(s[i - 1] - '0'));
        if (x >= 10)
        {
            j = 1;
            s[i] = (x % 10) + '0';
            s[i - 1] = '1';
            break;
        }
    }
    if (j != 1)
    {
        x = ((ll)(s[0] - '0')) + ((ll)(s[1] - '0'));
        s.erase(0, 1);
        s[0] = (x) + '0';
    }
    cout << s;

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
