#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

int GCD(int num1, int num2);
int LCM(int num1, int num2);

void order(int& num1, int& num2);

int main()
{
	int a = 0;
	int b = 0;
	
	cout<< "Enter two numbers to compute the GCD and LCM: ";
	cin >> a;
	cin >> b; 
       
	order(a,b);

	cout << "GCD of " << a << " " << b << " is " 
             << GCD(a,b) << endl;
      
        cout << "LCM of " << a << " " << b << " is " 
	     << LCM(a,b)  << endl;	

	return 0;
}

//////////////////////////////////////
///for the case of GCD for more than 2 numbers use:
///GCD(num1,num2,num3) => GCD(GCD(num1,num2),num3)
//////////////////////////////////////
int GCD(int num1, int num2)
{
	//quick check if any of the two is zero
	if(num2 == 0) 
	{
		return num1; 
	}
	else if (num1 == 0)
	{
		return num2;
	}	


	// after having setup num1 to hold the largest value we 
	// iterate N times until gcd is found when the remainder is zero
	while(num2 != 0)
	{	
		int temp = num2; // temp holds the last value of num2 while the next remainder is calculated
		num2 = num1 % temp;// num2 gets assigned the remainder of num1%num2
		num1 = temp;//num1 holds its predecessor
	}
	
	return num1;


}



////////////////////////////////////////////////////////////////////////////////////
///for the case of finding the LCM of more than two numbers use the recursive method:
///LCM(num1,num2,num3) => LCM(LCM(num1,num2),num3)
////////////////////////////////////////////////////////////////////////////////////	
int LCM(int num1, int num2)
{	
	
	int remainder,largest,smaller;
	int lcm = 0;

	//quick check if any of the two is zero
	if(num2 == 0)
	{
		return num1;
	}
	else if(num1==0)
	{
		return num2;
	}	


	
	//num1 holds the largest value
	largest = num1;
	smaller = num2;
	remainder = largest%smaller;

	while(remainder != 0)
	{
		largest = smaller;
		smaller = remainder;
		remainder = largest % smaller;
		
	}

	lcm = (num1 * num2)/smaller;

	return lcm;

}


void order(int& num1, int& num2)
{
	//if num2 is greater than num1 values are swapped
	if(num2 > num1)
	{
		swap(num1,num2);
	}
}
