#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int c, n, x, i = 1, f_max=0, d, m=0, y, j, aux, min_value_index=0;
    cin >> c;
    cin >> n;
    int v[n], v_forte[n];
    for (i=1; i<=n; i++)
    {
        cin >> y;
        v[i]=y;
    }
   for (i=1; i<=n; i++)
    {
        if (c==1)
        {
            if (v[i] == 1)
                m = 1;
            else m = 2;
            for (int d = 2; d * d <= v[i]; d++)
            {
                if (v[i] % d == 0)
                {
                    m = m+2;
                }
            }
            v_forte[i] = m;
            if(m == f_max) {
                if(v[i] < v[min_value_index]) {
                    min_value_index = i;
                }
            }

            if (m>f_max)
            {
                f_max = m;
                min_value_index = i;
            }


        }
    }
    for (i=1;i<=n;i++)
    {
        for (j = i+1; j<=n; j++)
        {
            if (v_forte[i]>v_forte[j])
            {
                aux = v_forte[i];
                v_forte[i] = v_forte[j];
                v_forte[j] = aux;

                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    if (c==1)
        {
            cout <<  f_max;
        }
    else
        cout << v_forte;
    return 0;
}

