#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool isPowerofTwo(ll n)
{
    if (n == 0)
        return 0;
    if ((n & (~(n - 1))) == n)
        return 1;
    return 0;
}

void solve()
{
    ll n, i, a[200001], h[200008] = {0}, med;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        h[a[i]]++;
    }
    sort(a, a + n);
    ll s = 0;
    for (i = 1; i <= n; i++)
    {
        if (h[i] > 0)
        {
            s += h[i];
            h[i] = s;
        }
    }

    ll l = 1, r = a[n - 1], ans = 1e9, cnt = 0, m = 0, low, high, mid, x;
    for (i = 2; i <= n + 2; i++)
    {
        cnt = 0;

        if (r == l)
        {
            r++;
        }
        low = h[l];
        mid = h[i] - h[l];
        if (r == i)
        {
            r++;
        }
        high = h[r] - h[l];
        if (!isPowerofTwo(low))
        {
            if (low <= 0)
            {
                cnt += 1;
            }
            else
            {
                x = log2(low) + 1;
                cnt += (pow(2, x) - low);
            }
        }
        if (!isPowerofTwo(mid))
        {
            if (mid <= 0)
            {
                cnt += 1;
            }
            else
            {
                x = log2(mid) + 1;
                cnt += (pow(2, x) - mid);
            }
        }
        if (!isPowerofTwo(high))
        {
            if (high <= 0)
            {
                cnt += 1;
            }
            else
            {
                x = log2(high) + 1;
                cnt += (pow(2, x) - high);
            }
        }
        ans = min(ans, cnt);

        if (h[i] > 0)
        {
            l = i;
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
