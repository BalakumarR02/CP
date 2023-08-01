#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, m = -1, r, has[200001] = {0};

    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
        m = max(m, x);
        has[x] += 1;
    }
    m++;
    vector<ll> ans;
    ll j = -1;
    while (j < n - 1)
    {
        map<ll, ll> mp;
        ll k = 0;
        for (i = j + 1; i < n; i++)
        {
            mp[v[i]] = 1;
            has[v[i]]--;
            while (mp[k] != 0)
            {
                k++;
            }
            if (k == m)
            {
                j = i;
                break;
            }
        }
        ans.push_back(k);
        if (i == n || j == n - 1)
        {
            break;
        }
        while (m && m >= 1)
        {
            m--;
            if (has[m])
            {
                break;
            }
        }
        m++;
        mp.clear();
    }
    cout << (ll)ans.size() << "\n";
    for (i = 0; i < (ll)ans.size(); i++)
    {
        cout << ans[i] << " ";
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
