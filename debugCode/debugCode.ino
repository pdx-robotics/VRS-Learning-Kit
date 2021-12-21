// Distance sensor setup

  // Front center distance sensor
  
    #define trigPinFC 31
    #define echoPinFC 32
    
  // Front left distance sensor
  
    #define trigPinFL 6
    #define echoPinFL 5
    
  // Front right distance sensor

    #define trigPinFR 34
    #define echoPinFR 35
  
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

Serial.begin(9600);
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

}

void loop() {

distanceFC();
distanceFL();
distanceFR();
distanceLSS();
distanceRSS();
distanceRL();
distanceRR();
Serial.print("Device reading: ");
Serial.println(distanceLSS());


}





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
