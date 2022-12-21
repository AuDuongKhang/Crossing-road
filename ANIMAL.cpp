#include "ANIMAL.h"

int ANIMAL::GetXmin() {
	return this->x_min;
}

int ANIMAL::GetXmax() {
	return this->x_max;
}

void ANIMAL::Left() {
	x_min -= step;
	x_max -= step;
}

void ANIMAL::Right() {
	x_min += step;
	x_max += step;
}

void ANIMAL::Move() {
	if (this->direction) {
		Right();
	}
	else
		Left();
}

ostream& operator<<(ostream& ou, const ANIMAL& p) {
	ou << p.x_min << " " << p.x_max << " " << p.y << " " << p.width << " " << p.direction << " " << p.step << " " << p.remove.length();
	return ou;
}