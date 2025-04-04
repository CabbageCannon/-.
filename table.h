#pragma once
#include<vector>
#include"cell.h"
#include<cmath>
#include<fstream>
#include<string>
using namespace std;
class table
{
public:
	table(int);
	//��ʾ����
	void showTable();
	//����������ļ�������
	void recFile(string);
	//�����������ͼ��
	void addSymbol();
	//�����ж������Ƿ��Ѿ�ʤ����
	bool isWin() const;
private:
	//����ÿ�������е�ͼ��
	vector<vector<cell*>>cells;
	//������ʾ��Ϣ
	vector<vector<string>>tips;
	//������ʾ��Ϣ
	void getTips();
	//�������־����Ŀ
	void initSymbolNum();
	//���¸���־����Ŀ
	void updateSymbolNum();
	vector<int>symbolNum;
	int sideWidth;
	int sideLength;
	vector<vector<symbol>>answer;
	symbol changeIntToSymbol(int);
};

