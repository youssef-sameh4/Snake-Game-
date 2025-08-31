#pragma once
#include <iostream>
#include<ctime>
#include"clsMap.h"
using namespace std;
class clsFood
{
private:
	int _Foodx, _Foody;
	clsMap map1;
public:
	void SetFoodX(int Foodx)
	{
		_Foodx = Foodx;
	}
	int GetFoodX()
	{
		return _Foodx;
	}
	__declspec(property(get = GetFoodX, put = SetFoodx)) int Foodx;

	void SetFoodY(int Foody)
	{
		_Foody = Foody;
	}
	int GetFoodY()
	{
		return _Foody;
	}
	__declspec(property(get = GetFoodY, put = SetFoodY)) int Foody;
	void Generate_Food(int Width,int Height)
	{
		srand(time(NULL));
		_Foodx = rand() % (Width - 2) + 1;
		_Foody = rand() % (Height - 2) + 1;

	}


};

