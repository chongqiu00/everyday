//a[0]
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct MyData{
    int nLen;
    char data[0]; //Ϊһ��char�������͵���������������û��Ԫ�أ�����ʵ��ַ�����ڴ˽ṹ��֮�����ַ������������ʵ��C���Ե�������չ��
};

int main(int argc, char* argv[])
{
    printf("sizeof(MyData) = %d\n", sizeof(MyData)); //�ֽ���Ϊ4��int��, dataΪ0���ֽڡ�
    char str[] = "123456";
    struct MyData *p = (struct MyData*) malloc(sizeof(MyData) + strlen(str));
    p->nLen = 10;
    memcpy(p->data, str, 10);
    printf("%s\n", p->data);//123456

    return 0;
}