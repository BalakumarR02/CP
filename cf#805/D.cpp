#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, p, cos = 0;
    string s;
    cin >> s >> p;
    vector<ll> ha(26, 0), hb(26, 0);
    n = s.length();
    for (i = 0; i < n; i++)
    {
        ha[s[i] - 'a']++;
        hb[s[i] - 'a']++;
        cos += (s[i] - 'a') + 1;
    }
    if (cos <= p)
    {
        cout << s << "\n";
        return;
    }
    for (i = 25; i >= 0; i--)
    {
        if (p > (cos - (ha[i] * (i + 1))))
        {
            ll num = (cos - p) / (i + 1);
            if ((cos - p) % (i + 1))
                num++;
            ha[i] -= num;
            break;
        }
        else
        {
            cos -= (ha[i] * (i + 1));
            ha[i] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (ha[s[i] - 'a'] != hb[s[i] - 'a'])
        {
            hb[s[i] - 'a']--;
            s.erase(s.begin() + i);
            i--;
            n--;
        }
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

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
