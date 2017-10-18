#include<iostream>
#include"government.h"
#include"purchase.h"
using namespace std;

int main()
{
    int choice;
    cout<<"----------------------------------------------"<<"\n"<<"RATIONSHOP MANAGEMENT SYSTEM"<<endl;
main_menu: cout<<"Enter Choice\n1 -> Government Login\n2 -> Ration Shop Login: ";
    cin>>choice;
    if(choice==1)
    {
        while(1)
        {
        cout<<"\n####GOVERNMENT LOGIN#####";
            government g;
        int ch;
        cout<<"\nEnter\n1-> Revoke all users\n2->Add User\n3->Remove User\n4->Display Users\n5->Display Shops\n6->Go to Main Menu\n7->Exit: ";
        cin>>ch;
            switch(ch)
            {
                case 1:g.revoke();
                    break;
                case 2:g.addUser();
                    break;
                case 3:g.removeUser();
                    break;
                case 4:g.displayUsers();
                    break;
                case 5:g.displayShops();
                    break;
                case 6: goto main_menu;
                case 7: exit(0);
                default:
                    cout<<"###ENTER PROPER CHOICE###";
            }
        }
    }
    else if(choice==2)
    {
        while(1)
        {
            cout<<"\n#####RATION SHOP LOGIN####";
            Purchase p;
            int ch;
            cout<<"\nEnter\n1-> Bill\n2-> Go to Main menu\n3-> Exit: ";
            cin>>ch;
            switch(ch)
            {
                case 1: p.bill();
                    break;
                case 2: goto main_menu;
                case 3: exit(0);
                default:
                    cout<<"###ENTER PROPER CHOICE###";

            }
        }
    }
    else
    {
        cout<<"\n##ERROR: Enter Proper Choice: ";
        goto main_menu;
    }
}
