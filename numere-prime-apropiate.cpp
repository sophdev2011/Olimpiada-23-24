#include <iostream>

using namespace std;

int main() 
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) 
    {
        int a;
        cin >> a;
        bool prim = true;
        for (int j = 2; j * j <= a; ++j) 
        {
            if (a % j == 0) 
            {
                prim = false;
                break;
            }
        }
            
        if (prim==true) 
        {
            cout << a << " ";
        } 
        else 
        {
            int x = a - 1;
            while (true) 
            {
                bool primX = true;
                for (int k = 2; k * k <= x; ++k) 
                {
                    if (x % k == 0) 
                    {
                        primX = false;
                        break;
                    }
                }
                if (primX) 
                {
                    break;
                }
                x--;
            }
            int y = a + 1;
            while (true) 
            {
                bool primY = true;
                for (int k = 2; k * k <= y; ++k) 
                {
                    if (y % k == 0) 
                    {
                        primY = false;
                        break;
                    }
                }
                if (primY) 
                {
                    break;
                }
                y++;
            }
            if (a - x < y - a)
            {
                cout << y << " ";
            } 
            else if (a - x > y - a)
            {
                cout << x << " ";
            }
            else if (a-x==y-a)
            {
                if (c==1)
                    cout <<  x << " ";
                else if (c==2)
                cout << y << " ";
            }
        }
        } 

        return 0;
    }

