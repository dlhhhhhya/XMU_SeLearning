#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR  20  // ����ַ�
#include<time.h>
#define MAX_NUM  200  // ���ʵ�������
struct word

//���ʵĽṹ��
{
	char  en[MAX_CHAR]; // Ӣ����ʽ
	char  ch[MAX_CHAR];   //������ʽ
}
s[MAX_NUM]; //��������
int   num;           //���ʸ���
int select=1;//select Ϊ�Ƿ��˳�ϵͳ�ı��
int d=0,c=0;
int in;

//����
void help() {
	printf("\n��ϵͳ��Ҫʵ��Ӣ�ﵥ��ѧϰ�Ĺ��ܡ��û��ɶԴʵ��ļ��еĵ��ʽ���Ԥ������ɾ�Ĳ顣");
	printf("\nͬʱ���ɽ�����Ӣ��Ӣ�в��ԡ���ϵͳ���ṩ�˲��Գɼ�����ʾ���ܡ�");
}

//���ļ��ж�ȡ���ʵ���Ϣ
void  readfile() {
	FILE *fp;
	int i=0;
	fp=fopen("data.txt","r");
	if(!fp) {
		printf("\n���ļ�data.txtʧ��!");
	}
	while(fscanf(fp,"%s %s ",s[i].en,s[i].ch)==2) {
		i++;
	}
	num=i;
	if(0==i)
		printf("\n�ļ�Ϊ�գ���ѡ��ʵ�ά�����Ӵ�����");
	else
		printf("\n");
	fclose(fp);
}

//���ļ��ж�ȡ���ʵ���Ϣ
void  writefile() {
	FILE *fp;
	int i=0;
	fp=fopen("data.txt","w");
	if(!fp) {
		printf("\n���ļ�data.txtʧ��!");
	}
	for(i=0; i<num; i++) {
		fprintf(fp,"\n%s %s ",s[i].en,s[i].ch);
	}
	printf("\n");
	fclose(fp);
}

//����ǿ�����ļ��ж�ȡ����
void  readRemeberfile() {
	FILE *fp;
	int i=0;
	fp=fopen("Remeberdata.txt","r");
	if(!fp) {
		printf("\n���ļ�Remeberdata.txtʧ��!");
	}
	while(fscanf(fp,"%s %s ",s[i].en,s[i].ch)==2) {
		i++;
	}
	num=i;
	if(0==i)
		printf("\n�㻹û�д���Ŷ��");
	else
		printf("\n");
	fclose(fp);
}

void sort() { /*���ֵ�����*/
	int i,j;
	char temp[MAX_CHAR];
	for(i=0; i<num-1; i++) {
		for(j=num-1; j>i; j--) {
			if(strcmp(s[j-1].en,s[j].en)>0) {
				strcpy(temp,s[j-1].en);
				strcpy(s[j-1].en,s[j].en);
				strcpy(s[j].en,temp);
				strcpy(temp,s[j-1].ch);
				strcpy(s[j-1].ch,s[j].ch);
				strcpy(s[j].ch,temp);
			}
		}
	}
}

//��ӵ�����Ϣ
void add() {
	int i=num,j,flag=1;
	while(flag) {
		flag=0;
		printf("\n�����뵥�ʵ�Ӣ����ʽ:");
		scanf("%s",s[i].en);
		for(j=0; j<i; j++)
			if(strcmp(s[i].en,s[j].en)==0) {
				printf("���иõ���,���������¼��!\n");
				flag=1;
				break; /*�����ظ������˳��ò�ѭ��,����ж��ٶ�*/
			}
	}
	printf("\n�����뵥�ʵ�������ʽ:");
	scanf("%s",s[i].ch);
	num++;
	printf("\n���������ϢΪ: Ӣ��: %s ����: %s  ",s[i].en,s[i].ch);
	sort();
}

//ɾ��������Ϣ
void del() {
	int i=0,j=0;
	char  en[MAX_CHAR];   //Ӣ����ʽ
	printf("\n��������Ҫɾ���ĵ���Ӣ����ʽ:");
	scanf("%s",en);
	for(i=0; i<num; i++) //���ҵ���Ӣ����ʽ��Ӧ�����
		if(strcmp(s[i].en,en)==0) {
			for(j=i; j<num-1; j++)
				s[j]=s[j+1];
			num--; //�������� 1
			return;
		}
	printf("\nû���������!");
}

//�޸ĵ�����Ϣ
void modify() {
	int i=0,choose=0,flag=1;//chooses����ѡ���ʶ��flag�����Ƿ��ҵ�����
	char  en[MAX_CHAR];   //Ӣ����ʽ
	while(flag||choose) {
		printf("\n��������Ҫ�޸ĵĵ���Ӣ����ʽ:");
		scanf("%s",en);
		for(i=0; i<num; i++) //���ҵ���Ӣ����ʽ��Ӧ�����
			if(strcmp(s[i].en,en)==0) {
				printf("\n�����뵥����ȷ��Ӣ����ʽ:");
				scanf("%s",s[i].en);
				printf("\n������˵�����ȷ�ĵ�������ʽ:");
				scanf("%s",s[i].ch);
				printf("\n�����޸���ѡ1��������һ����ѡ0:");
				scanf("%d",&choose);
				if(choose==0) return;
			}
		flag=0;
	}
	if(!flag)  printf("\nû���������!");
}

//����Ԥ��
void show() {
	int  i=0;
	printf("\n���ʣ�     Ӣ��        ����         ");
	for(i=0; i<num; i++)
		printf("\n          %-12s%-12s",s[i].en,s[i].ch);
}

