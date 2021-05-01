#include "Mall.h"
#include "MallUI.h"
#include "ShopUI.h"
using namespace std;

MallUI::MallUI()
{}
//���o�ɮפ��U�Ӱө����W�١C
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
/*���ɮ�Ū�J���@��i����ΡA
�ç���Ϋ᪺��Ʀs�Jshop���󤺡C*/
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
//���J��A�ɮסA���إ�shop�A�A��Ҧ���A�s�J�U��shop���󤺡C
void MallUI::LoadClothesFile(Mall& mall)
{
	fstream clothesData;
	int clothesNumber = 0, shopsNumber = 0;
	string fileData;
	clothesData.open("Cloth.txt");
	while (getline(clothesData, fileData))
	{
		if (fileData.find("Shop") != -1)//�Y�ثeŪ�J���ɮ׸�Ƨt��shop�r��A�h�إ�shop�C
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
void MallUI::DisplayShops(Mall mall)//��ܩҦ��ө�
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
void MallUI::start(Mall& mall)//�}�l�ʪ����ߨt�ΡC
{
	LoadClothesFile(mall);
	ShopUI UI1;
	int select = 0, error = 0;
	while(1)
	{
		if (error == 0)
		{
			DisplayShops(mall);
			cout << "��J-1�����{��" << endl;
		}
		cout << "Select Shop: ";
		cin >> select;
		if (select == -1)
		{
			break;
		}
		else if(select>mall.GetShopsAmount())
		{
			cout << "�п�ܵe���W�����a" << endl;
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