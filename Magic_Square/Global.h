#pragma once


#include <vtkRenderWindow.h>

#include <vtkNew.h>
#include <vtkTexture.h>
#include <vtkJPEGReader.h>
#include <vtkAssembly.h>


//VTK
#include <vtkSmartPointer.h>        // 智能指针管理
#include <vtkPoints.h>              // 点数据容器
#include <vtkCellArray.h>           // 顶点/单元数据
#include <vtkPolyData.h>            // 几何数据结构 存储几何数据（点、线、面等)
#include <vtkActor.h>               // 渲染Actor
#include <vtkPolyDataMapper.h>      // 数据映射数据到 OpenGL
#include <vtkSMPTools.h>            // 并行循环加速
#include <QVTKOpenGLNativeWidget.h>  //VTK OpenGL窗口控件
#include <vtkTimerLog.h>
#include <vtkRenderer.h>                 // 渲染器核心类
#include <vtkGenericOpenGLRenderWindow.h> // 跨平台渲染窗口
#include <vtkRenderWindowInteractor.h>     // 交互器
#include <vtkInteractorStyleSwitch.h>      // 交互风格切换
#include <vtkCamera.h>                     // 相机控制
#include <vtkCommand.h>                    // 事件回调基类（隐式依赖）
#include <vtkProperty.h>
#include <vtkPointData.h>             
#include <vtkSMPThreadLocal.h>

#include <vtkCubeSource.h>           //创建立方体几何体的类
#include <vtkAppendPolyData.h>		//用于合并多个 PolyData 对象
#include <vtkFloatArray.h>			
#include <vtkUnsignedCharArray.h>	//用于存储 RGB 颜色数据
#include <vtkGlyph3DMapper.h>		//于将立方体或其他几何体应用到点云数据上，进行批量渲染
#include <vtkTransformPolyDataFilter.h>
#include <vtkTransform.h>
#include <vtkObject.h>
#include <vtkPlaneSource.h>
#include <vtkFloatArray.h>
#include <vtkPolygon.h>


#include <vtkSphereSource.h>  //球体
#include <vtkCylinderSource.h>
#include <vtkTextureMapToCylinder.h>




#include <pcl/point_types.h>        // 点类型定义（如PointXYZRGB）
#include <pcl/point_cloud.h>        // 点云容器（CloudPtr）
#include <pcl/io/pcd_io.h>          // PCD文件读写   
#include <pcl/common/pca.h>

extern std::string texturePaths[6];


//全局参数管理类
#include "GlobalParameterClass.h"


//QT工具类

#include <qtimer.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qevent.h>
#include <qapplication.h>
#include <qthread.h>