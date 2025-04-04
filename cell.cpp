#include "cell.h"

cell::cell(symbol cellSymbol)
	:mySymbol(cellSymbol)
{
	//每个格子一开始都未填入图案
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
