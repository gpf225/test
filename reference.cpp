#include<map>
#include<iostream>


int& getInt()
{
	static int val = 99;
	return val;
}


int main()
{
	int& n1 = getInt();
	int  n2 = getInt();

	n1 = 1;
	n2 = 2;
	
	std::cout<< getInt() <<std::endl;
		
}
