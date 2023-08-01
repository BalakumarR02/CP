#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001], k, j;
    ll x;
    cin >> n >> k;
    ll quo = 0;
    vector<ll> r;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        quo += (a[i] / k);
        r.push_back(a[i] % k);
    }
    sort(r.begin(), r.end());
    map<ll, ll> mp;
    for (i = n - 1, j = 0; j < i;)
    {
        if ((r[i] + r[j]) >= k)
        {
            quo += (r[i] + r[j]) / k;
            i--;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout << quo << "\n";
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
