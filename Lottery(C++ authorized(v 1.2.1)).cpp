#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int lot[10000][7],info_lot[7],no = 1,k = 0,c = 1, lotall;
int search(int a,int k)
{
	for(int j=0;j<k;j++)
		if(info_lot[j] == a)
			return a+1;
	return a;
}

void make_info()
{
	srand((int)time(0));
	for(int i=0;i<7;i++)
	{
		info_lot[i] = rand()%33 + 1;
		info_lot[i] = search(info_lot[i], i);
	}
	sort(info_lot,info_lot+7);
}		
int main()
{
	while(1)
	{
		cout<<"XINXIN Lottery Device(XLD v 1.2.1)"<<endl;
		cout<<"copyright xinxin comp.. all rights reserved"<<endl;
		cout<<endl;
		cout<<"5 yuan every lot"<<endl;
		cout<<endl;
		cout<<"Lt all:";
		cin>>lotall;
		make_info();
		while(1)
		{
			for(int i=0;i<lotall;i++)   //i<k  k is the total number
			{
				cout<<"Lot Round:"<<time<<endl;
				cout<<"Lot No.:"<<no<<endl;
				cout<<"Lot Number:"<<endl;
				for(int i=0;i<7;i++)
					cin>>lot[k][i];
				cout<<endl;
				k+=1;
				no++;
			} 
			cout<<"Ready to run the lottery¡­¡­"<<endl;
			Sleep(10000);
			break;
		}
		cout<<"-------------------------------------------------"<<endl;
		cout<<"The Number of the lottery:"<<endl;
		for(int i=0;i<7;i++)
			cout<<info_lot[i]<<" ";
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<7;j++)
				lot[i][j] = 0;
		 } 
		no = 1;
		k = 1;
		Sleep(100000);
		system("cls");
	}
	return 0;
}
