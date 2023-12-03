#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("furnica.in");
ofstream fout("furnica.out");
int main()
{
    int N, C, T, aux, TP = 0, maxim = 0, lungime_parcursa = 0, timp_intrare, aux_i = 0;
    fin >> C;
    if (C==1 || C==2)
        fin >> N;
    else if (C==3)
        fin >> N >> T;
    int lv[N], lo[N];
    for (int i=1; i<=N; i++)
    {
        fin >> lo[i] >> lv[i];
    }
    aux = 0;
    for (int i=1; i<=N; i++)
    {
        timp_intrare=TP;
        /// coborare
        if (lv[i]<aux)
        {
            if (maxim < lungime_parcursa)
            {

                maxim = lungime_parcursa;
                lungime_parcursa = 0;
            }
            TP = TP + 2* (aux - lv[i]);
        }

        /// urcare
        if (lv[i]>aux)
        {
            TP = TP + 5 * (lv[i]-aux);
            lungime_parcursa = lungime_parcursa +(lv[i]-aux);
        }

        /// mers orizontal
        TP = TP + 3 * lo[i];
        lungime_parcursa = lungime_parcursa + lo[i];


        aux = lv[i];
        if (T >timp_intrare && T<=TP)
            aux_i = i;
    }
    TP = TP + lv[N] * 2;
    if (C==1)
        fout << TP;
    if (C==2)
        fout << maxim;
    if (C==3)
        fout << aux_i;
}
