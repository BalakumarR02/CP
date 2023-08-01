#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, m;

    cin >> n >> m;

    string s1 = "0 1", s2 = "1 0";
    for (i = 0; i < n; i++)
    {
        for (ll j = 0; j < m / 2; j++)
        {
            if ((j + i) % 2 == 0)
                cout << s2 << " ";
            else
                cout << s1 << " ";
        }
        cout << "\n";
        if (i % 2)
        {
            swap(s1, s2);
        }
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
