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
	//չʾ��ҳ�˵�
	int showMenu();
	//չʾ��ʾ�ؿ��˵�
	void levelMenu() const;
	//�����ļ����ݣ�ÿ������ʱ����
	void loadFile();
	//��¼�˺�
	void loginUser();
	//ע���˺�
	void addUser();
private:
	void chooseLevel() const;
	map<string, user>users;
};

