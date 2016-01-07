#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>

template<typename T>
struct menu_item
{
	char *text;
	void (T::*command)();
};

template<typename T>
class Menu
{
	bool Exit;
	T* t;
	COORD c;
	const menu_item<T> *list;
	HANDLE h;
	const unsigned int Nmenu;
public:
	enum keys{ ESC = 27, UP = 72, DOWN = 80, ENTER = 13 };
	Menu(unsigned int n, const menu_item<T> *list, T* t, COORD c = { 0, 0 });
	void MenuShow() const;
	void Menu<T>::SetExit(bool);
};


template<typename T>
Menu<T>::Menu(unsigned int n, const menu_item<T> *list, T* t, const COORD c) :
Exit(false),
Nmenu(n),
list(list),
c(c),
t(t)
{
	h = GetStdHandle(STD_OUTPUT_HANDLE);
}

template<typename T>
void Menu<T>::MenuShow() const
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(h, &csbi);
	int key, n = 0;
	do{
		SetConsoleCursorPosition(h, c);
		for (unsigned int i = 0; i < Nmenu; ++i)
		{
			if (i == n){
				SetConsoleTextAttribute(h, 0xA);
				std::cout << "# " << list[i].text << std::endl;
				SetConsoleTextAttribute(h, csbi.wAttributes);
			}
			else
				std::cout << "  " << list[i].text << "\n";
		}

		key = _getch();
		if (key == ENTER)
		{
			(t->*list[n].command)();
			if (Exit)
				break;
		}
		else if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case UP:
				n == 0 ? n = Nmenu - 1 : n--;
				break;
			case DOWN:
				n == Nmenu - 1 ? n = 0 : n++;
				break;
			}
		}
	} while (key != ESC);
}

template<typename T>
void Menu<T>::SetExit(bool e){
	Exit = e;
}