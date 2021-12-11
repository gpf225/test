#include <iostream>
        
using namespace std;
        
//#define  OUTPUT(A) cout<<A<<":"<<(A)<<endl;
#define  OUTPUT(A) cout<<#A<<":"<<(A)<<endl;

#define Func_A \
    do{\
        cout << "Func__a" << endl;\
    }while(0)
#define Func(A) Func_##A  // 两个是拼贴，一个是字符串化“” 

int main()
{
    int a=1,b=2;
        
    OUTPUT(a);
    OUTPUT(b);
    OUTPUT(a+b);
    static int n = 3;
    Func(A) ;
    void* pLabl = NULL;
    pLabl = &&LABEL1; 
    LABEL1:
        cout << "label1"<< endl;
    LABEL3:
        cout << "label3"<< endl;
    --n;
    if(n<=0)
        goto LABEL2; 
goto *pLabl;

    LABEL2:
       cout << "label2" << endl; 
    return 1;
}