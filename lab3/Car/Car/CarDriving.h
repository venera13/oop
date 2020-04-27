#pragma once
#include "stdafx.h"
#include "Car.h"

class CCarDriving
{
public:
	CCarDriving(CCar& car);
	~CCarDriving() = default;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetSpeed(int speed);
	bool SetGear(int gear);
	void GetInfo();

	void DoCommand(string const& command);

private:
	CCar& m_car;
};
