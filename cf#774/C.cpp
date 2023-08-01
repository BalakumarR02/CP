#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool isPowerofTwo(ll n)
{
    if (n == 0)
        return 0;
    if ((n & (~(n - 1))) == n)
        return 1;
    return 0;
}
vector<ll> v;
void factorial()
{
    ll i, s = 1;
    for (i = 1; s <= 1e13; i++)
    {
        s *= i;
        v.push_back(s);
    }
}
void solve()
{
    ll n, i, k = 0, tp, po, fac;

    cin >> n;
    while (n)
    {
        tp = log2(n);
        po = 1;
        while (tp--)
        {
            po *= 2;
        }
        i = upper_bound(v.begin(), v.end(), n) - v.begin() - 1;
        fac = v[i];
        cout << fac << " " << po << " ";
        n -= max(fac, po);
        k++;
    }
    cout << k << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    factorial();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
