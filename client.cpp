#include "client.h"
#include <vector>
#include <iostream>
#include <algorithm>

// constructor

Client::Client(std::string name, std::string prenom, std::string id, std::vector<Product> panier):
               _name(name),_prenom(prenom),_id(id),_panier(panier){
}

// OVERLOADING

// // ==
// bool operator==(Product &p, std::vector<Product> &_panier){ 
//   return true;
// }

// Overloading output of Client

std::ostream &operator<<(std::ostream &os, const Client &c){
     //parameters to be displayed
    os<< c.getName() << " " << c.getPrenom() << " " << c.getId()  << std::endl;
    for (auto it=c._panier.begin(); it!=c._panier.end(); it++){
        os << *it << std::endl;
    }
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

std::vector<Product> Client::getPanier() const{
    return _panier;
}

void Client::displayPanier() const{
  for (auto it=_panier.begin(); it!=_panier.end(); it++){
        std::cout << *it << std::endl;
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

void Client::setPanier(std::vector<Product> panier){
    _panier = panier;
}

void Client::addPanier(Product& p){
    if(p.getAvailable() != 0){
    _panier.push_back(p);
     p.decrAvailable();
    }
}

void Client::removePanier(std::string name){   // waramvunnye
     int index= -1;
   for (int a = 0; a < (int)_panier.size(); a++) {
         Product& q=_panier.at(a);
        if (q.getTitle() == findByName(name).getTitle()) {
        index = a;
        break;
    }
  }
       if (index != -1) {
          _panier.erase(_panier.begin() + index);
          findByName(name).incrAvailable();
       }
}

void Client::delProductProd(std::string name){
  for (int a = 0; a < (int) _panier.size(); a++) {       
        if (_panier.at(a).getTitle() == name ) {
       _panier.erase(_panier.begin() + a);
        break;
    }else{
    throw std::runtime_error("Product not found");
  }  
 }
}

void Client::emptyPanier(){
    for (auto it=_panier.begin(); it!=_panier.end(); it++){
    _panier.erase(it);
    std::cout <<"Your Char size is now:"<<_panier.size() <<std::endl;
    }
}

int Client::countTheOccurance(std::string name){
    int count = 0;
  for (auto it=_panier.begin(); it!=_panier.end(); it++){
    Product q = *it ;
    if (findByName(name).getTitle()== q.getTitle()){
        count ++;
    }
    q.setAvailable(q.getAvailable() - count);
  }
  return count;
}

void Client::changeProdQtyinPnr(std::string name, int qty){

 if(findByName(name).getAvailable() >= qty){
   if(countTheOccurance(name)<qty){ 
   while (countTheOccurance(name) <= qty ){
      addPanier(findByName(name));
      findByName(name).decrAvailable();
     }
    }
   }else{
    std::cout <<"Please we have: "<< findByName(name).getAvailable()<<" "<< findByName(name).getTitle()<<" remaining"<<std::endl;
  }

   if(countTheOccurance(name)>qty){ 
   while (countTheOccurance(name) > qty ){
    removePanier(name);
    findByName(name).incrAvailable();
    }
   }
}

Product& Client::findByName(std::string name){
  auto it = std::find_if(_panier.begin(), _panier.end(), 
    [&name](const Product& p){return p.getTitle() == name;});

    return *it;
    if (it == _panier.end()) {
    throw std::runtime_error("Product not found");
  }
}

void getTheClient(Client& c){
    std::cout<< c << std::endl;
    c.getPanier();
}
