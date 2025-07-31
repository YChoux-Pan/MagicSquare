#include "initializationVTK.h"

extern std::string texturePaths[6];

initializationVTK::initializationVTK(QObject *parent)
	: QObject(parent)
{}

initializationVTK::~initializationVTK()
{}

void initializationVTK::initializeRenderEnvironment(QVTKOpenGLNativeWidget * m_QVTKOpenGLNativeWidget)
{
	internalInitialize(m_QVTKOpenGLNativeWidget);
}

void initializationVTK::internalInitialize(QVTKOpenGLNativeWidget * m_QVTKOpenGLNativeWidget)
{
	vtkObject::GlobalWarningDisplayOff();  // 关闭警告日志
	// 清理资源，确保之前的渲染数据释放
	safeCleanupResources();
	m_QVTKOpenGLWidget = m_QVTKOpenGLNativeWidget;

	// 渲染环境初始化
	// 创建一个 vtkRenderer 来管理渲染过程
	m_RenderContext.renderer = vtkSmartPointer<vtkRenderer>::New();

	// 创建渲染窗口（OpenGL 渲染窗口）
	m_RenderContext.renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	// 设置 QSurfaceFormat 来指定 OpenGL 渲染的版本、配置和缓存设置
	QSurfaceFormat format;
	format.setVersion(3, 3);							// 设置 OpenGL 版本为 3.3
	format.setProfile(QSurfaceFormat::CoreProfile);		// 设置为核心模式
	format.setDepthBufferSize(24);						// 设置深度缓冲区大小为 24
	format.setSamples(4);								// 启用 4x 多重采样抗锯齿
	m_QVTKOpenGLWidget->setFormat(format);				// 设置 OpenGL 渲染窗口的格式

	// 创建渲染窗口交互器，用于与渲染窗口交互
	m_RenderContext.interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	m_RenderContext.interactor->SetRenderWindow(m_RenderContext.renderWindow);			// 设置交互器绑定的渲染窗口

	m_QVTKOpenGLWidget->setRenderWindow(m_RenderContext.renderWindow);  // 将渲染窗口设置到 QVTKOpenGLNativeWidget 中

	// 设置交互模式为 TrackballCamera，这是一种常用的相机交互模式
	auto style = vtkSmartPointer<vtkInteractorStyleSwitch>::New();
	style->SetCurrentStyleToTrackballCamera();			// 使用 Trackball 相机风格
	m_RenderContext.interactor->SetInteractorStyle(style);				// 设置交互器样式
	m_RenderContext.interactor->Initialize();							// 初始化交互器

	// 设置渲染器背景颜色
	m_RenderContext.renderer->SetBackground(0, 0, 0);					// 页面底部颜色值
	m_RenderContext.renderer->SetBackground2(0.2, 0.3, 0.4);            //页面顶部颜色值
	m_RenderContext.renderer->SetGradientBackground(1);					//开启渐变色背景设置

	// 将渲染器添加到渲染窗口中
	m_RenderContext.renderWindow->AddRenderer(m_RenderContext.renderer);

	// 创建并设置相机
	vtkNew<vtkCamera> camera;
	camera->SetParallelProjection(false);				// 开启平行投影模式
	camera->SetPosition(0, -50, 0);						// 设置相机的位置
	camera->SetViewUp(0, 0, 1);							// 设置相机的上方向
	camera->SetClippingRange(0.01, 1000);				// 设置相机的近平面和远平面距离
	m_RenderContext.renderer->SetActiveCamera(camera);					// 设置渲染器的活动相机

}

void initializationVTK::safeCleanupResources()
{
	if (m_RenderContext.interactor)
	{
		m_RenderContext.interactor->RemoveAllObservers();
		m_RenderContext.interactor->SetRenderWindow(nullptr);
		m_RenderContext.interactor->TerminateApp();
	}
	m_QVTKOpenGLWidget = nullptr;
}


