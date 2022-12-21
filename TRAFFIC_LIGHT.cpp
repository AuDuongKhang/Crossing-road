#include "TRAFFIC_LIGHT.h"

int TRAFFIC_LIGHT::GetX() {
	return x;
}

int TRAFFIC_LIGHT::GetY() {
	return y;
}

bool TRAFFIC_LIGHT::GetLightColor() {
	return light_color;
}

void TRAFFIC_LIGHT::CountDown() {
	if (time == 0) {
		light_color = !light_color;            // tín hiệu đèn mới sẽ ngược lại với nó
		time = (light_color ? green_light_time : red_light_time);       // thời gian sáng tương ứng với tín hiệu đèn
	}
	time -= 1;           // đếm ngược biến đếm
}

void TRAFFIC_LIGHT::Print() {
	gotoXY(x, y);
	if (light_color) {
		SetBackGroundColor((int)COLOR::LIGHT_GREEN); cout << "  ";
	}
	else {
		SetBackGroundColor((int)COLOR::RED);  cout << "  ";
	}
	SetBackGroundColor(BACKGROUND_COLOR);
}

ostream& operator<<(ostream& ou, const TRAFFIC_LIGHT& p) {
	ou << p.x << " " << p.y << " " << p.red_light_time << " " << p.green_light_time << " " << p.light_color << " " << p.time;
	return ou;
}

istream& operator>>(istream& in, TRAFFIC_LIGHT& p) {
	in >> p.x >> p.y >> p.red_light_time >> p.green_light_time >> p.light_color >> p.time;
	return in;
}