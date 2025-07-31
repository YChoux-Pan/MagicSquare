#pragma once
#include "Global.h"


class TrapezoidalFrustum
{
public:
    TrapezoidalFrustum(const FrustumParams& params, const std::array<double, 3>& normal)
        : params_(params), normal_(normal) {
    }

    vtkSmartPointer<vtkActor> CreateActor();

private:
    FrustumParams params_;
    std::array<double, 3> normal_;
};

