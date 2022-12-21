#include "TRUCK.h"

void TRUCK::Print() {
	for (int i = 0; i < 4; i++) {
		gotoXY(x_min + (direction ? space[i].first : space[i].second), y + i);
		cout << shape[i];
	}
}

void TRUCK::Print(int xMIN, int xMAX) {
	string temp = "";
	if (state)
		RemoveTail(xMIN, xMAX);
	for (int i = 0; i < 4; i++) {
		int index;
		int sp_true = (direction ? space[i].first : space[i].second);
		int sp_false = (!direction ? space[i].first : space[i].second);
		temp = shape[i];
		if (x_min + sp_true < xMIN) {
			index = shape[i].length() - (x_max - xMIN) - 1 + sp_false;
			if (index >= shape[i].length())
				temp = "";
			else
				temp = shape[i].substr(index);
			gotoXY(xMIN, y + i);
		}
		else if (x_max - sp_false > xMAX) {
			index = xMAX - x_min - sp_true + 1;
			if (index > 0)
				temp = shape[i].substr(0, index);
			else
				temp = "";
			gotoXY(x_min + sp_true, y + i);
		}
		else
			gotoXY(x_min + sp_true, y + i);
		cout << temp;
	}
}

void TRUCK::RemoveTail(int xMIN, int xMAX) {
	for (int i = 0; i < 4; i++) {
		if (direction) {
			if (x_min + space[i].first > xMIN && x_min + space[i].first <= xMAX + 1) {
				gotoXY(x_min - step + space[i].first, i + y);
				cout << remove;
			}
		}
		else {
			if (x_max - space[i].first >= xMIN - 1 && x_max - space[i].first < xMAX) {
				gotoXY(x_max + 1 - space[i].first, i + y);
				cout << remove;
			}
		}
	}
}

bool TRUCK::HitPerson(PERSON p) {
	int x_p = p.GetX(), y_p = p.GetY();
	int x_p_max = x_p + 6;
	if (y_p == y + 3) {
		if (x_p <= x_max - 1 && x_p_max >= x_min + 1)
			return true;
	}
	else if (y_p == y + 2 || y_p == y + 1) {
		if (x_p_max >= x_min && x_p <= x_max)
			return true;
	}
	else if (y_p == y) {
		if ((direction && (x_p_max >= x_min && x_p < x_max))
			|| (!direction && (x_p_max > x_min && x_p <= x_max)))
			return true;
	}
	else if (y_p == y - 1) {
		if ((direction && (x_p_max > x_min && x_p < x_max - 2))
			|| (!direction && (x_p_max > x_min + 2 && x_p <= x_max)))
			return true;
	}
	else if (y_p == y - 2) {
		if ((direction && (x_p_max - 2 >= x_min && x_p + 2 < x_max - 2))
			|| (!direction && (x_p_max - 2 > x_min + 2 && x_p + 2 <= x_max)))
			return true;
	}
	return false;
}

istream& operator>>(istream& in, TRUCK& p) {
	int t;
	in >> p.x_min >> p.x_max >> p.y >> p.width >> p.state >> p.direction >> p.step >> t;
	for (int i = 0; i < t; i++)
		p.remove += " ";
	if (!p.direction) {
		p.shape[0] = "____.===========-.";
		p.shape[1] = "_|[]  |  GROUP 10  |";
		p.shape[2] = "|      |            |";
		p.shape[3] = "'=(0)=='=(0)====(0)='";
	}
	return in;
}