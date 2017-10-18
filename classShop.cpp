#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream myfile;
	ofstream ofile("test.txt");
	string sname;
	//	int quantity;
	myfile.open("shopList.txt");
	int i=0;
	/*	do
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
		}while(!myfile.eof());*/
	while(!myfile.eof())		//Updating a record in a text file
	{
		getline(myfile,sname);
		if(sname=="guindy")
		{
			ofile<<"ramapuram"<<endl;
		}
		else ofile<<sname<<endl;	
	}
	myfile.close();
	ofile.close();
	remove("shopList.txt");
	rename("test.txt","shopList.txt");
	return 0;
}

