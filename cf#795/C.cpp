#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i, k;

    cin >> n >> k;
    string s;
    cin >> s;
    ll zeo = 0, o = 0, sum = 0, zs = 0, os = 0;
    for (i = 0; i < n - 1; i++)
    {
        sum += ((ll)(s[i] - '0') * 10) + (ll)(s[i + 1] - '0');
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            zs = 10;
            if (!zeo)
                zs = 0;
            break;
        }
        else
            zeo++;
    }
    ll j;
    for (j = 0; j < n; j++)
    {
        if (s[j] == '1')
        {
            os = 1;
            if (!o)
                os = 0;
            break;
        }
        else
            o++;
    }
    if (j == i)
    {
        if (k >= zeo)
        {
            k -= zeo;
            sum -= zs;
            if (!o)
                sum += 1;
        }
        else if (k >= o && zeo)
        {
            k -= o;
            sum -= os;
        }
    }
    else
    {
        if (k >= zeo)
        {
            k -= zeo;
            sum -= zs;
        }
        if (k >= o)
        {
            k -= o;
            sum -= os;
        }
    }

    cout << sum << "\n";
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
