#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[101], h[101] = {0}, s = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        h[abs(a[i])]++;
        if (a[i] == 0)
        {
            h[a[i]]++;
        }
        if (h[abs(a[i])] <= 2)
        {
            s++;
        }
    }

    cout << s << "\n";
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
