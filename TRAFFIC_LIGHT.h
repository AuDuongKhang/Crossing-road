#pragma once
#include "CONSOLE.h"

class TRAFFIC_LIGHT              // lớp đối tượng TRAFFIC_LIGHT
{
	int x{}, y{};                               // vị trí [x,y] của đèn giao thông
	int red_light_time{}, green_light_time{};   // thời gian đèn đỏ, đèn xanh
	bool light_color{};                         // tín hiệu đèn(true - đèn xanh, false - đèn đỏ)
	int time{};                                 // biến đếm thời gian
public:
	TRAFFIC_LIGHT() {};
	TRAFFIC_LIGHT(int X, int Y, int rl, int gl, bool lc)
		: x(X), y(Y), red_light_time(rl), green_light_time(gl), light_color(lc) {
		time = (light_color ? green_light_time : red_light_time);
	};
	~TRAFFIC_LIGHT() {};
	int GetX();                       // lấy tọa độ x
	int GetY();                       // lấy tọa độ y
	bool GetLightColor();             // lấy giá trị tín hiệu đèn
	void CountDown();                 // đếm ngược
	void Print();                     // in hình ảnh đèn
	friend ostream& operator<<(ostream& ou, const TRAFFIC_LIGHT &p);      // xuất dữ liệu đèn
	friend istream& operator>>(istream& in, TRAFFIC_LIGHT& p);            // nhập dữ liệu đèn
};