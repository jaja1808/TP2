#include "client.h"
#include "product.h"
#include "order.h"
#include "store.h"
#include <iostream>

/*
//cin overloading
std::istream &operator>>(std::istream &input, Product &newProduct){
    input >> newProduct;
    return input;
};
std::istream &operator>>(std::istream &input, Client &newClient){
    input >> newClient;
    return input;
};
*/
int main(int argc, char const *argv[]){

// input of product 
    Product iPhone ("IPHONE","apple_corporation",12,890.34);
    Product iMac("iMac","apple_machines",4,2098.45); //creating another product

//creating the first client 
    Client ga("ga","ju","juga",{iPhone});  //creating a second client
    Client pure ("Pure","rush","rushJa",{iPhone});

//creating the first Order
    Order myOrder(pure,{iPhone,iMac},Not_Delivered);

// creating the first sore 
    Store apple("AppleSrore",{iPhone},{pure},{myOrder});

// THE APPLICATION

 //Main menu
 std::cout <<"Welcome to Apple Store"<< std::endl;
 std::cout <<"press:"<< std::endl;
 std::cout <<"1.Store Management"<< std::endl;
 std::cout <<"2.Client Space"<< std::endl;
 std::cout <<"3.My Orders"<< std::endl;
 
 //
 Product newProduct;
 Client newClient;
 Order newOrder;
 int key;
 std::cin >> key;

switch (key){    
case 1:

 std::cout <<"1.Add a new product in store"<< std::endl;
 std::cout <<"2.Add a new client"<< std::endl;
 std::cout <<"3.Add an order"<< std::endl;
 std::cout <<"4.Remove a product in store"<< std::endl;
 std::cout <<"5.Remove a product in store"<< std::endl;
 std::cout <<"6.Display products"<< std::endl;
 std::cout <<"7.Display all clients of the store"<< std::endl;
 std::cout <<"8.Change quantity of product available"<< std::endl;
 std::cout <<"9.Search a Product"<< std::endl;
 std::cout <<"10.Search a Client"<< std::endl;

 int option1;
 std::cin >> option1;

   switch (option1){
     case 1:
         std::cout <<"Name of the  product"<< std::endl;
        //  std::cin >> title;

         break;

     default:
     break;
}      
   break;
 
 default:
    break;
 }


/*
// rest of codes 

    std::cout<< iPhone.getAmount()<< std::endl;
    std::cout<< iPhone.getAvailable()<< std::endl;
    iPhone.setAvailable(25);
    std::cout<< iPhone.getAvailable()<< std::endl;
    std::cout << "Test 1" << std::endl;
    getProduct(iPhone); // testing the getproduct method

    pure.addPanier(iMac);
    pure.getPanier();
    std::cout << " "<<std::endl;
    std::cout << "remove the last entered" << std::endl;
    pure.getPanier();
    std::cout << "Test 2" << std::endl;
    getTheClient(pure); // testing the getTheClient

    std::cout << " "<<std::endl;
    std::cout << "adding order and store" << std::endl;
    myOrder.addProducts(iMac);
    myOrder.setStatus(Delivered);
    myOrder.getClient();
    myOrder.getProductList();
    std::cout << " "<<std::endl;
    std::cout << "getting status" << std::endl;
    myOrder.getStatus();

    apple.addClients(ga);
    apple.getClients();
    
    std::cout << "Test 4" << std::endl;
    pure.findProduct(iPhone); // testing the find product in the char

    std::cout << "Test 3" << std::endl;
    pure.emptyPanier(); // deleting the products in the char

  pure.addPanier(iMac);
  pure.getPanier();
  pure.findProduct(iMac);
  pure.removePanier(iMac);
  pure.addPanier(iMac);
  std::cout << "Test 6 :" << pure.countTheOccurance(iMac) <<std::endl;
  pure.changeProdQtyinPnr(iMac,4);
  pure.getPanier();
  std::cout << "Test 8" << std::endl;
  pure.changeProdQtyinPnr(iMac,2);
  pure.getPanier();
  std::cout << "Test 9: " << iMac.getAvailable() << std::endl;

    apple.displayClient("rushJa");
    apple.displayProduct("IPHONE");

    std::cout << "Test 10" << std::endl;
    apple.addClients(ga);
    apple.getClients();
    apple.addPctToCntPnr(ga,iPhone);
    apple.changeAvailablePct(iMac,4);
    apple.addProducts(iMac);
    apple.getProducts();
    apple.changeqtyPctInCntPnr(ga,iMac,2);
*/    

    return 0;
}


