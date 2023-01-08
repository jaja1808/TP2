#include "store.h"
#include "order.h"
#include "client.h"
#include "product.h"
#include <vector>
#include <iostream>
#include <algorithm>


//constructor

Store::Store(std::string name,std::vector<Product> products, std::vector<Client> clients, std::vector<Order> orders):
              _name(name),_products(products),_clients(clients),_orders(orders){
}

//getters

void Store::displayClients(){
     for(auto it = _clients.begin() ; it != _clients.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::displayProducts(){
     for(auto it = _products.begin() ; it != _products.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::dispalyOrders(){
     for(auto it = _orders.begin() ; it != _orders.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Store::displayThisClient(std::string Id){
    std::cout << getClient(Id) << std::endl;
}

std::string Store::getStoreName(){
    return _name;
}

std::vector<Product> Store::getProductsList(){
    return _products;
}

std::vector<Client> Store::getClientsList(){
    return _clients;
}

std::vector<Order> Store::getOrdersList(){
    return _orders;
}

//setters

void Store::setStoreName(std::string name){
    _name = name;
}

void Store::addClients(Client& c){
    _clients.push_back(c);
}

void Store::newClientInStore(std::string name, std::string prenom, std::string Id, std::string nameProd){
    Client c;
    c.setname(name);
    c.setprenom(prenom);
    c.setId(Id);
    c.addPanier(getProduct(nameProd));
    addClients(c);
}

void Store::newProdInStore(std::string name, std::string Descr, float cost, int quant){
     Product p;
    p.setTitle(name);
    p.setDescr(Descr);
    p.setAvailable(quant);
    p.setAmount(cost);
    addProducts(p);
}

void Store::newOrderLinkPanier(std::string Id){
    Order o;
    o.setClient(getClient(Id));
    o.linkProducts();
    addOrders(o);
}

void Store::newOrderNewPr(std::string name, std::string Id){
    Order o;
    o.setClient(getClient(Id));
    o.addProducts(getProduct(name));
    addOrders(o);
}

void Store::addProducts(Product& p){
    _products.push_back(p);
}

void Store::addOrders(Order& o){
    _orders.push_back(o);
}

void Store::validateOrder(std::string Id){
    getOrderByClntId(Id).validOrder();
}

void Store::changeStOrd(std::string Id, std::string stat){
    getOrderByClntId(Id).setStatus(stat);
}

Product& Store::getProduct(std::string name){
    auto it = std::find_if(_products.begin(), _products.end(), 
    [&name](const Product& p){return p.getTitle() == name;});

    return *it;
    if (it == _products.end()) {
    throw std::runtime_error("Product not found");
  }
}

Client& Store::getClient(std::string Id){
    auto it = std::find_if(_clients.begin(), _clients.end(), 
    [&Id](const Client& p){return p.getId() == Id;});
 
  return *it;
  if (it == _clients.end()) {
    throw std::runtime_error("Client not found");
  }
}

Order &Store::getOrderByClntId(std::string Id){
  // TODO: insert return statement here
  auto it = std::find_if(_orders.begin(), _orders.end(), [&Id](const Order &o)
                         { return o.getClient().getId() == Id; });
  return *it;
   if (it == _orders.end()) {
    throw std::runtime_error("Order not found");
  }
}

void Store::changeAvailablePct(std::string name, int available){
 getProduct(name).setAvailable(available);
}

void Store::addPctToCntPnr(std::string Id,std::string name){
      getClient(Id).addPanier(getProduct(name));
}

void Store::removePctToCntPnr(std::string Id,std::string name){
    getClient(Id).removePanier(name);
}

void Store::changeqtyPctInCntPnr(std::string Id,std::string name, int quantity){
    getClient(Id).changeProdQtyinPnr(name, quantity);
    getClient(Id).displayPanier();
}
