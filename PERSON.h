#pragma once
#include "CONSOLE.h"

/*
hỉnh ảnh in khi an toàn và bị tông
                (0.0)       (>.<) 
               /| _ |\     /| _ |\
                 ^ ^         ^ ^
*/

class PERSON
{
	int x{}, y{};                            // tọa độ con người
	bool state{};                            // trạng thái con người(true - an toàn, false - bị tông)
	string shape[3] = {  "(O.O)", 
		                "/| _ |\\", 
		                  "^ ^" };           // chuỗi chứa hình ảnh con người khi an toàn
public:
	PERSON() {};
	PERSON(int X, int Y) : x(X), y(Y) {
		state = true;
	};
	int GetX();                 // trả về tọa độ x
	int GetY();                 // trả về tọa độ y
	bool GetState();            // trả về trạng thái
	void GoUp();                // đi lên
	void GoDown();              // đi xuống
	void TurnLeft();            // sang trái
	void TurnRight();           // sang phải
	void Print();               // in hình ảnh
	void Remove();              // xóa hình ảnh
	void getHit();              // bị tông
	void Finish();              // hoàn thành
	friend ostream& operator<<(ostream& ou, const PERSON& p);   // xuất dữ liệu con người
	friend istream& operator>>(istream& in, PERSON& p);         // nhập dữ liệu con người
};