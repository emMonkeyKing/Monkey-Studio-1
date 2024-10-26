#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int lot[10000][7],info_lot[7],no = 1,k = 0,c = 1;
void make_info()
{
	srand((int)time(0));
	for(int i=0;i<7;i++)
		info_lot[i] = rand()%33 + 1;
	sort(info_lot,info_lot+7);
}
int main()
{
	cout<<"XINXIN Lottery Device(XLD v 1.1.1)"<<endl;
	cout<<"copyright xinxin comp.. all rights reserved"<<endl;
	cout<<endl;
	cout<<"2 yuan every lot"<<endl;
	cout<<endl;
	while(1)
	{
		make_info();
		while(1)
		{
			cout<<"Lot Round:"<<time<<endl;
			cout<<"Lot No.:"<<no<<endl;
			cout<<"Lot Number:"<<endl;
			for(int i=0;i<7;i++)
				cin>>lot[k][i];
			cout<<endl;
			k+=1;
			no++;
			cout<<"Lot Round:"<<time<<endl;
			cout<<"Lot No.:"<<no<<endl;
			cout<<"Lot Number:"<<endl;
			k+=1;
			no++;
			for(int i=0;i<7;i++)
				cin>>lot[k][i];
			if(k = 2)   //Âú2×¢Ö±½Ó¿ª½± 
			{
				cout<<"Ready to run the lottery¡­¡­"<<endl;
				Sleep(10000);
				break;
			}
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
		no = 0;
		k = 0;
		Sleep(100000);
		system("cls");
	}
	return 0;
}
