#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n;
    string s;

    cin >> s;
    n = s.length();
    ll i = 0, j = n - 1, mi = -1;
    char le = 'z' + 1;
    for (i = 1; i < n - 1; i++)
    {
        if (le > s[i])
        {
            le = s[i];
            mi = i;
        }
    }
    i = 0;
    ll maj = min(mi + 1, n - 1), mai = max(mi - 1, (ll)0);
    if ((maj > n - 1 || le < s[mi + 1]) && (mai < 1 || le < s[mi - 1]))
    {
        cout << "Alice\n";
        return;
    }
    char se;
    if (s[maj] != s[mai])
    {
        cout << "Alice\n";
        return;
    }

    cout << "Draw\n";
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
