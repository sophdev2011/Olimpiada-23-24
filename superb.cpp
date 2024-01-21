#include <fstream>

using namespace std;
ifstream fin("superb.in");
ofstream fout("superb.out");
int main()
{
    int x, n = 0, cat;
    fin >> x;
    if (x%2023==0)
    {
        cat = x/2023;
        while (cat>0)
        {
            n = n + cat%10;
            cat = cat/10;
        }
        fout << n;
    }
    else 
    {
        fout << "NU";
    }
    return 0;
}