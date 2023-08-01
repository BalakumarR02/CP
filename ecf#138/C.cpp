#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, ao = 1, az = 1, co = 0, aco = 0;
    string a, b, a1;
    cin >> n >> a >> b;
    a1 = a;
    for (i = 0; i < n; i++)
    {
        a1[i] = (1 - (a1[i] - '0')) + '0';
        if (a[i] == '0')
        {
            ao = 0;
            aco++;
        }
        if (a[i] == '1')
        {
            az = 0;
            co++;
        }
    }
    if (a == b && az)
    {
        cout << "YES\n";
        return;
    }
    if (a == b)
    {
        cout << "YES\n";

        if (ao)
        {
            cout << "2\n";

            cout << "1 1\n2 " << n << "\n";
        }
        else
        {
            cout << 1 + aco << "\n";

            cout << "1 " << n << "\n";
            for (i = 0; i < n; i++)
            {
                if (a1[i] == '1')
                {
                    cout << i + 1 << " " << i + 1 << "\n";
                }
            }
        }
    }
    else if (a1 == b)
    {
        cout << "YES\n";

        if (az)
        {
            cout << "3\n";
            cout << "1 " << n << "\n";
            cout << "1 1\n2 " << n << "\n";
        }
        else
        {
            cout << co << "\n";

            for (i = 0; i < n; i++)
            {
                if (a[i] == '1')
                {
                    cout << i + 1 << " " << i + 1 << "\n";
                }
            }
        }
    }
    else
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
