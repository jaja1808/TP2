#include "client.h"
#include "product.h"
#include "order.h"
#include "store.h"
#include <iostream>


int main(int argc, char const *argv[]){

// input of product 
    Product iPhone ("IPHONE","apple_corporation",12,890.34);
    Product iMac("iMac","apple_machines",4,2098.45); //creating another product

//creating the first client 
    Client ga("ga","ju","juga",{iMac});  //creating a second client
    Client pure ("Pure","rush","rushJa",{iPhone});

//creating the first Order
    Order myOrder(pure,{iPhone,iMac},Not_Delivered);

// creating the first sore 
    Store apple("AppleSrore",{iPhone},{pure,ga},{myOrder});


    //trials

std::cout << "Test 10" << std::endl;
// apple.dispalyOrders();
// apple.displayClients();
// apple.displayProducts();
// std::cout << "Test 10" << std::endl;
// apple.changeqtyPctInCntPnr("rushJa", "IPHONE", 2);
// apple.displayClients();
// apple.displayProducts();
// std::cout << "Test 11" << std::endl;
// pure.changeProdQtyinPnr("IPHONE", 2);
// pure.addPanier(iMac);
// pure.changeProdQtyinPnr("iMac", 2);
// pure.displayPanier();
// pure.removePanier("IPHONE");
// pure.displayPanier();
// apple.newOrder();
// apple.changeqtyPctInCntPnr("juga", "iMac", 2);
// apple.dispalyOrders();
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
// std::cout << "Test 8" << std::endl;
// std::cout << pure.findByName("IPHONE") << std::endl;
// std::cout << "Test 8" << std::endl;
// myOrder.getProductList();
// std::cout << "Test 8" << std::endl;
// myOrder.linkProducts();
// myOrder.getProductList();
// std::cout << "Test 9" << std::endl;
// apple.addProducts(iMac);
// apple.changeAvailablePct("iMac", 5);
// std::cout << apple.displayProduct("iMac") << std::endl;

/*
// THE APPLICATION

 //Main menu
 std::cout <<"Welcome to "<< apple.getStoreName()<< std::endl;
 std::cout <<"press:"<< std::endl;
 std::cout <<"1.Store Management"<< std::endl;
 std::cout <<"2.Client Space"<< std::endl;
 std::cout <<"3.My Orders"<< std::endl;

 //Main Variables

 Product newProduct;
 Client newClient;
 Order newOrder;
 Store newStore;
 int key;
 int option1;

 //Product
 std::string Title;
 std::string description;
 int available;
 float amount;

 //Client
 std::string name;
 std::string prenom;
 std::string id;

 std::cin >> key;

 switch (key)
 {

 case 1:
     std::cout << "1.Add a new product in store" << std::endl;
     std::cout << "2.Add a new client" << std::endl;
     std::cout << "3.Add an order" << std::endl;
     std::cout << "4.Display products" << std::endl;
     std::cout << "5.Display all clients of the store" << std::endl;
     std::cout << "6.Change quantity of product available" << std::endl;
     std::cout << "7.Search a Product" << std::endl;
     std::cout << "8.Search a Client" << std::endl;

     std::cin >> option1;

     switch (option1)
     {
     case 1:
         std::cout <<"Name of the  product"<< std::endl;
         std::cin >> Title;
         newProduct.setTitle(Title);

         std::cout <<"Products available for sale"<< std::endl;
         std::cin >> available;
         newProduct.setAvailable(available);

         std::cout <<"Cost of the Product"<< std::endl;
         std::cin >> amount;
         newProduct.setAmount(amount);

         std::cout <<"Product Desription"<< std::endl;
         std::cin >> description;
         newProduct.setDescr(description);

         getProduct(newProduct);
         newStore.addProducts(newProduct);

         break;

     case 2:
         std::cout <<"Name of the Client"<< std::endl;
         std::cin >> name;
         newClient.setname(name);

         std::cout <<"Surname of the Client"<< std::endl;
         std::cin >> prenom;
         newClient.setprenom(prenom);

         std::cout <<"Unique ID of the Client"<< std::endl;
         std::cin >> id;
         newClient.setId(id);

         getTheClient(newClient);
         newStore.addClients(newClient);

         break;

     case 3:

         newOrder.addProducts(newProduct);
         newOrder.setClient(newClient);
         newOrder.setStatus(Delivered);

         newStore.addOrders(newOrder);

         break;

     case 4:

         newStore.getProducts();

         break;

     case 5:

         newStore.getClients();

         break;

     case 6:

         int quantity;
         std::cout << " Enter the new qunatity of the product" << std::endl;
         std::cin >> quantity;
         newStore.changeqtyPctInCntPnr(newClient, newProduct, quantity);

         break;

     case 7:

         std::cout << " Enter the name of the product" << std::endl;
         std::cin >> name;
         newStore.displayProduct(name);

         break;

     case 8:

         std::cout << " Enter the name of the client" << std::endl;
         std::cin >> name;
         newStore.displayClient(name);

         break;

     default:
         std::cout << "Invalid Input" << std::endl;
     break;
}
   break;


case 2:
 std::cout <<"1.Add a new product in the cart"<< std::endl;
 std::cout <<"2.Remove a product in cart"<< std::endl;
 std::cout <<"3.Place an order"<< std::endl;
 std::cout <<"4.Check amount"<< std::endl;
 std::cout <<"5.Validate an Order"<< std::endl;

 std::cin >> option1;

   switch (option1){

     case 1:

     newClient.addPanier(newProduct);

     break;

     default:
     break;
}
   break;


case 3:
 std::cout <<"1.Display all orders"<< std::endl;
 std::cout <<"2.Change the status of an order"<< std::endl;

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
*/

return 0;
}


