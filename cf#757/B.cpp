#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
void solve()
{
    ll n, i, a[200001], x0 = 0, t;

    cin >> n;
    pair<ll, ll> q[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        q[i] = make_pair(a[i], i);
    }
    t = 1;
    sort(q, q + n);
    for (i = n - 1; i >= 0; i -= 2)
    {
        q[i].first = x0 - t;
        if ((i <= 0))
            break;
        q[i - 1].first = x0 + t;
        t++;
    }
    t = 0;
    sort(q, q + n, sortbysec);
    for (i = 0; i < n; i++)
    {
        t += (2 * (abs(q[i].first - x0)) * (a[i]));
    }
    cout << t << endl;
    cout << x0 << " ";

    for (i = 0; i < n; i++)
    {
        cout << q[i].first << " ";
    }
    cout << endl;
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
