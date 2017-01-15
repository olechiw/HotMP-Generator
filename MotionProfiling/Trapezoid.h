#pragma once

#include "TrajectoryPoint.h"
#include <vector>



const double MAXIMUM_JERK = 3;
const double MAXIMUM_ACCELERATION = 10;
const double DISTANCE = 50;

const double TIME_CHANGING = (MAXIMUM_ACCELERATION / MAXIMUM_JERK); // Time at which it is no longer accelerating

const double DISTANCE_CHANGING = (.5 * (MAXIMUM_ACCELERATION * TIME_CHANGING));

const double DISTANCE_CONSTANT = (DISTANCE - (DISTANCE_CHANGING * 2));
const double TIME_CONSTANT = (DISTANCE_CONSTANT / MAXIMUM_ACCELERATION);

const double TOTAL_TIME = (TIME_CHANGING * 2 + TIME_CONSTANT);


struct Point
{
	double Acceleration;
	double Velocity;
	double Position;
};

class Trapezoid
{
	std::vector<TrajectoryPoint> m_motionProfile;
public:
	Trapezoid();
	~Trapezoid();
	double Acceleration(double t);
	double Velocity(double t);
	std::vector<TrajectoryPoint> Populate(int points);
};

