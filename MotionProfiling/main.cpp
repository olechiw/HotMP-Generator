#include <iostream>
#include "main.h"

using namespace std;

const double MAXIMUM_JERK = 3;
const double MAXIMUM_ACCELERATION = 10;
const double TARGET_VELOCITY = 50;

int main()
{
	SCurve* curve = new SCurve();
	std::vector<TrajectoryPoint> points;

	curve->PopulateProfile(120);

	points = curve->GetProfile();

	Trapezoid* trap = new Trapezoid(MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY);

	points = trap->Populate(120);

	for (int i = 0; i < points.size(); ++i)
	{
		std::cout << points[i].Acceleration << std::endl;
	}

	system("pause");
}



/*
TrajectoryPoint GeneratePoint(int step)
{
	
}
*/