#include <iostream>

using namespace std;

int main()
{
    int n,i, max_1 = 0, max_2 = 0, last_number, counter_max_1 = 0, counterVictor = 0, counterRadu = 0, first_number, nc, contine_2_cifre = 0, parcurgeri=1, carti_nealocate, pozitie_carte_nealocata=1;
    cin >> n;
    int v[n], cartialocate[n];
    /// citit vector
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        // toate cartile sunt nealocate
        cartialocate[i] = 0;

    }

    /// Determinare cele mai mari doua cifre din ultimul numar
    last_number = v[n];
    while (last_number>0)
    {
        if (max_1<last_number%10)
            max_1 = last_number%10;
        last_number = last_number / 10;
    }
    last_number = v[n];
    while (last_number>0)
    {
        if (max_1==last_number%10)
            counter_max_1++;
        if (max_2<last_number%10 && last_number%10<max_1)
            max_2 = last_number%10;
        if (counter_max_1>1)
        {
            max_2=max_1;
            break;
        }
        last_number = last_number / 10;
    }

    carti_nealocate = n;
    int parcurgere = 0;

    /// Parcurgem cartile de mai multe ori pana le alocam pe toate

    while(carti_nealocate > 0)
    {
        parcurgere++;
        /// gasim primul numar nealocat si aflam max1 si max2 al cifrelor sale
        i = 1;
        while (i<=n)
        {
            nc = v[i];
            counter_max_1 = 0;
            max_1 = 0;
            max_2 = 0;
            if (cartialocate[i] == 0)
            {
                while (nc>0)
                {
                    if (max_1<nc%10)
                        max_1 = nc%10;
                    nc = nc / 10;
                }
                nc = v[i];
                while (nc>0)
                {
                    if (max_1==nc%10)
                        counter_max_1++;
                    if (max_2<nc%10 && nc%10<max_1)
                        max_2 = nc%10;
                    if (counter_max_1>1)
                    {
                        max_2=max_1;
                        break;
                    }
                    nc = nc / 10;
                }
                // numar nealocat gasim - iesim din cautarea primului numar nealocat
                i = n;
            }
            //continuam cautarea
            i++;
        }

        // Alocam cartile ramase
        for(i=1; i<=n; i++)
        {


            // daca cartea[i] nu este alocata
            if (cartialocate[i] == 0)
            {
                nc = v[i];
                contine_2_cifre =0;
                while (nc>0)
                {
                    if (nc%10 == max_1 || nc%10 == max_2) contine_2_cifre++;
                    if (contine_2_cifre>1)
                    {
                        cartialocate[i] = 1;
                        if (parcurgere%2 == 0)
                        {
                            counterRadu++;
                        }
                        else
                        {
                            counterVictor++;
                        }
                        carti_nealocate--;
                        break;
                    }
                    nc = nc/10;
                }
            }

        }
    }

    if (counterRadu > counterVictor) cout <<"R "  << counterRadu;
    if (counterRadu < counterVictor) cout <<"V "  << counterVictor;

    return 0;
}