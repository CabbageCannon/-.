#include "cell.h"

cell::cell(symbol cellSymbol)
	:mySymbol(cellSymbol)
{
	//ÿ������һ��ʼ��δ����ͼ��
	IsEmpty = true;
}

void cell::changePlayerSymbol(symbol playerSymbol)
{
	this->playerSymbol = playerSymbol;
	this->changeIsEmpty(false);
}

symbol cell::getMySymbol() const
{
	return this->mySymbol;
}

symbol cell::getPlayerSymbol() const
{
	return this->playerSymbol;
}

bool cell::isEmpty() const
{
	return this->IsEmpty;
}

void cell::changeIsEmpty(bool is)
{
	this->IsEmpty = is;
}
