#include "Mall.h"
#include "MallUI.h"
#include "ShopUI.h"
using namespace std;

MallUI::MallUI()
{}
//取得檔案內各個商店的名稱。
string MallUI::CatchShopName(string input1)
{
	int count = 0, start = 0;
	string name;
	for (count = 0; count < input1.size(); count++)
	{
		if (input1[count] == ' ')
		{
			start = 1;
		}
		else if (start == 1)
		{
			if (input1[count] == ':')
			{
				break;
			}
			name += input1[count];
		}
	}
	return name;
}
/*對檔案讀入的一行進行切割，
並把切割後的資料存入shop物件內。*/
void MallUI::FileDataSplit(string input1, Mall& mall, int Id)
{
	int stringIndex, spilttime = 0;
	string subString, name, description;
	stringstream temp;
	double price;
	for (stringIndex = 0; stringIndex < input1.size(); stringIndex++)
	{
		if (input1[stringIndex] != ',')
		{
			subString += input1[stringIndex];
		}
		else
		{
			if (spilttime == 0)
			{
				name = subString;
			}
			else if (spilttime == 1)
			{
				description = subString;
			}
			subString = "";
			spilttime++;
			stringIndex++;
		}
	}
	temp << subString;
	temp >> price;
	mall.CreateNewCloth(name, description, price, Id);
}
//載入衣服檔案，先建立shop，再把所有衣服存入各個shop物件內。
void MallUI::LoadClothesFile(Mall& mall)
{
	fstream clothesData;
	int clothesNumber = 0, shopsNumber = 0;
	string fileData;
	clothesData.open("Cloth.txt");
	while (getline(clothesData, fileData))
	{
		if (fileData.find("Shop") != -1)//若目前讀入的檔案資料含有shop字串，則建立shop。
		{
			mall.CreateShop(CatchShopName(fileData));
			clothesNumber = 0;
			shopsNumber++;
		}
		else if (fileData[0] != '\0')
		{
			mall.SelectShop(shopsNumber - 1);
			FileDataSplit(fileData, mall, clothesNumber + 1);
			clothesNumber++;
		}
	}
	clothesData.close();
}
void MallUI::DisplayShops(Mall mall)//顯示所有商店
{
	vector<Shop*>*shops = mall.GetShops();
	vector<Shop*>::iterator oneShop;
	int count = 1;
	for (oneShop = (*shops).begin(); oneShop != (*shops).end(); oneShop++)
	{
		cout << count << "." << (*oneShop)->GetName() << endl;
		count++;
	}
}
void MallUI::start(Mall& mall)//開始購物中心系統。
{
	LoadClothesFile(mall);
	ShopUI UI1;
	int select = 0, error = 0;
	while(1)
	{
		if (error == 0)
		{
			DisplayShops(mall);
			cout << "輸入-1結束程式" << endl;
		}
		cout << "Select Shop: ";
		cin >> select;
		if (select == -1)
		{
			break;
		}
		else if(select>mall.GetShopsAmount())
		{
			cout << "請選擇畫面上的店家" << endl;
			error = 1;
		}
		else
		{
			cout << endl;
			vector<Shop*>*shops = mall.GetShops();
			vector<Shop*>::iterator oneShop;
			oneShop = shops->begin();
			UI1.ShopSystem((*oneShop[select - 1]));
			error = 0;
		}
	}
}