#include<iostream>
#include<iomanip>
using namespace std;
bool RUN(int year);
int MD(int year, int month);
int YFD(int year);
int MFD(int year, int month);
void Print_1(int year);
void Print_2(int year, int month);
 
bool RUN(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int MD(int year, int month)
{
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2)
	{
		if (RUN(year))
			return a[1] + 1;
		else
			return a[1];
	}
	else
	{
		return a[month - 1];
	}
}
int YFD(int year)//������Ϊ 0-6��0��ʾ�����죩
{
	//�ú����ݹ���
	//�����һ���������ǣ�ȥ���һ��������+ȥ��ȫ��������%7
	if (year == 1)
		return 1;
	else
	{
		if (RUN(year - 1))
			return (YFD(year - 1) + 366) % 7;
		else
			return (YFD(year - 1) + 365) % 7;
	}
}
 
int MFD(int year, int month)
{
	//�ݹ�
	//����µ�һ���������ǣ��ϸ��µ�һ��������+�ϸ���������%7
	if (month == 1)
		return YFD(year);
	else
		return (MFD(year, month - 1) + MD(year, month - 1)) % 7;
}
void Print_1(int year)
{
	for (int j = 1;j <= 12;j++)
	{
		cout << "  " << j << "��" << endl;
		Print_2(year,j);
	}
}
void Print_2(int year, int month)
{
	cout << "  ��  һ  ��  ��  ��  ��  ��" << endl;
	int pos = MFD(year, month), day = MD(year, month);
	cout << setw(4 * pos + 4) << 1;
	pos++;
	if (pos == 7)
	{
		cout << endl;
		pos = 0;
	}
	for (int i = 2;i <= day;i++)
	{
		cout << setw(4) << i;
		pos++;
		if (pos == 7)
		{
			cout << endl;
			pos = 0;
		}
	}
	cout << endl;
}
int main()
{
	cout << "��������ʾ����" << endl;
	cout << "***********************" << endl;
	cout << "1   �������" << endl << "2   �������" << endl << "0   �˳�" << endl;
	cout << "***********************" << endl;
	for (int i = 1;;i++)
	{
		cout << "������ " << i << " ��" << endl;
		cout << "����������ѡ��" ;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "��������ʾ�����" ;
			int year;
			cin >> year;
			Print_1(year);
		}
		else if (choice == 2)
		{
			int year, month;
			cout << "��������ʾ�����" ;
			cin >> year;
			cout << "�·�" ;
			cin >> month;
			Print_2(year, month);
		}
		else if (choice == 0)
		{
			cout << "���������" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}
