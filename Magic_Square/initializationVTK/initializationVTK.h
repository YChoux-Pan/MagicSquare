#pragma once

#include <QObject>
#include <Global.h>

#include "..\CubeUnit.h"
#include "..\TrapezoidalFrustum.h"
#include "..\CylindricalBodyUnit.h"
#include "..\SphereUnit.h"

using CloudPtr = pcl::PointCloud<pcl::PointXYZRGB>::Ptr;
class initializationVTK  : public QObject
{
	Q_OBJECT

public:
	initializationVTK(QObject *parent = nullptr);
	~initializationVTK();

	/// 创建一个空的渲染管线 、初始化相机视角、设置背景颜色
	void initializeRenderEnvironment(QVTKOpenGLNativeWidget* m_QVTKOpenGLNativeWidget);

	
	

	

	//对象自转
	void UnitRotation(vtkSmartPointer<vtkAssembly> rubiksCube,double X,double Y,double Z);

	
public:

	//球
	vtkSmartPointer<vtkAssembly> CreateSphere();
	//棱台
	vtkSmartPointer<vtkAssembly> CreateFrustum();
	//圆柱
	vtkSmartPointer<vtkAssembly> CreateCylindricalBody();
	//正方体
	vtkSmartPointer<vtkAssembly> CreateCube();
	//构建渲染模型1个正方体和六个棱台
	vtkSmartPointer<vtkAssembly> CreateCubeWithFrustums();
	//构建魔方拼装函数
	vtkSmartPointer<vtkAssembly> CreateRubiksCube();

	//魔方动画逻辑
	vtkSmartPointer<vtkAssembly> CreateRubiksCubes();//创建主体
	void CreatRCExplode(double distance);//创建炸开逻辑

	//旋转魔方一个面
	void rotateFace(Face face, Direction direction, bool animate = true);
	//旋转动画
	void animateRotation(const std::vector<vtkSmartPointer<vtkTransform>>& transforms,
		const std::vector<Position>& positions,
		const double center[3], const double axis[3], double totalAngle, int steps);

	// 应用旋转
	void applyRotation(const std::vector<vtkSmartPointer<vtkTransform>>& transforms,
		const std::vector<Position>& positions,
		const double center[3], const double axis[3], double angle);
private:

	
	//交互主体
	QVTKOpenGLNativeWidget* m_QVTKOpenGLWidget = nullptr;
	
	//交互对象
	RenderContext m_RenderContext;
	vtkSmartPointer<vtkAssembly> cubes[3][3][3];
	vtkSmartPointer<vtkTransform> transforms[3][3][3];
	//初始位置
	Position initialPositions[3][3][3];
	double explodeDistance = 0.0;

	void internalInitialize(QVTKOpenGLNativeWidget* m_QVTKOpenGLNativeWidget);	//初始化
	void safeCleanupResources();												//检查初始化环境

	bool m_isFirstRender = true;//第一次初始化相机
	//贴图函数
	vtkSmartPointer<vtkTexture> SetTexture(std::string InputFilePath);

	//清空对象
	void updataRenderAll();
	//支持统一的窗口刷新函数中转接口；
	void DisplayActor(RenderContext ctx, vtkSmartPointer<vtkAssembly> actor);
	

	
public:

	//创建1正方体+六个四棱台单位
	vtkSmartPointer<vtkAssembly> BuildCompositeUnit(const CubeParams& cubeParams, const std::array<FrustumParams, 6>& frustumParams);
	
	
};


