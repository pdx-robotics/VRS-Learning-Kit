// Motor A setup

  int enableMotorA = 22; // Enables PWM signal for Motor A.
  int motorAdirection1 = 24; // Spinning direction of motor A [IN2] (i).
  int motorAdirection2 = 23; // Spinning direction of motor A [IN1] (ii).


// Motor B setup

  int enableMotorB = 27; //Enables PWM signal for Motor B.
  int motorBdirection1 = 25; // Spinning direction of motor B [IN4] (i).
  int motorBdirection2 = 26; // Spinning direction of motor B [IN3] (ii).


// Left turn signal setup

  int frontLeftTurnSignal = 7;
  int rearLeftTurnSignal = 50;


// Right turn signal setup

  int frontRightTurnSignal = 30;
  int rearRightTurnSignal = 47;

// Distance sensor setup

  // Front center distance sensor
  
    #define trigPinFC 31
    #define echoPinFC 32
    
  // Front left distance sensor
  
    #define trigPinFL 34 
    #define echoPinFL 35 
    
  // Front right distance sensor

    #define trigPinFR 6 
    #define echoPinFR 5 
  
  // Left side skirt distance sensor

    #define trigPinLSS 11
    #define echoPinLSS 10
  
  // Right side skirt distance sensor

    #define trigPinRSS 50
    #define echoPinRSS 51
  
  // Rear left distance sensor

    #define trigPinRL 12
    #define echoPinRL 13
  
  // Rear right distance sensor

    #define trigPinRR 48
    #define echoPinRR 49


void setup() {

  // Configure motor A:
  
    pinMode(enableMotorA, OUTPUT);
    pinMode(motorAdirection1, OUTPUT);
    pinMode(motorAdirection2, OUTPUT);


  // Configure motor B:
  
    pinMode(enableMotorB, OUTPUT);
    pinMode(motorBdirection1, OUTPUT);
    pinMode(motorBdirection2, OUTPUT);


  // Configure distance sensors:

    // Front center distance sensor

      pinMode(trigPinFC, OUTPUT);
      pinMode(echoPinFC, INPUT);

    // Front left distance sensor

      pinMode(trigPinFL, OUTPUT);
      pinMode(echoPinFL, INPUT);

    // Front right distance sensor

      pinMode(trigPinFR, OUTPUT);
      pinMode(echoPinFR, INPUT);

    // Left side skirt distance sensor

      pinMode(trigPinLSS, OUTPUT);
      pinMode(echoPinLSS, INPUT);
      
    // Right side skirt distance sensor

      pinMode(trigPinRSS, OUTPUT);
      pinMode(echoPinRSS, INPUT);

    // Rear left distance sensor

      pinMode(trigPinRL, OUTPUT);
      pinMode(echoPinRL, INPUT);

    // Rear right distance sensor

      pinMode(trigPinRR, OUTPUT);
      pinMode(echoPinRR, INPUT);

  // Configure turn signals:

    // Left turn signal

      pinMode(frontLeftTurnSignal, OUTPUT);
      pinMode(rearLeftTurnSignal, OUTPUT);

    // Right turn signal

      pinMode(frontRightTurnSignal, OUTPUT);
      pinMode(rearRightTurnSignal, OUTPUT);

  }


void loop() {
  movement();
  avoid();
  }


// Motor functions

  void forwardMotorA(){
    // Turns motor A on in the forward direction.
    digitalWrite(motorAdirection1, HIGH);
    digitalWrite(motorAdirection2, LOW);
  }


  void forwardMotorB(){
    // Turns motor B on in the forward direction.
    digitalWrite(motorBdirection1, LOW);
    digitalWrite(motorBdirection2, HIGH);
  }


  void backwardMotorA(){
    // Turns motor A on in the backward direction.
    digitalWrite(motorAdirection1, LOW);
    digitalWrite(motorAdirection2, HIGH);
  }


  void backwardMotorB(){
    // Turns motor B on in the backward direction.
    digitalWrite(motorBdirection1, HIGH);
    digitalWrite(motorBdirection2, LOW);
  }


  void stopMotorA(){
    // Motor A's shaft stops rotating.
    digitalWrite(motorAdirection1, HIGH);
    digitalWrite(motorAdirection2, HIGH);
  }


  void stopMotorB(){
    // Motor B's shaft stops rotating.
    digitalWrite(motorBdirection1, HIGH);
    digitalWrite(motorBdirection2, HIGH);
  }


  void coastMotorA(){
    // Car will coast from forward momentum from power of Motor A before it was turned off.
    digitalWrite(motorAdirection1, LOW);
    digitalWrite(motorAdirection2, LOW);
  }


  void coastMotorB(){
    // Car will coast from forward momentum from power of Motor B before it was turned off.
    digitalWrite(motorBdirection1, LOW);
    digitalWrite(motorBdirection2, LOW);
  }


  void motorAon(){
    // Turns motor A on.
    digitalWrite(enableMotorA, HIGH);
  }


  void motorBon(){
    // Turns motor B on.
    digitalWrite(enableMotorB, HIGH);
  }


  void motorAoff(){
    // Turns motor A off.
    digitalWrite(enableMotorA, LOW);
  }


  void motorBoff(){
    // Turns motor B off.
    digitalWrite(enableMotorB, LOW);
  }


