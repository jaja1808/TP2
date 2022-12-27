#include "product.h"
#include <vector>
#include <iostream>

#ifndef _CLIENT
#define _CLIENT

class Client
{
private:
    /* data */

    std::string _name;
    std::string _prenom;
    std::string _id;
    std::vector <Product> _panier;

public:
  //constructor

    Client(std::string name = "jaja",
           std::string prenom = "Ja",
           std::string id ="Jajaja",
           std::vector <Product> panier = {});

    // getters 

    std::string getName() const;
    std::string getPrenom() const;
    std::string getId() const;

    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    void getPanier() const;

    //setters

    void setname(std::string name);
    void setprenom(std::string prenom);
    void setId(std::string id);
    friend std::ostream& operator<<(std::ostream& os, const Client& c);
    friend bool operator==(Product& p, std::vector <Product>& _panier); // probation

    //helpers

    void addPanier(Product p);
    void removePanier(Product p);
    void emptyPanier();
    void findProduct(Product& p);
    int countTheOccurance(Product& p);
    void changeProdQtyinPnr(Product& p, int qty);
    void findByName(std::string name);

};
 
 void getTheClient(Client c);

#endif //_CLIENT