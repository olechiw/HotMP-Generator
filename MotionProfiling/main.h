#pragma once


#define ITERATION_TIME 50 // MS between trajectory points
#define FILTER_ACCELERATE_TIME 200 // MS
#define FILTER_DECCELERATE_TIME 100 // MS
#define FILTER_ACCELERATE (FILTER_ACCELERATE_TIME / ITERATION_TIME) // # of Trajectory Points
#define FILTER_DECCELERATE (FILTER_DECCELERATE_TIME / ITERATION_TIME) // # of Trajectory Points

#define MAXIMUM_SPEED 10 // Feet per second
#define TRAVEL_DISTANCE 4 // Feet
#define TOTAL_TIME_MAX ((TRAVEL_DISTANCE / MAXIMUM_SPEED) * 1000) // MS

#define TOTAL_TIME_OVERALL (FILTER_ACCELERATE_TIME + TOTAL_TIME_MAX + FILTER_DECCELERATE_TIME) // MS

#define TOTAL_POINTS (TOTAL_TIME_OVERALL / ITERATION_TIME) // # of Trajectory Points

struct TrajectoryPoint
{
	double Step;
	double Time;
	double Filter1;
	double Filter2;
	double Velocity;
};


TrajectoryPoint GeneratePoint(int step);

TrajectoryPoint* PopulateMotionProfile();

TrajectoryPoint motionProfileTrajectoryPoints[TOTAL_POINTS];