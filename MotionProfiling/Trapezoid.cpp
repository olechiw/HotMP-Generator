#include "Trapezoid.h"
#include <iostream>

using namespace std;


double Trapezoid::Velocity(double t)
{
	if (t <= TIME_ACCELERATE)
	{
		return MAXIMUM_ACCELERATION * t;
	}

	else if (t < (TIME_ACCELERATE + TIME_CONSTANT))
	{
		return MAXIMUM_VELOCITY;
	}
	else
	{
		double velocityInitial = MAXIMUM_VELOCITY;
		double time = t - (TIME_ACCELERATE + TIME_CONSTANT);
		return velocityInitial - (time*MAXIMUM_ACCELERATION);
	}
}


double Trapezoid::Position(double t)
{
	//cout << endl << endl << endl << TIME_ACCELERATE << endl << endl << endl;
	if (t <= TIME_ACCELERATE)
	{
	//	cout << 1 << endl;
		return (Velocity(t) * t) / 2;
	}
	else if (t < TIME_ACCELERATE + TIME_CONSTANT)
	{
	//	cout << 2 << endl;
		//double maxTime = TIME_ACCELERATE;
		//double condition = TIME_ACCELERATE + TIME_CONSTANT;
		return (DISTANCE_ACCELERATE + (MAXIMUM_VELOCITY * (t - TIME_ACCELERATE)));
	}
	else
	{
	//	cout << 3 << endl;
		double deccelTime = t - TIME_ACCELERATE - TIME_CONSTANT;
		double trapezoid = (((Velocity(t) + MAXIMUM_VELOCITY) / 2) * deccelTime);
		return (((Velocity(t) + MAXIMUM_VELOCITY) / 2) * deccelTime) + DISTANCE_ACCELERATE + DISTANCE_CONSTANT;
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

		point.Velocity = Velocity(time);

		point.Position = Position(time);

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
