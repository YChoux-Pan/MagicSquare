#pragma once
#include "Global.h"
class CylindricalBodyUnit
{
public:
    explicit CylindricalBodyUnit(const CylinderParams& params)
        : m_params(params) {
    }

    vtkSmartPointer<vtkActor> CreateActor(); 

private:
    CylinderParams m_params;

};

