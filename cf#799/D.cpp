#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

ll mp[40];
void precomp()
{
    ll i;
    for (i = 0; i < 6; i++)
    {
        mp[i] = i * 10;
    }
    for (i = 6; i < 24; i++)
    {
        if ((i >= 6 && i < 10) || (i >= 16 && i < 20))
        {
            continue;
        }

        string s1 = to_string(i);
        ll x = (s1[1] - '0') * 10 + (s1[0] - '0');
        mp[i] = x;
    }
}
void solve()
{
    ll n, i;
    string s;
    cin >> s >> n;
    ll h = (s[0] - '0') * 10 + (s[1] - '0'), m = (s[3] - '0') * 10 + (s[4] - '0');
    ll ah = n / 60, am = n % 60;
    ll h1 = h, m1 = m, ans = 0;
    do
    {
        if (mp[h1] == m1)
        {
            ans++;
        }
        if ((m1 + am) >= 60)
            h1++;
        h1 = (h1 + ah) % 24;
        m1 = (m1 + am) % 60;

    } while (h != h1 || m != m1);

    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(mp, -1, sizeof(mp));
    precomp();
    ll t;

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
