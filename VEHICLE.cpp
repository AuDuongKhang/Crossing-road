#include "VEHICLE.h"

int VEHICLE::GetXmin() {
	return this->x_min;
}

int VEHICLE::GetXmax() {
	return this->x_max;
}

void VEHICLE::Left() {
	x_min -= step;
	x_max -= step;
}

void VEHICLE::Right() {
	x_min += step;
	x_max += step;
}

void VEHICLE::Move() {
	if (this->state) {
		if (this->direction) {
			Right();
		}
		else
			Left();
	}
}

int VEHICLE::DistanceToVehicle(VEHICLE *p) {
	if (direction)
		return p->x_min - x_max;
	else
		return x_min - p->x_max;
}

void VEHICLE::Stop() {
	state = false;
}

void VEHICLE::Run() {
	state = true;
}

int VEHICLE::DistanceToTrafficLight(TRAFFIC_LIGHT tf) {
	if (direction)
		return tf.GetX() - x_max;
	else
		return x_min - tf.GetX() - 1;
}

ostream& operator<<(ostream& ou, const VEHICLE& p) {
	ou << p.x_min << " " << p.x_max << " " << p.y << " " << p.width << " " << p.state << " " << p.direction << " " << p.step << " " << p.remove.length();
	return ou;
}