#include <iostream>
#include "main.h"

using namespace std;

#define _USE_DEBUG_VARIABLES_ true

#define _USE_DEBUG_OUTPUT_ true


// Different types of motors, for generating acceleration profiles
#define _USE_BANEBOT_550_ true




#ifndef _USE_DEBUG_VARIABLES_ // Instead, use the motor variables

#ifdef _USE_BANEBOT_550_

// Units of rpm

const double MAXIMUM_JERK = 500;
const double MAXIMUM_ACCELERATION = 1000;
const double TARGET_VELOCITY = 15000;
const double TARGET_DISTANCE = 100;
const double PRECISION = 128;
const double timeFactor = 1;

#else



const double MAXIMUM_JERK = 426.67;
const double MAXIMUM_ACCELERATION = 853.333;
const double TARGET_VELOCITY = 15000;
const double TARGET_DISTANCE = 20;
const double PRECISION = 128;
const double timeFactor = 10;



#endif // _USE_BANEBOT_550_


#elif _USE_DEBUG_VARIABLES_


const double MAXIMUM_JERK = 1;
const double MAXIMUM_ACCELERATION = 2;
const double TARGET_VELOCITY = 5;
const double TARGET_DISTANCE = 2;
const double PRECISION = 128;
const double timeFactor = 1;


#endif // _USE_DEBUG_VARIABLES_


int main()
{
	std::vector<TrajectoryPoint> points;

	SCurvedMotionProfile profile = SCurvedMotionProfile(MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY, TARGET_DISTANCE, PRECISION);

	points = profile.Populate();

	std::cout << "Acceleration,Velocity,Position" << endl;

	double timeIncrement = points[points.size() - 1].Time / PRECISION;

	for (int i = 0; i < points.size(); ++i)
	{
#ifndef _USE_DEBUG_OUTPUT_
		std::cout << "{ " << points[i].Position << " , " << points[i].Velocity << " , " << timeIncrement*timeFactor << " }";
		if (i != points.size() - 1)
			std::cout << ",";
		std::cout << endl;
#else
		std::cout << points[i].Acceleration << "," << points[i].Velocity << "," << points[i].Position << endl;
#endif // _USE_DEBUG_OUTPUT_
	}

	system("pause");
}



/*
TrajectoryPoint GeneratePoint(int step)
{
	
}
*/