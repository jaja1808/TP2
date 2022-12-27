#include "store.h"
#include "order.h"
#include <iostream>

//constructor

Store::Store(std::string name,std::vector<Product> products, std::vector<Client> clients, std::vector<Order> orders):
              _name(name),_products(products),_clients(clients),_orders(orders){
}

//friends

inline std::ostream &operator<<(std::ostream &os, const Client &c){
    // TODO: insert return statement here
    os<< c.getName() << " " << c.getPrenom() << " " << c.getId() << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Order &o){
    // TODO: insert return statement here
    os<< o.getClient() << std::endl;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Product& p){
   os<< p.getTitle() <<","<< p.getAvailable() <<","<< p.getAmount();
   return os;
}


//getters

void Store::getClients(){
     for(auto it = _clients.begin() ; it != _clients.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::getProducts(){
     for(auto it = _products.begin() ; it != _products.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::getOrders(){
     for(auto it = _orders.begin() ; it != _orders.end() ; it++){
        std::cout << *it << std::endl;
    }
}

std::string Store::getStoreName(){
    return _name;
}

//setters

void Store::setStoreName(std::string name){
    _name = name;
}

void Store::addClients(Client c)
{
    _clients.push_back(c);
}

void Store::addProducts(Product p){
    _products.push_back(p);
}

void Store::addOrders(Order o){
    _orders.push_back(o);
}

void Store::displayProduct(std::string name){
    for (auto it = _products.begin(); it !=_products.end(); it++){
      Product q = *it;
      if(name == q.getTitle()){
        std::cout << q << std::endl;
      }
    }
}

void Store::displayClient(std::string Id){
     for (auto it = _clients.begin(); it !=_clients.end(); it++){
      Client q = *it;
      if(Id == q.getId()){
        std::cout << q << std::endl;
      }
    }
}

void Store::changeAvailablePct(Product& p, int available){
         p.setAvailable(available);
}

void Store::addPctToCntPnr(Client& c,Product& p){
       c.addPanier(p);
}

void Store::removePctToCntPnr(Client& c,Product& p){
        c.removePanier(p);
}

void Store::changeqtyPctInCntPnr(Client& c,Product& p, int quantity){
          c.changeProdQtyinPnr(p,quantity);
}
