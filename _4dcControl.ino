	/*
	HG7881_Motor_Driver_Example - Arduino sketch

	This example shows how to drive a motor with using HG7881 (L9110) Dual
	Channel Motor Driver Module.  For simplicity, this example shows how to
	drive a single motor.  Both channels work the same way.

	This example is meant to illustrate how to operate the motor driver
	and is not intended to be elegant, efficient or useful.

	Connections:

	Arduino digital output D10 to motor driver input B-IA.
	Arduino digital output D11 to motor driver input B-IB.
	Motor driver VCC to operating voltage 5V.
	Motor driver GND to common ground.
	Motor driver MOTOR B screw terminals to a small motor.

	Related Banana Robotics items:

	BR010038 HG7881 (L9110) Dual Channel Motor Driver Module


https://www.BananaRobotics.com/shop/HG7881-(L9110)-Dual-Channel-Motor-Driver-
Module

	https://www.BananaRobotics.com
	*/
	#include "IRremote.h"
	//The setup function is called once at startup of the sketch
	const int receiverPin = 5; // chân digital 8 dùng để đọc tín hiệu
	IRrecv irrecv(receiverPin); // tạo đối tượng IRrecv mới
	decode_results results;// lưu giữ kết quả giải mã tín hiệu

	// wired connections
	#define HG7881_B_IA 10 // D10 --> Motor B Input A --> MOTOR B +
	#define HG7881_B_IB 11 // D11 --> Motor B Input B --> MOTOR B -


	// wired connections
	#define HG7881_B_IA1 9 // D10 --> Motor B Input A --> MOTOR B +
	#define HG7881_B_IB1 8 // D11 --> Motor B Input B --> MOTOR B -

	// wired connections
	#define HG7881_B_IA2 7 // D10 --> Motor B Input A --> MOTOR B +
	#define HG7881_B_IB2 6 // D11 --> Motor B Input B --> MOTOR B -


	// wired connections
	#define HG7881_B_IA3  12// D10 --> Motor B Input A --> MOTOR B +
	#define HG7881_B_IB3 13 // D11 --> Motor B Input B --> MOTOR B -


	// functional connections
	#define MOTOR_B_PWM HG7881_B_IA // Motor B PWM Speed
	#define MOTOR_B_DIR HG7881_B_IB // Motor B Direction

	// functional connections
	#define MOTOR_B_PWM1 HG7881_B_IA1 // Motor B PWM Speed
	#define MOTOR_B_DIR1 HG7881_B_IB1 // Motor B Direction

	// functional connections
	#define MOTOR_B_PWM2 HG7881_B_IA2 // Motor B PWM Speed
	#define MOTOR_B_DIR2 HG7881_B_IB2 // Motor B Direction

	// functional connections
	#define MOTOR_B_PWM3 HG7881_B_IA3 // Motor B PWM Speed
	#define MOTOR_B_DIR3 HG7881_B_IB3 // Motor B Direction


	// the actual values for "fast" and "slow" depend on the motor
	#define PWM_SLOW 150  // arbitrary slow speed PWM duty cycle
	#define PWM_FAST 255 // arbitrary fast speed PWM duty cycle
	#define DIR_DELAY 1000 // brief delay for abrupt motor changes
	unsigned long segment = 2000;
	unsigned long repeat = 5;
	unsigned long runLength = segment * repeat;


void setup()
	{
	Serial.begin( 9600 );
	irrecv.enableIRIn(); // start the IR receiver
	pinMode( MOTOR_B_DIR, OUTPUT );
	pinMode( MOTOR_B_PWM, OUTPUT );
	digitalWrite( MOTOR_B_DIR, LOW );
	digitalWrite( MOTOR_B_PWM, LOW );

	pinMode( MOTOR_B_DIR1, OUTPUT );
	pinMode( MOTOR_B_PWM1, OUTPUT );
	digitalWrite( MOTOR_B_DIR1, LOW );
	digitalWrite( MOTOR_B_PWM1, LOW );

	pinMode( MOTOR_B_DIR2, OUTPUT );
	pinMode( MOTOR_B_PWM2, OUTPUT );
	digitalWrite( MOTOR_B_DIR2, LOW );
	digitalWrite( MOTOR_B_PWM2, LOW );

	pinMode( MOTOR_B_DIR3, OUTPUT );
	pinMode( MOTOR_B_PWM3, OUTPUT );
	digitalWrite( MOTOR_B_DIR3, LOW );
	digitalWrite( MOTOR_B_PWM3, LOW );
	}


