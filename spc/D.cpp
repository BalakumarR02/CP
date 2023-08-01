#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    string s;
    cin >> n >> s;
    string t, pre;
    for (i = 1; i <= n; i++)
    {
        if (i % 4 == 1 || i % 4 == 0)
        {
            pre.push_back(s[i - 1]);
        }
        else if (i % 4 == 3 || i % 4 == 2)
        {
            t.push_back(s[i - 1]);
        }
    }
    if (n % 4 == 3 || n % 4 == 0)
    {
        reverse(t.begin(), t.end());
        cout << t << pre << "\n";
    }
    else
    {
        reverse(pre.begin(), pre.end());
        cout << pre << t << "\n";
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
