//#include <Servo.h>

int curDir = 2;
int h[5] {1, 0, 0, 1, 0};
int a[10] = {5, 0, 2, 2, 3, 0, 4, 2}, n = 8;
int i, flag, x = 5, y = 0, w[6] = {2, 2, 2, 2, 2, 2};

/////////////////////////////////////////////////////////////////////////////////////

const int lf = 22;
const int lb = 23;
const int rf = 24;
const int rb = 25;

int en1 = 45;
int en2 = 46;

//these pins can not be changed 2/3 are special pins
int encoderPinR1 = 3;
int encoderPinR2 = 2;

int encoderPinL1 = 19;
int encoderPinL2 = 18;


volatile int lastEncodedL = 0;
volatile long encoderValueL = 0;

volatile int lastEncodedR = 0;
volatile long encoderValueR = 0;

//////////////////////////////////////////////////////////////////////////////////////

//Servo Left;
//Servo Right;
//Servo arm;
//
//int Rightt = 180 ;
//int Leftt = 000 ;

///////////////////////////////////////////////////////////////////////////////////



const int leftIR = A8;
const int rightIR = A9;

int servoPin1 = 6;
int servoPin2 = 7;
int servoPin = 8;



void setup() {
  // put your setup code here, to run once:
  pinMode(29, OUTPUT);
  digitalWrite(29, HIGH);

  init_devices();

  Serial.begin (9600);

  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  pinMode(encoderPinL1, INPUT);
  pinMode(encoderPinL2, INPUT);

  pinMode(encoderPinR1, INPUT);
  pinMode(encoderPinR2, INPUT);


  digitalWrite(encoderPinL1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPinL2, HIGH); //turn pullup resistor on

  digitalWrite(encoderPinR1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPinR2, HIGH); //turn pullup resistor on

  analogWrite(en1, 200);
  analogWrite(en2, 200);

  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin, OUTPUT);


  //////////////////////////////////////////////////////////////////////////////////////

  //  Left.attach(6);
  //  Right.attach(7);
  //  arm.attach(8);
  //  arm.write(0);


  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  uupp();
  pplace();
  delay(3000);
  delay(4000);
  // wallForward(-1);
  movement();
  //  forward(10);
  //  zigZagForward(-2);
  delay(500);
  beep();
  exit(0);
}

//
//void movement(int a[],int dest_x, int dest_y)
//{
//  for(i=0;!(a[i]==dest_x && a[i+1]==dest_y) ; i+=2)
//  {
//    if((a[i]==4 && ( a[i+1]==0 || a[i+1]==2 )) && (a[i+2]==4 && a[i+3]==1))
//    {
//      wallForward();
//      i+=2;
//    }
//    else if((a[i]==2 && ( a[i+1]==0 || a[i+1]==2 )) && (a[i+2]==2 && a[i+3]==1))
//    {
//      zigZagForward();
//      i+=2;
//    }
//    else if((a[i]==0 && ( a[i+1]==0 || a[i+1]==2 ||  )) && (a[i+2]==0 && a[i+3]==1))
//    {
//      whiteForward();
//    }
//    else
//      regularforward();
//  }
//}

void movement()
{
  forwardWLS(1);
  rightTurn();
  forwardWLS (1);
  rightTurn();
  forwardWLS(1);
  Serial.println("AAAAAAAAAAAAAAAAaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaAAAAAAAAAAAAAAAAAAAAAAAA");
  for (i = 0; i < n ; i += 2)
  {
    lastEncodedL = 0;
    encoderValueL = 0;
    lastEncodedR = 0;
    encoderValueR = 0;
    pick();
    regularForward(a[i] - a[i + 2]);
    if (x == 4)
      zigZagForward(a[i + 1] - a[i + 3]);
    //wallForward(a[i + 1] - a[i + 3]);
    else if (x == 2)
      zigZagForward(a[i + 1] - a[i + 3]);
    else if (x == 0)
      whiteForward(a[i + 1] - a[i + 3]);
    place();
    delay(500);
    if (x == 4 && y == 2)break;
    //beep();
    i += 2;
    if (a[i + 1] != a[i + 3])
    {
      if (x == 4)
        zigZagForward(a[i + 1] - a[i + 3]);
      //        wallForward(a[i + 1] - a[i + 3]);
      else if (x == 2)
        zigZagForward(a[i + 1] - a[i + 3]);
      else if (x == 0)
        whiteForward(a[i + 1] - a[i + 3]);
    }
    regularForward(a[i] - a[i + 2]);
  }
  stopp();
}

void beep()
{
  //for (int i = 0; i < 5; i++)
  //{
  digitalWrite(29, LOW);
  delay(5000);
  digitalWrite(29, HIGH);
  //}
}
