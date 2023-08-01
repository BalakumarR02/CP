#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, b[502], j;

    cin >> n;
    vector<ll> a;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        b[i] = x;
    }
    sort(b, b + n);
    for (i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[j] == b[i])
                {
                    reverse(a.begin() + i, a.begin() + j + 1);
                    break;
                }
            }
            break;
        }
    }
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
