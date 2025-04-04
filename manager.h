#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<iomanip>
using namespace std;
struct user
{
	char account[11];
	char password[11];
};
class manager
{
public:
	manager();
	//显示所有用户信息
	void showUser() const;
	//检查是否是第一次登录管理员账号
	bool isFileEmpty() const;
	//初次登录管理员账号时可设置密码
	void setPassword();
	//输入密码登录账号
	void login();
	//显示管理员菜单
	void menu();
	void loadUser();
private:
	map<string, user>users;
	string password;
};

