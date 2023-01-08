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

     void displayClients ();
     void displayProducts();
     void dispalyOrders();
     void displayThisClient(std::string Id);
     std::string getStoreName();
     std::vector<Product> getProductsList();
     std::vector<Client> getClientsList();
     std::vector<Order> getOrdersList();

     //setters

     void setStoreName(std::string name);
     void addClients(Client& c);
     void newClientInStore(  std::string name,std::string prenom,std::string Id,std::string nameProd);
     void newProdInStore( std::string name,std::string Descr,float cost,int quant);
     void newOrderLinkPanier(std::string Id);
     void newOrderNewPr(std::string name,std::string Id);
     void addProducts(Product& p);
     void addOrders(Order& o);
     void validateOrder(std::string Id);
     void changeStOrd(std::string Id,std::string stat);
     Product& getProduct(std::string name);
     Client& getClient(std::string Id);
     Order &getOrderByClntId(std::string Id);
     void changeAvailablePct(std::string name, int availlable);
     void addPctToCntPnr(std::string Id,std::string name);
     void removePctToCntPnr(std::string Id,std::string name);
     void changeqtyPctInCntPnr(std::string Id,std::string name, int quantity);
     

};


#endif //_STORE