#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, n, i, counter = 0,suma, numar_siruri, rest_sir;
    cin >> n;
    cin >> a >> b >> c >> d >> e;
    int counta=0, countb=0, countc=0, countd=0, counte=0;
    suma = a+b+c+d+e;
    int v[n], sir[suma];
    for(i=1; i<=suma; i++)
    {
        if (i<=a) sir[i] = 1;
        if (i>a && i<=a+b) sir[i] =2;
        if (i>a+b && i<=a+b+c) sir[i] =3;
        if (i>a+b+c && i<=a+b+c+d) sir[i] =4;
        if (i>a+b+c+d && i<=a+b+c+d+e) sir[i] = 5;
        cout << "sir["<<i<<"]=" << sir[i] << endl;
    }

    /// Daca avem mai putine pozitii decat numarul de elemente din sir: N < A+B+C+D+E calculam cate elemente din SIR incap pe cele N pozitii
    if(suma>n)
    {
        cout << "Ultimul patratel va avea indexul " << n << " si va fi " << sir[n] << endl;

        if (n>=a) cout << "Vom avea " << a <<" patratele ce contin valoarea 1 !" << endl;
        else cout << "Vom avea " << a-n <<" patratele ce contin valoarea 1 !" << endl;

        if (n>=a+b) cout << "Vom avea " << b <<" patratele ce contin valoarea 2 !" << endl;
        else if (n>a && n<=a+b) cout << "Vom avea " << (a+b)-n <<" patratele ce contin valoarea 2 !" << endl;

        if (n>=a+b+c) cout << "Vom avea " << c <<" patratele ce contin valoarea 3 !" << endl;
        else if (n>a+b && n<=a+b+c) cout << "Vom avea " << (a+b+c)-n <<" patratele ce contin valoarea 3 !" << endl;

        if (n>=a+b+c+d) cout << "Vom avea " << d <<" patratele ce contin valoarea 4 !" << endl;
        else if (n>a+b+c && n<=a+b+c+d) cout << "Vom avea " << (a+b+c+d)-n <<" patratele ce contin valoarea 4 !" << endl;

        if (n>=a+b+c+d+e) cout << "Vom avea " << e <<" patratele ce contin valoarea 5 !" << endl;
        else if (n>a+b+c+d && n<=a+b+c+d+e) cout << "Vom avea " << (a+b+c+d+e)-n <<" patratele ce contin valoarea 5 !" << endl;
    }
    /// Daca avem mai multe pozitii decat numarul de elemente din sir: N > A+B+C+D+E calculam:
    ///     -  cate cate siruri intregi incap - adica catul impartirii lui N la (A+B+C+D+E)
    ///     -  daca restul impartirii lui N la (A+B+C+D+E) este >0 atunci inseamna ca vor mai incapea si cateva elemente dintr-un ultim sir - ultim sir incomplet - elemente pe care le adunam la cele calculate mai sus
    else
    {
        numar_siruri = n/suma;
        cout << "Numarul de siruri intregi = " << numar_siruri << endl;
        rest_sir=n%suma;

        if(rest_sir !=0) cout << "Ultimul patratel va avea indexul " << n << " si va fi " << sir[n%suma] << endl;
        else cout << "Ultimul patratel va avea indexul " << n << " si va fi " << sir[suma] << endl;

        counta= a*numar_siruri;
        countb= b*numar_siruri;
        countc= c*numar_siruri;
        countd= d*numar_siruri;
        counte= e*numar_siruri;

        if(rest_sir>0)
        {
            cout << "La final vor mai incapea doar = " << rest_sir << " din ultimul sir!" endl;
            if (rest_sir>=a) counta = counta+a;
            else counta=counta+(a-rest_sir);

            if (rest_sir>=a+b) countb= countb+b;
            else if (rest_sir>a && rest_sir<=a+b) countb = countb+(a+b)-rest_sir;

            if (rest_sir>=a+b+c) countc = countc+c;
            else if (rest_sir>a+b && rest_sir<=a+b+c) countc = countc+(a+b+c)-rest_sir;;

            if (rest_sir>=a+b+c+d) countd = countd+d;
            else if (rest_sir>a+b+c && rest_sir<=a+b+c+d) countd = countd+(a+b+c+d)-rest_sir;

            if (rest_sir>=a+b+c+d+e) counte=counte+e;
            else if (rest_sir>a+b+c+d && rest_sir<=a+b+c+d+e) counte = counte+(a+b+c+d+e)-rest_sir;
        }

        cout << "A. Vom avea " << counta <<" patratele ce contin valoarea 1 !" << endl;
        cout << "B. Vom avea " << countb <<" patratele ce contin valoarea 2 !" << endl;
        cout << "C. Vom avea " << countc <<" patratele ce contin valoarea 3 !" << endl;
        cout << "D. Vom avea " << countd <<" patratele ce contin valoarea 4 !" << endl;
        cout << "E. Vom avea " << counte <<" patratele ce contin valoarea 5 !" << endl;

    }
    return 0;
}
