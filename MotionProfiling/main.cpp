#include <iostream>
#include "main.h"

using namespace std;

const double MAXIMUM_JERK = 5;
const double MAXIMUM_ACCELERATION = 3;
const double TARGET_VELOCITY = 10;

int main()
{
	std::vector<TrajectoryPoint> points;

	SCurvedMotionProfile profile = SCurvedMotionProfile(MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY, 50, 120);

	points = profile.Populate();

	std::cout << "Acceleration,Velocity,Position,Time" << endl;

	for (int i = 0; i < points.size(); ++i)
	{
		std::cout << points[i].Acceleration << "," << points[i].Velocity << "," << points[i].Position << "," << points[i].Time << endl;
	}

	system("pause");
}



/*
TrajectoryPoint GeneratePoint(int step)
{
	
}
*/