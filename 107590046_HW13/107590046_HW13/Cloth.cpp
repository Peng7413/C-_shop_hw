#include "Cloth.h"

Cloth::Cloth(string name, string description, double price, int Id)
{
	_name = name;
	_description = description;
	_price = price;
	_Id = Id;
}
string Cloth::GetName()
{
	return _name;
}
string Cloth::GetDescription()
{
	return _description;
}
double Cloth::GetPrice()
{
	return _price;
}
void Cloth::SetId(int Id)
{
	_Id = Id;
}
int Cloth::GetId()
{
	return _Id;
}