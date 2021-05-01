#include "Mall.h"
using namespace std;
Mall::Mall()
{}
void Mall::CreateShop(string name)
{
	_shops.push_back(new Shop(name));
}
void Mall::CreateNewCloth(string name, string description, double price,int id)
{
	_shops.begin()[_shopindex]->CreateNewCloth(name, description, price, id);
}
void Mall::SelectShop(int shopindex)
{
	_shopindex = shopindex;
}
int Mall::GetShopsAmount()
{
	int count = 0;
	vector<Shop*>::iterator oneShop;
	for (oneShop = _shops.begin(); oneShop != _shops.end(); oneShop++)
	{
		count++;
	}
	return count;
}
vector<Cloth*>* Mall::GetClothes()
{
	return _shops.begin()[_shopindex]->GetClothes();
}
vector<Shop*>* Mall::GetShops()
{
	return &_shops;
}
