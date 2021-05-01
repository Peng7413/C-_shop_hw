#ifndef SHOP_H
#define SHOP_H
#include "Cloth.h"
class Shop {
public:
	Shop(string name);
	string GetName();
	void createNewCloth(string name, string description, double price, int Id);
	vector<Cloth*>* GetClothes();
private:
	vector<Cloth*> _clothes;
	string _name;
};
#endif

