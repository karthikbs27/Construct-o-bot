
void updateEncoder   ()
{
  
//  lastEncodedL = 0;
//  encoderValueL = 0;
//  lastEncodedR = 0;
//  encoderValueR = 0;
  updateEncoderL();
  updateEncoderR();
}

void updateEncoderL(){
  int MSB = digitalRead(encoderPinL1); //MSB = most significant bit
  int LSB = digitalRead(encoderPinL2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedL << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValueL ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValueL --;

  lastEncodedL = encoded; //store this value for next time
}

void updateEncoderR(){
  int MSB = digitalRead(encoderPinR1); //MSB = most significant bit
  int LSB = digitalRead(encoderPinR2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedR << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValueR ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValueR --;

  lastEncodedR = encoded; //store this value for next time
}
