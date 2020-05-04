#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../Car/CarDriving.h"

SCENARIO("Engine on")
{
	WHEN("engine was off")
	{
		CCar car;
		THEN("return true")
		{
			auto result = car.TurnOnEngine();
			CHECK(result == true);
		}
	}
	WHEN("engine was already on")
	{
		CCar car;
		auto carEngineTurnedOn = car.TurnOnEngine();
		THEN("return false")
		{
			auto result = car.TurnOnEngine();
			CHECK(result == false);
		}
	}

}
SCENARIO("Engine off") 
{
	WHEN("engine was on")
	{
		CCar car;
		auto carEngineTurnedOn = car.TurnOnEngine();
		THEN("return true")
		{
			auto result = car.TurnOffEngine();
			CHECK(result == true);
		}
	}
	WHEN("engine was already off") 
	{
		CCar car;
		THEN("return false") 
		{
			auto result = car.TurnOffEngine();
			CHECK(result == false);
		}
	}
	WHEN("engine was on, speed is'n 0, gear is't neutral") 
	{
		CCar car;
		THEN("return false")
		{
			car.TurnOnEngine();
			car.SetGear(Gear::First);
			car.SetSpeed(20);
			auto result = car.TurnOffEngine();
			CHECK(result == false);
		}
	}
}

SCENARIO("Change gear") 
{
	WHEN("engine was off and gear changes to neutral") 
	{
		CCar car;
		THEN("return true")
		{
			auto result = car.SetGear(Gear::Neutral);
			CHECK(result == true);
		}
	}
	WHEN("engine was off and gear changes not to neutral")
	{
		CCar car;
		THEN("return false")
		{
			auto result = car.SetGear(Gear::Second);
			CHECK(result == false);
		}
	}
	WHEN("engine was on, speed is 0, gear changes to reverse")
	{
		CCar car;
		THEN("return true")
		{
			car.TurnOnEngine();
			auto result = car.SetGear(Gear::Reverse);
			auto speed = car.GetSpeed();
			CHECK(speed == 0);
			CHECK(result == true);
		}
	}
	WHEN("engine was on, speed is 0, gear changes to second")
	{
		CCar car;
		THEN("return false")
		{
			car.TurnOnEngine();
			auto result = car.SetGear(Gear::Second);
			auto speed = car.GetSpeed();
			CHECK(speed == 0);
			CHECK(result == false);
		}
	}
	WHEN("engine was on, speed is 0, gear changes to second")
	{
		CCar car;
		THEN("return false")
		{
			car.TurnOnEngine();
			auto result = car.SetGear(Gear::Second);
			auto speed = car.GetSpeed();
			CHECK(speed == 0);
			CHECK(result == false);
		}
	}
}

SCENARIO("Change speed") 
{
	WHEN("engine was off")
	{
		CCar car;
		THEN("return false")
		{
			auto result = car.SetSpeed(20);
			CHECK(result == false);
		}
	}
	WHEN("engine was on, gear is neutral")
	{
		CCar car;
		THEN("return false")
		{
			car.TurnOnEngine();
			auto result = car.SetSpeed(100);
			CHECK(result == false);
		}
	}

	WHEN("engine was on, gear is first, correct speed")
	{
		CCar car;
		THEN("return true")
		{
			car.TurnOnEngine();
			car.SetGear(Gear::First);
			auto result = car.SetSpeed(20);
			CHECK(result == true);
		}
	}

	WHEN("engine was on, gear is first, incorrect speed")
	{
		CCar car;
		THEN("return false")
		{
			car.TurnOnEngine();
			car.SetGear(Gear::First);
			auto result = car.SetSpeed(60);
			CHECK(result == false);
		}
	}

	WHEN("engine was on, gear is neutral, speed increases")
	{
		CCar car;
		THEN("return false")
		{
			car.TurnOnEngine();
			auto result = car.SetSpeed(20);
			CHECK(result == false);
		}
	}
}

SCENARIO("Check direction")
{
	WHEN("speed is 0") 
	{
		CCar car;
		THEN("direction is stop") 
		{
			auto result = car.GetDirection();
			CHECK(result == Direction::Stop);
		}
	}
	WHEN("speed is't 0, gear is first")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(Gear::First);
		car.SetSpeed(20);
		THEN("direction is forward")
		{
			auto result = car.GetDirection();
			CHECK(result == Direction::Forward);
		}
	}
	WHEN("speed is't 0, gear is reverse")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(Gear::Reverse);
		car.SetSpeed(20);
		THEN("direction is back")
		{
			auto result = car.GetDirection();
			CHECK(result == Direction::Back);
		}
	}
}

SCENARIO("Car driving")
{
	WHEN("correct commands") 
	{
		stringstream input("EngineOn\nSetGear 1\nSetSpeed 20\nSetGear 2\nSetGear 0\nSetSpeed 10\nEngineOff\n");
		THEN("correct driving") 
		{
			CCar car;
			CCarDriving carDriving(car);
			string command;
			while (getline(input, command))
			{
				carDriving.DoCommand(command);
			}
			auto direction = car.GetDirection();
			auto gear = car.GetGear();
			auto speed = car.GetSpeed();
			CHECK(direction == Direction::Forward);
			CHECK(gear == Gear::Neutral);
			CHECK(speed == 10);
		}
	}
}