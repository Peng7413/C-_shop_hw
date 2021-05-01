/*
Purpose: 製作出一個服飾店，
		 可以新增衣服、
		 顯示所有衣服、
		 結束程式。
Author:
	Class: 資工二
	ID: 107590046
	Name:彭建豪
Homework number: HW6
Date:2019/10/21
*/
#include <iostream>
#include <cstdlib>
#include "Shop.h"
using namespace std;

void DisplayInstructionList(Shop& shop1)//顯示指令清單
{
	cout << "(" + shop1.GetName() + ")" << "1.新增衣服" << endl;
	cout << "(" + shop1.GetName() + ")" << "2.查看所有衣服" << endl;
	cout << "(" + shop1.GetName() + ")" << "3.結束程式" << endl;
}
/*對檔案讀入的一行進行切割，
並把切割後的資料存入shop物件內。*/
void FileDataSplit(string input1, Shop& shop1, int Id)
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
	shop1.createNewCloth(name, description, price, Id);
}
//載入衣服檔案，把所有衣服存入shop物件內。
void LoadCloths(Shop& shop1)
{
	fstream clothesData;
	int clothesNumber = 0, switch1 = 0;
	string fileData;
	clothesData.open("Cloth.txt");
	while (getline(clothesData, fileData))
	{
		if (switch1 == 1)
		{
			FileDataSplit(fileData, shop1, clothesNumber + 1);
			clothesNumber++;
		}
		switch1 = 1;
	}
	clothesData.close();
}
//比較數字大小，若number2大於number1回傳number2，小於則回傳number1。
int CompareLength(int number1, int number2)
{
	if (number1 < number2)
	{
		return number2;
	}
	return number1;
}
/*取得所有衣服資料內，名稱、價格最長的字串，
以此長度作為輸出排版依據。*/
void GetMaxStringLength(Shop& shop1, int maxLength[2])
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
void DisplayClothes(Shop& shop1, int maxLength[3])
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
}
int CountClothes(Shop& shop1)
{
	vector<Cloth*>* clothes;
	vector<Cloth*>::iterator oneCloth;
	clothes = shop1.GetClothes();
	oneCloth = (*clothes).begin();
	int clothesNumber = 0;
	for (oneCloth = (*clothes).begin(); oneCloth != (*clothes).end(); oneCloth++)
	{
		clothesNumber++;
	}
	return clothesNumber;
}
//新增一件衣服。
void InputCloth(Shop& shop1, int Id)
{
	string name, description;
	double price;
	cout << "請輸入衣服名稱: ";
	getline(cin, name);
	cout << "請輸入衣服描述: ";
	getline(cin, description);
	while(1)
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
			shop1.createNewCloth(name, description, price, Id);
			break;
		}
	}

}
//開始服飾店系統。
void ShopSystem(Shop& shop1)
{
	int clothesNumber, maxLength[2] = { 0,0 };
	int instruction, error = 0;
	LoadCloths(shop1);
	clothesNumber = CountClothes(shop1);
	DisplayInstructionList(shop1);
	while(1)
	{
		if(error == 0)
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
			break;
		}
		else if ((!cin || cin.gcount() != 1) || (instruction > 3))
		{
			cout << "請輸入正確選項: ";
			error = 1;
		}
	}
}
int main()
{
	Shop shop1("H&M");
	ShopSystem(shop1);
	system("pause");
	return 0;
}
