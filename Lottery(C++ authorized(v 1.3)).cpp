#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int lot[10000][7],info_lot[7],no = 1,k = 0,c = 1, lotall;

int search(int a,int k)
{
	int num = 0;
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
			if(lot[a][j] == info_lot[i]) num++;
	cout<<num/2<<endl;
}

void make_info()
{
	srand((int)time(0));
	for(int i=0;i<7;i++)
		info_lot[i] = rand()%33 + 1;
	sort(info_lot,info_lot+7);
}		

void animation()
{
	int nn = lotall;
	for(int i=0;i<lotall;i++)
	{
		system("cls");
		printf("Lot:");
		for(int j = nn;j>=1;j--)
			printf("\n");
		for(int j = 0;j<lotall;j++)
		{
			for(int s = 0;s<7;s++)
				printf("%d ",lot[j][s]);
			cout<<endl<<endl;
		}
		Sleep(10);
		nn--;
	}
}
int main()
{
	while(1)
	{
		cout<<"XINXIN Lottery Device(XLD v 1.3)"<<endl;
		cout<<"copyright xinxin comp.. all rights reserved"<<endl;
		cout<<endl;
		cout<<"5 yuan every lot"<<endl;
		cout<<endl;
		cout<<"Lt all:";
		cin>>lotall;
		make_info();
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
		animation();
		cout<<"Ready to run the lottery¡­¡­"<<endl;
		Sleep(10000);
		
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
