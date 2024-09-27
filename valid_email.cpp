// C++ program for the above approach

#include <iostream>
#include <regex>
using namespace std;

// Function to check the email id
// is valid or not
bool isValid(const string& email)
{

	// Regular expression definition
	const regex pattern(
		"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// Match the string pattern
	// with regular expression
	return regex_match(email, pattern);
}

// Driver Code
int main()
{
	// Given string email
	string email
		= "contribute@geeksforgeeks.org";

	// Function Call
	bool ans = isValid(email);

	// Print the result
	if (ans) {
		cout << email << " : "
			<< "valid" << endl;
	}
	else {
		cout << email << " : "
			<< "invalid" << endl;
	}
}
