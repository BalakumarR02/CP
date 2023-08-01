#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    vector<ll> v;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll bin[11] = {0};
    for (i = 0; i <= 10; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if ((1 << i) & v[j])
            {
                bin[i]++;
            }
        }
    }
    ll maxi = 0, mini = 0;
    for (i = 0; i <= 10; i++)
    {
        if (bin[i] == n)
        {
            mini += (1 << i);
        }
        if (bin[i])
        {
            maxi += (1 << i);
        }
    }
    cout << maxi - mini << "\n";
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
