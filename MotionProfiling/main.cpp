#include <iostream>
#include "main.h"

using namespace std;

const double MAXIMUM_JERK = 5;
const double MAXIMUM_ACCELERATION = 3;
const double TARGET_VELOCITY = 10;
const double TARGET_DISTANCE = 50;
const double PRECISION = 120;

int main()
{
	std::vector<TrajectoryPoint> points;

	SCurvedMotionProfile profile = SCurvedMotionProfile(MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY, TARGET_DISTANCE, PRECISION);

	points = profile.Populate();

	std::cout << "Acceleration,Velocity,Position,Time" << endl;

	double finalTime = points[points.size() - 1].Time;
	double timeIncrement = finalTime / PRECISION;

	for (int i = 0; i < points.size(); ++i)
	{
		std::cout << "{ " << points[i].Position << " , " << points[i].Velocity << " , " << timeIncrement << " }";
		if (i != points.size() - 1)
			std::cout << ",";
		std::cout << endl;
	}

	system("pause");
}



/*
TrajectoryPoint GeneratePoint(int step)
{
	
}
*/