// Movement functions

  void forward(int duration){
    // Car will move forward.
    forwardMotorA();
    forwardMotorB();
    delay(duration);
  }


  void backward(int duration){
    // Car will move backward.
    digitalWrite(frontLeftTurnSignal, HIGH);
    digitalWrite(rearLeftTurnSignal, HIGH);
    digitalWrite(frontRightTurnSignal, HIGH);
    digitalWrite(rearRightTurnSignal, HIGH);
    delay(100);
    digitalWrite(frontLeftTurnSignal, LOW);
    digitalWrite(rearLeftTurnSignal, LOW);
    digitalWrite(frontRightTurnSignal, LOW);
    digitalWrite(rearRightTurnSignal, LOW);
    delay(100);
    backwardMotorA();
    backwardMotorB();
    delay(duration);
  }


  void right(int duration){
    // Car will turn right.
    rightTurnSignal();
    backwardMotorA();
    forwardMotorB();
    delay(duration);
  }


  void left(int duration){
    // Car will turn left.
    leftTurnSignal();
    forwardMotorA();
    backwardMotorB();
    delay(duration);
  }


  void coast(int duration){
    // Car will coast.
    coastMotorA();
    coastMotorB();
    delay(duration);
  }


  void stopCar(int duration){
    // Car will stop.
    stopMotorA();
    stopMotorB();
    delay(duration);
  }


  void motorsOff(){
    // Both motors are turned off.
    motorAoff();
    motorBoff();
  }


  void motorsOn(){
    // Both motors are turned on.
    motorAon();
    motorBon();
  }


// Distance sensor measurements:

  // Front center distance sensor measurement
  
    int distanceFC(){
      int duration, distance;
      digitalWrite(trigPinFC, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPinFC, LOW);
      duration = pulseIn(echoPinFC, HIGH);
      distance = (duration/2) / 29.1;
      return distance;
    }

  // Front left distance sensor measurement

    int distanceFL(){
      int duration, distance;
      digitalWrite(trigPinFL, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPinFL, LOW);
      duration = pulseIn(echoPinFL, HIGH);
      distance = (duration/2) / 29.1;
      return distance;
    }


  // Front right distance sensor measurement

    int distanceFR(){
      int duration, distance;
      digitalWrite(trigPinFR, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPinFR, LOW);
      duration = pulseIn(echoPinFR, HIGH);
      distance = (duration/2) / 29.1;
      return distance;
    }


  // Left side skirt distance measurement

    int distanceLSS(){
      int duration, distance;
      digitalWrite(trigPinLSS, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPinLSS, LOW);
      duration = pulseIn(echoPinLSS, HIGH);
      distance = (duration/2) / 29.1;
      return distance;
    }


  // Right side skirt distance measurement

    int distanceRSS(){
      int duration, distance;
      digitalWrite(trigPinRSS, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPinRSS, LOW);
      duration = pulseIn(echoPinRSS, HIGH);
      distance = (duration/2) / 29.1;
      return distance;
    }


  // Rear left distance measurement

    int distanceRL(){
      int duration, distance;
      digitalWrite(trigPinRL, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPinRL, LOW);
      duration = pulseIn(echoPinRL, HIGH);
      distance = (duration/2) / 29.1;
      return distance;
    }


  // Rear right distance measurement

    int distanceRR(){
      int duration, distance;
      digitalWrite(trigPinRR, HIGH);
      delayMicroseconds(1000);
      digitalWrite(trigPinRR, LOW);
      duration = pulseIn(echoPinRR, HIGH);
      distance = (duration/2) / 29.1;
      return distance;
    }


