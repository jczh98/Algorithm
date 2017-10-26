#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1000;

int result[MAXN + 1];

int factorial(int n)
{
    int digits, j;

    memset(result, 0, sizeof(result));

    result[0] = 1;
    digits = 1;
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        for (j = 0; j < digits; j++)
            result[j] *= i;

        for (j = 0; j <= digits || carry; j++)
        {
            result[j] += carry;
            carry = result[j] / 10;
            result[j] %= 10;
        }
        digits = j;
    }

    return digits;
}

int main()
{
    int n, digits;

    while (cin >> n)
    {
        digits = factorial(n);
        int sum = 0;
        for (int i = 0; i <= digits; i++)
            sum += result[i];
        cout << sum << endl;
    }

    return 0;
}