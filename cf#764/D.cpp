#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k, h[27] = {0}, p = 0, p1 = 0, ans = 0, sum = 0, extra = 0;
    string s;
    vector<ll> v;
    cin >> n >> k >> s;
    for (i = 0; i < n; i++)
    {
        h[(ll)s[i] - 'a']++;
    }
    for (i = 0; i < 26; i++)
    {
        p += (h[i] / 2);
        p1 += (h[i] % 2);
    }
    sum = (p / k);
    extra = (p % k) * 2 + p1;
    ans = sum * 2;
    if (extra >= k)
        ans++;
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
