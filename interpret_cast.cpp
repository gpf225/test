/*************************************************************************
	> File Name: deina.cpp
	> Author: gaopengfei
	> Mail:  
	> Created Time: 2021年08月01日 星期日 18时33分46秒
 ************************************************************************/

#include <cstring>
#include <iostream>
#include <memory>
#include <stdio.h>
using namespace std;
#define MAXLEN 1024

struct Edian_Judeg {
    int* pn;
    char* pc;
    string data;

    Edian_Judeg(int n)
    {
        data.resize(n);
        pn = reinterpret_cast<int*>(&data[0]);
        pc = reinterpret_cast<char*>(&data[0]);
        // 和联合体union差不多，所以计算机存储的都是01二进制，
        // 只是编译器编译后的程序能根据计算机内存中的二进制的位置将存储信息解析成不同的字节。
        // 例如:
        // 计算机中0x12345678的地址上存储了一个字节的0x01,那么如果程序中把这个读入char类型则解析成一个字符赋值给一个char变量，
        // 如果赋值给int变量，则根据大端小端把0x01这个字节变成0x00000001或者0x01000000存入int型变量中,无论大端小端都是1这个数值。
    }
};

int main()
{
    Edian_Judeg test(MAXLEN);
    //char c1 = 0x62;
    char c1 = 0x61;
    char c2 = 0x00;
    char c3 = 0x00;
    char c4 = 0x04;
    //test.data[0] = c1;
    //test.data += c1; // 后面的输出会有问题 ,原因代确定
    memcpy(&test.data[0], &c1, sizeof c1);
    memcpy(&test.data[1], &c2, sizeof c1);
    memcpy(&test.data[2], &c3, sizeof c1);
    memcpy(&test.data[3], &c4, sizeof c1);
    //*test.pc = c1;
    // char c2 = 0x01000001;   //overflow_error
    cout << "string:" << test.data << endl
         << "char:" << *test.pc << endl
         << "int:" << *test.pn << endl
         << "string.c_str()" << (test.data.c_str()) << endl //  相当于 printf的 %s站位符
         << "&string.data[0]" << (&test.data[0]) << endl;   //  输出了字符串
    printf("/& string.c_str():%p \n", test.data.c_str());
    printf("/& string.data[0]:%p \n", &test.data[0]); //  输出了地址  cout 遇见 char* 的地址直接变成了 %s 输出地址后面的字符串

    char c0 = 'a';
    cout << "char:" << c0 << endl
         << "int:" << int(c0) << endl;

    int nt = 0x01020304; // 4321是小端
    cout << int(*((char*)(&nt))) << " " << int(*((char*)(&nt) + 1)) << " "
         << int(*((char*)(&nt) + 2)) << " " << int(*((char*)(&nt) + 3)) << endl;
#define test
#ifdef test
    char array1[2];
    array1[0] = 0x01;
    array1[1] = 0x02;
    char array2[2];
    array2[0] = 0x02;
    array2[1] = 0x01;
    struct starray {
        char arrayc[2];
        starray()
        {
            arrayc[0] = 0x01;
            arrayc[1] = 0x02;
        }
    };
    starray starray1;
    //cout << "int arrayc" << int(array1[0]) << "int arrayc" << int(array2);
    //cout << "int starray:" << interpret_cast<int>(starray1) << endl;
#endif
}
