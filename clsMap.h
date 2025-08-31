#pragma once
#include <iostream>
using namespace std;
class clsMap
{
private:
	int _width, _height;
public:
	void SetWidth(int width)
	{
		_width = width;
	}
	int GetWidth()
	{
		return _width;
	}
	__declspec(property(get = GetWidth, put = SetWidth)) int Width;

	void SetHeight(int height)
	{
		_height = height;
	}
	int GetHeight()
	{
		return _height;
	}
	__declspec(property(get = GetHeight, put = SetHeight)) int Height;
};

