#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *a="bcd";
    printf("����ַ���%c /n", *a);  /*����ַ���ʹ��"%c"*/
    printf("����ַ���%c /n", *(a+1) );  /*����ַ���ʹ��"%c"*/
    printf("����ַ�����%s /n", a); /*����ַ�����ʹ��"%s"������a֮ǰ�������Ǻ�"*"  */ 
    system("pause");  /*Ϊ���ܿ���������*/
}
