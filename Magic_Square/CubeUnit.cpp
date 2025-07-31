#include "CubeUnit.h"




vtkSmartPointer<vtkActor> CubeUnit::CreateActor() 
{
    auto cube = vtkSmartPointer<vtkCubeSource>::New();
    cube->SetXLength(params_.xLength);
    cube->SetYLength(params_.yLength);
    cube->SetZLength(params_.zLength);
    cube->Update();

    auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cube->GetOutputPort());

    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    if (params_.texture) {
        actor->SetTexture(params_.texture);
    }
    else {
        actor->GetProperty()->SetColor(0.7, 0.7, 0.7);
    }

    return actor;
}