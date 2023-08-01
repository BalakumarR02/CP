#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;
ll binarySearch(ll arr[], ll low, ll high, ll x)
{
    if (high >= low)
    {
        ll mid = low + (high - low) / 2;
        if (x == arr[mid])
            return mid;
        if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid - 1), x);
    }
    return -1;
}
void solve()
{
    ll n, i, a[200001], k;

    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i < n - 1; i++)
    {
        if (binarySearch(a, i + 1, n - 1, a[i] + k) != -1)
        {
            cout << "YES\n";
            return;
        }
        // for (ll j = i - 1; j >= 0; j--)
        // {
        //     if ((a[i] - a[j]) == k)
        //     {
        //         cout << "YES\n";
        //         return;
        //     }
        // }
    }

    cout << "NO\n";
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
