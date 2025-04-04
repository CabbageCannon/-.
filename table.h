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
	//显示棋盘
	void showTable();
	//接收问题的文件并处理
	void recFile(string);
	//用于玩家填入图案
	void addSymbol();
	//用于判断现在是否已经胜利了
	bool isWin() const;
private:
	//管理每个格子中的图案
	vector<vector<cell*>>cells;
	//管理提示信息
	vector<vector<string>>tips;
	//计算提示信息
	void getTips();
	//计算各标志的数目
	void initSymbolNum();
	//更新各标志的数目
	void updateSymbolNum();
	vector<int>symbolNum;
	int sideWidth;
	int sideLength;
	vector<vector<symbol>>answer;
	symbol changeIntToSymbol(int);
};

