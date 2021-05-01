#ifndef SHOPUI_H
#define SHOPUI_H
#include "Shop.h"
class ShopUI
{
public:
	ShopUI();
	void ShopSystem(Shop& shop1);
private:
	void DisplayInstructionList(Shop& shop1);
	int CompareLength(int number1, int number2);
	void GetMaxStringLength(Shop& shop1, int maxLength[2]);
	void DisplayClothes(Shop& shop1, int maxLength[3]);
	int CountClothes(Shop& shop1);
	void InputCloth(Shop& shop1, int Id);
};
#endif
