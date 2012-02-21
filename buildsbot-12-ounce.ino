/*
 BUILDSbot 12 Ounce
 
 Developers: Christopher Woodall
 BUILDS
 MIT License
 
 WARNING:
 
 */


int ledPin = 9;    // LED connected to digital pin 9
char incomingByte = 0;
int left;
int right;
int mid;
int prev_read;
int current_read;
int avg;

void setup()  { 
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.println("BUILDSbot 12 Ounce");
  // nothing happens in setup 
  avg = analogRead(0);
  
  testBench();  
} 

void loop()  { 
  while(Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == 'f') {
      moveForward();
    } else if (incomingByte == 'b') {
      moveBackward();
    } else if (incomingByte == 's') {
      analogWrite(9, 0);  
      analogWrite(11, 0);
    } else if (incomingByte == 'r') {
      turnRight();
    } else if (incomingByte == 'l') {
      turnLeft();
    } else if (incomingByte == 'g') { 
      analogWrite(9,250);
      analogWrite(11, 250);
    } else if (incomingByte == '1') {
      analogWrite(9, 220);
      analogWrite(11, 250);
    }
  }
 
  left = analogRead(0);
  mid = analogRead(1);
  right = analogRead(2);
  
  if (left < 50)
    Serial.println("left hit");
  if (right < 50)
    Serial.println("right hit");
  if (mid < 50)
    Serial.println("mid hit");
}

void moveForward() {
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  
  digitalWrite(10,HIGH);  
  digitalWrite(8,LOW);
}

void moveBackward() {
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  
  digitalWrite(10,LOW);
  digitalWrite(8,HIGH);
}

void turnRight() {
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  
  digitalWrite(10, HIGH);
  digitalWrite(8, LOW);
}


void turnLeft() {
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  
  digitalWrite(10,LOW);  
  digitalWrite(8,HIGH);
}

void testBench() {
  analogWrite(9,255);
  analogWrite(11,255);
  moveForward();
  delay(1000);
  turnLeft();
  delay(1000);
  turnRight();
  delay(1000);
  moveBackward();
  delay(1000);
  moveForward();
  delay(1000);
  analogWrite(9,0);
  analogWrite(11,0);
 

}
