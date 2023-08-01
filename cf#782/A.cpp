#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, b, r, j = 0, k = 0;

    cin >> n >> r >> b;
    ll div = ceil((double)(r) / (b + 1));
    ll x = (r) % (b + 1);
    if (x == 0)
        x = (b + 1);
    i = 0;
    while (i < n)
    {

        if (k >= x)
        {
            for (j = 0; j < div - 1; j++)
            {
                cout << "R";
                i++;
            }
        }
        else
        {
            for (j = 0; j < div; j++)
            {
                cout << "R";
                i++;
            }
        }

        k++;
        if (i >= n)
            break;
        cout << "B";
        i++;
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
