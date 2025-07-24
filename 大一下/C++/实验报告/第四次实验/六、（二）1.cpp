#include <iostream>
using namespace std;

//ѡ������ 
void SelectSort(int arr[],int N)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i<N - 1; i++)
    {
        temp = i;
        for (j = i + 1; j<N; j++)
        {   
            if (arr[j] < arr[temp])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            arr[temp] ^= arr[i];
            arr[i] ^= arr[temp];
            arr[temp] ^= arr[i];
        }
    }
}

//��������
int GetMidIndex(int* array, int left, int right)  
{  
    int mid = left + ((right-left)>>1);  

    if (array[left] < array[right])  
    {  
        if (array[right] < array[mid])  
            return right;  
        else if (array[left] > array[mid])  
            return left;  
        else  
            return mid;  
    }  
    else  
    {  
        if (array[right] > array[mid])  
            return right;  
        else if (array[left] < array[mid])  
            return left;  
        else  
            return mid;  
    }  
}  
int QuickSort(int* array, int left, int right)  
{  
    //  
    // prevָ���key���ǰһ��λ��  
    // cur��ǰѰ�ұ�keyС�����ݡ�  
    //  
    int keyIndex = GetMidIndex(array, left, right);  
    if (keyIndex != right)  
    {  
        swap(array[keyIndex], array[right]);  
    }  

    int key = array[right];  
    int prev = left - 1;  
    int cur = left;  

    while (cur < right)  
    {  
        // �ҵ���key��С����������ǰ������ݽ��н���  
        if(array[cur] < key && ++prev != cur)  
            swap(array[cur], array[prev]);  

        ++cur;  
    }  

    swap(array[++prev], array[right]);  

    return prev;  
}   
//ð������ 
int BubbleSort(int arr[],int len)
{
    int i = 0;
    int j = 0;
    int count = 0;
    for (i = 0; i < len - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < len - 1 - i; j++)
        {
            count++;
            if (arr[j]>arr[j + 1])
            {
                flag = 1;
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
int main(int argc, const char * argv[])
{
	int length;
	cout << "�������鳤�ȣ�"; 
	cin >> length;
	int *data = new int[length]; 
	for(int i=0;i<length;i++){
		cin >> data[i];
	} 
	cout << "ѡ������" << endl;
	SelectSort(data,length);
	for(int i=0;i<length;i++){
		cout << data[i] << " ";
	} 
	cout << endl;
	cout << "��������" << endl;
	QuickSort(data,0,length-1);
	for(int i=0;i<length;i++){
		cout << data[i] << " ";
	} 
	cout << endl;
	cout << "ð������" << endl;
	BubbleSort(data,length);
	for(int i=0;i<length;i++){
		cout << data[i] << " ";
	} 
	cout << endl;
    return 0;
}
