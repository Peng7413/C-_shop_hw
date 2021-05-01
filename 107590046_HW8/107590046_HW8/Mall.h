#ifndef MALL_H
#define MALL_H
#include "Shop.h"
class Mall
{
public:
	Mall();
	void CreateNewCloth(string name, string description, double price,int id);
	void CreateShop(string name);
	void SelectShop(int shopindex);
	int GetShopsAmount();
	vector<Cloth*>* GetClothes();
	vector<Shop*>* GetShops();
private:
	int _shopindex;
	vector<Shop*> _shops;
};
#endif
