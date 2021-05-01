#include "Customer.h"
Customer::Customer(string name)
{
	_name = name;
	_point = 2000;
	_order = nullptr;
}
string Customer::GetName()
{
	return _name;
}
double Customer::GetCash()
{
	return _point;
}

void Customer::MakeNewOrder(Shop *shop)
{
	_order = new Order(shop);
}
void Customer::AddClothToOrder(Cloth *cloth)
{
	_order->AddCloth(cloth);
}
double Customer::GetOrderTotalPrice()
{
	return _order->GetTotalPrice();
}
bool Customer::IsPointEnough()
{
	if (GetOrderTotalPrice() > _point)
	{
		return false;
	}
	else if (GetOrderTotalPrice() <= _point)
	{
		return true;
	}
}
void Customer::ReducePointFromOrder()
{
	_point = _point - GetOrderTotalPrice();
}
void Customer::CancelOrder()
{
	delete _order;
}
Order* Customer::GetCurrentOrder()
{
	return _order;
}