#include "AMBULANCE.h"

void AMBULANCE::Print() {
	return;
}

void AMBULANCE::Print(int xMIN, int xMAX) {
	RemoveTail(xMIN, xMAX);
	string temp = "";
	for (int i = 0; i < 5; i++) {
		temp = shape[i];
		if (x_min < xMIN) { 
			temp = shape[i].substr(AMBULANCE_WTDTH - (x_max - xMIN) - 1, x_max - xMIN + 1);
			gotoXY(xMIN, y + i);
		}
		else if (x_max > xMAX) {
			temp = shape[i].substr(0, xMAX - x_min + 1);
			gotoXY(x_min, y + i);
		}
		else
			gotoXY(x_min, y + i);
		cout << temp;
	}
}

void AMBULANCE::RemoveTail(int xMIN, int xMAX) {
	for (int i = 0; i < 5; i++) {
		if (x_min > xMIN && x_min <= xMAX + 1) {
			gotoXY(x_min - step, i + y);
			cout << remove;
		}
	}
}

bool AMBULANCE::HitPerson(PERSON p) {
	return false;
}