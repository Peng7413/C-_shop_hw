#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Order.h"
class Customer {
public:
	Customer(string name);
	string GetName();
	double GetCash();
	void MakeNewOrder(Shop *shop);
	void AddClothToOrder(Cloth *cloth);
	double GetOrderTotalPrice();
	bool IsPointEnough();
	void ReducePointFromOrder();
	void CancelOrder();
	Order* GetCurrentOrder();
private:
	string _name;
	double _point;
	Order *_order;
};
#endif
