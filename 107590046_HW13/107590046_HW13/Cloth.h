#ifndef CLOTH_H
#define CLOTH_H
#include <iostream>
#include <cstdlib>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
#include <fstream>
#include <iomanip>
class Cloth {
public:
	Cloth(string name, string description, double price, int Id);
	string GetName();
	string GetDescription();
	virtual double GetPrice();
	void SetId(int Id);
	int GetId();
private:
	string _name;
	string _description;
	double _price;
	int _Id;
};
#endif
