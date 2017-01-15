#include "Trapezoid.h"
#include <iostream>

using namespace std;


double Trapezoid::Acceleration(double t)
{
	if (t <= TIME_CHANGING)
	{
		return MAXIMUM_JERK * t;
	}

	else if (t < (TIME_CHANGING + TIME_CONSTANT))
	{
		return MAXIMUM_ACCELERATION;
	}
	else
	{
		double velocityInitial = MAXIMUM_ACCELERATION;
		double time = t - (TIME_CHANGING + TIME_CONSTANT);
		return velocityInitial - (time*MAXIMUM_JERK);
	}
}


double Trapezoid::Velocity(double t)
{
	//cout << endl << endl << endl << TIME_ACCELERATE << endl << endl << endl;
	if (t <= TIME_CHANGING)
	{
	//	cout << 1 << endl;
		return (Acceleration(t) * t) / 2;
	}
	else if (t < TIME_CHANGING + TIME_CONSTANT)
	{
	//	cout << 2 << endl;
		//double maxTime = TIME_ACCELERATE;
		//double condition = TIME_ACCELERATE + TIME_CONSTANT;
		return (DISTANCE_CHANGING + (MAXIMUM_ACCELERATION * (t - TIME_CHANGING)));
	}
	else
	{
	//	cout << 3 << endl;
		double deccelTime = t - TIME_CHANGING - TIME_CONSTANT;
		double trapezoid = (((Acceleration(t) + MAXIMUM_ACCELERATION) / 2) * deccelTime);
		return (((Acceleration(t) + MAXIMUM_ACCELERATION) / 2) * deccelTime) + DISTANCE_CHANGING + DISTANCE_CONSTANT;
	}
	
}

std::vector<TrajectoryPoint> Trapezoid::Populate(int points)
{
	points += 1;

	std::vector<TrajectoryPoint> profile;

	TrajectoryPoint point = TrajectoryPoint();

	double timeIncrement = TOTAL_TIME / points;
	double time = 0;

	for (int i = 0; i < points; ++i)
	{
		time += timeIncrement;

		point.Acceleration = Acceleration(time);

		point.Velocity = Velocity(time);

		point.Time = time;

		profile.push_back(point);
	}

	profile.erase(profile.end()-1);

	return profile;
}

Trapezoid::Trapezoid()
{
}


Trapezoid::~Trapezoid()
{
}
