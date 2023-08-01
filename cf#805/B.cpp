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
    vector<ll> a, b;
    unordered_map<ll, ll> mb;
    ll ma = 0;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        while (!(x % 2))
        {
            x /= 2;
        }
        mb[x]++;
        a.push_back(x);
    }
    string ok = "YES";
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        while (x)
        {
            if (mb[x])
            {
                mb[x]--;
                break;
            }
            x /= 2;
        }
        if (x == 0)
            ok = "NO";
    }

    cout
        << ok << "\n";
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