void dcRun(){
		Serial.println( "Fast forward..." );
		// always stop motors briefly before abrupt changes
		digitalWrite( MOTOR_B_DIR, LOW );
		digitalWrite( MOTOR_B_PWM, LOW );
		digitalWrite( MOTOR_B_DIR1, LOW );
		digitalWrite( MOTOR_B_PWM1, LOW );
		digitalWrite( MOTOR_B_DIR2, LOW );
		digitalWrite( MOTOR_B_PWM2, LOW );
		digitalWrite( MOTOR_B_DIR3, LOW );
		digitalWrite( MOTOR_B_PWM3, LOW );
		delay( DIR_DELAY );
		// set the motor speed and direction
		digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
		analogWrite( MOTOR_B_PWM, 255-PWM_FAST ); // PWM speed = fast;
		digitalWrite( MOTOR_B_DIR1, HIGH ); // direction = forward
		analogWrite( MOTOR_B_PWM1, 255-PWM_FAST ); // PWM speed = fast
		digitalWrite( MOTOR_B_DIR2, HIGH ); // direction = forward
		analogWrite( MOTOR_B_PWM2, 255-PWM_FAST ); // PWM speed = fast
		digitalWrite( MOTOR_B_DIR3, HIGH ); // direction = forward
		analogWrite( MOTOR_B_PWM3, 255-PWM_FAST ); // PWM speed = fast
	}

	void dcRunReverse(){
		Serial.println( "Fast reverse..." );
		// always stop motors briefly before abrupt changes
		digitalWrite( MOTOR_B_DIR, LOW );
		digitalWrite( MOTOR_B_PWM, LOW );
		digitalWrite( MOTOR_B_DIR1, LOW );
		digitalWrite( MOTOR_B_PWM1, LOW );
		digitalWrite( MOTOR_B_DIR2, LOW );
		digitalWrite( MOTOR_B_PWM2, LOW );
		digitalWrite( MOTOR_B_DIR3, LOW );
		digitalWrite( MOTOR_B_PWM3, LOW );
		delay( DIR_DELAY );
		// set the motor speed and direction
		digitalWrite( MOTOR_B_DIR, LOW ); // direction = reverse
		analogWrite( MOTOR_B_PWM, PWM_FAST ); // PWM speed = fast
		digitalWrite( MOTOR_B_DIR1, LOW ); // direction = reverse
		analogWrite( MOTOR_B_PWM1, PWM_FAST ); // PWM speed = fast
		digitalWrite( MOTOR_B_DIR2, LOW ); // direction = reverse
		analogWrite( MOTOR_B_PWM2, PWM_FAST ); // PWM speed = fast
		digitalWrite( MOTOR_B_DIR3, LOW ); // direction = reverse
		analogWrite( MOTOR_B_PWM3, PWM_FAST ); // PWM speed = fast
	}

void dcStop(){
		digitalWrite( MOTOR_B_DIR, HIGH );
		digitalWrite( MOTOR_B_PWM, HIGH );

		digitalWrite( MOTOR_B_DIR1, HIGH );
		digitalWrite( MOTOR_B_PWM1, HIGH );

		digitalWrite( MOTOR_B_DIR2, HIGH );
		digitalWrite( MOTOR_B_PWM2, HIGH );

		digitalWrite( MOTOR_B_DIR3, HIGH );
		digitalWrite( MOTOR_B_PWM3, HIGH );
	}

void practice(){
	Serial.println( "-----------------------------" );
	Serial.println( "practice mode..." );
	unsigned long startTime = millis();
	unsigned long currTime;
	unsigned long count = 0;
	while (count < repeat){
		Serial.println(count);
		dcRun();
		delay(segment);
		dcRunReverse();
		delay(segment);
		count++;
	}
	dcStop();
	Serial.println( "-----------------------------" );
	Serial.println( "Exit practice mode..." );
}

