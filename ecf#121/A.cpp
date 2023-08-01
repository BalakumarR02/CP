#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, h[26] = {0};
    string s;
    char c;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++)
    {
        h[s[i] - 'a']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (h[i] == 2)
        {
            c = i + 'a';
            cout << c;
            cout << c;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (h[i] == 1)
        {
            cout << (char)(i + 'a');
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
