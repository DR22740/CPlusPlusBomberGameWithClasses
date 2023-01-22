#pragma once

class GameObject {
protected:
	char symbol = 'X';
public:
	void setSymbol(char s);
	char getSymbol();
};

class UserPlayer : public GameObject {

private:
	int x;
	int y;
public:
	void setLocation(int x_, int y_);
	int getX();
	int getY();
};