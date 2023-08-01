#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i = 0, m, k;
    string a, b, ans;

    cin >> n >> m >> k >> a >> b;
    ll j = 0, num = 0, num1 = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            num1 = 0;
            if (num < k)
            {
                ans.push_back(a[i]);
                i++;
                num++;
            }
            else
            {
                ans.push_back(b[j]);
                j++;
                num = 0;
            }
        }
        else
        {
            num = 0;
            if (num1 < k)
            {
                ans.push_back(b[j]);
                j++;
                num1++;
            }
            else
            {
                ans.push_back(a[i]);
                i++;
                num1 = 0;
            }
        }
    }

    cout << ans << "\n";
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
