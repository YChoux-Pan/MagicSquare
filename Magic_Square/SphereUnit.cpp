#include "SphereUnit.h"

vtkSmartPointer<vtkActor> SphereUnit::CreateActor()
{

    // 创建球体几何体
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

    // 绑定纹理
    if (params_.texture) {
        actor->SetTexture(params_.texture);
    }

    return actor;

}