#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;
    string s, k;
    cin >> n >> s >> k;
    map<ll, ll> fix, mov;
    i = 0;
    while (i < n)
    {
        if (s[i] == '1')
            fix[i] = 1;
        else
            break;
        i++;
    }
    ll j = n - 1;
    while (j >= 0)
    {
        if (s[j] == '1')
            fix[j] = 1;
        else
            break;
        j--;
    }
    for (; i <= j; i++)
    {
        if (s[i] == '1')
        {
            mov[i] = 1;
        }
    }
    ll ans = 0, prevo = -1e9, ones = 0, nones = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ones++;
        if (s[i] == '1' && !fix[i])
        {
            prevo = i;
        }
        if (k[i] == '1')
        {
            nones++;
            if (fix[i])
            {
                continue;
            }
            else if (mov[i])
            {
                mov[i] = 2;
                continue;
            }
            if (fix[i - 1] || fix[i + 1])
            {

                if (!mov[i + 1] && !mov[i - 1])
                {
                    ans++;
                    ones++;
                    fix[i] = 1;
                }
                else
                {
                    cout << "-1\n";
                    return;
                }
            }
            else
            {
                auto p = mov.upper_bound(i);
                if (p == mov.end() && prevo != -1e9 && mov[prevo] != 2)
                {
                    ans += ((i - prevo) * 2);
                    mov[prevo] = 0;
                    mov[i] = 1;
                }
                else if (p != mov.end())
                {
                    ll curo = p->first;
                    if ((i - prevo) < (curo - i))
                    {
                        ans += ((i - prevo) * 2);
                        mov[prevo] = 0;
                        mov[i] = 2;
                    }
                    else
                    {
                        ans += ((curo - i) * 2);
                        mov[curo] = 0;
                        mov[i] = 2;
                    }
                }
                else
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
    }
    if (ones != nones)
        cout << -1 << "\n";
    else
        cout
            << ans << "\n";
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
