#include <bits/stdc++.h>
using namespace std;

long int m, e[100], d[100], p, q, n, t, no_of_entries;
int flag;

int prime(long int pr)
{
    long int i;
    long int j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

long int cd(long int e)
{
    long int k = 1;
    while (1)
    {
        k = k + t; // same as 1+k*t
        if (k % e == 0)
            return (k / e);
    }
}

void ce()
{
    int k;
    k = 0;
    for (long int i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 10)
                break;
        }
    }

    no_of_entries = k;
}

void encrypt()
{
    long int pm, e_key;
    unsigned long long k;

    cout << "Enter the number to be encrypted : ";
    cin >> pm;

    cout << "Choose the key e : ";
    cin >> e_key;

    k = 1;
    for (long int j = 0; j < e_key; j++)
    {
        k = k * pm;
        k = k % n;
    }
    //k = (long long)pow(pm, e_key) % n;

    cout << "\nTHE ENCRYPTED MESSAGE IS : " << k << endl;
}

void decrypt()
{
    long int cm, d_key, k;

    cout << "Enter the number to be decrypted : ";
    cin >> cm;

    cout << "Choose the key d : ";
    cin >> d_key;

    k = 1;
    for (long int j = 0; j < d_key; j++)
    {
        k = k * cm;
        k = k % n;
    }

    cout << "\nTHE DECRYPTED MESSAGE IS : " << k << endl;
}

int main()
{
    cout << "\nENTER P : ";
    cin >> p;
    flag = prime(p);
    if (flag == 0)
    {
        cout << "\nWRONG INPUT , Enter a prime number \n";
        exit(1);
    }
    cout << "\nENTER q: ";
    cin >> q;
    flag = prime(q);
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT , Enter a prime number p!=q \n";
        exit(1);
    }

    n = p * q;
    t = (p - 1) * (q - 1);

    cout << "Value of n = p * q = " << n << endl;
    cout << "Value of  t = (p - 1) * (q - 1) = " << t << endl;

    ce();

    cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
    for (int i = 0; i < no_of_entries; i++)
        cout << e[i] << "\t" << d[i] << "\n";

    encrypt();
    decrypt();

    return 0;
}
