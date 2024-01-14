#include <iostream>

using namespace std;

int main()
{
    int n, v[4], x, aux, ora_max, ora_min, min_max, min_min, auxzeciora = -1, auxunitora = -1, auxzecimin = -1, auxunitmi = -1, ignore_index_ore_zecimale = 1, ignore_index_ore_unitati = 1, ignore_index_min_zecimale = 1;
    cin >> n;
    x = n;
    for (int i = 1; i <= 4; i++)
    {
        v[i] = x % 10;
        x = x / 10;
    }

    // ================== Calcul Ora Maxima  ==================

    // Calcul zecimala ora
    for (int i = 1; i <= 4; i++)
    {
        if (auxzeciora < v[i] && v[i] <= 2)
        {
            auxzeciora = v[i];
            ignore_index_ore_zecimale = i;
        }
    }


    // Calcul unitati ora
    for (int i = 1; i <= 4; i++)
    {
        if (auxzeciora < 2)
        {
            if (auxunitora < v[i] && v[i] <= 9 && i != ignore_index_ore_zecimale)
            {
                auxunitora = v[i];
                ignore_index_ore_unitati = i;
            }
        }
        else
        {
            if (auxunitora < v[i] && v[i] <= 3 && i != ignore_index_ore_zecimale)
            {
                auxunitora = v[i];
                ignore_index_ore_unitati = i;
            }
        }
    }
    ora_max = -1;
    ora_max = auxzeciora * 10 + auxunitora;

    // Calcul zecimala minut
    for (int i = 1; i <= 4; i++)
    {
        if (auxzecimin < v[i] && v[i] <= 5 && i != ignore_index_ore_zecimale && i != ignore_index_ore_unitati)
        {
            auxzecimin = v[i];
            ignore_index_min_zecimale = i;
        }
    }

    // Calcul unitati minut
    for (int i = 1; i <= 4; i++)
    {

        if (i != ignore_index_min_zecimale && i != ignore_index_ore_unitati && i != ignore_index_ore_zecimale)
        {
            auxunitmi = v[i];
        }
    }

    min_max = -1;
    min_max = auxzecimin * 10 + auxunitmi;

    string antet_minute;
    if (min_max < 10) antet_minute = ":0";
    else antet_minute = ":";

    cout << ora_max << antet_minute << min_max << endl;

     // ================== Calcul Ora Minima  ==================
    auxzeciora = 10; 
    auxunitora = 10;
    auxzecimin = 10;
    auxunitmi = 10;
    // Calcul zecimala ora
    for (int i = 1; i <= 4; i++)
    {
        if (auxzeciora > v[i] && v[i] <= 2)
        {
            auxzeciora = v[i];
            ignore_index_ore_zecimale = i;
        }
    }


    // Calcul unitati ora
    for (int i = 1; i <= 4; i++)
    {
        if (auxzeciora < 2)
        {
            if (auxunitora > v[i] && v[i] <= 9 && i != ignore_index_ore_zecimale)
            {
                auxunitora = v[i];
                ignore_index_ore_unitati = i;
            }
        }
        else
        {
            if (auxunitora > v[i] && v[i] <= 3 && i != ignore_index_ore_zecimale)
            {
                auxunitora = v[i];
                ignore_index_ore_unitati = i;
            }
        }
    }
    ora_min = 10;
    ora_min = auxzeciora * 10 + auxunitora;

    // Calcul zecimala minut
    for (int i = 1; i <= 4; i++)
    {
        if (auxzecimin > v[i] && v[i] <= 5 && i != ignore_index_ore_zecimale && i != ignore_index_ore_unitati)
        {
            auxzecimin = v[i];
            ignore_index_min_zecimale = i;
        }
    }

    // Calcul unitati minut
    for (int i = 1; i <= 4; i++)
    {

        if (i != ignore_index_min_zecimale && i != ignore_index_ore_unitati && i != ignore_index_ore_zecimale)
        {
            auxunitmi = v[i];
        }
    }

    min_min = -1;
    min_min = auxzecimin * 10 + auxunitmi;
    
    string antet_ore2;
    string antet_minute2;

    if (ora_min < 10) antet_ore2 = "0";
    else antet_ore2 = "";

    if (min_min < 10) antet_minute2 = ":0";
    else antet_minute2 = ":";

    cout << antet_ore2 << ora_min << antet_minute2 << min_min << endl;

    int min_final, max_final;
    if (min_min>min_max)
    {
        ora_max--;
        min_max = min_max + 60;
    }
    min_final = min_max-min_min;
    max_final = ora_max-ora_min;

    string antet_minute3, antet_ore3;
    if ((max_final%10) == 0) antet_ore3 ="0";
    else antet_ore3 ="";

    if (min_min < 10) antet_minute3 =":0";
    else antet_minute3 =":";
    cout << antet_ore3 << max_final << antet_minute3 << min_final;

}
