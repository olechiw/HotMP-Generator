#include <iostream>
#include "main.h"

using namespace std;

//#define _USE_DEBUG_VARIBLES_




#ifndef _USE_DEBUG_VARIABLES_
const double MAXIMUM_JERK = 426.67;
const double MAXIMUM_ACCELERATION = 853.333;
const double TARGET_VELOCITY = 15000;
const double TARGET_DISTANCE = 20;
const double PRECISION = 128;
const double timeFactor = 10;
#else
const double MAXIMUM_JERK = 1;
const double MAXIMUM_ACCELERATION = 2;
const double MAXIMUM_VELOCITY = 5;
const double TARGET_DISTANCE = 50;
const double PRECISION = 128;
const double timeFactor = 1;
#endif


int main()
{
	std::vector<TrajectoryPoint> points;

	SCurvedMotionProfile profile = SCurvedMotionProfile(MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY, TARGET_DISTANCE, PRECISION);

	points = profile.Populate();

	std::cout << "Acceleration,Velocity,Position,Time" << endl;

	double timeIncrement = points[points.size() - 1].Time / PRECISION;

	for (int i = 0; i < points.size(); ++i)
	{
		std::cout << "{ " << points[i].Position << " , " << points[i].Velocity << " , " << timeIncrement*timeFactor << " }";
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