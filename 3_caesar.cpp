#include <iostream>
#include <string>
using namespace std;

void decrypt()
{
	string str;
	int key;

	cout << "Enter the encrypted message" << endl;
	cin.ignore();
	getline(cin, str);
	cout << "Enter the shift: ";
	cin >> key;

	char ch;
	for (int i = 0; str[i] != '\0'; i++)
	{
		ch = str[i];
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - key;

			if (ch < 'a')
			{
				ch = ch + 'z' - 'a' + 1;
			}
			str[i] = ch;
		}

		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch - key;

			if (ch < 'A')
			{
				ch = ch + 'Z' - 'A' + 1;
			}
			str[i] = ch;
		}
	}
	cout << "Decrypted message is: " << endl;
	cout << str << endl;
}
void encrypt()
{
	string str;
	int key;

	cout << "Enter the message to encrypt:" << endl;
	cin.ignore();
	getline(cin, str);
	cout << "Enter the shift: ";
	cin >> key;

	char ch;
	for (int i = 0; str[i] != '\0'; i++)
	{
		ch = str[i];
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch + key;

			if (ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}
			str[i] = ch;
		}

		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + key;

			if (ch > 'Z')
			{
				ch = ch - 'Z' + 'A' - 1;
			}
			str[i] = ch;
		}
	}
	cout << "Encrypted message is: " << endl;
	cout << str << endl;
}

int main()
{
	while (1)
	{
		cout << endl
			 << "CAESAR CIPHER" << endl;
		cout << "Choose Option:" << endl
			 << "1)Encrypt" << endl
			 << "2)Decrypt" << endl
			 << "3)Exit" << endl;
		int c;
		cin >> c;

		switch (c)
		{
		case 1:
			encrypt();
			break;
		case 2:
			decrypt();
			break;
		case 3:
			return 0;
		default:
			cout << "Enter Choice Correctly" << endl;
		}
	}
}
