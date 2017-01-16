#include "SCurvedMotionProfile.h"



SCurvedMotionProfile::SCurvedMotionProfile(
	double maxJerk,
	double maxAcceleration,
	double maxVelocity,
	double targetDistance,
	int precision)
	:
	MAXIMUM_JERK(maxJerk),
	MAXIMUM_ACCELERATION(maxAcceleration),
	MAXIMUM_VELOCITY(maxVelocity),
	TARGET_DISTANCE(targetDistance),
	PRECISION(precision)
{

}


std::vector<TrajectoryPoint> SCurvedMotionProfile::Populate()
{
	TrapezoidVelocity velocityTrapezoid = TrapezoidVelocity(MAXIMUM_VELOCITY, MAXIMUM_ACCELERATION, TARGET_DISTANCE);

	double changingDistance = velocityTrapezoid.DistanceChanging() * 2;

	if (TARGET_DISTANCE < changingDistance)
	{
		
		double prevMax = MAXIMUM_VELOCITY;
		SetMaximumVelocity();
		double maxReduction = MAXIMUM_VELOCITY / prevMax;
		MAXIMUM_ACCELERATION *= maxReduction;
		velocityTrapezoid = TrapezoidVelocity(MAXIMUM_VELOCITY, MAXIMUM_ACCELERATION, TARGET_DISTANCE);
		
	}

	double totalTime = velocityTrapezoid.TotalTime();
	double changeTime = (MAXIMUM_VELOCITY / MAXIMUM_ACCELERATION) / 2;
	double changingPercentage = changeTime / totalTime;
	double constantPercentage = 1.0 - (changingPercentage * 2.0);

	Trapezoid trap(MAXIMUM_JERK, MAXIMUM_ACCELERATION, MAXIMUM_VELOCITY);

	sCurve = trap.Populate(PRECISION * changingPercentage);

	// All the points
	std::vector<TrajectoryPoint> motionProfile;

	// Go to maximum velocity to begin with
	motionProfile.insert(motionProfile.end(), sCurve.begin(), sCurve.end());

	// Constant velocity. Does not currently account for time
	TrajectoryPoint t;
	for (int i = 0; i < PRECISION * constantPercentage; ++i)
	{
		t.Velocity = MAXIMUM_VELOCITY;
		t.Acceleration = 0;
		motionProfile.push_back(t);
	}

	// Add the back S-Curve
	std::reverse(sCurve.begin(), sCurve.end());
	motionProfile.insert(motionProfile.end(), sCurve.begin(), sCurve.end());

	return motionProfile;
}


void SCurvedMotionProfile::SetMaximumVelocity()
{
	MAXIMUM_VELOCITY = sqrt(TARGET_DISTANCE * MAXIMUM_ACCELERATION);
}