#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first == b.first)
    {
        return (a.second > b.second);
    }
    return a.first < b.first;
}
void solve()
{
    ll n, i, k, a[200001];
    vector<pair<ll, ll>> v;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back({a[i] + i, i});
    }
    sort(v.begin(), v.end(), cmp);
    ll jum = 0;
    ll ha[200001] = {0};
    for (i = n - 1; i >= 0 && k >= 1; i--)
    {
        ha[v[i].second]++;
        k--;
        if (!k)
        {
            break;
        }
    }
    ll dam = 0;
    for (i = 0; i < n; i++)
    {
        if (ha[i])
        {
            jum++;
            continue;
        }
        dam += a[i] + jum;
    }

    cout << dam << "\n";
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
