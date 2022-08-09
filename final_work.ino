int soilMoistureValue = 0;
int percentage=0;


int green = 13;
int yellow = 12;
int red = 11;

#define waterSensorPower 6
#define sensorPin A1
int val = 0;
int waterLevel = 0;
void setup() {

  //relay 
  pinMode(3,OUTPUT);

  //leds
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);

  //waterSensor
  pinMode(waterSensorPower, OUTPUT);
  digitalWrite(waterSensorPower, LOW);

  Serial.begin(9600);

}

void loop() {

  
  getMoistureValue();
  waterLevel = readWaterSensor();
  Serial.println(waterLevel);
  showWaterHeight();
  

}

void showWaterHeight(){

  if(waterLevel<15){
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
  else if(waterLevel>15 && waterLevel < 500)
  {
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
  }
  
}

int readWaterSensor(){

  digitalWrite(waterSensorPower, HIGH);
  delay(10);
  val = analogRead(sensorPin);
  digitalWrite(waterSensorPower, LOW);
  delay(1000);
  return val;
  
}

void getMoistureValue(){

  soilMoistureValue = analogRead(A0);

Serial.println(percentage);

percentage = map(soilMoistureValue, 490, 1023, 100, 0);

if(percentage < 10)  

{

  //Serial.println(" pump on");
  //Serial.println(" Saturation " + percentage);

  digitalWrite(3,LOW);

}

if(percentage >80)

{

  //Serial.println("pump off");
  //Serial.println(" Saturation " + percentage);
  digitalWrite(3,HIGH);

}
}
