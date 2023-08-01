#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if ((abs(a.first - a.second)) < (abs(b.first - b.second)))
        return 1;
    return 0;
}
void solve()
{
    ll n, i, hash[1001] = {0}, x, y, j;

    cin >> n;
    vector<pair<ll, ll>> p;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end(), cmp);
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        if (p[i].first == p[i].second)
        {
            hash[p[i].first] = 1;
            v.push_back(p[i].first);
        }
        else
        {
            for (j = p[i].first; j <= p[i].second; j++)
            {
                if (hash[j] == 0)
                {
                    v.push_back(j);
                    hash[j] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << p[i].first << " " << p[i].second << " " << v[i] << "\n";
    }
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