// Movement functions

  void movement(){
    // Car will continually move forward until it meets specified parameters.
    int distance_0;
    distance_0 = distanceFC();
    while(distance_0 > 15){
      motorsOn();
      forward(1);
      distance_0 = distanceFC();
    }
    stopCar(0);
  }


  void avoidLeft(){ 
    // If the car's left side is too close to a wall, it will turn right and move forward.
    right(1500);
    }


  void avoidRight(){ 
    // If the car's right side is too close to a wall, it will turn left and move forward.
    left(1500);
    }


  void avoidBackupTurnAround(){ 
    // If the front center of the car is too close to a wall, it will drive backwards and turn around.
    backward(100);
    right(1500);
    }
    


  void avoidLeftCorner(){ 
    // If the car is stuck in a left corner, it will turn left, go backward, turn left, and go forward.
    left(1000);
    backward(100);
    left(1000);
    }


  void avoidRightCorner(){
    // If the car is stuck in a right corner, it will turn right, go backwards, turn right, and go forward.
    right(1000);
    backward(100);
    right(1000);
    }


  void avoidRightStraight(){ 
    // The car will straigthen forward when its front-left is about to be close to a wall.
    right(1000);
    forward(100);
    }


  void avoidLeftStraight(){ 
    // The car will straighten forward when its front-right is about to be close to a wall.
    left(1000);
    forward(100);
    }


  void goForward(){
    // If the car's rear end gets too close to a wall while backing up, it will move forward.
    forward(100);
  }


  void avoid(){
    // Car will move in particular directions given the parameters.
    if (distanceFC() < 8 && distanceLSS(), distanceRSS() > 10){
      avoidBackupTurnAround();
    }
    else if (distanceFL() < 7){
      avoidRightStraight();
    }
    else if (distanceFR() < 7){
      avoidLeftStraight();
    }
    else if (distanceLSS() < 7){
      avoidLeft();
    }
    else if (distanceRSS() < 7){
      avoidRight();
    }
    else if (distanceFC() < 8 && distanceLSS() < 8){
      avoidLeftCorner();
    }
    else if (distanceFC() < 8 && distanceRSS() < 8){
      avoidRightCorner();
    }
    else if (distanceRL() && distanceRR() < 8){
      goForward();
    }
}


  void leftTurnSignal() {
    // Left turn signals activates when car turns left.

      digitalWrite(frontLeftTurnSignal, HIGH);
      digitalWrite(rearLeftTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontLeftTurnSignal, LOW);
      digitalWrite(rearLeftTurnSignal, LOW);
      delay(100);
      digitalWrite(frontLeftTurnSignal, HIGH);
      digitalWrite(rearLeftTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontLeftTurnSignal, LOW);
      digitalWrite(rearLeftTurnSignal, LOW);
      delay(100);
      digitalWrite(frontLeftTurnSignal, HIGH);
      digitalWrite(rearLeftTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontLeftTurnSignal, LOW);
      digitalWrite(rearLeftTurnSignal, LOW);
      delay(100);
      digitalWrite(frontLeftTurnSignal, HIGH);
      digitalWrite(rearLeftTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontLeftTurnSignal, LOW);
      digitalWrite(rearLeftTurnSignal, LOW);
      delay(100);
      digitalWrite(frontLeftTurnSignal, HIGH);
      digitalWrite(rearLeftTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontLeftTurnSignal, LOW);
      digitalWrite(rearLeftTurnSignal, LOW);
      delay(100);
      
  }


  void rightTurnSignal() {
    // Right turn signal activates when car turns right.

      digitalWrite(frontRightTurnSignal, HIGH);
      digitalWrite(rearRightTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontRightTurnSignal, LOW);
      digitalWrite(rearRightTurnSignal, LOW);
      delay(100);
      digitalWrite(frontRightTurnSignal, HIGH);
      digitalWrite(rearRightTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontRightTurnSignal, LOW);
      digitalWrite(rearRightTurnSignal, LOW);
      delay(100);
      digitalWrite(frontRightTurnSignal, HIGH);
      digitalWrite(rearRightTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontRightTurnSignal, LOW);
      digitalWrite(rearRightTurnSignal, LOW);
      delay(100);
      digitalWrite(frontRightTurnSignal, HIGH);
      digitalWrite(rearRightTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontRightTurnSignal, LOW);
      digitalWrite(rearRightTurnSignal, LOW);
      delay(100);
      digitalWrite(frontRightTurnSignal, HIGH);
      digitalWrite(rearRightTurnSignal, HIGH);
      delay(100);
      digitalWrite(frontRightTurnSignal, LOW);
      digitalWrite(rearRightTurnSignal, LOW);
      delay(100);

  }
