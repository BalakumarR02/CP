#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, ans;
    cin >> n;
    vector<int> a(n), b(n), coa(n + 1), cob(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        coa[a[i]]++;
        cob[b[i]]++;
    }

    ans = (ll)(n * (n - 1) * (n - 2)) / 6;
    for (i = 0; i < n; i++)
    {
        ans -= ((ll)(coa[a[i]] - 1) * (cob[b[i]] - 1));
    }

    cout << ans << endl;
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
