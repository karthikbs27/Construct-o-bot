void rightTurn()
{
  analogWrite(en1, 150);
  analogWrite(en2, 160);
  if (curDir == 3)
    curDir = 0;
  else curDir++;
  right();
  int encoderInitL = encoderValueL;
  int encoderInitR = encoderValueR;
  int cm = 20 * 3.142 * 85 / 360 / 2; ///cm=radius*angle
  int cmEncode = 2160 * cm / 11;
  while (encoderInitL + cmEncode >= encoderValueL && encoderInitR - cmEncode <= encoderValueR)
    updateEncoder();
  while (readSensors() == 0) //2
    delay(3);
  stopp();
  delay(500);
}

void leftTurn()
{
  analogWrite(en1, 140);
  analogWrite(en2, 140);
  if (curDir == 0) curDir = 3;
  else curDir--;
  left();
  int encoderInitL = encoderValueL;
  int encoderInitR = encoderValueR;
  int cm = 20 * 3.142 * 65 / 360 / 2; ///cm=radius*angle
  int cmEncode = 2160 * cm / 11;
  while (encoderInitL - cmEncode <= encoderValueL && encoderInitR + cmEncode >= encoderValueR)
    updateEncoder();
  while (readSensors() ==0 ) //2
    delay(3);
  stopp();
  delay(500);
}

void turn(int dir)
{
  if (dir == curDir)return;
  if (
    curDir == 3 && dir == 0)
    rightTurn();
  else if (curDir == 0 && dir == 3)
    leftTurn();
  else if (dir > curDir)
    rightTurn();
  else
    leftTurn();
  turn(dir);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void left()
{
  //Serial.println("Right");
  digitalWrite(rb, LOW);
  digitalWrite(lb, HIGH);
  digitalWrite(rf, HIGH);
  digitalWrite(lf, LOW);
}

void right()
{
  //Serial.println("Right");
  digitalWrite(rf, LOW);
  digitalWrite(lf, HIGH);
  digitalWrite(rb, HIGH);
  digitalWrite(lb, LOW);
}
