#pragma once

#include <vector>

#include "TrajectoryPoint.h"

class SCurve
{
private:

	// Array of all of the motion points
	std::vector<TrajectoryPoint> m_motionProfile;
public:
	// Calculate the values
	static double PositionConcave(double t);
	static double VelocityConcave(double t);
	static double AccelerationConcave(double t);

	static double PositionConvex(double t);
	static double VelocityConvex(double t);
	static double AccelerationConvex(double t);

	// Populate motion profile
	void PopulateProfile(int points);

	// Get the private profile
	std::vector<TrajectoryPoint> GetProfile() { return m_motionProfile; }
};