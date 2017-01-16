#include <iostream>
#include "main.h"

using namespace std;

const double MAXIMUM_JERK = 5;
const double MAXIMUM_ACCELERATION = 10;
const double TARGET_VELOCITY = 50;

int main()
{
	std::vector<TrajectoryPoint> points;

	Trapezoid* trap = new Trapezoid(MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY);

	points = trap->Populate(120);

	

	SCurvedMotionProfile profile = SCurvedMotionProfile(MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY, .2, 120);

	points = profile.Populate();


	for (int i = 0; i < points.size(); ++i)
	{
		std::cout << points[i].Acceleration << "," << points[i].Velocity << endl;
	}

	system("pause");
}



/*
TrajectoryPoint GeneratePoint(int step)
{
	
}
*/