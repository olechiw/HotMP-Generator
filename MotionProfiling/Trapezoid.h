#pragma once

#include "TrajectoryPoint.h"
#include <vector>



const double MAXIMUM_ACCELERATION = 5;
const double MAXIMUM_VELOCITY = 10;
const double DISTANCE = 100;

const double TIME_ACCELERATE = (MAXIMUM_VELOCITY / MAXIMUM_ACCELERATION); // Time at which it is no longer accelerating

const double DISTANCE_ACCELERATE = (.5 * (MAXIMUM_VELOCITY * TIME_ACCELERATE));

const double DISTANCE_CONSTANT = (DISTANCE - (DISTANCE_ACCELERATE * 2));
const double TIME_CONSTANT = (DISTANCE_CONSTANT / MAXIMUM_VELOCITY);

const double TOTAL_TIME = (TIME_ACCELERATE * 2 + TIME_CONSTANT);


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
	double Velocity(double t);
	double Position(double t);
	std::vector<TrajectoryPoint> Populate(int points);
};

