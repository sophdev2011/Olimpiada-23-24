#include <iostream>

using namespace std;

int main()
{
    int n, suma, pc, npc, rest_pc, rest_npc, cat_pc, cat_npc;
    cin >> n >> pc >> npc;
    bool Ok = false;
    suma = npc + pc;
    if ((pc < 0 || pc > 100000) || (npc < 0 || npc > 100000) || (n < 0 || n > 100000))
    {
        cout << -1;
    }
    else
    {
        // k va fi restul impartirii lui n la pc*i, respectiv la npc*j
        for (int k = 0; k < n; k++)
        {
            // i reprezinta nr potential de ciocolate pt PC; PC trb sa primeasca nr max de ciocolate, de aceea parcurgem descrescator
            for (int i = n - k; i > 0; i--)
            {
                // j reprezinta nr potential de ciocolate pt NPC; NPC trb sa primeasca nr min de ciocolate, de aceea parcurgem crescator
                for (int j = 1; j < n - k; j++)
                {
                    if ((i * pc + j * npc) == n - k)
                    {
                        //cout << "PC = " << i << " ciocolate, NPC = " << j << " ciocolate si au ramas " << k << " ciocolate nedistribuite!" << endl;
                        cout << k;
                        Ok = true;
                        i = 0;
                        j = n;
                        k = n;
                    }
                }
            }
        }
    }
    if (Ok==false) cout << -1;
    return 0;
}
