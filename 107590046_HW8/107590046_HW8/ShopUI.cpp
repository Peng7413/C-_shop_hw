#include "Shop.h"
#include "ShopUI.h"
using namespace std;

ShopUI::ShopUI()
{}
void ShopUI::DisplayInstructionList(Shop& shop1)//顯示指令清單
{
	cout << "(" + shop1.GetName() + ")" << "1.新增衣服" << endl;
	cout << "(" + shop1.GetName() + ")" << "2.查看所有衣服" << endl;
	cout << "(" + shop1.GetName() + ")" << "3.返回商場" << endl;
}
//比較數字大小，若number2大於number1回傳number2，小於則回傳number1。
int ShopUI::CompareLength(int number1, int number2)
{
	if (number1 < number2)
	{
		return number2;
	}
	return number1;
}
/*取得所有衣服資料內，名稱、價格最長的字串，
以此長度作為輸出排版依據。*/
void ShopUI::GetMaxStringLength(Shop& shop1, int maxLength[2])
{
	vector<Cloth*>* clothes;
	vector<Cloth*>::iterator oneCloth;
	string longestName, longestPrice;
	stringstream temp;
	clothes = shop1.GetClothes();
	oneCloth = (*clothes).begin();
	for (oneCloth = (*clothes).begin(); oneCloth != (*clothes).end(); oneCloth++)
	{
		longestName = (*oneCloth)->GetName();
		maxLength[0] = CompareLength(maxLength[0], longestName.size());

		temp << (*oneCloth)->GetPrice();
		temp >> longestPrice;
		temp.clear();
		maxLength[1] = CompareLength(maxLength[1], longestPrice.size());
	}
}
//顯示所有衣服，排版後輸出。
void ShopUI::DisplayClothes(Shop& shop1, int maxLength[3])
{
	vector<Cloth*>* clothes;
	vector<Cloth*>::iterator oneCloth;
	GetMaxStringLength(shop1, maxLength);
	cout << "No.    ";
	cout << std::left << std::setw(maxLength[0] + 4) << "衣服名稱";
	cout << std::left << std::setw(maxLength[1] + 4) << "價格";
	cout << "描述" << endl;
	clothes = shop1.GetClothes();
	oneCloth = (*clothes).begin();
	for (oneCloth = (*clothes).begin(); oneCloth != (*clothes).end(); oneCloth++)
	{
		cout << std::left << std::setw(7) << (*oneCloth)->GetId();
		cout << std::left << std::setw(maxLength[0] + 4) << (*oneCloth)->GetName();
		cout << std::left << std::setw(maxLength[1] + 4) << (*oneCloth)->GetPrice();
		cout << (*oneCloth)->GetDescription() << endl;
	}
	cout << endl;
}
//計算該商店的衣服數量。
int ShopUI::CountClothes(Shop& shop1)
{
	vector<Cloth*>* clothes;
	clothes = shop1.GetClothes();
	return clothes->size();
}
//新增一件衣服。
void ShopUI::InputCloth(Shop& shop1, int Id)
{
	string name, description;
	double price;
	cout << "請輸入衣服名稱: ";
	getline(cin, name);
	cout << "請輸入衣服描述: ";
	getline(cin, description);
	while (1)
	{
		cout << "請輸入價格: ";
		cin >> price;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (!cin || cin.gcount() != 1)
		{
			cout << "輸入不可有非數字，請重新輸入" << endl;
		}
		else if (price <= 0)
		{
			cout << "價格不能小於等於零，請重新輸入" << endl;
		}
		else
		{
			shop1.CreateNewCloth(name, description, price, Id);
			cout << endl;
			break;
		}
	}

}
//開始服飾店系統。
void ShopUI::ShopSystem(Shop& shop1)
{
	int clothesNumber, maxLength[2] = { 0,0 };
	int instruction, error = 0;
	clothesNumber = CountClothes(shop1);
	while (1)
	{
		DisplayInstructionList(shop1);
		if (error == 0)
		{
			cout << "請輸入選擇: ";
		}
		cin >> instruction;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (instruction == 1)
		{
			InputCloth(shop1, clothesNumber + 1);
			error = 0;
			clothesNumber++;
		}
		else if (instruction == 2)
		{
			DisplayClothes(shop1, maxLength);
			error = 0;
		}
		else if (instruction == 3)
		{
			cout << endl;
			break;
		}
		else if ((!cin || cin.gcount() != 1) || (instruction > 3))
		{
			cout << "請輸入正確選項: ";
			error = 1;
		}
	}
}
