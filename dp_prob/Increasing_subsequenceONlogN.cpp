#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i;

    cin >> n;

    vector<ll> v(n + 1);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int dp[n];
    map<int, int> mp;
    for (i = 0; i < n; i++)
    {
        int val;
        auto x = mp.lower_bound(v[i]);
        if (x == mp.begin())
        {
            val = 0;
            cout << val << " " << i << "  ";
        }

        else
        {
            x--;
            val = x->second;
            cout << val << " " << i << "  ";
        }

        dp[i] = val + 1;
        if (mp[v[i]] < dp[i])
        {
            mp[v[i]] = dp[i];
            auto it = mp.find(v[i]);
            it++;
            while (it != mp.end() && it->second <= dp[i])
            {
                auto temp = it;
                it++;
                mp.erase(temp);
            }
        }
    }

    cout << *max_element(dp, dp + n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
