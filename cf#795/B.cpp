#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i, a[200001];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ne = 1, le = 0;
    vector<pair<ll, ll>> v, ans;
    for (i = 1; i <= n; i++)
    {
        if (i != n && a[i] == a[i - 1])
        {
            v.push_back({i + 1, i});
            ne++;
        }
        else
        {
            if (ne == 1)
            {
                cout << "-1\n";
                return;
            }
            v.push_back({le + 1, i});
            le = i;
            ne = 1;
        }
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++)
    {
        cout << v[i].second << " ";
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
