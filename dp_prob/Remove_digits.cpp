#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int mod = 1e9 + 7;
int mod1 = 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    ll x = 0;

    while (n)
    {
        ll n1 = n, ma = -1;
        while (n1)
        {
            ma = max(ma, n1 % 10);
            n1 /= 10;
        }
        x++;
        n -= ma;
    }

    cout << x << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
