#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

bool cmp(pair<ll, pair<ll, ll>> &p1, pair<ll, pair<ll, ll>> &p2)
{
    return p1.first < p2.first;
}
void solve()
{
    int n, i;

    cin >> n;
    int a, b, p;
    vector<pair<ll, pair<ll, ll>>> v(n + 1);

    for (i = 1; i <= n; i++)
    {
        cin >> a >> b >> p;
        v[i] = make_pair(b, make_pair(a, p));
    }

    sort(v.begin() + 1, v.end(), cmp);

    vector<ll> v1;
    for (int i = 1; i < v.size(); i++)
        v1.push_back(v[i].first);
    vector<ll> dp(n + 1, 0);
    dp[0] = 0;

    for (i = 1; i <= n; i++)
    {

        int j = lower_bound(v1.begin(), v1.end(), (v[i].second).first) - (v1.begin());

        dp[i] = max(dp[i - 1], ((v[i].second).second + dp[j]));
    }
    cout << dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
