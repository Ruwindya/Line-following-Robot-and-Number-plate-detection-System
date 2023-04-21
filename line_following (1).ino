#define LEFT_SENSOR 46  
#define RIGHT_SENSOR 42
#define LEFT_MOTOR_1 11 
#define LEFT_MOTOR_2 10 
#define RIGHT_MOTOR_1 8 
#define RIGHT_MOTOR_2 9 
#define trigPin 36
#define echoPin 32

void setup() {

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(LEFT_MOTOR_1, OUTPUT);
  pinMode(LEFT_MOTOR_2, OUTPUT);
  pinMode(RIGHT_MOTOR_1, OUTPUT);
  pinMode(RIGHT_MOTOR_2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop() {
  int leftSensorValue = digitalRead(LEFT_SENSOR);
  int rightSensorValue = digitalRead(RIGHT_SENSOR);
  long duration, distance;
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  delay(50); 

  if(distance < 20){
    digitalWrite(LEFT_MOTOR_1, LOW);
    analogWrite(LEFT_MOTOR_2, 0);
    digitalWrite(RIGHT_MOTOR_1, LOW);
    analogWrite(RIGHT_MOTOR_2, 0);
   }
   else{
       
         if (leftSensorValue == 1 && rightSensorValue == 0) {
             digitalWrite(LEFT_MOTOR_1, LOW);
             analogWrite(LEFT_MOTOR_2, 170); // A1
             analogWrite(RIGHT_MOTOR_1, 170); //A2
             digitalWrite(RIGHT_MOTOR_2, LOW);
             
         }
       
         else if (leftSensorValue == 0 && rightSensorValue == 1) {
            analogWrite(LEFT_MOTOR_1, 170);
            digitalWrite(LEFT_MOTOR_2, LOW);
            digitalWrite(RIGHT_MOTOR_1, LOW);
            analogWrite(RIGHT_MOTOR_2, 170); 
            
         }
        
          else if (leftSensorValue == 1 && rightSensorValue == 1) {
               analogWrite(LEFT_MOTOR_1, 170); 
               digitalWrite(LEFT_MOTOR_2, LOW);
               analogWrite(RIGHT_MOTOR_1, 170); 
               digitalWrite(RIGHT_MOTOR_2, LOW);
               
          }
         
           else {
              digitalWrite(LEFT_MOTOR_1, LOW);
              analogWrite(LEFT_MOTOR_2, 150);
              digitalWrite(RIGHT_MOTOR_1, LOW);
              analogWrite(RIGHT_MOTOR_2, 150);
             
            }
    }
}
