#pragma once
class clsPlayer
{
	int _Score;
	bool _Lose;
public:
	void SetScore(int Score)
	{
		_Score = Score;
	}
	int GetScore()
	{
		return _Score;
	}
	__declspec(property(get = GetScore, put = SetScore)) int Score;

	void SetLose(bool Lose)
	{
		_Lose = Lose;
	}
	bool GetLose()
	{
		return _Lose;
	}
	__declspec(property(get = GetLose, put = SetLose)) bool Lose;

};

