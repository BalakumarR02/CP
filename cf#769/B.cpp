#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    ll x = log2((n - 1)), num;
    num = pow(2, x);
    vector<ll> v1;
    for (i = num; i < n; i++)
    {
        v1.push_back(i);
    }
    for (i = 1; i < num; i++)
    {
        cout << i << " ";
    }
    cout << 0 << " ";
    for (i = 0; i < (ll)v1.size(); i++)
    {
        cout << v1[i] << " ";
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
