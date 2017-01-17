#include "SCurvedMotionProfile.h"


/*
Constructor and Predetermined Variables
*/

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
	SCURVE_TIME = (MAXIMUM_VELOCITY / MAXIMUM_ACCELERATION);
	SCURVE_DISTANCE = (.5 * (MAXIMUM_VELOCITY * SCURVE_TIME));

	CONSTANT_DISTANCE = (TARGET_DISTANCE - (SCURVE_DISTANCE * 2));
	CONSTANT_TIME = (CONSTANT_DISTANCE / MAXIMUM_VELOCITY);

	TOTAL_TIME = CONSTANT_TIME + (SCURVE_TIME * 2);
}

/*
Generation of the Motion Profile
*/

#pragma region Generation


void SCurvedMotionProfile::GenerateFirstSCurve(bool underMax)
{
	double changingPercentage = SCURVE_TIME / TOTAL_TIME;

	if (underMax) changingPercentage = .5;

	Trapezoid trap(MAXIMUM_JERK, MAXIMUM_ACCELERATION, MAXIMUM_VELOCITY);

	sCurve = trap.Populate(PRECISION * changingPercentage);

	motionProfile.insert(motionProfile.end(), sCurve.begin(), sCurve.end());
}


void SCurvedMotionProfile::GenerateConstantVelocity()
{
	double changingPercentage = SCURVE_TIME / TOTAL_TIME;
	double constantPercentage = 1 - changingPercentage - changingPercentage;

	TrajectoryPoint t;
	for (int i = 0; i < PRECISION * constantPercentage; ++i)
	{
		t.Velocity = MAXIMUM_VELOCITY;
		t.Acceleration = 0;
		motionProfile.push_back(t);
	}
}

void SCurvedMotionProfile::GenerateLastSCurve(bool underMax)
{
	std::reverse(sCurve.begin(), sCurve.end());

	// Flip acceleration
	for (int i = 0; i < sCurve.size(); ++i)
	{
		sCurve[i].Acceleration *= -1;
	}

	motionProfile.insert(motionProfile.end(), sCurve.begin(), sCurve.end());
}

void SCurvedMotionProfile::GeneratePositionTime()
{
	TrajectoryPoint t;

	double position = 0, time = 0;
	double timeIncrement = TOTAL_TIME / PRECISION;
	for (int i = 0; i < motionProfile.size(); ++i)
	{
		time += timeIncrement;
		t = motionProfile[i];
		t.Position = position + (t.Velocity * timeIncrement);
		t.Time = time;
		motionProfile[i] = t;
		position = t.Position;
	}
}

#pragma endregion

/*
Population of the MotionProfile Vector
*/
std::vector<TrajectoryPoint> SCurvedMotionProfile::Populate()
{

	if (TARGET_DISTANCE < (SCURVE_DISTANCE * 2))
	{
		PopulateUnderChanging();
	}
	else
	{
		GenerateFirstSCurve(NOT_UNDER_MAX);
		GenerateConstantVelocity();
		GenerateLastSCurve(NOT_UNDER_MAX);
		GeneratePositionTime();
	}

	return motionProfile;
}

void SCurvedMotionProfile::PopulateUnderChanging()
{
	MAXIMUM_VELOCITY = sqrt(TARGET_DISTANCE * MAXIMUM_ACCELERATION);
	TOTAL_TIME = ((MAXIMUM_VELOCITY / MAXIMUM_ACCELERATION) * 2);
	SCURVE_TIME = (.5 * TOTAL_TIME);


	GenerateFirstSCurve(UNDER_MAX);
	GenerateLastSCurve(UNDER_MAX);
	GeneratePositionTime();
}