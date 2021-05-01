/*
Purpose: �s�@�X�@�ӪA�����A
		 �i�H�s�W��A�B
		 ��ܩҦ���A�B
		 �����{���C
Author:
	Class: ��u�G
	ID: 107590046
	Name:�^�ػ�
Homework number: HW6
Date:2019/10/21
*/
#include <iostream>
#include <cstdlib>
#include "Shop.h"
using namespace std;

void DisplayInstructionList(Shop& shop1)//��ܫ��O�M��
{
	cout << "(" + shop1.GetName() + ")" << "1.�s�W��A" << endl;
	cout << "(" + shop1.GetName() + ")" << "2.�d�ݩҦ���A" << endl;
	cout << "(" + shop1.GetName() + ")" << "3.�����{��" << endl;
}
/*���ɮ�Ū�J���@��i����ΡA
�ç���Ϋ᪺��Ʀs�Jshop���󤺡C*/
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
//���J��A�ɮסA��Ҧ���A�s�Jshop���󤺡C
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
//����Ʀr�j�p�A�Ynumber2�j��number1�^��number2�A�p��h�^��number1�C
int CompareLength(int number1, int number2)
{
	if (number1 < number2)
	{
		return number2;
	}
	return number1;
}
/*���o�Ҧ���A��Ƥ��A�W�١B����̪����r��A
�H�����ק@����X�ƪ��̾ڡC*/
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
//��ܩҦ���A�A�ƪ����X�C
void DisplayClothes(Shop& shop1, int maxLength[3])
{
	vector<Cloth*>* clothes;
	vector<Cloth*>::iterator oneCloth;
	GetMaxStringLength(shop1, maxLength);
	cout << "No.    ";
	cout << std::left << std::setw(maxLength[0] + 4) << "��A�W��";
	cout << std::left << std::setw(maxLength[1] + 4) << "����";
	cout << "�y�z" << endl;
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
//�s�W�@���A�C
void InputCloth(Shop& shop1, int Id)
{
	string name, description;
	double price;
	cout << "�п�J��A�W��: ";
	getline(cin, name);
	cout << "�п�J��A�y�z: ";
	getline(cin, description);
	while(1)
	{
		cout << "�п�J����: ";
		cin >> price;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (!cin || cin.gcount() != 1)
		{
			cout << "��J���i���D�Ʀr�A�Э��s��J" << endl;
		}
		else if (price <= 0)
		{
			cout << "���椣��p�󵥩�s�A�Э��s��J" << endl;
		}
		else
		{
			shop1.createNewCloth(name, description, price, Id);
			break;
		}
	}

}
//�}�l�A�����t�ΡC
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
			cout << "�п�J���: ";
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
			cout << "�п�J���T�ﶵ: ";
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
