#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    string s[100001];

    cin >> n;
    vector<pair<string, ll>> a;
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n);
    ll x = 1;
    for (i = 1; i < n; i++)
    {

        if (s[i] == s[i - 1])
        {
            x++;
            continue;
        }
        a.push_back({s[i - 1], x});
        x = 1;
    }
    if (s[i - 1] == s[i - 2])
    {
        a.push_back({s[i - 1], x});
    }

    ll pa = 0;
    x = 0;
    for (i = 0; i < (ll)a.size(); i++)
    {
        for (ll j = i + 1; j < (ll)a.size(); j++)
        {
            if ((a[i].first)[0] == (a[j].first)[0] || (a[i].first)[1] == (a[j].first)[1])
            {
                pa += ((a[i].second) * (a[j].second));
            }
        }
    }
    cout << pa << "\n";
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
