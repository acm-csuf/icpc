// This is NOT COMPLETE :)

// example of string class
// parse input
// compile on command line
// read input until EOF (end of file)
// input/output redirect

#include <iostream>
#include <string>
using namespace std;

// == Compile_on_Command_Line =======================================
// 
// $ g++ myfile.cpp -o name
// $ ./name
// 
// ==================================================================

// == Read_input_until_(EOF) ========================================
// 
// If you are using the command line to enter input, this
// program will wait for input. Once you type something and
// press enter, the program will read each "word" in a loop
// until it reaches the end of the line (where you pressed enter),
// and it will print each "word" out onto the command line
// followed by a new line.
//
// Example: you type "1 2 3", and you see
// 1
// 2
// 3
//
// Then the program waits for you to enter something again.
// If you press "cntrl + c" the program will end. If you press
// "cntrl + d" the program also ends. The difference is that
// "cntrl + d" represents the EOF character which is read by the
// program and tells the while loop to stop looping, while "cntrl + c"
// actually terminates the program no matter what it is doing.
//
// In short, the program is waiting for the EOF character to end,
// even though you did not specify this in the program. This is why
// the program stops when it is reading from an input file (instead
// of reading from the command line).
//
// ==================================================================

// == Input/Output_Redirecting ======================================
//
// The cool thing is that you can give the program a file without
// using file I/O! That's right; no opening and closing files or
// any extra lines of code in your program. How you do this is with
// redirection operators ('<' and '>').
//
// In your command line
//
// ==================================================================

int main(void)
{
	string mystring;
	
	while(cin >> mystring)
		{
		cout << mystring << endl;
		}

	return 0;
}
