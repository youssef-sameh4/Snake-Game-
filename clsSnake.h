#pragma once

class clsSnake
{
private:
	int _HeadX, _Heady, _Tail_N;
public:
	void SetHeadX(int HeadX)
	{
		_HeadX = HeadX;
	}
	int GetHeadX()
	{
		return _HeadX;
	}
	__declspec(property(get = GetHeadX, put = SetHeadX)) int HeadX;
	void SetHeady(int Heady)
	{
		_Heady = Heady;
	}
	int GetHeady()
	{
		return _Heady;
	}
	__declspec(property(get = GetHeady, put = SetHeady)) int Heady;

	void SetTail_N(int Tail_N)
	{
		_Tail_N = Tail_N;
	}
	int GetTail_N()
	{
		return _Tail_N;
	}
	__declspec(property(get = GetTail_N, put = SetTail_N)) int Tail_N;
};

