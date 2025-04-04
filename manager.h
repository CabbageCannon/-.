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
	//��ʾ�����û���Ϣ
	void showUser() const;
	//����Ƿ��ǵ�һ�ε�¼����Ա�˺�
	bool isFileEmpty() const;
	//���ε�¼����Ա�˺�ʱ����������
	void setPassword();
	//���������¼�˺�
	void login();
	//��ʾ����Ա�˵�
	void menu();
	void loadUser();
private:
	map<string, user>users;
	string password;
};

