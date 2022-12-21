#include "ELEPHANT.h"

void ELEPHANT::Print() {
	for (int i = 0; i < 5; i++) {
		gotoXY(x_min + (direction ? space[i].first : space[i].second), y + i);
		cout << shape[i];
	}
}

void ELEPHANT::Print(int xMIN, int xMAX) {
	string temp = "";
	RemoveTail(xMIN, xMAX);
	for (int i = 0; i < 5; i++) {
		int index;
		int sp_true = (direction ? space[i].first : space[i].second);                 
		int sp_false = (!direction ? space[i].first : space[i].second);
		temp = shape[i];
		if (x_min + sp_true < xMIN) {                             // con voi đang vào làn đường theo hướng trái, ra khỏi làn đường theo hướng phải
			index = shape[i].length() - (x_max - xMIN) - 1 + sp_false;          // tính số ký tự cần lấy trong chuỗi 
			if (index >= shape[i].length())                          // index không hợp lệ
				temp = "";
			else
				temp = shape[i].substr(index);
			gotoXY(xMIN, y + i);                                 // đi đến điểm đầu làn đường
		}
		else if (x_max - sp_false > xMAX) {                      // con voi đang vào làn đường theo hướng phải, ra khỏi làn đường theo hướng trái
			index = xMAX - x_min - sp_true + 1;                  // tính số ký tự cần lấy từ mỗi chuỗi
			if (index > 0)         
				temp = shape[i].substr(0, index);
			else
				temp = "";                                       // index không hợp lệ
			gotoXY(x_min + sp_true, y + i);                      // đi đến điểm đầu con voi
		}
		else
			gotoXY(x_min + sp_true, y + i);                     // khi xe hoàn toàn trong làn đường
		cout << temp;                                       // xuất phần tử chuỗi
	}
}

void ELEPHANT::RemoveTail(int xMIN, int xMAX) {
	for (int i = 0; i < 5; i++) {
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

bool ELEPHANT::HitPerson(PERSON p) {
	int x_p = p.GetX(), y_p = p.GetY();
	int x_p_max = x_p + 6;
	if (y_p == y + 4 || y_p == y + 3 || y_p == y + 2 || y_p == y + 1) {     // xét các trường hợp vị trí người so với voi
		if (x_p_max > x_min && x_p < x_max)
			return true;
	}
	else if (y_p == y) {
		if (x_p + 2 < x_max && x_p_max - 2 > x_min)
			return true;
	}
	else if (y_p == y - 1) {
		if (x_p + 3 < x_max && x_p_max - 3 > x_min)
			return true;
	}
	else if (y_p == y - 2) {
		if (x_p + 2 <= x_max - 4 && x_p_max - 2 >= x_min + 4)
			return true;
	}
	return false; 
}

istream& operator>>(istream& in, ELEPHANT& p) {
	int t;
	in >> p.x_min >> p.x_max >> p.y >> p.width >> p.direction >> p.step >> t;
	for (int i = 0; i < t; i++)
		p.remove += " ";
	if (!p.direction) {
		p.shape[1] = "_/ 0 }     \\";
		p.shape[2] = "/_     }     }-.";
		p.shape[3] = "// \\_   __   /  |";
		p.shape[4] = "\"    |_|  |_|   '";
	}
	return in;
}