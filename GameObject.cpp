#include "GameObject.h"
#include <stdlib.h>

using namespace std;

void GameObject::setSymbol(char s)
{
	symbol = s;
}

char GameObject::getSymbol()
{
	return symbol;
}

void UserPlayer::setLocation(int x_, int y_)
{
	x = x_;
	y = y_;
}

int UserPlayer::getX()
{
	return x;
}

int UserPlayer::getY()
{
	return y;
}
