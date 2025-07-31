#pragma once

#include <QtWidgets/QWidget>
#include "ui_Magic_Square.h"
#include "initializationVTK/initializationVTK.h"

class Magic_Square : public QWidget
{
    Q_OBJECT

public:
    Magic_Square(QWidget *parent = nullptr);
    ~Magic_Square();

	void loadingOK();
private:
    Ui::Magic_SquareClass ui;
    QComboBox* comboBox;
	Face m_Face;

private:
    void Cubeunit();//正方体
    void CylindricalBodyUnit();//圆柱体
    void SphereUnit();//球体
    void FrustumUnit();//棱台
	void RubiksCube();//魔方
	void CreateCubeFrustums();//棱台+正方体

private:
	QTimer* rotationTimer;
	QTimer* explodeTimer;
	vtkSmartPointer<vtkAssembly> m_rubiksCube;
	double rotationAngle = 0.0;
	double rotationSpeed = 1.0;  // 每帧自转角度，单位度/帧

	double explodeAngle = 0.0;
	double explodeSpeed = 0.2;

	bool explode = false;
	//定时器函数
	void RotateRubiksCube();

	void RotateExplode();
private slots:
    
    void PYCreationUnit(int index);//创建对象

	void Rotation();//自转

	void RCRound();//创建主体

	void RCExplode();//创建炸开逻辑
	
	void slotInit();//初始化信号槽

signals:

	void signalLoadingOK();


};

