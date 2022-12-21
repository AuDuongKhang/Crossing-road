#pragma once
#include "ANIMAL.h"
 
#define PIGTURTLE_WIDTH 22        // độ rộng rùa heo

/*
   _.------._  _/\/\_
  /   ====   \/   0 _|
 /   ======   \_____/              // hình ảnh in con rùa heo
<\__  _____  __/ 
   \\/    \\/         
*/

class PIGTURTLE : public ANIMAL                  // lớp  PIGTURTLE kế thừa lớp ANIMAL
{                                                     // các thuộc tính, phương thức tương tự như con voi
	string shape[5] = {"_.------._  _/\\/\\_",
	                   "/   ====   \\/   0 _|",             
		               "/   ======   \\_____/",
		               "<\\__  _____  __/",
		               "\\\\/    \\\\/"};
	pair<int, int> space[5] = { {3, 1}, {2, 0}, {1, 1}, {0, 6}, {3, 9} };
public:
	PIGTURTLE() {};
	PIGTURTLE(int Xmin, int Y, bool dir, int STEP = 1) : ANIMAL(Xmin, Y, dir, STEP) {
		this->width = PIGTURTLE_WIDTH;
		this->x_max = this->x_min + this->width - 1;
		if (!dir) {
			shape[0] = "_/\\/\\_  _.------._";
			shape[1] = "|_ 0   \\/   ====   \\";
			shape[2] = "\\_____/   ======   \\";
			shape[3] = "\\__  _____  __/>";
			shape[4] = "\\//    \\//";
		}
	}
	void Print();
	void Print(int xMIN, int xMAX);
	void RemoveTail(int xMIN, int xMAX);
	bool HitPerson(PERSON p);
	friend istream& operator>>(istream& in, PIGTURTLE& p);
};

