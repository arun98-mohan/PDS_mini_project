#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Government will
   d 1) add / remove users
   d 2) revoke all users to "not purchased" status
   d 3) display all ration shops with details
   d 4) display all users with details
 */

class government
{
	public:
		void revoke() //Function to make all users as not purchased
		{
			ifstream myfile;
			ofstream ofile("test.txt");
			string name,place,pur;
			myfile.open("userDatabase.txt");
			while(!myfile.eof())
			{
				getline(myfile,name);
				getline(myfile,place);
				getline(myfile,pur);
				if(name!="")
				{
					ofile<<name<<endl;
					//cout<<name<<endl;
					ofile<<place<<endl;
					//cout<<place<<endl;
					ofile<<"no"<<endl;
					//cout<<"no"<<endl;
				}}
			myfile.close();
			ofile.close();
			remove("userDatabase.txt");
			rename("test.txt","userDatabase.txt");
			cout<<"\nALL USERS SET AS NOT-PURCHASED\n";
		}
		void addUser() //Function to add user
		{
			string name,place,temp;
			cout<<"\nEnter new user's name: ";
			cin>>name;
			cout<<"\nEnter new User's ration place: ";
			cin>>place;
			ifstream myfile;
			myfile.open("userDatabase.txt");
			ofstream ofile("test.txt");
			ofile<<name<<endl;
			ofile<<place<<endl;
			ofile<<"no"<<endl;
			while(!myfile.eof())
			{
				getline(myfile,name);
				getline(myfile,place);
				getline(myfile,temp);
				if(name!="") ofile<<name<<'\n'<<place<<'\n'<<temp<<endl;
			}
			myfile.close();
			ofile.close();
			remove("userDatabase.txt");
			rename("test.txt","userDatabase.txt");
		}
    
		void removeUser() //Function to remove an user
		{
			string name;
			cout<<"\nEnter the user to be removed: ";
			cin>>name;
			string nameT,placeT,purT;
			ifstream myfile;
			ofstream ofile("test.txt");
			myfile.open("userDatabase.txt");
			while(!myfile.eof())
			{
				getline(myfile,nameT);
				getline(myfile,placeT);
				getline(myfile,purT);
				if(nameT!="")
					if(nameT!=name)
					{
						ofile<<nameT<<'\n'<<placeT<<'\n'<<purT<<endl;
					}
			}
			myfile.close();
			ofile.close();
			remove("userDatabase.txt");
			rename("test.txt","userDatabase.txt");
		}
		void displayUsers()	//Function to display details of all users
		{
            cout<<"\n####USER DETAILS####";
            string name,place,pur;
			ifstream myfile;
			myfile.open("userDatabase.txt");
			while(!myfile.eof())
			{
				getline(myfile,name);
				getline(myfile,place);
				getline(myfile,pur);
				if(name!="")
					cout<<"\nName: "<<name<<"\tPlace: "<<place<<"\tStatus: "<<pur<<endl;
			}
		}
		void displayShops() //Function to display details of all ration shops
		{
            cout<<"\n####RATION SHOP DETAILS####";
            string name,item1,item2,quantity1,quantity2;
			ifstream myfile;
			myfile.open("shopList.txt");
			while(!myfile.eof())
			{
				myfile>>name>>item1>>quantity1>>item2>>quantity2;
				if(name!="")
				{
					cout<<"\nName: "<<name<<"\nItem: "<<item1<<" "<<quantity1<<"kgs\tItem: "<<item2<<" "<<quantity2<<"kgs"<<endl;
				}
			}
		}

};
