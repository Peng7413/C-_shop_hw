#include "Shop.h"

Shop::Shop(string name)
{
	_name = name;
}
string Shop::GetName()
{
	return _name;
}
void Shop::createNewCloth(string name, string description, double price, int Id)
{
	_clothes.push_back(new Cloth(name, description, price,Id));
}
vector<Cloth*>* Shop::GetClothes()
{
	return &_clothes;
}