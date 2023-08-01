#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define all1(v) (v).begin() + 1, (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define allr1(v) (v).rbegin() + 1, (v).rend()
#define sort0(v) sort(all(v))
#define fo(i, a, b) for (i = a; i <= b; i++)
#define fi(i, a, b) for (i = a; i >= b; i--)

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define sz(x) (ll) x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005

const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
const ll N = 1e5; // limit for array size

vector<double> TDMA1D(ll n, vector<vector<double>> &a)
{
    ll i, j, m;
    m = 4;
    vector<double> phi(n + 2, 0);

    vector<double> P(n + 1, 0), Q(n + 1, 0);
    fo(i, 1, n)
    {
        P[i] = a[i][2] / (a[i][1] - a[i][3] * P[i - 1]);
        Q[i] = (a[i][3] * Q[i - 1] + a[i][4]) / (a[i][1] - a[i][3] * P[i - 1]);
    }
    fi(i, n, 1)
    {
        phi[i] = P[i] * phi[i + 1] + Q[i];
    }
    return phi;
}

void TDMA2D(ll n, ll m, vector<vector<vector<double>>> &a, ll sweep)
{
    ll i, j, k;
    double err = 1e9;
    ll sw = sweep;
    if (sweep == 3)
    {
    }
    if (sweep > 3)
    {
        sweep--;
        swap(n, m);
    }
    ll iter = 0;
    vector<vector<double>> phi(n + 2, vector<double>(m + 2, 0));
    while (err > 1 && iter <= 1e5)
    {
        fo(i, 1, m)
        {
            ll ind = (sw == 2 || sw == 4) ? i : m - i + 1;
            vector<vector<double>> tda(n + 1, vector<double>(4, 0));

            for (j = 1; j <= n; j++)
            {
                double val = 0;
                ll f1 = j, f2 = ind;
                for (k = 1; k < 6; k++)
                {
                    if (k == sweep)
                    {
                        val += a[f1][f2][k] * phi[j][ind + 1];
                        continue;
                    }
                    else if (k == sweep + 1)
                    {
                        val += a[f1][f2][k] * phi[j][ind - 1];
                        continue;
                    }
                    tda[j][max(1LL, k - ((sw < 4) ? 2 : 0))] = a[f1][f2][k];
                    // cout << j << " " << k << "  ";
                }
                tda[j][4] = val + a[f1][f2][6];
            }
            fo(j, 1, n)
            {
                for (k = 1; k <= 4; k++)
                {
                    cout << tda[j][k] << " ";
                }
                cout << "\n";
            }
            vector<double> ph1 = TDMA1D(n, tda);

            fo(j, 1, n)
            {

                err += (phi[j][ind] - ph1[j]) * (phi[j][ind] - ph1[j]);

                phi[j][ind] = ph1[j];
                // cout << ph1[j] << " ";
            }
            cout << "\n";
        }
        err = sqrt(err);
        // cout << err << "\n";

        iter++;
    }
    if (iter > 1e5)
    {
        cout << "Diverges!!!\n";
        return;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cout << phi[i][j] << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, i, j, k, p = 6, sweep = 3;
    cin >> n >> m;
    vector<vector<vector<double>>> a(n + 1, vector<vector<double>>(m + 1, vector<double>(p + 1, 0)));
    // To get the matrix

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= p; k++)
            {
                cin >> a[j][i][k];
            }
        }
    }
    // sweep =2 (+x), =3(-x),=4(+y),=5(-y)
    TDMA2D(n, m, a, sweep);

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)

// 5
// 3 -1 0 0 0
// -1 2 -1 0 0
// 0 -1 2 -1 0
// 0 0 -1 2 -1
// 0 0 0 -1 3
// 204 12 20 28 1236
// 200

// 5
// 3 1 0 204
// 2 1 1 12
// 2 1 1 20
// 2 1 1 28
// 3 0 1 1236

// 20  5 0  1100
// 15  5 5  100
// 15  5 5  100
// 15  5 5  100
// 10  0 5  100

// 4 3
// 20	10	0	10	0	500
// 30	10	0	10	10	500
// 30	10	0	10	10	500
// 40	10	0	0	10	2500
// 30	10	10	10	0	0
// 40	10	10	10	10	0
// 40	10	10	10	10	0
// 50	10	10	0	10	2000
// 20	0	10	10	0	0
// 30	0	10	10	10	0
// 30	0	10	10	10	0
// 40	0	10	0	10	2000