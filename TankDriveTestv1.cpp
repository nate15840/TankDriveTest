#include "WPILib.h"

/*
 * Nate Thorn
 * C++
 * 23 JAN 2016
 */

class Robot: public IterativeRobot
{
public:
	//initialize channels
	const static int rightChannel			=	0;
	const static int leftChannel			=	1;
	const static int compressor				=	0;
	const static int rightStickChannel		=	0;
	const static int leftStickChannel		=	1;
	const static int sol0					=	0;
	const static int sol1					=	1;

	Victor rightVictor, leftVictor;
	Compressor comp;
	Joystick rightStick, leftStick;
	DoubleSolenoid dsol;
	RobotDrive tank;

	const int SHIFT_BUTTON	=	1;

	Robot():
		rightVictor(rightChannel),
		leftVictor(leftChannel),
		comp(compressor),
		rightStick(rightStickChannel),
		leftStick(leftStickChannel),
		dsol(sol0, sol1),
		tank(rightVictor, leftVictor)
	{}

	void RobotInit()
	{

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		tank.SetSafetyEnabled(false);
	}

	void TeleopPeriodic()
	{
		tank.TankDrive(rightStick, leftStick);
		if ((rightStick.GetRawButton(SHIFT_BUTTON) == true) or (leftStick.GetRawButton(SHIFT_BUTTON) == true))
		{
			dsol.Set(DoubleSolenoid::kForward);
		}
		else
		{
			dsol.Set(DoubleSolenoid::kReverse);
		}
	}
};

START_ROBOT_CLASS(Robot)
