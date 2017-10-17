#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream myfile;
	string sname,item;
	int quantity;
	myfile.open("shopList.txt");
	int i=0;
	do
	{
		myfile>>sname;
		cout<<sname<<endl;
		myfile>>item;
		cout<<item<<endl;
		myfile>>quantity;
		cout<<quantity<<endl;
		myfile>>item;
		cout<<item<<endl;
		myfile>>quantity;
		cout<<quantity<<endl;
	}while(!myfile.eof());
	myfile.close();
	return 0;
}

