#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

ofstream myfile;

void solve()
{
    ll r, c, n, i, k;
    cin >> r >> c;
    ll tree = 0;
    vector<vector<char>> v(r, vector<char>(c, 0));
    for (ll i = 0; i < r; i++)
    {
        for (ll j = 0; j < c; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == '^')
                tree++;
        }
    }

    if (!tree)
    {
        myfile << "Possible\n";
        for (ll i = 0; i < r; i++)
        {
            for (ll j = 0; j < c; j++)
            {
                myfile << v[i][j];
            }
            myfile << "\n";
        }
        return;
    }
    if (r == 1 || c == 1)
    {
        myfile << "Impossible\n";
        return;
    }
    myfile << "Possible\n";
    for (ll i = 0; i < r; i++)
    {
        for (ll j = 0; j < c; j++)
        {
            myfile << "^";
        }
        myfile << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;
    myfile.open("hacker.txt");

    for (ll i = 1; i <= t; i++)
    {

        myfile << "Case #" << i << ": ";
        solve();
    }
    myfile.close();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
