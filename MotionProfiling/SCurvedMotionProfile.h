#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <math.h>
#include <stdio.h>
#include "Trapezoid.h"
#include "TrajectoryPoint.h"
#include "TrapezoidVelocity.h"

class SCurvedMotionProfile
{
	std::vector<TrajectoryPoint> sCurve;

	double MAXIMUM_JERK, MAXIMUM_ACCELERATION, MAXIMUM_VELOCITY;

	double TARGET_DISTANCE;

	double SCURVE_TIME, SCURVE_DISTANCE;

	int PRECISION;
public:
	SCurvedMotionProfile(
		double maxJerk, // Acceleration Change Per TIME
		double maxAcceleration, //  DISTANCE Per TIME Squared
		double maxVelocity, // DISTANCE Per TIME
		double targetDistance, // DISTANCE
		int precision); // # of Trajectory Points

	std::vector<TrajectoryPoint> Populate();

	void SetMaximumVelocity();
};

