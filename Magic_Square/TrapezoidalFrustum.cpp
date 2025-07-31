#include "TrapezoidalFrustum.h"
 


vtkSmartPointer<vtkActor> TrapezoidalFrustum::CreateActor()
{
    const double bw = params_.baseWidth / 2.0;
    const double bh = params_.baseHeight / 2.0;
    const double tw = params_.topWidth / 2.0;
    const double th = params_.topHeight / 2.0;
    const double h = params_.height;

    const double nx = normal_[0], ny = normal_[1], nz = normal_[2];

    double center[3] = {
        nx * h / 2.0,
        ny * h / 2.0,
        nz * h / 2.0
    };

    double up[3] = { 0 }, right[3] = { 0 };
    if (nx != 0) { up[1] = 1; right[2] = 1; }
    else if (ny != 0) { up[0] = 1; right[2] = 1; }
    else { up[0] = 1; right[1] = 1; }

    auto points = vtkSmartPointer<vtkPoints>::New();

    // base 0-3
    for (int i = 0; i < 4; ++i) {
        int sx = (i == 0 || i == 3) ? -1 : 1;
        int sy = (i < 2) ? -1 : 1;

        points->InsertNextPoint(
            center[0] - nx * h / 2 + sx * bw * right[0] + sy * bh * up[0],
            center[1] - ny * h / 2 + sx * bw * right[1] + sy * bh * up[1],
            center[2] - nz * h / 2 + sx * bw * right[2] + sy * bh * up[2]
        );
    }

    // top 4-7
    for (int i = 0; i < 4; ++i) {
        int sx = (i == 0 || i == 3) ? -1 : 1;
        int sy = (i < 2) ? -1 : 1;

        points->InsertNextPoint(
            center[0] + nx * h / 2 + sx * tw * right[0] + sy * th * up[0],
            center[1] + ny * h / 2 + sx * tw * right[1] + sy * th * up[1],
            center[2] + nz * h / 2 + sx * tw * right[2] + sy * th * up[2]
        );
    }

    auto polys = vtkSmartPointer<vtkCellArray>::New();

    // 四个侧面
    for (int i = 0; i < 4; ++i) {
        vtkSmartPointer<vtkPolygon> face = vtkSmartPointer<vtkPolygon>::New();
        face->GetPointIds()->SetNumberOfIds(4);
        face->GetPointIds()->SetId(0, i);
        face->GetPointIds()->SetId(1, (i + 1) % 4);
        face->GetPointIds()->SetId(2, (i + 1) % 4 + 4);
        face->GetPointIds()->SetId(3, i + 4);
        polys->InsertNextCell(face);
    }

    // 顶面
    vtkSmartPointer<vtkPolygon> top = vtkSmartPointer<vtkPolygon>::New();
    for (int i = 0; i < 4; ++i) top->GetPointIds()->InsertNextId(4 + i);
    polys->InsertNextCell(top);

    auto poly = vtkSmartPointer<vtkPolyData>::New();
    poly->SetPoints(points);
    poly->SetPolys(polys);

    // 设置 UV —— 顶面映射（纹理映射只对顶面做）
    auto tcoords = vtkSmartPointer<vtkFloatArray>::New();
    tcoords->SetNumberOfComponents(2);
    tcoords->SetName("TextureCoordinates");

    for (vtkIdType i = 0; i < poly->GetNumberOfPoints(); ++i) {
        double p[3];
        poly->GetPoint(i, p);

        double u = 0.5, v = 0.5;
        if (i >= 4) { // top 面
            double du = (p[0] + tw) / (2.0 * tw); // 假设顶面中心为0
            double dv = (p[1] + th) / (2.0 * th);
            u = std::clamp(du, 0.0, 1.0);
            v = std::clamp(dv, 0.0, 1.0);
        }
        tcoords->InsertNextTuple2(u, v);
    }

    poly->GetPointData()->SetTCoords(tcoords);

    auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(poly);

    auto actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    if (params_.texture) {
        actor->SetTexture(params_.texture);
    }
    else {
        actor->GetProperty()->SetColor(1.0, 0.7, 0.3);
    }

    return actor;
}
