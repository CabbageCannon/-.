#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<cstring>
#include"table.h"
#include"manager.h"
using namespace std;
//struct user
//{
//	char account[11];
//	char password[11];
//};
class game
{
public:
	game();
	//~game();
	//展示首页菜单
	int showMenu();
	//展示显示关卡菜单
	void levelMenu() const;
	//加载文件内容，每次启动时进行
	void loadFile();
	//登录账号
	void loginUser();
	//注册账号
	void addUser();
private:
	void chooseLevel() const;
	map<string, user>users;
};