vtkSmartPointer<vtkAssembly> initializationVTK::BuildCompositeUnit(const CubeParams& cubeParams, const std::array<FrustumParams, 6>& frustumParams)
{
    vtkSmartPointer<vtkAssembly> assembly = vtkSmartPointer<vtkAssembly>::New();

    CubeUnit cube(cubeParams);
    assembly->AddPart(cube.CreateActor());

    std::array<std::array<double, 3>, 6> normals = {
        std::array<double, 3>{1, 0, 0},   // +X
        std::array<double, 3>{-1, 0, 0},  // -X
        std::array<double, 3>{0, 1, 0},   // +Y
        std::array<double, 3>{0, -1, 0},  // -Y
        std::array<double, 3>{0, 0, 1},   // +Z
        std::array<double, 3>{0, 0, -1},  // -Z
    };

    //正方体的尺寸
    std::array<double, 3> cubeDims = {
       cubeParams.xLength,
       cubeParams.yLength,
       cubeParams.zLength
    };

    for (int i = 0; i < 6; ++i) {
        const auto& normal = normals[i];
        const auto& frustumParam = frustumParams[i];

        TrapezoidalFrustum panel(frustumParam, normal);
        auto actor = panel.CreateActor();

        // 计算位移
        int axis = (i / 2); // 0:X, 1:Y, 2:Z
        double offset = 0.5 * cubeDims[axis] ;

        double dx = normal[0] * offset;
        double dy = normal[1] * offset;
        double dz = normal[2] * offset;

        actor->SetPosition(dx, dy, dz);
        assembly->AddPart(actor);
    }
    return assembly;
}

void initializationVTK::updataRenderAll()
{
	m_RenderContext.renderer->RemoveAllViewProps();
}

void initializationVTK::DisplayActor(RenderContext ctx, vtkSmartPointer<vtkAssembly> actor)
{
	ctx.renderer->RemoveAllViewProps();
	ctx.renderer->AddActor(actor);
	ctx.renderer->ResetCamera();  // 可选：让视角自动调整
	ctx.renderWindow->Render();
}

vtkSmartPointer<vtkTexture> initializationVTK::SetTexture(std::string InputFilePath)
{
	vtkSmartPointer<vtkJPEGReader> reader = vtkSmartPointer<vtkJPEGReader>::New();
	reader->SetFileName(InputFilePath.c_str());
	reader->Update();

	vtkSmartPointer<vtkTexture> textures = vtkSmartPointer<vtkTexture>::New();
	textures->SetInputConnection(reader->GetOutputPort());
	textures->InterpolateOn();//双线性渲染

	return textures;
}




vtkSmartPointer<vtkAssembly> initializationVTK::CreateCubeWithFrustums()
{
	
    CubeParams cubeParams;
    cubeParams.xLength = 5.0;
    cubeParams.yLength = 5.0;
    cubeParams.zLength = 5.0;

    cubeParams.texture = SetTexture(texturePaths[0]);

    std::array<FrustumParams, 6> frustumParams;
    for (int i = 0; i < 6; ++i) {
        frustumParams[i].baseWidth = 5.0;
        frustumParams[i].baseHeight = 5.0;
        frustumParams[i].topWidth = 4.0;
        frustumParams[i].topHeight = 4.0;
        frustumParams[i].height = 0.2;
        frustumParams[i].texture = SetTexture(texturePaths[i]);
    }

    auto fullObject = BuildCompositeUnit(cubeParams, frustumParams);
	DisplayActor(m_RenderContext, fullObject);
	
	return fullObject;
}

