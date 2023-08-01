#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

ll LCM(ll a, ll b)
{
    return (a * b) / (__gcd(a, b));
}
void solve()
{
    ll n, i, p[200001];

    cin >> n;
    string s;
    cin >> s;
    for (i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i] -= 1;
    }
    ll ans = 1;

    map<ll, ll> mp;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        if (mp[i] || p[i] == i)
            continue;
        ll j = p[i];
        ll an = 1, l = 0;
        char c = s[i];
        while (j != i)
        {
            mp[j] = 1;
            if (c != s[j])
            {
                l = 1;
            }
            an++;
            j = p[j];
        }
        mp[i] = 1;
        if (l == 0)
            an = 1;
        ans = LCM(ans, max(an, (ll)1));
    }

    cout << ans << "\n";
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