//��ѯ����
void search() {
	int i=0,choose=0,flag=1;
	char  ch[MAX_CHAR];   //������ʽ
	char  en[MAX_CHAR];   //Ӣ����ʽ
	while(choose||flag) {
		printf("��ѡ�����Ĳ�ѯ��Ӣ�Ĳ�ѯ��\n");
		printf("1.���յ���������ʽ��ѯ\n");
		printf("2.���յ���Ӣ����ʽ��ѯ\n");
		scanf("%d",&in);
		switch(in) {
			case 1: {
				while(flag) {
					printf("\n��������Ҫ��ѯ�ĵ��ʵ�Ӣ����ʽ��");
					scanf("%s",en);
					for(i=0; i<num; i++) { //���ҵ���Ӣ����ʽ��Ӧ�����
						if(strcmp(s[i].en,en)==0) {
							printf("\nӢ����ʽ          ������ʽ            ");
							printf("\n    %-12s%12%",s[i].en,s[i].ch);
						}
					}
					printf("\n������ѯѡ1��������һ��ѡ0��");
					scanf("%d",&choose);
					if(choose==0)
						return;
					flag=0;
				}
				if(!flag)
					printf("\nû���������!");
			}
			break;
			case 2: {
				while(flag) {
					printf("\n��������Ҫ��ѯ�ĵ��ʵ�������ʽ��");
					scanf("%s",ch);
					for(i=0; i<num; i++) { //���ҵ���������ʽ��Ӧ�����
						if(strcmp(s[i].ch,ch)==0) {
							printf("\nӢ����ʽ          ������ʽ          ");
							printf("\n   %-12s%12s",s[i].en,s[i].ch);
						}
					}
					printf("\n������ѯ��ѡ1��������һ����ѡ0:");
					scanf("%d",&choose);
					if(choose==0) return;

					flag=0;
				}
				if(!flag)
					printf("\nû���������!");
			}
			break;
			default:
				printf("�����ѡ����ʣ����������룡");
				break;
		}
	}
}

//����Ӣ����
void zytest() {
	char b1[20];
	int z;
	int choose=1;
	int   i;
	while(choose) {
		i = rand()%num;
		printf("\n��%s��������Ӣ�ĵ���:\n\n",s[i].ch);
		gets(b1);
		printf("\n��%s��\n\n",s[i].en);
// 	scanf("%s",b1);
		if(strcmp(b1,s[i].en)!=0) {

			printf("\n�������!���ɵ!\n");

		} else {
			printf("\n��ϲ�㣬�ش���ȷ\n\n");

		}

	}
}

//Ӣ���в���
void yztest() {
	char b1[20];
	int z,x=41;
	int choose=1;
	int   i;
	i = rand()%num;
	while(choose) {
		i = rand()%num;
		printf("\n��%s��������������˼:\n\n",s[i].en);
		gets(b1);
		printf("\n��%s��\n\n",s[i].ch);
		if(strcmp(b1,s[i].ch)!=0) {

			printf("\n����������ɵ��\n");
		} else {
			printf("\n��ϲ�㣬�ش���ȷ!\n\n");
		}
	}
}

//�ɼ��б�
void list() {
	printf("\n �����������:%d�� **ÿ�ο�10��**\n",c);
	printf(" ����������ȷ:%d�� **ÿ�μ�10��**\n",d);
	printf(" ����ܵ÷�Ϊ:%d��\n\n",10*d-10*c);
}

//�ʵ�ά��
void maintain() {
	int choose;//ά������ѡ��
	printf("   ------------------\n");
	printf("   1.���ӵ���\n");
	printf("   2.�޸ĵ���\n");
	printf("   3.ɾ������\n");
	printf("   4.��ѯ����\n");
	printf("   5.�˳����˵�\n");
	printf("   ------------------\n");
	while(1) {
		printf(" \n������ά�����ܱ��:");
		scanf("%d",&choose);
		switch(choose) {
			case 1:
				add();
				writefile();
				break;
			case 2:
				modify();
				writefile();
				break;
			case 3:
				del();
				writefile();
				break;
			case 4:
				search();
				break;
			case 5:
				return;
			default:
				printf("\n����1-5֮��ѡ��");
		}
	}
}

//�û�����
void menu() {
	int item;
	srand((int)time(0));
	printf("\n");
	printf("***************************************************************\n");
	printf("#                                                             #\n");
	printf("#                         Ӣ�ﵥ��С����                      #\n");
	printf("#                                                             #\n");
	printf("#                        �汾 �� v1.0   by maoli              #\n");
	printf("#                                                             #\n");
	printf("***************************************************************\n");
	printf("#                                                             #\n");
	printf("#       0.�ʿ�ά��          1.����Ԥ��                        #\n");
	printf("#                                                             #\n");
	printf("#       2.���ʱ���(��Ӣ)    3.���ʱ���(Ӣ��)                  #\n");
	printf("#                                                             #\n");
	printf("#       4.��ѯ�ɼ�          5.����                            #\n");
	printf("#                                                             #\n");
	printf("#       6.�˳�ϵͳ                                            #\n");
	printf("#                                                             #\n");
	printf(" **************************************************************\n");
	printf("\n");
	printf("       ��ѡ������Ҫ�Ĳ������(0-5)���س�ȷ��:");
	scanf("%d",&item);
	printf("\n");
	readfile();
	switch(item) {
		case 0:
			maintain();
			break;
		case 1:
			show();
			break;
		case 2:
			zytest();
			break;
		case 3:
			yztest();
			break;
		case 4:
			list();
			break;
		case 5:
			help();
			break;
		case 6:
			select =0;
			break;
		default:
			printf("����0-6֮��ѡ��\n");
	}
}
int main() {
	while(select) {
		menu();
	}
	system("pause");
	return 0;
}

