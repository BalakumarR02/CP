#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k, a[200001] = {0};
    string s;

    cin >> n >> k >> s;
    ll z = 0, o = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            z++;
        }
        else
            o++;
    }

    if (k % 2 != 0)
    {
        for (i = 0; i < n; i++)
        {
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
