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
    ll d = 0;
    unordered_map<int, int> mp;
    cout << 2 << "\n";

    for (i = 1; i <= n; i++)
    {
        if (!mp[i])
        {
            ll j = i;
            while (j <= n)
            {
                cout << j << " ";
                mp[j] = 1;
                j *= 2;
            }
        }
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
