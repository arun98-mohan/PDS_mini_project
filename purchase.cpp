#include<iostream>
#include<string>
#include<fstream>
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

    void updateShop(string place,int sugar,int price) //Function to update the stock in RationShop
    {
        
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
       int total;
       total=(sugar*10)+(rice*2);
       cout<<"BILL: "<<total<<"INR"<<endl;
       update(name);
       updateShop(place,sugar,rice);
			}
		}

};

int main()
{
    Purchase p;
    p.bill();
    return 0;
}
