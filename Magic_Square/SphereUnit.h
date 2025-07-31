#pragma once
#include "Global.h"
class SphereUnit
{
public:
    SphereUnit(const SphereParams& params)
        : params_(params) {
    }

    vtkSmartPointer<vtkActor> CreateActor();

private:
    SphereParams params_;

};

