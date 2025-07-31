#include "CylindricalBodyUnit.h"


vtkSmartPointer<vtkActor> CylindricalBodyUnit::CreateActor()
{
    auto source = vtkSmartPointer<vtkCylinderSource>::New();
    source->SetRadius(m_params.radius);
    source->SetHeight(m_params.height);
    source->SetResolution(m_params.resolution);
    source->SetCapping(m_params.capped);
    source->Update();

    // 创建纹理映射
    auto textureMapper = vtkSmartPointer<vtkTextureMapToCylinder>::New();
    textureMapper->SetInputConnection(source->GetOutputPort());
    textureMapper->PreventSeamOn();
    textureMapper->Update();

    // 映射纹理坐标
    auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(textureMapper->GetOutputPort());

    // 创建演员
    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    if (m_params.texture) {
        actor->SetTexture(m_params.texture);
    }

    return actor;
}