vtkSmartPointer<vtkAssembly> initializationVTK::CreateRubiksCube()
{

	vtkSmartPointer<vtkAssembly> rubiksCube = vtkSmartPointer<vtkAssembly>::New();

	const int gridSize = 3;
	const double cubeSize = 5.0;
	const double spacing = 0.2;
	const double step = cubeSize + spacing;
	const double centerOffset = (gridSize - 1) * step / 2.0;

	// 遍历每一层的小方块
	for (int x = 0; x < gridSize; ++x) {
		for (int y = 0; y < gridSize; ++y) {
			for (int z = 0; z < gridSize; ++z) {

				CubeParams cubeParams;
				std::array<FrustumParams, 6> frustumParams;

				cubeParams.xLength = 5.0;
				cubeParams.yLength = 5.0;
				cubeParams.zLength = 5.0;
				cubeParams.texture = SetTexture(texturePaths[0]);

				for (int i = 0; i < 6; ++i) {
					frustumParams[i].baseWidth = 5.0;
					frustumParams[i].baseHeight = 5.0;
					frustumParams[i].topWidth = 4.0;
					frustumParams[i].topHeight = 4.0;
					frustumParams[i].height = 0.1;
					frustumParams[i].texture = SetTexture(texturePaths[i]);
				}

				vtkSmartPointer<vtkAssembly> unit = BuildCompositeUnit(cubeParams, frustumParams);

				// 设置单元位置
				double posX = (x * step) - centerOffset;
				double posY = (y * step) - centerOffset;
				double posZ = (z * step) - centerOffset;
				unit->SetPosition(posX, posY, posZ);
				rubiksCube->AddPart(unit);
			}
		}
	}

	DisplayActor(m_RenderContext, rubiksCube);

	return rubiksCube;
}

vtkSmartPointer<vtkAssembly> initializationVTK::CreateRubiksCubes()
{

	
	const int gridSize = 3;
	const double cubeSize = 5.0;
	const double spacing = 0.2;
	const double step = cubeSize + spacing;
	const double centerOffset = (gridSize - 1) * step / 2.0;

	vtkSmartPointer<vtkAssembly> rubiksCube = vtkSmartPointer<vtkAssembly>::New();
	// 遍历每一层的小方块
	for (int x = 0; x < gridSize; ++x) {
		for (int y = 0; y < gridSize; ++y) {
			for (int z = 0; z < gridSize; ++z) {

				CubeParams cubeParams;
				std::array<FrustumParams, 6> frustumParams;

				cubeParams.xLength = 5.0;
				cubeParams.yLength = 5.0;
				cubeParams.zLength = 5.0;
				cubeParams.texture = SetTexture(texturePaths[0]);

				for (int i = 0; i < 6; ++i) {
					frustumParams[i].baseWidth = 5.0;
					frustumParams[i].baseHeight = 5.0;
					frustumParams[i].topWidth = 4.0;
					frustumParams[i].topHeight = 4.0;
					frustumParams[i].height = 0.1;
					frustumParams[i].texture = SetTexture(texturePaths[i]);
				}

				vtkSmartPointer<vtkAssembly> unit = BuildCompositeUnit(cubeParams, frustumParams);
				// 设置单元位置
				vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
				double posX = (x * step) - centerOffset;
				double posY = (y * step) - centerOffset;
				double posZ = (z * step) - centerOffset;
				transform->Translate(posX,posY,posZ);
				
				auto assembly = vtkSmartPointer<vtkAssembly>::New();
				assembly->AddPart(unit);
				assembly->SetUserTransform(transform);
				
				cubes[x][y][z] = assembly;
				transforms[x][y][z] = transform;
				initialPositions[x][y][z] = { posX,posY,posZ };

				rubiksCube->AddPart(assembly);				
			}
		}
	}
	
	DisplayActor(m_RenderContext, rubiksCube);

	return rubiksCube;
}

void initializationVTK::CreatRCExplode(double distance)
{
	explodeDistance = distance;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int z = 0; z < 3; z++)
			{
				if (x == 1 && y == 1 && z == 1) continue;
				double dx = (x - 1);
				double dy = (y - 1);
				double dz = (z - 1);

				double length = std::sqrt(dx * dx + dy * dy + dz * dz);

				if (length>0)
				{
					dx /= length;
					dy /= length;
					dz /= length;
				}


				transforms[x][y][z]->Identity();
				transforms[x][y][z]->Translate(
					initialPositions[x][y][z].x + dx*explodeDistance,
					initialPositions[x][y][z].y + dy*explodeDistance,
					initialPositions[x][y][z].z + dz*explodeDistance
					);


			}
		}
			
	}
	m_RenderContext.renderer->GetRenderWindow()->Render();


}

