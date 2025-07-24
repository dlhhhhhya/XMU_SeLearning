#include <bits/stdc++.h>

#define LINE    8
#define ROW     8

int Chessboard[LINE][ROW]    = {0};
int iNextX[8] = {1, 2, 2, 1, -1, -2, -2, -1};//�ڶ�������X����
int iNextY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};//�ڶ�������Y����
int iNextXReal[8] = {0};//�ڶ������ʵX����
int iNextYReal[8] = {0};//�ڶ������ʵY����
int iNextRealIndex;//��ѡ�ĵڶ�����ʵ��ѡ���ĵڶ��������
int iCount;              //�м����ڶ����������
int iNextNextNum[8] = {0};//ÿ���ڶ����м���������


bool Tour(int x, int y)
{
    int step, i, j, tempX, tempY, iMin;

    //��һ��
    Chessboard[y][x] = 1;

    //��2�㵽��64��
    for (step=2; step<=(LINE*ROW); step++)
    {
        for (i=0; i<8; i++)
        {
            iNextNextNum[i] = 0;
        }

        iCount = 0;
        for (i=0; i<8; i++)//�鿴��8�����Ƿ����Ҫ��
        {
            tempX = x + iNextX[i];
            tempY = y + iNextY[i];

            if (tempX>=0 && tempX<ROW && tempY>=0 && tempY<LINE \
                && Chessboard[tempY][tempX] == 0)//����Ҫ�����������Χ���ϵĵ���
            {
                iNextXReal[iCount] = tempX;
                iNextYReal[iCount] = tempY;
                iCount++;
            }
        }

        if (iCount == 0)
        {
            return false;
        }
        else if (iCount == 1)
        {
            iNextRealIndex = 0;
        }
        else
        {

            for (i=0; i<iCount; i++)
            {
                for (j=0; j<8; j++)
                {
                    tempX = iNextXReal[i] + iNextX[j];
                    tempY = iNextYReal[i] + iNextY[j];
                    if (tempX>=0 && tempX<ROW && tempY>=0 && tempY<LINE \
                        && Chessboard[tempY][tempX] == 0)
                    {
                        iNextNextNum[i]++;//����Ҫ���ÿ����ÿ����2����Χ�м�������Ҫ���3��
                    }

                }
            }

            iMin = iNextNextNum[0];
            iNextRealIndex = 0;
            for (i=1; i<iCount; i++)
            {
                if (iNextNextNum[i] < iMin)
                {
                    iMin = iNextNextNum[i];
                    iNextRealIndex = i;
                }
            }

        }

        //ѡ����һ�����ٵĵ�
        x = iNextXReal[iNextRealIndex];
        y = iNextYReal[iNextRealIndex];
        Chessboard[y][x] = step;//��N���ֵΪN
    }
    return true;
}
void ShowStep(int step)
{
    int i, j;
    for (i=0; i<LINE; i++)
    {
        for (j=0; j<ROW; j++)
        {
            if (Chessboard[i][j] <= step+10 && Chessboard[i][j] > step)
                printf("%4d", Chessboard[i][j]-1);
            else
                printf("    ");
        }
        printf("\n");
    }
}

void Show(void)
{
    int i, j;
//    for (int step = 1; step <= LINE * ROW; step+=10)
//    {
//        printf("Step: %d - %d\n", step, step+10);
//        for (i=0; i<ROW; i++)
//        {
//            printf("----");
//        }
//        printf("\n");
//        ShowStep(step);
//        printf("\n");
//        for (i=0; i<ROW; i++)
//        {
//            printf("----");
//        }
//        printf("\n");
//    }
    printf("Step: %d ����\n", LINE * ROW);
    for (int i=0; i<LINE; i++)
    {
        for (int j=0; j<ROW; j++)
        {
            printf("%4d", Chessboard[i][j]-1);
        }
        printf("\n");
    }
    
}

int main(void)
{
    int x, y;

    printf("��������ʼ�㣨x, y����");
    scanf("%d %d", &x, &y);
    //�ж��Ƿ񳬳�
    if(x>7||x<0||y>7||y<0){
        printf("���벻����\n");
        return 0;
    }

    if (Tour(x, y))
    {
        printf("�����ɹ���\n");
        Show();
    }
    else
    {
        printf("����ʧ�ܣ�\n");
    }

    return 0;
}

