#include <iostream>
#include <string.h>

#ifndef PRODUCT
#define PRODUCT

class Product
{
private:
    /* data */
    
   std::string _title;
   std::string _description;
   int _available;
   float _amount;

public:
    Product( std::string _title ="Jata",
             std::string _description = "yiwivvyvv",
             int _available = 12,
             float _amount =12.45);

    //getters

    std::string getTitle() const;
    float getAmount() const;
    int getAvailable() const;
    std::string getDescr() const;
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    

    //setters

    void setTitle(std::string title);
    void setAmount(float amount);
    void setAvailable(int available);
    void setDescr(std::string description);

    //methods

    void decrAvailable(); 
    void incrAvailable();
};

  void getProduct(Product p);

#endif //PRODUCT