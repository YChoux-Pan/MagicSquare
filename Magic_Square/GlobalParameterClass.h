#pragma once

#include "Global.h"

//渲染交互参数绑定
struct RenderContext {
	vtkSmartPointer<vtkRenderer> renderer;
	vtkSmartPointer<vtkRenderWindow> renderWindow;
	vtkSmartPointer<vtkRenderWindowInteractor> interactor;  // 可选
};


struct ShapeConfig
{
    double cubeSize = 5.0;
    double frustumHeight = 1.0;
    double frustumTopSize = 4.0;

    std::array<vtkSmartPointer<vtkTexture>, 7> textures;
};

//正方体
struct CubeParams {
    double xLength = 5.0;
    double yLength = 5.0;
    double zLength = 5.0;

    vtkSmartPointer<vtkTexture> texture = nullptr;
};

//棱台
struct FrustumParams {
    double baseWidth = 5.0;
    double baseHeight = 5.0;

    double topWidth = 4.0;
    double topHeight = 4.0;

    double height = 1.0;

    vtkSmartPointer<vtkTexture> texture = nullptr;
};

//球体
struct SphereParams {
    double radius = 1.0;//半径
    int thetaResolution = 32;//经度分辨率
    int phiResolution = 32;//维度分辨率
    vtkSmartPointer<vtkTexture> texture = nullptr;//纹理对象
};

//圆柱体
struct CylinderParams
{
    double radius = 1.0;                     // 圆柱体半径
    double height = 2.0;                     // 圆柱体高度（沿 Z 轴方向）
    int resolution = 32;                     // 圆周方向的分辨率（三角面片数）

    bool capped = true;                      // 是否封闭两端面（top/bottom）

    vtkSmartPointer<vtkTexture> texture = nullptr; // 纹理贴图（可选）
};

//魔方参数
enum Face { U, D, L, R, F, B }; // 魔方面标识
enum Direction { CW, CCW };      // 旋转方向: 顺时针/逆时针

struct Position {
	double x, y, z;
};













class GlobalParameterClass
{
};

