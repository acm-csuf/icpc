#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	//Encodes the following message as "CEO EUWH Ejcrvgt Twngu!"
	//by replacing each letter by the letter 2 places after it
	//with loopback (Z gets replaced by B, etc).
	//The main purpose is to show that characters in strings can
	//be interpreted as integers and used in arithmetic.
	string message = "ACM CSUF Chapter Rules!";
	int offset = 2;

	for (int i=0; i<message.length(); i++)
	{
		if ( isupper(message[i]) )
		{
			message[i] = (message[i] - 'A' + offset)%26 + 'A';
		}
		else if ( islower(message[i]) )
		{
			message[i] = (message[i] - 'a' + offset)%26 + 'a';
		}
	}

	cout << message << endl;

	system("pause");
	return 0;
}