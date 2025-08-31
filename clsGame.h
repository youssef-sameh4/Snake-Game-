#pragma once
#include<iostream>
#include"clsMap.h"
#include"clsPlayer.h"
#include"clsSnake.h"
#include"clsFood.h"
#include<conio.h>
#include<Windows.h>
class clsGame
{
private:
	int _speed;
	int _Tail_X[50], _Tail_Y[50];
	static enum Direction
	{
		Top,Down,Left,Right
	};
	static enum Level
	{
		easy = 1, medium = 2, hard = 3
	};
	Level elevel;
	Direction Dir;

	clsFood food;
	clsMap map;
	clsPlayer player;
	clsSnake snake;
	void setColor(int color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
	void _Shift_Right(int arr[], int size)
	{
		for (int i = size - 2;i >= 0;i--)
		{
			arr[i + 1] = arr[i];
		}
	}
	void _Setup()
	{
		map.Height = 20;
		map.Width = 40;
		food.Generate_Food(map.Width, map.Height);
		///////
		snake.HeadX = map.Width/2;
		snake.Heady = map.Height/2;
		snake.Tail_N = 0;
		////////
		player.Lose = false;
		player.Score = 0;

	}
	void _Drow()
	{
		system("cls");
		for (int i = 0; i < map.Height; i++)
		{
			for (int j = 0; j < map.Width; j++)
			{
				
				if (i == 0 || i == map.Height - 1 || j == 0 || j == map.Width - 1)
				{
					setColor(15);
					cout << "*";
				}
			
				else if (i == snake.Heady && j == snake.HeadX)
				{
					setColor(14);
					cout << "O";
				}
				
				else if (i == food.Foody && j == food.Foodx)
				{
					setColor(12); 
					cout << "$";
				}
			
				else
				{
					bool printed = false;
					for (int z = 0; z < snake.Tail_N; z++)
					{
						if (_Tail_Y[z] == i && _Tail_X[z] == j)
						{
							setColor(10); 
							cout << "o";
							printed = true;
							break;
						}
					}
					if (!printed)
					{
						cout << " ";
					}
				}
			}
			cout << endl;
		}

		setColor(15);
		cout << "Player Score : " << player.Score << endl;
	}
	void _hideCursor() {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}
	void _Input()
	{
		if (_kbhit())
		{
			char c = _getch();
			switch (c)
			{
			case 'w':
			{
			  Dir = Top; 
			  break;
			}
			case 's':
			{
				Dir = Down;
				break;
			}
			case 'd':
			{
				Dir = Right;
				break;
			}
			case 'a':
			{
				Dir = Left;
				break;
			}
			case 'x':
			{
				exit(0);
				break;
			}
			}
		}
	}
	void _Move()
	{
		_Shift_Right(_Tail_X, snake.Tail_N);
		_Shift_Right(_Tail_Y, snake.Tail_N);
		_Tail_X[0] = snake.HeadX;
		_Tail_Y[0] = snake.Heady;

		switch (Dir)
		{
		case Top:
		{
			snake.Heady--;
			break;
		}
		case Down:
		{
			snake.Heady++;
			break;
		}
		case Right:
		{
			snake.HeadX++;
			break;
		}
		case Left:
		{
			snake.HeadX--;
			break;
		}
		}
		if (snake.Heady >= map.Height || snake.Heady <= 0 || snake.HeadX >= map.Width || snake.HeadX <= 0)
		{
			player.Lose = true;
		}
		for (int i = 0; i < snake.Tail_N; i++)
		{
			if (_Tail_X[i] == snake.HeadX && _Tail_Y[i] == snake.Heady)
			{
				player.Lose = true;
			}
		}
		if (snake.HeadX == food.Foodx && snake.Heady == food.Foody)
		{
			food.Generate_Food(map.Width, map.Height);
			player.Score+=1;
			snake.Tail_N++;
		}
	}
	void _gameOver(int score) {
		system("cls");
		setColor(4); 
		cout << "\n\n\t\t[ GAME OVER ]\n";
		setColor(7); 
		cout << "\t\tPlayer Score : " << score << endl;

		cout << "\n\t\tPress R to Restart or Q to Quit\n";

		char choice;
		do {
			choice = _getch();
			if (choice == 'r' || choice == 'R') {
				system("cls");
				cout << "\n\tRestarting Game...\n";
				_StartGame();
				break;
			}
			else if (choice == 'q' || choice == 'Q') {
				cout << "\n\tThanks for playing!\n";
				exit(0);
			}
		} while (true);
	}

	void SelectLevel()
	{
		short level;
		system("cls");
		setColor(11);
		cout << "\n\n\t\t===  Choose Level  ===\n\n";
		setColor(7);
		cout << "\t1. Easy\n";
		cout << "\t2. Medium\n";
		cout << "\t3. Hard\n\n";
		cout << "Choose Level(1-3):\n";
		
		cin >> level;

		switch (level)
		{
			
		case  easy : 
			_speed = 200;
			break;
		case medium: 
			_speed = 100;
			break;
		case hard: 
			_speed = 50;
			break;
		default:
			cout << "Invalid choice!.\n";
			break;
		}
	}


	void _StartGame()
	{
		_Setup();
		SelectLevel();
		while (!player.Lose)
		{
			_hideCursor();
			_Drow();
			_Input();
			_Move();
			Sleep(_speed);
		}
		_gameOver(player.Score);
	}
	
public:
	
	void PrintMainMenueGame()
	{
		int choice = 0;

		while (true) {
			system("cls");
			setColor(11);
			cout << "\n\n\t\t=== WELCOME TO SNAKE GAME ===\n\n";
			setColor(7);
			 
			cout << "\t1. Start Game\n";
			cout << "\t2. Instructions\n";
			cout << "\t3. Exit\n\n";

			cout << "\tEnter choice (1-3): ";
			cin >> choice;

			if (choice == 1) {
				_StartGame();

				cout << "\n\tStarting Game...\n";
				_getch();
				break;
			}
			else if (choice == 2) {
				system("cls");
				cout << "\n\t=== Instructions ===\n";
				cout << "\tUse W A S D to move the snake.\n";
				cout << "\tEat food (O) to grow your tail and increase score.\n";
				cout << "\tAvoid hitting the walls or yourself!\n";
				cout << "\n\tPress any key to go back...\n";
				_getch();
			}
			else if (choice == 3) {
				cout << "\n\tThanks for playing!\n";
				exit(0);
			}
			else {
				cout << "\n\tInvalid choice, try again.\n";
				_getch();
			}
		}
	}
};

