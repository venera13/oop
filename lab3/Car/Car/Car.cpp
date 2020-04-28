#include "Car.h"

extern const map<Gear, pair<int, int>> SPEED_RANGES = {
	{ Gear::Reverse, { 0, 20 } },
	{ Gear::Neutral, { 0, 150 } },
	{ Gear::First, { 0, 30 } },
	{ Gear::Second, { 20, 50 } },
	{ Gear::Third, { 30, 60 } },
	{ Gear::Fourth, { 40, 90 } },
	{ Gear::Fifth, { 50, 150 } },
};

bool IsSpeedInGearRange(Gear const& gear, int const& speed)
{
	for (auto& speedRange : SPEED_RANGES)
	{
		if (gear == Gear::Neutral)
		{
			return true;
		}
		else if (speedRange.first == gear && (speed >= speedRange.second.first && speed <= speedRange.second.second))
		{
			return true;
		}
	}
	return false;
}

bool CCar::TurnOnEngine()
{
	if (!m_isEngineTurnOn)
	{
		m_isEngineTurnOn = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_isEngineTurnOn && m_speed == 0 && m_gear == Gear::Neutral)
	{
		m_isEngineTurnOn = false;
		return true;
	}
	return false;
}

void CCar::SetDirection(Gear const& gear)
{
	if (((m_gear == Gear::Reverse && gear == Gear::Neutral) || (m_gear == Gear::Neutral && gear == Gear::Reverse)) && m_speed != 0)
	{
		m_direction = Direction::Back;
	}
	else if (m_speed == 0)
	{
		m_direction = Direction::Stop;
	}
	else
	{
		m_direction = Direction::Forward;
	}
}

bool CCar::SetGear(Gear gear)
{
	if (!m_isEngineTurnOn)
	{
		if (gear == Gear::Neutral)
		{
			m_gear = gear;
			SetDirection(gear);
			return true;
		}
		else
		{
			return false;
		}
	}

	if (IsSpeedInGearRange(gear, m_speed) || gear == m_gear)
	{
		if (gear == Gear::Reverse && m_speed != 0)
		{
			return false;
		}
		if (gear == Gear::First && m_gear == Gear::Reverse && m_speed != 0)
		{
			return false;
		}
		if (gear == Gear::First && m_gear == Gear::Neutral && m_direction == Direction::Back)
		{
			return false;
		}
		SetDirection(gear);
		m_gear = gear;
		return true;
	}
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (m_gear == Gear::Neutral && m_isEngineTurnOn)
	{
		if (speed <= m_speed)
		{
			m_speed = speed;
			SetDirection();
			return true;
		}
		return false;
	}
	if (IsSpeedInGearRange(m_gear, speed) && m_isEngineTurnOn)
	{
		m_speed = speed;
		SetDirection();
		return true;
	}
	return false;
}

Gear CCar::GetGear()
{
	return m_gear;
}

int CCar::GetSpeed()
{
	return m_speed;
}

Direction CCar::GetDirection()
{
	return m_direction;
}

bool CCar::CheckIsEngineTurnOn()
{
	return m_isEngineTurnOn;
}
