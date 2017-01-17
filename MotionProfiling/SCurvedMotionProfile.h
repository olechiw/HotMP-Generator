#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <math.h>
#include <stdio.h>
#include "Trapezoid.h"
#include "TrajectoryPoint.h"

const bool NOT_UNDER_MAX = false;
const bool UNDER_MAX = true;

class SCurvedMotionProfile
{
	std::vector<TrajectoryPoint> sCurve;

	std::vector<TrajectoryPoint> motionProfile;

	double MAXIMUM_JERK, MAXIMUM_ACCELERATION, MAXIMUM_VELOCITY;

	double TARGET_DISTANCE;

	double SCURVE_TIME, SCURVE_DISTANCE;

	double CONSTANT_TIME, CONSTANT_DISTANCE;

	double TOTAL_TIME;

	int PRECISION;
public:
	SCurvedMotionProfile(
		double maxJerk, // Acceleration Change Per TIME
		double maxAcceleration, //  DISTANCE Per TIME Squared
		double maxVelocity, // DISTANCE Per TIME
		double targetDistance, // DISTANCE
		int precision); // # of Trajectory Points

	std::vector<TrajectoryPoint> Populate();

	void PopulateUnderChanging();

	void GenerateFirstSCurve(bool underMax);
	void GenerateConstantVelocity();
	void GenerateLastSCurve(bool underMax);
	void GeneratePositionTime();
};

