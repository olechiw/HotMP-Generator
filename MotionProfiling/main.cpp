#include <iostream>
#include "main.h"

int main()
{
	SCurve* curve = new SCurve();
	std::vector<TrajectoryPoint> points;

	curve->PopulateProfile(50);

	points = curve->GetProfile();

	for (int i = 0; i < points.size(); ++i)
	{
		std::cout << points[i].Velocity << std::endl;
	}
	system("pause");
}



/*
TrajectoryPoint GeneratePoint(int step)
{
	
}
*/