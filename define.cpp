#include <iostream>
        
using namespace std;


// https://zhuanlan.zhihu.com/p/344240420 宏定义展开规则
// GO_LABEL(GO_LABEL_HEAD,__LINE__) GO_LABEL宏中没有"# ##"则进入下一层，下一层中
// 展开GO_LABEL_HEAD 和 __LINE__， 然后回到上一层执行GO_LABEL2(GoLabel_,21)
// 第28行代码,说明: 已经定义过的宏定义标签是可以用 && 赋值给空指针的,宏定义标签在内存中也是一个地址而已; 但是必须要先定义 第24行


#define GO_LABEL_HEAD GoLabel_
#define GO_LABEL2(s1, s2) s1##s2
#define GO_LABEL(s1, s2) GO_LABEL2(s1, s2)

#define STRINGIFY(S) #S
#define DEFER_STRINGIFY(S) STRINGIFY(S)
#define GO_LABEL_STR_ DEFER_STRINGIFY(GO_LABEL_HEAD) "_" DEFER_STRINGIFY(__LINE__)
#define GO_LABEL_STR DEFER_STRINGIFY(GO_LABEL_HEAD) "" DEFER_STRINGIFY(__LINE__)

#define EXAMPLE \
    do{ \
        void* pLable = NULL; \
        GO_LABEL(GO_LABEL_HEAD,__LINE__): \
        cout << (char*)GO_LABEL_STR_ << endl; \
        if(!pLable) \
        { \
			pLable = &&GO_LABEL(GO_LABEL_HEAD,__LINE__); \
            goto *pLable; \
        } \
        cout << (char*)GO_LABEL_STR << endl; \
    } while (0)


int main()
{
    EXAMPLE;
}
