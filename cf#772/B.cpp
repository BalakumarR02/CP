#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k, a[200001];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> v;
    ll m = 0;
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            v.push_back(i);
        }
    }
    ll sz = v.size();
    for (i = 0; i < sz; i += 2)
    {
        if (i < sz - 1 && v[i + 1] - v[i] == 2)
        {
            m++;
            a[(v[i + 1] + v[i]) / 2] = max(a[((v[i + 1] + v[i]) / 2) - 1], a[((v[i + 1] + v[i]) / 2) + 1]);
        }
        else
        {
            m++;
            a[v[i]] = max(a[v[i] - 1], a[v[i] + 1]);
            i--;
        }
    }

    cout << m << "\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
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
