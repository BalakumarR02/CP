#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    string s, s1;
    cin >> n;
    cin >> s;
    s1.push_back(s[0]);
    for (i = 1; i < n; i++)
    {
        if (((s[i] - 'a') <= (s[i - 1] - 'a')) && s[i] != s1[0])
        {
            s1.push_back(s[i]);
        }
        else
        {
            break;
        }
    }
    cout << s1;
    for (i = s1.length() - 1; i >= 0; i--)
        cout << s1[i];
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
