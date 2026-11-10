#include <iostream>


using namespace std;




float BruteForcePolynomial(int p[], int n, float x0)
{
    float res = 0;
    for (int i = n; i >= 0; --i)
    {
       float power = 1;
       for (int j = 1; j <= i; ++j)
        power *= x0;
        cout << "\np=" << p[i] << endl;

       res += p[i]*power;
    }
    return res;
}

int main()
{
    int p[] = {4, -5, 2, 1};
    int n = sizeof(p)/sizeof(p[0])-1;

    float x = 1.2;

    cout << BruteForcePolynomial(p, n, x);

    return 0;
}

