//Problem 661 - Blowing Fuses
//Sergio German & Jaime Cabrera
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int deviceNum, operations, capacity, sequence = 1;
	bool f = false;

	while(true)
	{
		vector<int> device;
		vector<int> ops;
		vector<bool> st;
		cin >> deviceNum >> operations >> capacity;

		if( (deviceNum == 0) && (operations == 0) && (capacity == 0) )
			break;

		f = false;
		int count = 0;
		int d = 0;

		while(count < deviceNum)
		{
			cin >> d;
			device.push_back(d);
			st.push_back(false);
			++count;
		}

		count = 0;
		int o = 0;

		while(count < operations)
		{
			cin >> o;
			ops.push_back(o-1);
			++count;
		}

		int maxAmps = 0;
		int cons = 0;
		int ans = 0;

		for( vector<int>::iterator it = ops.begin();!f && it != ops.end(); it++)
		{
			int cdev;
			cdev = *it;
			bool state = st[cdev];
			if (state)
				cons -= device[cdev];
			else
			{
				cons += device[cdev];
				maxAmps = max(cons , capacity  );
				if(maxAmps > capacity)
					f = true;
			}
		state = !state;
		st[cdev] = state;
		ans = max(cons,ans);
      }

	  cout << "Sequence " << sequence << endl;

		if(f == true)
			cout << "Fuse was blown." << endl;
		else{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << ans << " amperes." << endl;
		}
		sequence++;
		cout << endl;
	}
	return 0;
}
