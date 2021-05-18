#include<iostream>
using namespace std;

int main()
{
	int n1 = 0;
	int n2 = 26843547;
	int n3 = n2*160;
	//数字越界，正数从0开始重新排序，但是不能从正数变成负数
	cout << n3 <<endl;
}
