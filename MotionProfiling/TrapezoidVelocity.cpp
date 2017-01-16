#include "TrapezoidVelocity.h"
#include <iostream>

using namespace std;


double TrapezoidVelocity::Velocity(double t)
{
	if (t <= TIME_CHANGING)
	{
		return MAXIMUM_ACCELERATION * t;
	}

	else if (t < (TIME_CHANGING + TIME_CONSTANT))
	{
		return MAXIMUM_VELOCITY;
	}
	else
	{
		double velocityInitial = MAXIMUM_VELOCITY;
		double time = t - (TIME_CHANGING + TIME_CONSTANT);
		return velocityInitial - (time*MAXIMUM_ACCELERATION);
	}
}


double TrapezoidVelocity::Position(double t)
{
	//cout << endl << endl << endl << TIME_ACCELERATE << endl << endl << endl;
	if (t <= TIME_CHANGING)
	{
		//	cout << 1 << endl;
		return (Velocity(t) * t) / 2;
	}
	else if (t < TIME_CHANGING + TIME_CONSTANT)
	{
		//	cout << 2 << endl;
		//double maxTime = TIME_ACCELERATE;
		//double condition = TIME_ACCELERATE + TIME_CONSTANT;
		return (DISTANCE_CHANGING + (MAXIMUM_VELOCITY * (t - TIME_CHANGING)));
	}
	else
	{
		//	cout << 3 << endl;
		double deccelTime = t - TIME_CHANGING - TIME_CONSTANT;
		double trapezoid = (((Velocity(t) + MAXIMUM_VELOCITY) / 2) * deccelTime);
		return (((Velocity(t) + MAXIMUM_VELOCITY) / 2) * deccelTime) + DISTANCE_CHANGING + DISTANCE_CONSTANT;
	}

}

std::vector<TrajectoryPoint> TrapezoidVelocity::Populate(int points)
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

	profile.erase(profile.end() - 1);

	return profile;
}

TrapezoidVelocity::TrapezoidVelocity(double maxVelocity, double maxAcceleration, double distance)
	:
	MAXIMUM_VELOCITY(maxVelocity),
	MAXIMUM_ACCELERATION(maxAcceleration),
	DISTANCE(distance)
{

	TIME_CHANGING = (MAXIMUM_VELOCITY / MAXIMUM_ACCELERATION); // Time at which it is no longer accelerating

	DISTANCE_CHANGING = (.5 * (MAXIMUM_VELOCITY * TIME_CHANGING));

	DISTANCE_CONSTANT = (DISTANCE - (DISTANCE_CHANGING * 2));
	TIME_CONSTANT = (DISTANCE_CONSTANT / MAXIMUM_VELOCITY);

	TOTAL_TIME = (TIME_CHANGING * 2 + TIME_CONSTANT);
}



TrapezoidVelocity::~TrapezoidVelocity()
{
}
