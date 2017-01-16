#pragma once

#include "TrajectoryPoint.h"
#include <vector>


/*
const double MAXIMUM_JERK = 3;
const double MAXIMUM_ACCELERATION = 10;
const double TARGET_VELOCITY = 50;

const double TIME_CHANGING = (MAXIMUM_ACCELERATION / MAXIMUM_JERK); // Time at which it is no longer accelerating

const double VELOCITY_CHANGING = (.5 * (MAXIMUM_ACCELERATION * TIME_CHANGING));

const double VELOCITY_CONSTANT = (TARGET_VELOCITY - (VELOCITY_CHANGING * 2));
const double TIME_CONSTANT = (VELOCITY_CONSTANT / MAXIMUM_ACCELERATION);

const double TOTAL_TIME = (TIME_CHANGING * 2 + TIME_CONSTANT);
*/


class Trapezoid
{
	
	std::vector<TrajectoryPoint> m_motionProfile;
	
	double MAXIMUM_JERK, MAXIMUM_ACCELERATION, TARGET_VELOCITY;

	double TIME_CHANGING, VELOCITY_CHANGING;
	double TIME_CONSTANT, VELOCITY_CONSTANT;

	double TOTAL_TIME;
	
public:
	Trapezoid(double maxJerk, double maxAcceleration, double targetVelocity);
	double Acceleration(double t);
	double Velocity(double t);
	std::vector<TrajectoryPoint> Populate(int points);
};

