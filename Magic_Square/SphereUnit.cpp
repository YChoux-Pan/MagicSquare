#include "SphereUnit.h"

vtkSmartPointer<vtkActor> SphereUnit::CreateActor()
{

    // �������弸����
    vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetRadius(params_.radius);
    sphereSource->SetThetaResolution(params_.thetaResolution);
    sphereSource->SetPhiResolution(params_.phiResolution);
    sphereSource->Update();

    // Mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(sphereSource->GetOutputPort());

    // Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    // ������
    if (params_.texture) {
        actor->SetTexture(params_.texture);
    }

    return actor;

}