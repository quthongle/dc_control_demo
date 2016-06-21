#include "Arduino.h"
#include "dcControl.h"


/*------------------------
 *
 * #define dcStNOT_INIT	0
 # define dcStINIT	1*

 #define dcStRUNNING	2
 #define dcStPAUSE	3

 #define dcStSTOP	4
 int _range = 255;
 char _speedPin;
 char _directionPin;

 bool _isInit = false;
 bool _isLock = true;
 unsigned long _duration;
 ------------------------*/

dcControl::dcControl(){
	_speedPin = 10;
	_directionPin = 11;
	_speed = 0;
	_direction = 0;

	_range = 255;
	_isInit = false;
	_isLock = false;
	_duration = 1000; //1 second
	_sysState = dcStUNINIT_LOCK;
	_id = millis();

	_runLength = 0;
	_sleepLength = 0;
	_slept = 0;
	_idled = 0;

	pinMode(_speedPin, OUTPUT);
	pinMode(_directionPin, OUTPUT);
}
void dcControl::init(int spPin, int dirPin, int range){
	if (_isLock == false){
		_speedPin = spPin;
		_directionPin = dirPin;
		_range = range;
	}
}

void dcControl::attach(char spPin, char dirPin){
	if (_isLock == false){
		_speedPin = spPin;
		_directionPin = dirPin;
	}
}
void dcControl::setPwmRange(int range){
	if (_isLock == false){
		_range = range;
	}
}

/*--------------------------------------------------------*
 * SETTING SECTION
 * -------------------------------------------------------*/
//SETTING
bool dcControl::setSpeedPin(char sP){
	if (_isLock == false){
		_speedPin = sP;
		return true;
	}
	return false;
}
bool dcControl::setDirPin(char dP){
	if (_isLock == false){
		_directionP = dP;
		return true;
	}
	return false;
}
bool dcControl::setSpeed(char spd){
	if (_isLock == false){
		_speed = spd;
		return true;
	}
	return false;
}
bool dcControl::setDir(char dirc){
	if (_isLock == false){
		_direction = dirc;
		return true;
	}
	return false;
}
bool dcControl::setMaxRange(char rg){
	if (_isLock == false){
		_range = rg;
		return true;
	}
	return false;
}
bool dcControl::setRunLength(unsigned long runl){
	if (_isLock == false){
		_runLength = runl;
		return true;
	}
	return false;
}
bool dcControl::setLock(){
	if (_isLock == false){
		_isLock = true;
	}
	return true;
}
bool dcControl::setUnLock(){
	if (_isLock == true){
		_isLock = false;
	}
	return true;
}
unsigned long setSleepDuration(unsigned long dur){
	if (_isLock == false){
		_sleepLength = dur;
		return true;
	}
	return false;
}
unsigned long setSleepRemain(unsigned long dur){
	if (_isLock == false){
		if (_sysState == dcStPAUSE)
			return 1; //TODO
	}
	return -1;
}
int setState(int sta){
	if (_isLock == false){
		_sysState = sta;
		return true;
	}
	return false;
}

/*--------------------------------------------------------*
 * QUERY SECTION
 * -------------------------------------------------------*/
//QUERY
unsigned char dcControl::getSpeedPin(){
	return _speedPin;
}
unsigned char dcControl::getDirPin(){
	return _directionPin;
}
unsigned char dcControl::getSpeed(){
	return _speed;
}
char dcControl::getDir(){
	return _direction;
}
unsigned char dcControl::getMaxRange(){
	return _range;
}
bool dcControl::isLock(){
	return _isLock;
}
bool dcControl::isRunning(){
	return (_sysState == dcStRUNNING);
}
unsigned long dcControl::getSleepDuration(){
	return _sleepLength;
}
unsigned long dcControl::getSleepRemain(){
	return _sleepLength-_slept;
}
int dcControl::getState(){
	return _sysState;
}
unsigned long dcControl::getId(){
	return _id;
}
void dcControl::getInfor(){
	Serial.begin(9600);
	Serial.println("...DC INFOR...");
	Serial.print("._id : ");
	Serial.println(_id);
	Serial.print("._range : ");
	Serial.println(_range);

	Serial.print("._speedPin : ");
	Serial.println(_speedPin);
	Serial.print("._directionPin : ");
	Serial.println(_directionPin);

	Serial.print("._speed : ");
	Serial.println(_speed);
	Serial.print("._direction : ");
	Serial.println(_direction);

	Serial.print(".state : ");
	Serial.println(_sysState);
	Serial.print("._isLock : ");
	Serial.println(_isLock);
	Serial.print("._speed : ");
	Serial.println(_speed);
	Serial.print("._direction : ");
	Serial.println(_direction);

	Serial.print("._runLength : ");
	Serial.println(_runLength);
	Serial.print("._sleepLength : ");
	Serial.println(_sleepLength);


	Serial.print("._slept : ");
	Serial.println(_slept);
	Serial.print("._idled : ");
	Serial.println(_idled);
}


/*--------------------------------------------------------*
 * COMMAND SECTION
 * -------------------------------------------------------*/
//COMMAND
void dcControl::exRun(){
	if (_isLock == false){
		_speed = constrain(_speed, - _range, _range);
		if (_direction < 0)
		{
			digitalWrite(_directionPin, HIGH);
		}
		else
		{
			digitalWrite(_directionPin, LOW);
		}
		analogWrite(_speedPin, _speed);
	}
}
void dcControl::exRun(unsigned char speed){
	if (_isLock == false){
		speed = constrain(speed, - _range, _range);
		if (_direction < 0)
		{
			digitalWrite(_directionPin, HIGH);
		}
		else
		{
			digitalWrite(_directionPin, LOW);
		}
		analogWrite(_speedPin, speed);
	}
}
void dcControl::exRun(unsigned char speed, char dir){
	if (_isLock == false){
		speed = constrain(speed, - _range, _range);
		if (dir < 0)
		{
			digitalWrite(_directionPin, HIGH);
		}
		else
		{
			digitalWrite(_directionPin, LOW);
		}
		analogWrite(_speedPin, speed);
	}
}
void dcControl::exRunUntil(){
	if (_isLock == false){

	}
}
void dcControl::exRunUntil(unsigned long duration){
	if (_isLock == false){

	}
}
void dcControl::exRunUntil(unsigned long duration, int speed){
	if (_isLock == false){

	}
}
void dcControl::exRunUntil(unsigned long duration, int speed, int dir){
	if (_isLock == false){

	}
}

void dcControl::exStop(){
	if (_isLock == false){

	}
}
void dcControl::exCheckPointStop(){
	if (_isLock == false){

	}
}
void dcControl::exImdStop(){
	if (_isLock == false){

	}
}
void dcControl::exTemStop(unsigned long duration){
	if (_isLock == false){

	}
}
void dcControl::exPause(){
	if (_isLock == false){

	}
}
void dcControl::exTemPause(unsigned long duration){
	if (_isLock == false){

	}
}
void dcControl::exeResume(){
	if (_isLock == false){

	}
}
void dcControl::exRunAutoRever(unsigned long duration){
	if (_isLock == false){

	}
}
void dcControl::exReverDirection(){
	if (_isLock == false){

	}
}
/*--------------------------------------------------------*
 * RESET SECTION
 * -------------------------------------------------------*/
//RESET
void dcControl::resetDefault(){
	if (_isLock == false){

	}
}
void dcControl::restart(){
	if (_isLock == false){

	}
}
