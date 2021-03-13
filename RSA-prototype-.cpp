#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int prime()
{
	srand(time(NULL));
	vector<int> arr;
	for (int i = 2; i < 500; i++)
	{
		bool isprime = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isprime = false;
			}
		}
		if (isprime && 500 % i != 0)
		{
			arr.push_back(i);
		}
	}
	int roll = rand() % arr.size();
	return arr[roll];
}

int smallexp(int n)
{
	srand(time(NULL));
	vector<int> arr;
	for (int i = 2; i < n; i++)
	{
		bool isprime = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isprime = false;
			}
		}
		if (isprime && n % i != 0)
		{
			arr.push_back(i);
		}
	}
	int roll = rand() % arr.size();
	return arr[roll];
}

int main()
{
	int prime1 = prime(), prime2 = prime(), d = 0, message;
	int multy = prime1 * prime2, fib = (prime1 - 1) * (prime2 - 1);
	int openexp = smallexp(fib);

	cout << "Your open key is (you can send it): " << openexp << " " << multy << endl;
	while (((d * openexp) % fib != 1) && d < fib) { d++; }
	cout << "Your secret key is (DON'T SHOW IT TO ANYONE): " << d << " " << multy << endl;
	cout << "Enter you message (just number) and it hasn't to be more than " << multy << ": ", cin >> message;

	int encmessage = (int)pow(message, openexp) % multy;
	cout << "Encrypted message is: " << encmessage << endl;
	int decrypted = (int)pow(encmessage, d) % multy;
	cout << "Decrypted message is: " << decrypted << endl;

	return 0;
}
