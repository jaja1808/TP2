#include "client.h"
#include <vector>
#include <iostream>

// constructor

Client::Client(std::string name, std::string prenom, std::string id, std::vector<Product> panier):
               _name(name),_prenom(prenom),_id(id),_panier(panier){
}

// OVERLOADING

// ==
bool operator==(Product &p, std::vector<Product> &_panier){ 
  return true;
}
// Overloading output of product
inline std::ostream& operator << (std::ostream& os,const Product& p){
   os << p.getTitle() <<","<< p.getAvailable() <<","<< p.getAmount();
   return os;
}
// Overloading output of client
inline std::ostream &operator<<(std::ostream &os, const Client &c){
    os<< c.getName() << " " << c.getPrenom() << " " << c.getId() << std::endl;
    return os;
}

//getters

std::string Client::getName() const{
    return _name;
}

std::string Client::getPrenom() const{
    return _prenom;
}

std::string Client::getId() const{
    return _id;
}

void Client::getPanier() const{
   for (auto it=_panier.begin(); it!=_panier.end(); it++){
    std::cout<< *it << std::endl;
    }
}

// setters

void Client::setname(std::string name){
    _name = name;
}

void Client::setprenom(std::string prenom){
    _prenom = prenom;
}

void Client::setId(std::string id){
    _id = id;
}

void Client::addPanier(Product p){
    if(p.getAvailable() != 0){
    _panier.push_back(p);
    p.decrAvailable();
    }
}

void Client::removePanier(Product p){   // waramvunnye
     int index= -1;
   for (int a = 0; a < _panier.size(); a++) {
         Product& q=_panier.at(a);
        if (q.getTitle() == p.getTitle()) {
        index = a;
        break;
    }
  }
       if (index != -1) {
          _panier.erase(_panier.begin() + index);
          p.incrAvailable();
       }
}


void Client::emptyPanier(){
    for (auto it=_panier.begin(); it!=_panier.end(); it++){
    _panier.erase(it);
    std::cout <<"Your Char size is now:"<<_panier.size() <<std::endl;
    }
}

void Client::findProduct(Product& p){
  for (auto it=_panier.begin(); it!=_panier.end(); it++){
    Product q = *it ;
    if (p.getTitle()== q.getTitle()){
        std::cout << q <<std::endl;
    }
  }
}

int Client::countTheOccurance(Product &p){
    int count = 0;
  for (auto it=_panier.begin(); it!=_panier.end(); it++){
    Product q = *it ;
    if (p.getTitle()== q.getTitle()){
        count ++;
    }
  }
  return count;
}

void Client::changeProdQtyinPnr(Product &p, int qty){

 if(p.getAvailable() >= qty){
   if(countTheOccurance(p)<qty){ 
   while (countTheOccurance(p) <= qty ){
      addPanier(p);
      p.decrAvailable();
     }
    }
   }else{
    std::cout <<"Please we have: "<<p.getAvailable()<<" products remaing"<<std::endl;
  }

   if(countTheOccurance(p)>qty){ 
   while (countTheOccurance(p) > qty ){
    removePanier(p);
    p.incrAvailable();
    }
   }
}
void Client::findByName(std::string name){
   for (auto it=_panier.begin(); it!=_panier.end(); it++){
    Product q = *it ;
    if (q.getTitle()==name){
       std::cout << q <<std::endl; 
    }
   }      
}

void getTheClient(Client c){
    std::cout<< c << std::endl;
    c.getPanier();
}
