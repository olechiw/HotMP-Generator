#include <iostream>
#include "main.h"

using namespace std;

int main()
{
	SCurve* curve = new SCurve();
	std::vector<TrajectoryPoint> points;

	curve->PopulateProfile(120);

	points = curve->GetProfile();

	Trapezoid* trap = new Trapezoid();

	points = trap->Populate(120);

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