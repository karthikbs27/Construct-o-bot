void forward(int cm)
{
  
  analogWrite(en1,122);
  analogWrite(en2,120);
  forward();
  int cmEncode = 1620*cm/22;
  int encoderInitL = encoderValueL;
  int encoderInitR = encoderValueR;
  while(encoderInitL+cmEncode>=encoderValueL && encoderInitR+cmEncode>=encoderValueR)
    updateEncoder();
  Serial.print("L = ");
  Serial.print(encoderValueL);
  Serial.print("\tR = ");
  Serial.println(encoderValueR);
  stopp();
}
void fastForward(int cm)
{
  
  analogWrite(en1,200);
  analogWrite(en2,210);
  forward();
  int cmEncode = 1620*cm/22;
  int encoderInitL = encoderValueL;
  int encoderInitR = encoderValueR;
  while(encoderInitL+cmEncode>=encoderValueL && encoderInitR+cmEncode>=encoderValueR)
    updateEncoder();
  Serial.print("L = ");
  Serial.print(encoderValueL);
  Serial.print("\tR = ");
  Serial.println(encoderValueR);
  stopp();
}

void backward(int cm)
{
  analogWrite(en1,120);
  analogWrite(en2,120);
  backward();
  int cmEncode = 1620*cm/22;
  int encoderInitL = encoderValueL;
  int encoderInitR = encoderValueR;
  while(encoderInitL-cmEncode<=encoderValueL && encoderInitR-cmEncode<=encoderValueR)
    updateEncoder();
  Serial.print("L = ");
  Serial.print(encoderValueL);
  Serial.print("\tR = ");
  Serial.println(encoderValueR);
  stopp();
}


void stopp()
{
  digitalWrite(rf,LOW);
  digitalWrite(lf,LOW);
  digitalWrite(rb,LOW);
  digitalWrite(lb,LOW);
}


void forward()
{
  //Serial.print("Forward\n");
  
  digitalWrite(rf,HIGH);
  digitalWrite(lf,HIGH);
  digitalWrite(rb,LOW);
  digitalWrite(lb,LOW);
}

void backward()
{
  //Serial.print("Forward\n");
  
  digitalWrite(rb,HIGH);
  digitalWrite(lb,HIGH);
  digitalWrite(rf,LOW);
  digitalWrite(lf,LOW);
}

void velocity(int lspeed, int rspeed)
{
  analogWrite(en1,lspeed);
  analogWrite(en2,rspeed);
  forward();
}
