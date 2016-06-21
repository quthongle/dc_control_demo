#ifndef dcControl_h
#define dcControl_h

#include "Arduino.h"

#define dcStNOT_INIT	0
#define dcStINIT	1

#define dcStRUNNING	2
#define dcStPAUSE	3

#define dcStSTOP	4
#define dcStINIT_LOCK	5
#define dcStINIT_UNLOCK	6
#define dcStUNINIT_LOCK	7
#define dcStUNINIT_UNLOCK	8
/*---State transition:-----------------------------------

dcStNOT_INIT-->INIT
INIT(1):	case:sigRun	RUN

RUN(2):	case:sigStop	STOP
		case:sigPause	PAUSE

STOP(1):	case:sigRun	RUN

PAUSE(3):	case:sigRun	RUN
		case:sigResume	RESUME
		case:sigStop	STOP

RESUME(?):	case:sigRun	RUN
			case:sigPause	PAUSE
			case:sigStop	STOP

---State transition:-----------------------------------*/
class dcControl{
private:
	int _range = 255;
	unsigned char _speedPin;
	unsigned char _directionPin;
	unsigned char _speed;
	char _direction;

	bool _isInit = false;
	bool _isLock = true;
	unsigned long _runLength;
	unsigned long _sleepLength;
	unsigned long _slept;
	unsigned long _idled;
	char _sysState = dcStNOT_INIT;
	unsigned long _id = millis();

public:
	//INIT
	dcControl();
	void init(int spPin, int dirPin, int range);
	void attach(char spPin, char dirPin);
	void setPwmRange(int range);

	//SETTING
	bool setSpeedPin(char sP);
	bool setDirPin(char dP);
	bool setSpeed(char spd);
	bool setDir(char dirc);
	bool setMaxRange(char rg);
	bool setRunLength(unsigned long runl);
	bool setLock();
	bool setUnLock();
	unsigned long setSleepDuration(unsigned long dur);
	unsigned long setSleepRemain(unsigned long dur);
	int setState(int sta);

	//QUERY
	int getSpeedPin();
	int getDirPin();
	int getSpeed();
	int getDir();
	int getMaxRange();
	bool isLock();
	bool isRunning();
	unsigned long getSleepDuration();
	unsigned long getSleepRemain();
	int getState();
	unsigned long getId();
	void getInfor();

	//COMMAND
	void exRun();
	void exRun(int speed);
	void exRun(int speed, int dir);
	void exRunUntil();
	void exRunUntil(unsigned long duration);
	void exRunUntil(unsigned long duration, int speed);
	void exRunUntil(unsigned long duration, int speed, int dir);

	void exStop();
	void exCheckPointStop();
	void exImdStop();
	void exTemStop(unsigned long duration);

	void exPause();
	void exTemPause(unsigned long duration);
	void exeResume();

	void exRunAutoRever(unsigned long duration);
	void exReverDirection();

	//RESET
	void resetDefault();
	void restart();

};

#endif