// 10125
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

int main(){
	// Variables
	long long int S;
	long long int d;
	long long int a;
	long long int b;
	long long int c;
	long long int ab;
	long long int abc;
	long long int temp;
	
	bool found;
	
	while ((cin >> S) && (S != 0)) {
		list<long long int> myList;
		long long int myArray[S];
		
		found = false;
		
		// Read in Values
		for (int i = 0; i < S; i++) {
			cin >> temp;
			myList.push_back(temp);
		}
		
		myList.sort();
		
		//cout << "S: " << S << endl;
		//cout << "List Size: " << myList.size() << endl;
		
		for(int i=0; i < S; i++) {
			myArray[i] = myList.front();
			myList.pop_front();
		}
	
		// Now check if proper value!
		for (int i = S-1; i >= 0; i--) {
			d = myArray[i];
			//cout << "D:" << d << endl;
			
			for (int j = S-1; j >= 0; j--) {
				if (j == i) {
					continue;
				}
			
				a = myArray[j];
				
				for (int k = S-1; k >= 0; k--) {
					if ((k == i) || (k == j)) {
						continue;
					}
				
				
					b = myArray[k];
					ab = a + myArray[k];
					
					for (int l = S-1; l >= 0; l--) {
						if ((l == i) || (l == k) || (l == j)) {
							continue;
						}
					
						c = myArray[l];
						abc = ab + myArray[l];
						//cout << "ABC: " << a << " + " << b << " + " << c << " = "<< abc << endl;
						
						if (abc == d) {
							//cout << "ABC: " << a << " + " << b << " + " << c << " = "<< abc << endl;
							cout << d << endl;
							found = true;
							break;
						}
					}
					
					if(found) {
						break;
					}
				}
				
				if(found) {
					break;
				}
			}
			
			if(found) {
				break;
			}
		}
		
		if (!found) {
			cout << "no solution" << endl;
		}
	}
	
	return 0;
}
