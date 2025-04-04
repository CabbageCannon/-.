#include<iostream>
#include"table.h"
#include"game.h"
using namespace std;

int main()
{
	game newGame;
	//未登录账号则循环显示主菜单
	int choice;
	while ((choice = newGame.showMenu()) == 2);
	//已经成功登录
	if (choice == 1)
	{
		newGame.levelMenu();
	}
}