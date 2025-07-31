#include "Magic_Square.h"

extern initializationVTK* m_initializationVTK;
extern std::string texturePaths[6];

Magic_Square::Magic_Square(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	connect(this, &Magic_Square::signalLoadingOK, this, &Magic_Square::slotInit);

}

Magic_Square::~Magic_Square()
{}

void Magic_Square::loadingOK()
{
	emit signalLoadingOK();
}

void Magic_Square::Cubeunit()
{
	m_rubiksCube = m_initializationVTK->CreateCube();
}

void Magic_Square::CylindricalBodyUnit()
{
	m_rubiksCube = m_initializationVTK->CreateCylindricalBody();
}

void Magic_Square::SphereUnit()
{
	m_rubiksCube = m_initializationVTK->CreateSphere();
}

void Magic_Square::FrustumUnit()
{
	m_rubiksCube = m_initializationVTK->CreateFrustum();
}

void Magic_Square::RubiksCube()
{
	m_rubiksCube = m_initializationVTK->CreateRubiksCube();
}

void Magic_Square::CreateCubeFrustums()
{
	m_rubiksCube = m_initializationVTK->CreateCubeWithFrustums();
}

void Magic_Square::RotateRubiksCube()
{
	rotationAngle += rotationSpeed;
	m_initializationVTK->UnitRotation(m_rubiksCube, 0.0, rotationAngle, rotationAngle);

	if (explode)
	{
		if (explodeAngle <= 1.0)
		{
			explode = false;
		}
		explodeAngle -= explodeSpeed;
		 m_initializationVTK->CreatRCExplode(explodeAngle);

	}
	else
	{
		if (explodeAngle >= 10.0)
		{
			explode = true;
		}
		explodeAngle += explodeSpeed;
		m_initializationVTK->CreatRCExplode(explodeAngle);

	}
}

void Magic_Square::RotateExplode()
{
	

}



void Magic_Square::PYCreationUnit(int index)
{
    switch (index)
    {
    case 0:
        Cubeunit();
        break;
    case 1:
        FrustumUnit();
        break;
    case 2:
        CylindricalBodyUnit();
        break;
    case 3:
        SphereUnit();
        break;
    case 4:
		CreateCubeFrustums();
		break;
	case 5:
		RubiksCube();
        break;
    default:
       
        break;
    }
}


void Magic_Square::Rotation()
{
	if (ui.pb_rotation->text() == "自转")
	{
		rotationSpeed = ui.le_rotation->text().toDouble();
		if (!rotationTimer->isActive())
			rotationTimer->start(16); // 约 60 FPS，每帧调用一次

		ui.pb_rotation->setText("停止");
	}
	else
	{
		if (rotationTimer->isActive())
			rotationTimer->stop();
		ui.pb_rotation->setText("自转");
	}
}

void Magic_Square::RCRound()
{
	m_rubiksCube = m_initializationVTK->CreateRubiksCubes();
}

void Magic_Square::RCExplode()
{
	if (ui.pb_rcExplode->text() == "炸开")
	{
		if (!explodeTimer->isActive())
			explodeTimer->start(16); // 约 60 FPS，每帧调用一次

		ui.pb_rcExplode->setText("停止");
	}
	else
	{
		if (explodeTimer->isActive())
			explodeTimer->stop();
		ui.pb_rcExplode->setText("炸开");
	}
	
}

void Magic_Square::slotInit()
{
	show();
	QTimer::singleShot(100, this, [this]()
		{
			m_initializationVTK->initializeRenderEnvironment(ui.widget_vtk);
		});
	
	QVBoxLayout* layout = new QVBoxLayout(ui.frame_2);
	ui.cb_unit->addItem("正方体");
	ui.cb_unit->addItem("棱台");
	ui.cb_unit->addItem("圆柱");
	ui.cb_unit->addItem("球");
	ui.cb_unit->addItem("正方体+棱台");
	ui.cb_unit->addItem("魔方");
	connect(ui.cb_unit, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Magic_Square::PYCreationUnit);
	texturePaths[0] = "D:/Foodman/ch021_MagicSquare/Magic_Square/x64/Release/Input.jpg";
	texturePaths[1] = "D:/Foodman/ch021_MagicSquare/Magic_Square/x64/Release/Input1.jpg";
	texturePaths[2] = "D:/Foodman/ch021_MagicSquare/Magic_Square/x64/Release/Input2.jpg";
	texturePaths[3] = "D:/Foodman/ch021_MagicSquare/Magic_Square/x64/Release/Input3.jpg";
	texturePaths[4] = "D:/Foodman/ch021_MagicSquare/Magic_Square/x64/Release/Input4.jpg";
	texturePaths[5] = "D:/Foodman/ch021_MagicSquare/Magic_Square/x64/Release/Input5.jpg";
	//自转
	rotationTimer = new QTimer(this);
	connect(rotationTimer, &QTimer::timeout, this, &Magic_Square::RotateRubiksCube);
	connect(ui.pb_rotation, &QPushButton::clicked, this, &Magic_Square::Rotation);
	ui.le_rotation->setText(QString::number(rotationSpeed));

	//炸开逻辑
	connect(ui.pb_rcRound, &QPushButton::clicked, this, &Magic_Square::RCRound);
	connect(ui.pb_rcExplode, &QPushButton::clicked, this, &Magic_Square::RCExplode);
	explodeTimer = new QTimer(this);
	connect(explodeTimer,&QTimer::timeout,this, &Magic_Square::RotateExplode);


	// 假设这些连接写在你的 MainWindow 或 Controller 构造函数中
	connect(ui.pb_U, &QPushButton::clicked, this, [=]() { m_initializationVTK->rotateFace(Face::U, Direction::CW); });
	connect(ui.pb_D, &QPushButton::clicked, this, [=]() { m_initializationVTK->rotateFace(Face::D, Direction::CW); });
	connect(ui.pb_L, &QPushButton::clicked, this, [=]() { m_initializationVTK->rotateFace(Face::L, Direction::CW); });
	connect(ui.pb_R, &QPushButton::clicked, this, [=]() { m_initializationVTK->rotateFace(Face::R, Direction::CW); });
	connect(ui.pb_F, &QPushButton::clicked, this, [=]() { m_initializationVTK->rotateFace(Face::F, Direction::CW); });
	connect(ui.pb_B, &QPushButton::clicked, this, [=]() { m_initializationVTK->rotateFace(Face::B, Direction::CW); });

}