int getIR(){
	int ret = -1;
	if (irrecv.decode(&results)) // nếu nhận được tín hiệu
	{
		if (results.value!= 0 )
		{
		Serial.println (results.value,  HEX);
		/*1- FF30CF
			2 - FF18E7                    *
			3- FF7A85
			4- FF10EF
			5- FF38C7
			6- FF5AA5
			7- FF42BD
			8- FF4AB5
			9- FF52AD
			0- FF6897*/
		switch (results.value){
			case 0xFF30CF: Serial.println ("----im getting 1-----");
			ret =  1;
				break;
			case 0xFF18E7: Serial.println ("----im getting 2-----");
			ret =  2;
				break;
			case 0xFF7A85: Serial.println ("----im getting 3-----");
			ret =  3;
				break;
			case 0xFF10EF: Serial.println ("----im getting 4-----");
			ret =  4;
				break;
			case 0xFF38C7: Serial.println ("----im getting 5-----");
			ret =  5;
				break;
			case 0xFF5AA5: Serial.println ("----im getting 6-----");
			ret =  6;
				break;
			case 0xFF42BD: Serial.println ("----im getting 7-----");
			ret =  7;
				break;
			case 0xFF4AB5: Serial.println ("----im getting 8-----");
			ret =  8;
				break;
			case 0xFF52AD: Serial.println ("----im getting 9-----");
			ret =  9;
				break;
			case 0xFF6897: Serial.println ("----im getting 0-----");
			ret =  0;
				break;
			default:  Serial.println ("--INVALID SIG---");
			ret =  -1;
				break;
		}
     }
      delay(200);
      irrecv.resume(); // nhận giá trị tiếp theo
	}
	return ret;
}
void loop()
	{
	boolean isValidInput;
	// draw a menu on the serial port
	Serial.println( "-----------------------------" );
	Serial.println( "MENU:" );
	Serial.println( "1) Fast forward" );
	Serial.println( "2) Forward" );
	Serial.println( "3) Soft stop (coast)" );
	Serial.println( "4) Reverse" );
	Serial.println( "5) Fast reverse" );
	Serial.println( "6) Hard stop (brake)" );
	Serial.println( "7) practice mode" );
	Serial.println( "-----------------------------" );
	do
	{
	int c;
	// get the next character from the serial port
	//Serial.print( "?" );
	//while( !Serial.available() )
	//	; // LOOP...
	//c = Serial.read();
	c = getIR();
	// execute the menu option based on the character recieved
	switch( c )
	{
		case 1: // 1) Fast forward
		Serial.println( "Fast forward..." );
		dcRun();
		isValidInput = true;
		break;

		case 2: // 2) Forward
		Serial.println( "Forward..." );
		// always stop motors briefly before abrupt changes
		digitalWrite( MOTOR_B_DIR, LOW );
		digitalWrite( MOTOR_B_PWM, LOW );
		delay( DIR_DELAY );
		// set the motor speed and direction
		digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
		analogWrite( MOTOR_B_PWM, 255-PWM_SLOW ); // PWM speed = slow
		isValidInput = true;
		break;

		case 3: // 3) Soft stop (preferred)
		Serial.println( "Soft stop (coast)..." );
			dcStop();
		isValidInput = true;
		break;

		case 4: // 4) Reverse
		Serial.println( "Fast forward..." );
		// always stop motors briefly before abrupt changes
		digitalWrite( MOTOR_B_DIR, LOW );
		digitalWrite( MOTOR_B_PWM, LOW );
		delay( DIR_DELAY );
		// set the motor speed and direction
		digitalWrite( MOTOR_B_DIR, LOW ); // direction = reverse
		analogWrite( MOTOR_B_PWM, PWM_SLOW ); // PWM speed = slow
		isValidInput = true;
		break;

		case 5: // 5) Fast reverse
		Serial.println( "Fast forward..." );
			dcRunReverse();
		isValidInput = true;
		break;

		case 6: // 6) Hard stop (use with caution)
			dcStop();
		isValidInput = true;
		break;

		case 7: // 7) practice mode
			practice();
			isValidInput = true;
			break;
		default:
		// wrong character! display the menu again!
		isValidInput = false;
		break;
	}
	} while( isValidInput == true );

	// repeat the main loop and redraw the menu...
	}
	/*EOF*/