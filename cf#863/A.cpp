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

double x_vel(double x, double rho, double del)
{
    return rho * (x * x + 1) * del;
}
double y_vel(double x, double rho, double del)
{
    return rho * (x * x + 1) * del;
}
double m_sour(double x, double y)
{
    return 4 * (x + y);
}

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
    if (sweep == 3 || sweep == 5)
    {
        sweep--;
    }
    if (sweep > 3)
    {
        // sweep--;
        swap(n, m);
    }
    ll iter = 0;
    vector<vector<double>> phi(n + 2, vector<double>(m + 2, 0));
    while (err >= 1e-6 && iter <= 1e5)
    {
        err = 0.0;
        fo(i, 1, m)
        {
            ll ind = (sw == 2 || sw == 4) ? i : m - i + 1;
            vector<vector<double>> tda(n + 1, vector<double>(5, 0));

            for (j = 1; j <= n; j++)
            {
                double val = 0;
                ll f1 = j, f2 = ind;
                if (sw > 3)
                {
                    f1 = ind;
                    f2 = j;
                }
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
                }
                tda[j][4] = val + a[f1][f2][6];
            }

            vector<double> ph1 = TDMA1D(n, tda);

            fo(j, 1, n)
            {
                err += (phi[j][ind] - ph1[j]) * (phi[j][ind] - ph1[j]);
                phi[j][ind] = ph1[j];
            }
        }
        err = sqrt(err);

        iter++;
    }
    if (iter > 1e5)
    {
        cout << "Diverges!!!\n";
        return;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << setprecision(4) << fixed << phi[j][i] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, n, m, k;
    double L = 3.0, rho = 2.0, phi_s = 0.5, phi_b = 1.0, gamma = 3;
    cin >> n;
    m = n;
    vector<vector<vector<double>>> a(n + 1, vector<vector<double>>(n + 1, vector<double>(7, 0.0)));
    vector<vector<double>> phi(n + 2, vector<double>(n + 2, 0.0));
    double del_x = L / n, del_y = L / m;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            double F_e = x_vel(j * del_x, rho, del_y), F_w = x_vel((j - 1) * del_x, rho, del_y), F_n = y_vel(i * del_y, rho, del_x), F_s = y_vel((i - 1) * del_y, rho, del_x);
            double D_e = gamma * del_y / del_x, D_w = gamma * del_y / del_x, D_n = gamma * del_y / del_x, D_s = gamma * del_y / del_x;
            double ab = 0, ap = 0, ae = D_e - F_e / 2, an = D_n - F_n / 2, aw = D_w + F_w / 2, as = D_s + F_s / 2, b = phi_s * m_sour((i - 0.5) * del_x, (j - 0.5) * del_x) * del_x * del_y;
            if (i == 1)
            {
                ab += 2 * as;
                b += (2 * as * phi_b);
                as = 0;
            }
            else if (i == n)
            {
                ab += 0;
                an = 0;
            }
            if (j == 1)
            {
                ab += 2 * aw;
                b += (2 * aw * 0);
                aw = 0;
            }
            else if (j == n)
            {
                ab += 0;
                ae = 0;
            }
            ap = ae + aw + as + an + ab + F_e + F_n - F_s - F_w;
            a[i][j][1] = ap, a[i][j][2] = ae, a[i][j][3] = aw, a[i][j][4] = an, a[i][j][5] = as, a[i][j][6] = b;
        }
    }

    TDMA2D(n, m, a, 4);

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
