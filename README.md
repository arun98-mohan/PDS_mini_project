##How to run the Program

compile "main.cpp"


### Header File - "government.h"
functionalities
1)  revoke - makes all users to "not purchased status"
2) addUser - to add a user to a ration shop
3) removeUser - to remove a user from a ration shop
4) displayUsers - to display all users in all ration shops
5) displayShops - to display all ration shops with their stock availability

### Header File - "purchase.h"
functionalities
1) userVerify - to verify if the entered user details are correct
2) shopVerify - to verify if enough stocks are available with the ration shop to give to the requested customer
3) update - to mark that a user has purchased item for that month
4) updateShop - to update the stock in ration shop after purchase
5) bill - /* Function to be called, which calls other functions */ this function gets the required stock and prints the bill

### ShopList.txt
Format of Data

<shopname>
<sugar> /*written as it as without <>*/
<quantity>
<rice> /*written as it as without <>*/
<quantity>

### UserDatabase.txt
Format of Data

<username>
<corresponding_shop>
<purchased or not> /* no-> not purchased "PURCHASED"->purchased */
