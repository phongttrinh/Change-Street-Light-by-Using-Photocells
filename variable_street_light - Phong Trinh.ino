// Phong Thanh Trinh

int const redPin = 4; 
int const yellowPin = 3;
int const photoresistorPin = A5;
unsigned long timeStamp;
float streetLight;
int sensorOutput;
int sensorMin = 1023;
int sensorMax = 0;
int countCycle = 0; 

void setup()
{
pinMode(redPin,OUTPUT);
pinMode(yellowPin, OUTPUT);
pinMode(photoresistorPin, INPUT);
}

void loop()
{
timeStamp = millis() ;
sensorOutput = analogRead(photoresistorPin);

 if (timeStamp < 5000){ 
digitalWrite(redPin, HIGH);
  if (sensorOutput > sensorMax){
    sensorMax = sensorOutput;}
  if (sensorOutput <sensorMin) {
    sensorMin= sensorOutput;} 
}
else {
 digitalWrite(redPin, LOW); 
 streetLight= 255.0* (float(sensorMax-sensorOutput)/float(sensorMax -sensorMin));
 analogWrite(yellowPin, streetLight);

}
}
