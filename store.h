#include "product.h"
#include "client.h"
#include "order.h"
#include <iostream>

#ifndef _STORE
#define _STORE

class Store
{
private:
    /* data */
    std::string _name;
    std::vector <Product> _products;
    std::vector <Client> _clients;
    std::vector <Order> _orders;

public:
    Store( std::string name = "EasyStore",std::vector <Product> products = {Product ()},
           std::vector <Client> clients = {Client ()},
           std::vector <Order> orders = {Order ()});

     //getters

     friend std::ostream& operator<<(std::ostream& os, const Product& p);
     friend std::ostream& operator<<(std::ostream& os, const Client& c);
     friend std::ostream& operator<<(std::ostream& os, const Order& o);
    //  friend std::ostream& operator+(std::ostream& os, const Product& p);

     void getClients ();
     void getProducts();
     void getOrders();
     std::string getStoreName();

     //setters

     void setStoreName(std::string name);
     void addClients(Client c);
     void addProducts(Product p);
     void addOrders(Order o);
     void displayProduct(std::string name);
     void displayClient(std::string Id);

     
     void changeAvailablePct(Product& p, int availlable);
     void addPctToCntPnr(Client& c,Product& p);
     void removePctToCntPnr(Client& c,Product& p);
     void changeqtyPctInCntPnr(Client& c,Product& p, int quantity);
     

};


#endif //_STORE