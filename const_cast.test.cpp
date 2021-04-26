#include<string>
#include<iostream>

using namespace std;

int main()
{
	const string s1 = "gpf123";
	string& s2 = const_cast<string&>(s1);	
	s2 = "ad";
	cout<<s1<<endl;
}
