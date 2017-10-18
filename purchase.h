#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
//#include<stdio.h>
using namespace std;

/*This class will be used to verify user details and update the user record with quantity purchased
 */

class Purchase
{
	public:
		int userVerify(string s,string t)	//S-> name of user t->place of user)
		{
			ifstream myfile;
			myfile.open("userDatabase.txt");
			string name;
			int flag=1;
			while(!myfile.eof())
			{
				getline(myfile,name);
				if(name==s)
				{
					//cout<<"\n###USER VERIFIED###\n";
					string place;
					string pur;
					getline(myfile,place);
					getline(myfile,pur);
					if(place==t) //verifying if place is same as given
					{
						if(pur=="no")	//verifying that user has not purchased any good
							flag=0;
						if(pur=="PURCHASED")
							cout<<"\nalready purchased\n";
					}
				}
				else
				{
					string place,pur;
					getline(myfile,place);
					getline(myfile,pur);
					/*	if(pur=="PURCHASED")
						cout<<"\n####USER ALREADY PURCHASED####\n"; */
				}
			}
			myfile.close();
			if(flag==1) return 0;	//return 0 if user details are wrong
			else if(flag==0) return 1;
		}

		int shopVerify(string name,int sugar,int rice)
		{
			ifstream myfile;
			myfile.open("shopList.txt");
			string n;
			while(!myfile.eof())
			{
				getline(myfile,n);
				if(n==name)
				{
					string it1,it2,t1,t2;
					int s,r;
					getline(myfile,it1);
					getline(myfile,t1);
					getline(myfile,it2);
					getline(myfile,t2);
					stringstream geek;
					geek.clear();
					geek.str("");
					geek.str(t1);
					geek>>s;
					geek.clear();
					geek.str("");
					geek.str(t2);
					geek>>r;
					if(s-sugar <=0||r-rice<=0)
						return 0;       //returning 0 if we arent having enough stocks for the customer;
				}
			}
			return 1;
		}

		/* Function to Update the details */
		void update(string name)
		{
			ifstream myfile;
			ofstream ofile("test.txt");
			string n,waste;
			myfile.open("userDatabase.txt");
			while(!myfile.eof())
			{
				getline(myfile,n);
				if(n!="")
				{
					if(n==name)
					{
						cout<<"\n####DETAILS UPDATING IN FILE####";
						string place;
						getline(myfile,place);
						ofile<<n<<endl;
						ofile<<place<<endl;
						ofile<<"PURCHASED"<<endl;
						getline(myfile,waste);
					}
					else
					{
						string place;
						getline(myfile,place);
						getline(myfile,waste);
						ofile<<n<<endl;
						ofile<<place<<endl;
						ofile<<"no"<<endl;
					}
				}
			}
			myfile.close();
			ofile.close();
			remove("userDatabase.txt");
			rename("test.txt","userDatabase.txt");
		}

		void updateShop(string place,int sugar,int rice) //Function to update the stock in RationShop
		{
			string placeT;
			int sugarT,riceT;
			string sT,rT,t1,t2;
			ifstream myfile;
			myfile.open("shopList.txt");
			ofstream ofile("test.txt");
			while(!myfile.eof())
			{
				getline(myfile,placeT);
				getline(myfile,sT);
				getline(myfile,t1);
				getline(myfile,rT);
				getline(myfile,t2);
				stringstream geek;
				geek.clear();
				geek.str("");
				geek.str(t1);
				geek>>sugarT;
				geek.clear();
				geek.str("");
				geek.str(t2);
				geek>>riceT;
				// cout<<"\nInside While Loop";
                if(placeT!="")
                {
				if(place!=placeT)
				{
					ofile<<placeT<<"\n"<<sT<<"\n"<<sugarT<<"\n"<<rT<<"\n"<<riceT<<endl;
					//cout<<"Places not disturbed"<<endl;
				}
				else if(place==placeT)
				{
					ofile<<placeT<<"\n"<<sT<<"\n"<<sugarT-sugar<<"\n"<<rT<<"\n"<<riceT-rice<<endl;
					//cout<<"PLACE FOUND"<<endl;
				}
                }

			}
			myfile.close();
			ofile.close();
			remove("shopList.txt");
			rename("test.txt","shopList.txt");
		}

		/*Function to be called. -> It calls userVerify -> It calls update function after generating bill */

		void bill() //To Bill the user and update his records
		{
			cout<<"Enter User Name: ";
			string name,place;
			cin>>name;
			cout<<"Enter User Place: ";
			cin>>place;
			int f;
			f=userVerify(name,place);
			if(f==0)
			{
				cout<<"\n###INCORRECT DETAILS - USER DOESNT EXIST###\n";
				return;
			}
			else
			{
				int sugar,rice;
sugar: cout<<"\nEnter Sugar weight purchased: ";
       cin>>sugar;
       if(sugar>5 || sugar<0)
       {
	       cout<<"\n###Enter Proper Value (less than 5kgs)###";
	       goto sugar;
       }
rice:  cout<<"\nEnter Rice weight purchased: ";
       cin>>rice;
       if(rice>5 || rice<0)
       {
	       cout<<"\nEnter Proper Value (less than 5kgs)";
	       goto rice;
       }
       /* sugar 1 kg= 10 INR
	  rice 1kg= 2 INR
	*/
       f=shopVerify(place,sugar,rice);
       if(f==0)
       {
	       cout<<"\n####NOT ENOUGH STOCKS###";
	       return;
       }

       int total;
       total=(sugar*10)+(rice*2);
       cout<<"BILL: "<<total<<"INR"<<endl;
       update(name);
       updateShop(place,sugar,rice);
			}
		}

};
