#ifndef MALLUI_H
#define MALLUI_H
#include "Mall.h"
class MallUI
{
public:
	MallUI();
	void start(Mall& mall);
private:
	Mall _mall;
	void DisplayShops(Mall mall);
	void LoadClothesFile(Mall& mall);
	string CatchShopName(string input1);
	void FileDataSplit(string input1, Mall& mall, int Id);
};
#endif