void initializationVTK::rotateFace(Face face, Direction direction, bool animate)
{
	double angle = (direction == CW) ? 90.0 : -90.0;
	double axis[3] = { 0,0,0 };
	int fixedIndex = 0;
	int rotationType = 0;

	switch (face)
	{
	case U:
		axis[1] = 1;fixedIndex = 2;	rotationType = 2;break;
	case D:
		axis[1] = 1;fixedIndex = 0;	rotationType = 2;break;
	case L:
		axis[1] = 1;fixedIndex = 0;	rotationType = 0;break;
	case R:
		axis[1] = 1;fixedIndex = 2;	rotationType = 0;break;
	case F:
		axis[1] = 1;fixedIndex = 2;	rotationType = 1;break;
	case B:
		axis[1] = 1;fixedIndex = 0;	rotationType = 1;break;
	}
	std::vector<vtkSmartPointer<vtkTransform>> affetedTransforms;
	std::vector<Position> affectedInitialPositions;

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			for (int z = 0; z < 3; z++) {
				if (x == 1 && y == 1 && z == 1) continue; // 跳过中心块

				// 检查当前方块是否在要旋转的面上
				bool shouldRotate = false;
				switch (rotationType) {
				case 0: shouldRotate = (x == fixedIndex); break; // X固定
				case 1: shouldRotate = (y == fixedIndex); break; // Y固定
				case 2: shouldRotate = (z == fixedIndex); break; // Z固定
				}

				if (shouldRotate) {
					affetedTransforms.push_back(transforms[z][y][x]);
					affectedInitialPositions.push_back(initialPositions[z][y][x]);
				}
			}
		}
	}
	// 计算旋转中心
	double center[3] = { 0, 0, 0 };
	switch (rotationType) {
	case 0: center[0] = (fixedIndex - 1) * 5.1; break;
	case 1: center[1] = (fixedIndex - 1) * 5.1; break;
	case 2: center[2] = (fixedIndex - 1) * 5.1; break;
	}

	// 执行旋转动画
	if (animate) {
		animateRotation(affetedTransforms, affectedInitialPositions,
			center, axis, angle, 20);
	}
	else {
		applyRotation(affetedTransforms, affectedInitialPositions,
			center, axis, angle);
	}


}

void initializationVTK::animateRotation(const std::vector<vtkSmartPointer<vtkTransform>>& transforms, const std::vector<Position>& positions, const double center[3], const double axis[3], double totalAngle, int steps)
{
	double stepAngle = totalAngle / steps;

	for (int step = 0; step < steps; step++) {
		for (size_t i = 0; i < transforms.size(); i++) {
			transforms[i]->Identity();

			// 移动到中心
			transforms[i]->Translate(-center[0], -center[1], -center[2]);
			// 旋转
			transforms[i]->RotateWXYZ((step + 1) * stepAngle, axis);
			// 移回原位置
			transforms[i]->Translate(center[0], center[1], center[2]);

			// 应用炸开效果
			double dx = positions[i].x;
			double dy = positions[i].y;
			double dz = positions[i].z;

			double length = std::sqrt(dx * dx + dy * dy + dz * dz);
			if (length > 0) {
				dx /= length;
				dy /= length;
				dz /= length;
			}

			transforms[i]->Translate(
				dx * explodeDistance,
				dy * explodeDistance,
				dz * explodeDistance
			);
		}
		m_RenderContext.renderer->GetRenderWindow()->Render();
		QApplication::processEvents(); // 处理事件循环以更新UI
		QThread::msleep(30); // 延迟以实现动画效果
	}
}
void initializationVTK::applyRotation(const std::vector<vtkSmartPointer<vtkTransform>>& transforms, const std::vector<Position>& positions, const double center[3], const double axis[3], double angle)
{
	for (size_t i = 0; i < transforms.size(); i++) 
	{
		transforms[i]->Identity();

		// 移动到中心
		transforms[i]->Translate(-center[0], -center[1], -center[2]);
		// 旋转
		transforms[i]->RotateWXYZ(angle, axis);
		// 移回原位置
		transforms[i]->Translate(center[0], center[1], center[2]);

		// 应用炸开效果
		double dx = positions[i].x;
		double dy = positions[i].y;
		double dz = positions[i].z;

		double length = std::sqrt(dx * dx + dy * dy + dz * dz);
		if (length > 0) {
			dx /= length;
			dy /= length;
			dz /= length;
		}

		transforms[i]->Translate(
			dx * explodeDistance,
			dy * explodeDistance,
			dz * explodeDistance
		);
	}
	m_RenderContext.renderer->GetRenderWindow()->Render();
}


