#include "TrapezoidMotionProfile.h"
#include <iostream>

using namespace std;


double TrapezoidMotionProfile::Velocity(double t)
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
		double accelerationInitial = MAXIMUM_VELOCITY;
		double time = t - (TIME_CHANGING + TIME_CONSTANT);
		return accelerationInitial - (time*MAXIMUM_ACCELERATION);
	}
}


double TrapezoidMotionProfile::Position(double t)
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

std::vector<TrajectoryPoint> TrapezoidMotionProfile::Populate(int points)
{
	points += 1;

	std::vector<TrajectoryPoint> profile;

	TrajectoryPoint point = TrajectoryPoint();

	double timeIncrement = TOTAL_TIME / points;
	double time = 0;

	for (int i = 0; i < points; ++i)
	{
		time += timeIncrement;

		point.Acceleration = Velocity(time);

		point.Velocity = Position(time);

		point.Time = time;

		profile.push_back(point);
	}

	profile.erase(profile.end() - 1);

	return profile;
}

TrapezoidMotionProfile::TrapezoidMotionProfile(double maxJerk, double maxAcceleration, double targetVelocity) :
	MAXIMUM_ACCELERATION(maxJerk),
	MAXIMUM_VELOCITY(maxAcceleration),
	TARGET_DISTANCE(targetVelocity)
{
	TIME_CHANGING = (MAXIMUM_VELOCITY / MAXIMUM_ACCELERATION);

	DISTANCE_CHANGING = (.5 * (MAXIMUM_VELOCITY * TIME_CHANGING));

	DISTANCE_CONSTANT = (TARGET_DISTANCE - (DISTANCE_CHANGING * 2));
	TIME_CONSTANT = (DISTANCE_CONSTANT / MAXIMUM_VELOCITY);

	TOTAL_TIME = (TIME_CHANGING * 2 + TIME_CONSTANT);
}