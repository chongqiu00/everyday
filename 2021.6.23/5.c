#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char str_2[30] = "zww is !";
    printf("%s, %d, %d\n", str_2, sizeof(str_2), strlen(str_2));
    char str[30] = "zww";

    printf("sizeof(str)=%d\n", sizeof(str));

    //拷贝
    //memset(str, 0, sizeof(str));
    strcpy(str, "mmm");
    printf("strcpy(str, \"mmm\"); str=%s\n", str);

    strncpy(str, "123", 2);
    printf("strncpy(str, \"123\"); str=%s\n", str);

    //比较
    char str_1[30] = "zww";
    strcpy(str, "zww");
    if ( strcmp(str, str_1) == 0 ){
        printf("str与str_1相等！\n");
    }
    strcpy(str_1, "zwwww");
    if ( strncmp(str, str_1, 3) == 0 ){
        printf("str与str_1相等！\n");
    }
    //查找
    if ( NULL != (strchr(str, 'z'))){
        printf("存在, %c\n", *(strchr(str, 'z')));
    }
    if ( NULL != (strrchr(str, 'z'))){
        printf("存在, %c\n", *(strrchr(str, 'z')));
    }
    if ( NULL != (strstr(str, "zw")))
    {
        printf("存在！\n");
    }
    //拼接strcat
    strcat(str, "zww");
    printf("%s\n", str);
    strncat(str, "1234", 2);
    printf("%s\n", str);



    return 0;
}