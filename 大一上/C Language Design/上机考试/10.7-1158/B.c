#include <stdio.h>
int main(void)
{
	char a;int flag;//a��������ַ� flag���ж��ǲ����Ѿ��пո��� 
    while(scanf("%c",&a)!=EOF){//�����ַ� 
    	if(a==' '){
    		if(flag==1)continue;//��������ظ��ո� 
    		else {
    			flag=1;//����Ѿ��пո��� 
    			printf(" ");
			}
		}else{
			printf("%c",a);//��������ַ� 
			flag=0;
		} 
	} 
	printf("\n");
	return 0;
}
