void up(int angle=15) {
  //    Left.write(Leftt);
  //    delay(15);
  //    Right.write(Rightt);
  //    delay(15);
  for(int i=0;i<angle;i++){
    
     // A pulse each 20ms
    digitalWrite(servoPin1, HIGH);
    delayMicroseconds(300); // Duration of the pusle in microseconds
    digitalWrite(servoPin1, LOW);
    delayMicroseconds(19700);

    
    digitalWrite(servoPin2, HIGH);
    delayMicroseconds(2600);
    digitalWrite(servoPin2, LOW);
    delayMicroseconds(17400);
     // 20ms - duration of the pusle
    // Pulses duration: 600 - 0deg; 1450 - 90deg; 2300 - 180deg
  }
}
void pickk(){
  for(int i=0;i<5;i++){
    
     // A pulse each 20ms
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(1300); // Duration of the pusle in microseconds
    digitalWrite(servoPin, LOW);
    delayMicroseconds(18700);
  }
}


void placee(){
  for(int i=0;i<5;i++){
    
     // A pulse each 20ms
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(500); // Duration of the pusle in microseconds
    digitalWrite(servoPin, LOW);
    delayMicroseconds(19500);
  }
}


void places() {
  delay(500);
  //backward(5);
  delay(500);
  pplace();
  //arm.write(0);
  //forward(5);
  delay(500);
}


void picks() {
  delay(500);
  backward(12);
  ddown(75);
  //down(1);
  forward(10);
  delay(1000);
  ppick();
  //ddown(65);
  //arm.write(40);
  //uupp();
  delay(500);
  uupp();
  //up();
  //forward(5);
  delay(500);
}

void pick() {
  if (x == 5 && y == 0) {
    if (w[1 - 1] == 2) {
      turn(3);
      picks();
    }
    if (w[1 - 1] == 1) {
      turn(1);
      picks();
    }
  }
  if (x == 3 && y == 0) {
    if (w[3 - 1] == 2) {
      turn(3);
      picks();

    }
    if (w[3 - 1] == 1) {
      turn(1);
      picks();

    }
  }
  if (x == 1 && y == 0) {
    if (w[5 - 1] == 2) {
      turn(3);
      picks();
    }
    if (w[5 - 1] == 1) {
      turn(1);
      picks();
    }
  }
  if (x == 5 && y == 2) {
    if (w[2 - 1] == 2) {
      turn(1);
      picks();
    }
    if (w[2 - 1] == 1) {
      turn(3);
      picks();
    }
  }
  if (x == 3 && y == 2) {
    if (w[4 - 1] == 2) {
      turn(1);
      picks();
    }
    if (w[4 - 1] == 1) {
      turn(3);
      picks();
    }
  }
  if (x == 1 && y == 2) {
    if (w[6 - 1] == 2) {
      turn(1);
      picks();
    }
    if (w[6 - 1] == 1) {
      turn(3);
      picks();
    }
  }
  //arm code comes here
}

void place() {
  backward(6);
  //forward(2);
  if (x == 4 && y == 0) {
    //if (h[0] == 0) {
      uupp();
      //up();
      places();

    //}
  }
  if (x == 2 && y == 0) {
    //if (h[3] == 0) {
      ddown(40);
      //down(1);
      places();

    //}
  }
  if (x == 4 && y == 2) {
    //if (h[2] == 0) {
      ddown(40);
      //down(1);
      places();

    //}
  }
  if (x == 2 && y == 2) {
    //if (h[0] == 0) {
      uupp();
      //up();
      places();

    //}
  }
  if (x == 0 && y == 1) {
    //if (h[0] == 0) {
      ddown(40);
      //down(1);
      places();

    //}
  }
  uupp();
  forward(6);
  //backward(2);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void down(int angle) {
  //    for(int i=0;i<80;i++){
  //      Left.write(Leftt+i);
  //      delay(10);
  //      Right.write(Rightt-i);
  //      delay(10);
for(int i=0;i<angle;i++){
    
     // A pulse each 20ms
    digitalWrite(servoPin1, HIGH);
    delayMicroseconds(1000); // Duration of the pusle in microseconds
    digitalWrite(servoPin1, LOW);
    delayMicroseconds(19000);

    
    digitalWrite(servoPin2, HIGH);
    delayMicroseconds(1900);
    digitalWrite(servoPin2, LOW);
    delayMicroseconds(18100);
}
}









//
//void uppp(int angle){
//  for(int i=0;i<angle;i++){
//    
//     // A pulse each 20ms
//    digitalWrite(servoPin1, HIGH);
//    delayMicroseconds(300); // Duration of the pusle in microseconds
//    digitalWrite(servoPin1, LOW);
//    delayMicroseconds(19700);
//
//    
//    digitalWrite(servoPin2, HIGH);
//    delayMicroseconds(2600);
//    digitalWrite(servoPin2, LOW);
//    delayMicroseconds(17400);
//     // 20ms - duration of the pusle
//    // Pulses duration: 600 - 0deg; 1450 - 90deg; 2300 - 180deg
//  }
//}
//
//void downn(int angle){
//  for(int i=0;i<angle;i++){
//    
//     // A pulse each 20ms
//    digitalWrite(servoPin1, HIGH);
//    delayMicroseconds(1000); // Duration of the pusle in microseconds
//    digitalWrite(servoPin1, LOW);
//    delayMicroseconds(19000);
//
//    
//    digitalWrite(servoPin2, HIGH);
//    delayMicroseconds(1900);
//    digitalWrite(servoPin2, LOW);
//    delayMicroseconds(18100);
//     // 20ms - duration of the pusle
//    // Pulses duration: 600 - 0deg; 1450 - 90deg; 2300 - 180deg
//  }
//}
