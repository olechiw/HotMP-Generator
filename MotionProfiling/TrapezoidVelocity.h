#pragma once

#include "TrajectoryPoint.h"
#include <vector>


struct Point
{
	double Acceleration;
	double Velocity;
	double Position;
};

class TrapezoidVelocity
{
	std::vector<TrajectoryPoint> m_motionProfile;

	double MAXIMUM_ACCELERATION, MAXIMUM_VELOCITY, DISTANCE;

	double TIME_CHANGING, DISTANCE_CHANGING;

	double TIME_CONSTANT, DISTANCE_CONSTANT;

	double TOTAL_TIME;
public:
	TrapezoidVelocity(double maxVelocity, double maxAcceleration, double distance);
	~TrapezoidVelocity();
	double Velocity(double t);
	double Position(double t);
	std::vector<TrajectoryPoint> Populate(int points);
	double TimeChanging() { return TIME_CHANGING; }
	double DistanceChanging() { return DISTANCE_CHANGING; }
	double TimeConstant() { return TIME_CONSTANT; }
	double DistanceConstant() { return DISTANCE_CONSTANT; }
	double TotalTime() { return TOTAL_TIME; }
};

