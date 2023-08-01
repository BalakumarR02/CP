#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, j, k, s = 0;

    cin >> n >> k;
    vector<ll> a;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    j = k;
    s = 0;
    while (j && !a.empty())
    {
        s += (*(a.end() - 1 - j) / *(a.end() - 1));
        a.erase(a.end() - 1 - j);
        a.erase(a.end() - 1);
        j--;
    }

    if (a.size())
    {
        for (j = 0; j < a.size(); j++)
        {
            s += a[j];
        }
    }
    cout << s << endl;
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
