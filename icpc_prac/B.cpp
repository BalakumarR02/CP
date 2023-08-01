#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll N;
    cin >> N;
    string s;
    cin >> s;
    ll D[N];
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        D[i] = x;
    }

    // D, s, N are defined

    ll ma = -1;
    ll turns = 0;
    ll res = -1;

    for (int j = 0; j < N; j++)
    {
        if (s[j] == 'B')
        {
            if (j > ma)
            {
                cout << "-1\n";
                return;
            }

            res = max(res, D[j] + j);
        }

        ma = max(ma, D[j] + j);
    }

    cout << turns << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}