#include<iostream>
#include"table.h"
#include"game.h"
using namespace std;

int main()
{
	game newGame;
	//δ��¼�˺���ѭ����ʾ���˵�
	int choice;
	while ((choice = newGame.showMenu()) == 2);
	//�Ѿ��ɹ���¼
	if (choice == 1)
	{
		newGame.levelMenu();
	}
}