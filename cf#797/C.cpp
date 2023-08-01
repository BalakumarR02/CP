#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, s[200001], f[200001];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    vector<ll> dur;
    dur.push_back(f[0] - s[0]);
    ll las = f[0];
    for (i = 1; i < n; i++)
    {
        dur.push_back((f[i] - max(s[i], las)));
        las = f[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << dur[i] << " ";
    }

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
