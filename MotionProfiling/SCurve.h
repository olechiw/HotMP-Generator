#pragma once

#include <vector>

/*
S-Curve Constants
*/

// Time the S-Curve will happen
#define TIME 5 // Seconds

// Current motion
#define INITIAL_VELOCITY 0
#define INITIAL_ACCELERATION 0

// Maximum motion
#define MAXIMUM_VELOCITY 5 // Meters per Second
#define MAXIMUM_ACCELERATION 1 // Meters per Second

// Jerk
#define MAXIMUM_JERK (MAXIMUM_VELOCITY/TIME/TIME)
#define JERK_ALLOWED MAXIMUM_JERK




struct TrajectoryPoint
{
	double Position; // 
	double Velocity; // Meters per Second
	double Acceleration;
};

class SCurve
{
private:

	// Array of all of the motion points
	std::vector<TrajectoryPoint> m_motionProfile;
public:
	// Calculate the values
	static double Position(double t);
	static double Velocity(double t);
	static double Acceleration(double t);

	// Populate motion profile
	void PopulateProfile(int points);
};