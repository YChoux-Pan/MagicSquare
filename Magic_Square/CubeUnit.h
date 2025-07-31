#pragma once
#include "Global.h"

class CubeUnit
{
public:
	CubeUnit(const CubeParams& params) :params_(params) {}

    vtkSmartPointer<vtkActor> CreateActor(); 


private:
	
	CubeParams params_;
};

