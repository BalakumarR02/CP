#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, W, H, x1, y1, x2, y2, w, h, dw, dh, dist;

    cin >> t;
    while (t--)
    {
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        dw = (W - x2) + x1;
        dh = (H - y2) + y1;
        if (((W - x2) >= w || x1 >= w) || ((H - y2) >= h || y1 >= h))
        {
            dist = 0;
        }
        else if (dw < w && dh < h)
        {
            dist = -1;
        }
        else if (dw >= w && dh < h)
        {
            dist = min((w - x1), (w - (W - x2)));
        }
        else if (dh >= h && dw < w)
        {
            dist = min((h - y1), (h - (H - y2)));
        }
        else
        {
            dw = min((w - x1), (w - (W - x2)));
            dh = min((h - y1), (h - (H - y2)));
            dist = min(dh, dw);
        }
        cout << dist << endl;
    }
    return 0;
}
