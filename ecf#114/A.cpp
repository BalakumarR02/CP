#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(ll n)
{
    if (n == 0)
        return;
    cout << "(";
    solve(n - 1);
    cout << ")";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, i, ans;

    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = n;
        while (ans)
        {
            for (i = 0; i < (n - ans); i++)
            {
                cout << "(";
            }
            for (i = 0; i < ans; i++)
            {
                cout << "()";
            }
            for (i = 0; i < (n - ans); i++)
            {
                cout << ")";
            }
            cout << endl;
            ans--;
        }
    }
    return 0;
}
