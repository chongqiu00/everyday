//a[0]
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct MyData{
    int nLen;
    char data[0]; //为一个char数据类型的数组名，该数组没有元素，其真实地址紧跟在此结构体之后，这种方法可以巧妙的实现C语言的数组扩展。
};

int main(int argc, char* argv[])
{
    printf("sizeof(MyData) = %d\n", sizeof(MyData)); //字节数为4（int）, data为0个字节。
    char str[] = "123456";
    struct MyData *p = (struct MyData*) malloc(sizeof(MyData) + strlen(str));
    p->nLen = 10;
    memcpy(p->data, str, 10);
    printf("%s\n", p->data);//123456

    return 0;
}