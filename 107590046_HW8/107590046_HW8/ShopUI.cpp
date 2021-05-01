#include "Shop.h"
#include "ShopUI.h"
using namespace std;

ShopUI::ShopUI()
{}
void ShopUI::DisplayInstructionList(Shop& shop1)//��ܫ��O�M��
{
	cout << "(" + shop1.GetName() + ")" << "1.�s�W��A" << endl;
	cout << "(" + shop1.GetName() + ")" << "2.�d�ݩҦ���A" << endl;
	cout << "(" + shop1.GetName() + ")" << "3.��^�ӳ�" << endl;
}
//����Ʀr�j�p�A�Ynumber2�j��number1�^��number2�A�p��h�^��number1�C
int ShopUI::CompareLength(int number1, int number2)
{
	if (number1 < number2)
	{
		return number2;
	}
	return number1;
}
/*���o�Ҧ���A��Ƥ��A�W�١B����̪����r��A
�H�����ק@����X�ƪ��̾ڡC*/
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
//��ܩҦ���A�A�ƪ����X�C
void ShopUI::DisplayClothes(Shop& shop1, int maxLength[3])
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
	cout << endl;
}
//�p��Ӱө�����A�ƶq�C
int ShopUI::CountClothes(Shop& shop1)
{
	vector<Cloth*>* clothes;
	clothes = shop1.GetClothes();
	return clothes->size();
}
//�s�W�@���A�C
void ShopUI::InputCloth(Shop& shop1, int Id)
{
	string name, description;
	double price;
	cout << "�п�J��A�W��: ";
	getline(cin, name);
	cout << "�п�J��A�y�z: ";
	getline(cin, description);
	while (1)
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
			shop1.CreateNewCloth(name, description, price, Id);
			cout << endl;
			break;
		}
	}

}
//�}�l�A�����t�ΡC
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
			cout << endl;
			break;
		}
		else if ((!cin || cin.gcount() != 1) || (instruction > 3))
		{
			cout << "�п�J���T�ﶵ: ";
			error = 1;
		}
	}
}