void initializationVTK::UnitRotation(vtkSmartPointer<vtkAssembly> rubiksCube, double X, double Y, double Z)
{

	if (rubiksCube == NULL)
	{
		return;
	}
	rubiksCube->SetOrientation(X, Y, Z); // 围绕 Z 轴

	m_RenderContext.renderWindow->Render(); // 刷新画面
}

vtkSmartPointer<vtkAssembly> initializationVTK::CreateSphere()
{
	updataRenderAll();
	SphereParams m_SphereParams;
	m_SphereParams.radius = 5.0;
	m_SphereParams.thetaResolution = 30;
	m_SphereParams.phiResolution = 30;
	m_SphereParams.texture = SetTexture(texturePaths[3]);

	SphereUnit m_SphereUnit(m_SphereParams);
	auto cySphereActor = m_SphereUnit.CreateActor();
	vtkSmartPointer<vtkAssembly> unit = vtkSmartPointer<vtkAssembly>::New();
	unit->AddPart(cySphereActor);

	DisplayActor(m_RenderContext, unit);
	return unit;
}

vtkSmartPointer<vtkAssembly> initializationVTK::CreateFrustum()
{
	updataRenderAll();
	FrustumParams m_FrustumParams;
	m_FrustumParams.baseHeight = 5.0;
	m_FrustumParams.baseWidth = 5.0;
	m_FrustumParams.height = 1.0;
	m_FrustumParams.topHeight = 4.0;
	m_FrustumParams.topWidth = 4.0;
	m_FrustumParams.texture = SetTexture(texturePaths[2]);


	std::array<std::array<double, 3>, 6> normals = {
	   std::array<double, 3>{1, 0, 0},   // +X
	   std::array<double, 3>{-1, 0, 0},  // -X
	   std::array<double, 3>{0, 1, 0},   // +Y
	   std::array<double, 3>{0, -1, 0},  // -Y
	   std::array<double, 3>{0, 0, 1},   // +Z
	   std::array<double, 3>{0, 0, -1},  // -Z
	};


	TrapezoidalFrustum m_TrapezoidalFrustum(m_FrustumParams, normals[0]);

	auto cyfrustumActor = m_TrapezoidalFrustum.CreateActor();
	vtkSmartPointer<vtkAssembly> unit = vtkSmartPointer<vtkAssembly>::New();
	unit->AddPart(cyfrustumActor);

	DisplayActor(m_RenderContext, unit);
	return unit;
}

vtkSmartPointer<vtkAssembly> initializationVTK::CreateCylindricalBody()
{
	updataRenderAll();
	CylinderParams cylParams;
	cylParams.radius = 1.5;
	cylParams.height = 4.0;
	cylParams.resolution = 64;
	cylParams.capped = true;
	cylParams.texture = SetTexture(texturePaths[0]);

	CylindricalBodyUnit cylinder(cylParams);
	auto cylinderActor = cylinder.CreateActor();

	vtkSmartPointer<vtkAssembly> unit = vtkSmartPointer<vtkAssembly>::New();
	unit->AddPart(cylinderActor);

	DisplayActor(m_RenderContext, unit);
	return unit;
}

vtkSmartPointer<vtkAssembly> initializationVTK::CreateCube()
{
	updataRenderAll();
	vtkSmartPointer<vtkAssembly> Cube = vtkSmartPointer<vtkAssembly>::New();
	CubeParams cbParams;
	cbParams.xLength = 5.0;
	cbParams.yLength = 5.0;
	cbParams.zLength = 5.0;
	cbParams.texture = SetTexture(texturePaths[1]);

	CubeUnit m_cubeUnit(cbParams);
	auto cyCubeUnitActor = m_cubeUnit.CreateActor();
	
	Cube->AddPart(cyCubeUnitActor);

	vtkSmartPointer<vtkAssembly> unit = vtkSmartPointer<vtkAssembly>::New();
	unit->AddPart(Cube);

	DisplayActor(m_RenderContext, unit);

	
	return Cube;
}


