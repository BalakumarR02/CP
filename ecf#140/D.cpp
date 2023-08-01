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
    ll x = 1, con = 0;
    char c = '2';
    for (i = 2; i <= n; i++)
    {
        if (s[i - 2] == '0')
        {
            if (c == '2' || c == '0')
                con++;
            else
            {
                con = 1;
            }
            c = s[i - 2];
        }
        else if (s[i - 2] == '1')
        {
            if (c == '2' || c == '1')
                con++;
            else
                con = 1;
            c = s[i - 2];
        }
        cout << i - con << " ";
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
