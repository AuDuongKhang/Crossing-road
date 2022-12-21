#include "CAR.h"

void CAR::Print() {
	for (int i = 0; i < 4; i++) {
		gotoXY(x_min + space[i], y + i);
		cout << shape[i];
	}
}

void CAR::Print(int xMIN, int xMAX) {
	if(state)
		RemoveTail(xMIN, xMAX);                  // xóa phần đuôi
	string temp = "";
	for (int i = 0; i < 4; i++) {
		int index;
		temp = shape[i];
		if (x_min + space[i] < xMIN) {           // khi xe đang vào làn đường theo hướng phải, ra khỏi làn đường theo hướng trái
			index = shape[i].length() - (x_max - xMIN) - 1 + space[i];         // tính số ký tự cần lấy từ mỗi chuỗi
			if (index >= shape[i].length())               // index không hợp lệ
				temp = "";
			else
				temp = shape[i].substr(index);            // xuất chuỗi cần thiết khi xe đang vào làn đường
			gotoXY(xMIN, y + i);                          // đi đến điểm đầu làn đường
		}
		else if (x_max - space[i] > xMAX) {      // khi xe đang vào làn đường từ hướng trái, ra khỏi làn đường từ hướng phải
			index = xMAX - x_min - space[i] + 1;          // tính số ký tự cần lấy từ mỗi chuỗi
			if (index > 0)                               
				temp = shape[i].substr(0, index);           
			else
				temp = "";                                // index không hợp lệ
			gotoXY(x_min + space[i], y + i);              // đi đến điểm đều xe ô tô
		}
		else
			gotoXY(x_min + space[i], y + i);             // khi xe hoàn toàn trong làn đường
		cout << temp;                            // xuất phần tử chuỗi
	}
}

bool CAR::HitPerson(PERSON p) {
	int x_p = p.GetX(), y_p = p.GetY();
	int x_p_max = x_p + 6;
	if (y_p == y + 3) {                                   // xét các trường hợp vị trí người so với xe
		if (x_p <= x_max - 1 && x_p_max >= x_min + 1)
			return true;
	}
	else if (y_p == y + 2 || y_p == y + 1) {
		if(x_p_max >= x_min && x_p <= x_max)
			return true;
	}
	else if (y_p == y) {
		if(x_p_max >= x_min + 1 && x_p <= x_max - 1)
			return true;
	}
	else if (y_p == y - 1) {
		if (x_p <= x_max - 2 && x_p_max >= x_min + 2)
			return true;
	}
	else if (y_p == y - 2) {
		if (x_p <= x_max - 4 && x_p_max >= x_min + 4)
			return true;
	}
	return false;
}

void CAR::RemoveTail(int xMIN, int xMAX) {
	for (int i = 0; i < 4; i++) {
		if (direction) {
			if (x_min + space[i] > xMIN && x_min + space[i] <= xMAX + 1) {
				gotoXY(x_min - step + space[i], i + y);
				cout << remove;
			}
		}
		else {
			if (x_max - space[i] >= xMIN - 1 && x_max - space[i] < xMAX) {
				gotoXY(x_max + 1 - space[i], i + y);
				cout << remove;
			}
		}
	}
}

istream& operator>>(istream& in, CAR& p) {
	int t;
	in >> p.x_min >> p.x_max >> p.y >> p.width >> p.state >> p.direction >> p.step >> t;
	for (int i = 0; i < t; i++)
		p.remove += " ";
	if (!p.direction)
		p.shape[1] = "_|  ____\\";
	return in;
}