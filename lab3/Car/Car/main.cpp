#include "Car.h"
#include "CarDriving.h"

int main()
{
	CCar car;
	CCarDriving carDriving(car);

	string command;
	while (getline(cin, command))
	{
		carDriving.DoCommand(command);
	}
}
