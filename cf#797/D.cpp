#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k;

    cin >> n >> k;
    string s;
    cin >> s;
    ll s1 = 0;
    ll bla[200001];
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            bla[i] = 1;
        }
        else
            bla[i] = 0;
        if (i < k)
        {
            s1 += bla[i];
        }
    }
    ll ans = s1;
    for (i = k; i < n; i++)
    {
        s1 += (bla[i] - bla[i - k]);
        ans = max(ans, s1);
    }

    cout << k - ans << "\n";
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
