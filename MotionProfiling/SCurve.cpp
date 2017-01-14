#pragma once
#include "SCurve.h"
#include <iostream>


double SCurve::Position(double t)
{
	return JERK_ALLOWED * ((t*t*t) / 6);
}

double SCurve::Velocity(double t)
{
	return JERK_ALLOWED * ((t*t) / 2);
}

double SCurve::Acceleration(double t)
{
	return JERK_ALLOWED * t;
}

void SCurve::PopulateProfile(int points)
{
	double timeIncrement = TIME / points;

	double time = 0;

	for (int i = 0; i < points; ++i)
	{
		time += timeIncrement;

		m_motionProfile.push_back({
			Position(time),
			Velocity(time),
			Acceleration(time) });
	}
}
