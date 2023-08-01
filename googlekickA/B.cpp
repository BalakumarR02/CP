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
    cin >> s;
    n = s.length();
    ll sum = 0, mini = 1e9;
    for (i = 0; i < n; i++)
    {
        sum += (s[i] - '0');
        mini = min(mini, (ll)(s[i] - '0'));
    }
    if (sum % 9 == 0)
    {
        cout << s[0] << "0";
        for (i = 1; i < n; i++)
        {
            cout << s[i];
        }
        cout << "\n";
    }
    else
    {
        ll rem = 9 - (sum % 9);
        ll k = 0;
        if (rem < mini)
        {
            cout << rem << s;
        }
        else
        {
            for (i = 0; i < n; i++)
            {

                if (rem >= 0 && (s[i] - '0') > rem)
                {
                    cout << rem;
                    rem = -1;
                }
                cout << s[i];
            }
            if (rem != -1)
                cout << rem;
        }

        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
