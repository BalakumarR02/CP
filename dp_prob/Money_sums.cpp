#include <bits/stdc++.h>
#define ll long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

using namespace std;

void solve()
{
    ll n, x = 0;

    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        x += v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    set<ll> st;
    for (int i = 1; i <= n; i++)
    {
        for (int sum = 0; sum <= x; sum++)
        {
            if (sum == 0)
            {
                dp[i][sum] = 1;
                continue;
            }
            else
            {
                int op1 = (v[i] > sum) ? 0 : dp[i - 1][sum - v[i]];
                int op2 = dp[i - 1][sum];
                dp[i][sum] = (op1 + op2) % mod;
            }
            if (i == n && dp[i][sum])
            {
                st.insert(sum);
            }
        }
    }

    cout << st.size() << "\n";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
