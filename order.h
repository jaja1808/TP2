#include "product.h"
#include "client.h"
#include <iostream>

#ifndef _ORDER
#define _ORDER

enum Status{
    Delivered, Not_Delivered
};

class Order{

private:

    /* data */
    Client _client;
    std::vector <Product> _chosenProducts;
    Status _status; 

public:

    Order( Client client = Client (),
           std::vector <Product> chosenProducts = {Product ()},
           Status status = Not_Delivered );

      //getters

   Client getClient() const;
   friend std::ostream& operator<<(std::ostream& os, const Product& p); 
   friend std::ostream& operator<<(std::ostream& os, const Client& c);

   void getProductList();
   void getStatus() const;

   // setters

   void setStatus(Status s);
   void addProducts(Product p);
   void validOrder();
  
};

// bool isValidOrder(Order o);
// void displayOrders(Order o);

#endif //_ORDER