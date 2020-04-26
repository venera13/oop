#include "CarDriving.h"

Gear IntToGear(int const& gear) 
{
	switch (gear)
	{
	case -1:
		return Gear::Reverse;
	case 0:
		return Gear::Neutral;
	case 1:
		return Gear::First;
	case 2:
		return Gear::Second;
	case 3:
		return Gear::Third;
	case 4:
		return Gear::Fourth;
	case 5:
		return Gear::Fifth;
	default:
		throw logic_error("unknow gear");
	}
}

CCarDriving::CCarDriving(CCar& car)
	: m_car(car)
{
}

bool CCarDriving::TurnOnEngine()
{
	auto result = m_car.TurnOnEngine();
	if (result)
	{
		cout << "engine was turned on" << endl;
	}
	else
	{
		cout << "engine was already on" << endl;
	}
	return result;
}

bool CCarDriving::TurnOffEngine()
{
	auto result = m_car.TurnOffEngine();
	if (result)
	{
		cout << "engine was turned off" << endl;
	}
	else
	{
		cout << "engine was not turned off" << endl;
	}
	return result;
}

bool CCarDriving::SetSpeed(int speed)
{
	auto result = m_car.SetSpeed(speed);
	if (result)
	{
		cout << "speed change to " << speed << endl;
	}
	else
	{
		cout << "speed didn't change" << endl;
	}
	return result;
}

bool CCarDriving::SetGear(int gear)
{
	try
	{
		auto result = m_car.SetGear(IntToGear(gear));
		if (result)
		{
			cout << "gear change to " << gear << endl;
		}
		else
		{
			cout << "gear didn't change" << endl;
		}
	}
	catch (logic_error const& e)
	{
		cout << e.what() << endl;
	}
	
	return false;
}

void CCarDriving::DoCommand(string const& command)
{
	if (command == "EngineOn")
	{
		TurnOnEngine();
	}
	else if (command == "EngineOff")
	{
		TurnOffEngine();
	}
	
}
