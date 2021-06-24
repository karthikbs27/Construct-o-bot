void regularForward(int node)
{
  if (node == 0)return;
  x -= node;
  if (node < 0)
  {
    turn(2);
    node = (-1) * node;
  }
  else
    turn(0);
  int count = 0;    //count : variable to count the number of nodes
  int sensor;   //sensor : store the value returned by the function readSensors();
  while (true)
  {
    Serial.print("RegularForward\t");
    Serial.print("node=");
    Serial.print(count);
    Serial.print("\t");
    sensor = readSensors();
    forward();
    Serial.println("\t");
    switch (sensor)
    {
      case -1: count++;
        Serial.println("node");
        stopp();
        delay(300);
        forward(6);
        //    delay(350);
        if (count == node)
          return;
        break;
      case 0: velocity(110, 125);
        Serial.print("White\t");
        break;
      case 2: velocity(110, 130);
        Serial.print("left\t");
        break;
      case 3: velocity(130, 110);
        Serial.print("right\t");
        break;
      case 1: velocity(130 , 130);
        Serial.print("forward\t");
        break;
    }
  }
  delay(1000);
  stopp();
}


void whiteForward(int node)
{
  y -= node;
  if (node < 0)
  {
    turn(1);
    node = abs(node);
  }
  else
    turn(3);
  forward();
  int count = 0;    //count : variable to count the number of nodes
  int sensor;   //sensor : store the value returned by the function readSensors();
  while (true)
  {
    Serial.print("WhiteForward\t");
    sensor = readSensors();
    forward();
    switch (sensor)
    {
      case 0: count++;
        velocity(180, 180);
        delay(380);
        stopp();
        if (count == node)
          return;
        break;
      case -1: velocity(0, 100);
        break;
      case 3: velocity(0, 120);
        break;
      case 2: velocity(120, 0);
        break;
      case 10: velocity(120, 120);
        break;
      case 1: stopp();
        return;
        break;
    }
  }
}



void wallForward(int node)
{
  //  y -= node;
  //  if (node < 0)
  //  {
  //    turn(1);
  //    node = (-1) * (node);
  //  }
  //  else
  //    turn(3);
  static int leftValue, rightValue;
  //  regularForwardWall();
  //  forward(10);
  //  forward(10);
  delay(1000);
  node += 2;
  while (readSensors() == 0)
  {
    Serial.print("WallForward\tL=");
    forward();
    leftValue = analogRead(leftIR);
    Serial.print(leftValue);
    Serial.print("\tR=");
    Serial.print(rightValue);
    Serial.print("\t");
    delay(5);
    rightValue = analogRead(rightIR);
    delay(3);
    if (leftValue > rightValue)
      velocity(130, 110);
    else if (leftValue < rightValue)
      velocity(110, 130);
    else
      velocity(130, 130);
  }
  //  regularForward(1);
}

void regularForwardWall()
{
  int count = 0;    //count : variable to count the number of nodes
  int sensor;   //sensor : store the value returned by the function readSensors();
  while (true)
  {
    Serial.print("RegularForwardWall\t");
    sensor = readSensors();
    forward();
    Serial.println("\t");
    switch (sensor)
    {
      case 0: count++;
        Serial.println("node");
        stopp();
        delay(300);
        forward(6);
        //    delay(350);
        if (count == 1)
          return;
        break;
      //      case 0:velocity(110,120);
      //          Serial.println("White");
      //        break;
      case 2: velocity(90, 100);
        Serial.println("left");
        break;
      case 3: velocity(100, 90);
        Serial.println("right");
        break;
      case 1: velocity(100 , 100);
        Serial.println("forward");
        break;
    }
  }
  delay(1000);
  stopp();
}
void zigZagForward(int node)
{
  y -= node;
  if (node < 0)
    turn(1);
  else
    turn(3);
  Serial.print("ZigZagForward\t");
  regularForwardWall();
  delay(500);
  for (int i = 0; i < 14; i++)
    fastForward(10);
  delay(500);
  forwardWLS(1);
}


int readSensors(void)
{
  int thresh = 400;
  int right_sensor, left_sensor, middle_sensor;
  left_sensor = analogRead(A1);
  delay(3);
  middle_sensor = analogRead(A2);
  delay(3);
  right_sensor = analogRead(A3);
  Serial.print("\t(");
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(")");
  Serial.print(curDir);
  Serial.print("\t");
  Serial.print(left_sensor);
  Serial.print("\t");
  Serial.print(middle_sensor);
  Serial.print("\t");
  Serial.print(right_sensor);
  Serial.println("\n");
  printf("%d\t%d\t%d\n", left_sensor, middle_sensor, right_sensor);
  if (left_sensor < thresh && middle_sensor < thresh && right_sensor < thresh)
    return 0;
  if (left_sensor < thresh && middle_sensor < thresh && right_sensor > thresh)
    return 3;
  if (left_sensor < thresh && middle_sensor > thresh && right_sensor < thresh)
    return 1;
  if (left_sensor < thresh && middle_sensor > thresh && right_sensor > thresh)
    return -1;
  if (left_sensor > thresh && middle_sensor < thresh && right_sensor < thresh)
    return 2;
  if (left_sensor > thresh && middle_sensor < thresh && right_sensor > thresh)
    return 10;
  if (left_sensor > thresh && middle_sensor > thresh && right_sensor < thresh)
    return -1;
  if (left_sensor > thresh && middle_sensor > thresh && right_sensor > thresh)
    return -1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void forwardWLS(int node)
{
  int count = 0;    //count : variable to count the number of nodes
  int sensor;   //sensor : store the value returned by the function readSensors();
  while (true)
  {
    sensor = readSensors();
    forward();
    Serial.println("ForwardWLS\t");
    switch (sensor)
    {
      case -1: count++;
        Serial.println("node");
        stopp();
        delay(300);
        forward(3);
        //    delay(350);
        if (count == node)
          return;
        break;
      case 0: velocity(120, 95);
        Serial.println("White");
        break;
      case 2: velocity(100, 110);
        Serial.println("left");
        break;
      case 3: velocity(120, 100);
        Serial.println("right");
        break;
      case 1: velocity(130 , 130);
        Serial.println("forward");
        break;
    }
  }
  delay(1000);
  stopp();
}
