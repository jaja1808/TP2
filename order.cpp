#include "order.h"
#include "client.h"
#include "product.h"
#include <iostream>

//constructor

Order::Order(Client client, std::vector<Product> chosenProducts, Status status): 
            _client(client),_chosenProducts(chosenProducts),_status(status){
}

inline std::ostream &operator<<(std::ostream &os, const Client &c){
    // TODO: insert return statement here
    os<< c.getName() << " " << c.getPrenom() << " " << c.getId() << std::endl;
    return os;
}

Client Order::getClient() const{
    return _client;
}

inline std::ostream& operator<<(std::ostream& os, const Product& p){
   os << p.getTitle() <<","<< p.getAvailable() <<","<< p.getAmount();
   return os;
}

void Order::getProductList(){
    for(auto it = _chosenProducts.begin() ; it != _chosenProducts.end() ; it++){
        std::cout << *it << std::endl;
    }
}

void Order::getStatus() const{
    
    if (_status == 0){
        std::cout<<"Delivered"<<std::endl;
    }else{
        std::cout<<"Not-Delivered"<<std::endl;
    };
}

void Order::setStatus(Status s){
     _status = s;
}

void Order::addProducts(Product p){
    _chosenProducts.push_back(p);
}

void Order::validOrder(){
    _client.emptyPanier();
    _chosenProducts.clear();
}
/*
bool isValidOrder(Order o){
   if(o.getClient()= Client())
    return true;
}

void displayOrders(Order o){
    if(isValidOrder){
      o.getStatus();
    }else{
        std::cout <<" your order is not valid yet"<<std::endl;
    }
}
*/