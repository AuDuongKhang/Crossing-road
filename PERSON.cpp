#include "PERSON.h"

int PERSON::GetX() {
	return x;
}

int PERSON::GetY() {
	return y;
}

bool PERSON::GetState() {
	return state;
}

void PERSON::GoUp() {
	--y;
}

void PERSON::GoDown() {
	++y;
}

void PERSON::TurnLeft() {
	--x;
}

void PERSON::TurnRight() {
	++x;
}

void PERSON::Print() {
	gotoXY(x + 1, y); cout << shape[0];
	gotoXY(x, y + 1); cout << shape[1];
	gotoXY(x + 2, y + 2); cout << shape[2];
}

void PERSON::Remove() {
	for (int i = 0; i < 3; i++) {
		gotoXY(x, y + i);
		cout << "       ";
	}
}

void PERSON::getHit() {
	state = false;
	// đối hình ảnh khi bị tông
	shape[0] = "(>.<)";
}

void PERSON::Finish() {
	state = false;
}

ostream& operator<<(ostream& ou, const PERSON& p) {
	ou << p.x << " " << p.y << " " << p.state;
	return ou;
}

istream& operator>>(istream& in, PERSON& p) {
	in >> p.x >> p.y >> p.state;
	return in;
}