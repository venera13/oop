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

string GetStringGear(Gear const& gear)
{
	switch (gear)
	{
	case Gear::Reverse:
		return "reverse";
	case Gear::Neutral:
		return "neutral";
	case Gear::First:
		return "first";
	case Gear::Second:
		return "second";
	case Gear::Third:
		return "third";
	case Gear::Fourth:
		return "fourth";
	case Gear::Fifth:
		return "fifth";
	default:
		return "unknown gear";
	}
}

string GetStringDirection(Direction const& direction)
{
	switch (direction)
	{
	case Direction::Back:
		return "back";
	case Direction::Forward:
		return "forward";
	case Direction::Stop:
		return "stop";
	default:
		return "unknown direction";
	}
}

string GetEngineStatus(bool const& engineStatus)
{
	if (engineStatus)
	{
		return "On";
	}
	return "Off";
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

void CCarDriving::GetInfo()
{
	cout << "  Engine is " << GetEngineStatus(m_car.CheckIsEngineTurnOn()) << endl;
	cout << "  Direction " << GetStringDirection(m_car.GetDirection()) << endl;
	cout << "  Speed " << m_car.GetSpeed() << endl;
	cout << "  Gear " << GetStringGear(m_car.GetGear()) << endl;
}

void CCarDriving::DoCommand(string const& commandLine)
{
	vector<string> command;
	boost::split(command, commandLine, is_any_of(" "), token_compress_on);

	if (command[0] == "EngineOn" && command.size() == 1)
	{
		TurnOnEngine();
	}
	else if (command[0] == "EngineOff" && command.size() == 1)
	{
		TurnOffEngine();
	}
	else if (command[0] == "SetGear" && command.size() == 2)
	{
		SetGear(stoi(command[1]));
	}
	else if (command[0] == "SetSpeed" && command.size() == 2)
	{
		SetSpeed(stoi(command[1]));
	}
	else if (command[0] == "GetInfo" && command.size() == 1)
	{
		GetInfo();
	}
	else
	{
		cout << "Unknow command" << endl; 
	}
}
