#include <bits/stdc++.h>
#include <fstream>

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
const int n = 5, m = 5;

float phi_a = 500, phi_b = 500, phi_c = 100, phi_d = 500;
float phi_oo = 300;
float side = 1, g = 1;
float del_x = side / n;
float A = del_x;

float h = 10;
float u = (h * g * 2 / del_x) / (h + g * 2 / del_x);

float src(int x, int y)
{
    return 100 + 500 * (n - x + y) / n;
    return 0;
}
vector<double> TDMA1D(ll n, vector<vector<double>> &a)
{
    ll i, j;
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
void TDMA2D1(ll n, ll m, vector<vector<vector<double>>> &a, ofstream &MyFile)
{
    ll i, j, k;
    double err = 1e9;

    ll iter = 0;
    vector<vector<double>> phi(n + 2, vector<double>(m + 2, 0));
    while (err >= 1e-6 && iter <= 1e5)
    {
        err = 0.0;
        for (i = 1; i <= m; i++)
        {
            vector<vector<double>> matr(n + 1, vector<double>(5, 0));
            for (j = 1; j <= n; j++)
            {
                matr[j][1] = a[j][i][1];
                matr[j][2] = a[j][i][4];
                matr[j][3] = a[j][i][5];
                matr[j][4] = a[j][i][6] + a[j][i][2] * phi[j][i + 1] + a[j][i][3] * phi[j][i - 1];
            }
            // for (j = 1; j <= n; j++)
            // {
            //     cout << matr[j][1] << " " << matr[j][2] << " " << matr[j][3] << " " << matr[j][4] << "  ";
            // }
            // cout << "\n";
            vector<double> ph1 = TDMA1D(n, matr);
            fo(j, 1, n)
            {
                err += (phi[j][i] - ph1[j]) * (phi[j][i] - ph1[j]);
                phi[j][i] = ph1[j];
                cout << phi[j][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";

        // err = sqrt(err);
        iter++;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            MyFile << setprecision(4) << fixed << phi[i][j] << " ";
        }
        MyFile << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream MyFile("tdma_ans.txt");

    ll i, j, p = 6, sweep = 2;
    vector<vector<vector<double>>> a(n + 1, vector<vector<double>>(m + 1, vector<double>(7, 0)));
    // To get the matrix
    double delx = ((double)1 / m), dely = ((double)1 / n), k = 1.0, h = 10.0, ueq = 0;
    ueq = (h * ((double)k / (dely / 2))) / (h + ((double)k / (dely / 2)));
    // cout << ueq << " ";
    vector<vector<float>> phi(m, vector<float>(n, 200));
    double err = 1e9;

    ll iter = 0;
    while (err >= 1e-6 && iter <= 1e5)
    {
        vector<vector<float>> ay(m, vector<float>(n, 0)), by(m, vector<float>(n, 0)), cy(m, vector<float>(n, 0)), dy(m, vector<float>(n, 0)), ax(m, vector<float>(n, 0)), bx(m, vector<float>(n, 0)), cx(m, vector<float>(n, 0)), dx(m, vector<float>(n, 0));

        err = 0.0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ax[i][j] = 4 * g * A / del_x;
                bx[i][j] = 1 * g * A / del_x;
                cx[i][j] = 1 * g * A / del_x;
                if (j != 0 && j != n - 1)
                {
                    dx[i][j] = phi[i][j + 1] * g * A / del_x + phi[i][j - 1] * g * A / del_x + src(i, j) * del_x * del_x;
                }
                else if (j != 0)
                {
                    dx[i][j] = phi[i][j - 1] * g * A / del_x + src(i, j) * del_x * del_x;
                }
                else
                {
                    dx[i][j] = phi[i][j + 1] * g * A / del_x + src(i, j) * del_x * del_x;
                }

                if (j == 0)
                {
                    ax[i][j] += 1 * g * A / del_x;
                    dx[i][j] += 2 * phi_d * g * A / del_x;
                }

                if (j == n - 1)
                {
                    ax[i][j] += 1 * g * A / del_x;
                    dx[i][j] += 2 * phi_b * g * A / del_x;
                }

                if (i == 0)
                {
                    ax[i][j] += 1 * g * A / del_x;
                    cx[i][j] = 0;
                    dx[i][j] += 2 * phi_a * g * A / del_x;
                }

                if (i == n - 1)
                {
                    ax[i][j] += u * A - 1 * g * A / del_x;
                    bx[i][j] = 0;
                    dx[i][j] += u * A * phi_oo;
                }
            }
            vector<vector<double>> a(n + 1, vector<double>(5, 0));
            for (int j = 0; j < n; j++)
            {
                a[j + 1][1] = ax[j][i];
                a[j + 1][2] = bx[j][i];
                a[j + 1][3] = cx[j][i];
                a[j + 1][4] = dx[j][i];
                cout << a[j + 1][1] << " ";
            }

            vector<double> phi_line = TDMA1D(m, a);
            for (int j = 0; j < n; j++)
            {
                err += pow((phi[j][i] - phi_line[j + 1]), 2);
                phi[j][i] = phi_line[j + 1];
            }
            cout << "\n";
        }
        cout << "\n\n";

        iter++;
        // sweep =2 (+x), =3(-x),=4(+y),=5(-y)
    }
    // TDMA2D1(n, m, a, MyFile);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            MyFile << setprecision(4) << fixed << phi[i - 1][j - 1] << " ";
        }
        MyFile << "\n";
    }
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