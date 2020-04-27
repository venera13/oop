#pragma once
#include "stdafx.h"

enum class Gear
{
	Reverse,
	Neutral,
	First,
	Second,
	Third,
	Fourth,
	Fifth
};

enum class Direction
{
	Back,
	Stop,
	Forward
};

extern const map<Gear, pair<int, int>> SPEED_RANGES;

class CCar
{
public:
	CCar() = default;
	~CCar() = default;

	bool TurnOnEngine();
	bool TurnOffEngine();
	void SetDirection(Gear const& gear = Gear::Neutral);
	bool SetGear(Gear gear);
	bool SetSpeed(int speed);

	Gear GetGear();
	int GetSpeed();
	Direction GetDirection();
	bool CheckIsEngineTurnOn();

private:
	bool m_isEngineTurnOn = false;
	Gear m_gear = Gear::Neutral;
	int m_speed = 0;
	Direction m_direction = Direction::Stop;
};