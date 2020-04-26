#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../Car/Car.h"

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
		THEN("return true")
		{
			car.TurnOnEngine();
			auto result = car.SetSpeed(100);
			CHECK(result == true);
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

	WHEN("engine was on, gear is first, uncorrect speed")
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