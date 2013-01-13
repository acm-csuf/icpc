#include <iostream>
using namespace std;
	 
#define ARRAY_SIZE 5                                  //change the array size here
	 
void PrintArray(int* array, int n);
void QuickSort(int* array, int startIndex, int endIndex);
int SplitArray(int* array, int pivotValue, int startIndex, int endIndex);
void swap(int &a, int &b);
	 
int main(void)
{
	int array[ARRAY_SIZE];
	int i;
	     
	for( i = 0; i < ARRAY_SIZE; i++)             //array elements input
	{
		cout<<"Enter an integer : ";
		cin>>array[i];
	}

	cout<<endl<<"The list you input is : "<<endl;
	PrintArray(array, ARRAY_SIZE);
	QuickSort(array,0,ARRAY_SIZE - 1);              //sort array from first to last element
	cout<<endl<<"The list has been sorted, now it is : "<<endl;
	PrintArray(array, ARRAY_SIZE);
     
	cin.get();
	cin.get();
	return 0;
	}
 
	/* This function swaps two numbers
	   Arguments : a, b - the numbers to be swapped
   */

	void swap(int &a, int &b)
	{
	    int temp;
	    temp = a;
	    a = b;
	    b = temp;
	}
 
	/* This function prints an array.
		Arguments : array - the array to be printed
	   n - number of elements in the array
	*/

void PrintArray(int* array, int n)
{
    int i;      
	for( i = 0; i < n; i++) cout<<array[i]<<'\t';
}
	 
/* This function does the quicksort
	   Arguments :
	             array - the array to be sorted
	             startIndex - index of the first element of the section
	             endIndex - index of the last element of the section
*/

void QuickSort(int* array, int startIndex, int endIndex)
{

	int pivot = array[startIndex];                  //pivot element is the leftmost element
	int splitPoint;
     
	if(endIndex > startIndex)                         //if they are equal, it means there is
                                                      //only one element and quicksort's job
                                                     //here is finished
	{
		splitPoint = SplitArray(array, pivot, startIndex, endIndex);
                                                  //SplitArray() returns the position where
                                                  //pivot belongs to
        array[splitPoint] = pivot;
        QuickSort(array, startIndex, splitPoint-1);   //Quick sort first half
        QuickSort(array, splitPoint+1, endIndex);    //Quick sort second half
   }
}
	 
/* This function splits the array around the pivot
	   Arguments :
            array - the array to be split
            pivot - pivot element whose position will be returned
            startIndex - index of the first element of the section
            endIndex - index of the last element of the section
   Returns :
           the position of the pivot
*/
int SplitArray(int* array, int pivot, int startIndex, int endIndex)
{
    int leftBoundary = startIndex;
    int rightBoundary = endIndex;
    
	while(leftBoundary < rightBoundary)             //shuttle pivot until the boundaries meet
	{
    	while( pivot < array[rightBoundary]       //keep moving until a lesser element is found
				&& rightBoundary > leftBoundary)   //or until the leftBoundary is reached
		{
       		rightBoundary--;                      //move left
		}
		
		swap(array[leftBoundary], array[rightBoundary]);
//PrintArray(array, ARRAY_SIZE);            //Uncomment this line for study
          
		while( pivot >= array[leftBoundary]       //keep moving until a greater or equal element is found
		       && leftBoundary < rightBoundary)   //or until the rightBoundary is reached
		{
	        leftBoundary++;                        //move right
		}
 
    swap(array[rightBoundary], array[leftBoundary]);
         //PrintArray(array, ARRAY_SIZE);            //Uncomment this line for study
	}
	return leftBoundary;                              //leftBoundary is the split point because
                                                      //the above while loop exits only when
                                                      //leftBoundary and rightBoundary are equal
}
