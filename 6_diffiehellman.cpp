#include <bits/stdc++.h>
using namespace std;
unsigned int power(unsigned long long int a, unsigned long long int b, unsigned long long int p)
{
	if (b == 1)
		return a;
	else
		return ((unsigned long long)pow(a, b) % p);
}
int main()
{
	unsigned long long int p1, p2, s1, s2, x1, x2, sym1, sym2;
	cout << "Enter Publicly available numbers\n";
	cin >> p1 >> p2;
	cout << "Enter the secret key selected by the first person\n";
	cin >> s1;
	cout << "Computing Public Key..\n";
	x1 = power(p2, s1, p1);
	cout << "Done !\nPublic key 1-> " << x1 << endl;
	cout << "Enter the secret key selected by the second person\n";
	cin >> s2;
	cout << "Computing Public Key..\n";
	x2 = power(p2, s2, p1);
	cout << "Done!\nPublic key 2 -> " << x2 << endl;
	cout << "Sharing Public Key\n";
	sym1 = power(x2, s1, p1);
	sym2 = power(x1, s2, p1);
	cout << "Shared Secret 1-> " << sym1 << "\nshared secret key 2-> " << sym2;
}
