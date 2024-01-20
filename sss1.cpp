#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("sss.in");
ofstream fout("sss.out");
int main()
{
    int c, n, k = 0, aux, sum = 0, l = 1, max_sum = 0, sum_l = 0;
    fin >> c >> n;
    int v[n];
    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
        if (c == 1 && i == 1)
        {
            aux = v[i];
            while (aux > 0)
            {
                if (aux % 10 != 0)
                {
                    k = aux % 10;
                    break;
                }
                else
                    aux = aux / 10;
            }
        }
    }
    if (c == 1 && k > 0 && k < n)
    {
        for (int i = n - k + 1; i <= n; i++)
        {
            sum = sum + v[i];
            k++;
        }
        fout << sum;
    }
    if (c == 2)
    {
        while (sum_l < n)
        {

            sum = 0;
            for (int i = n - sum_l; i > n - sum_l - l; i--)
            {
                sum = sum + v[i];
            }

            if (max_sum < sum)
                max_sum = sum;

            sum_l = sum_l + l;
            l++;
        }
        fout << max_sum;
    }
}