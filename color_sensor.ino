#define S0 34
#define S1 23
#define S2 27
#define S3 29
#define sensorOut 28
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
   redfrequency = pulseIn(sensorOut, LOW);
 
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenfrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
 
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bluefrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
/*
 if(redfrequency < greenfrequency && redfrequency < bluefrequency) {
  Serial.println("RED");
 }
 else if(greenfrequency < redfrequency && greenfrequency < bluefrequency) {
  Serial.println("GREEN");
 }
 else if(bluefrequency < redfrequency && bluefrequency < greenfrequency) {
  Serial.println("BLUE");
 }
 */
 if(greenfrequency > 38 && greenfrequency < 50) {
  Serial.println("GREEN");
 }
 else if(bluefrequency > 80 && greenfrequency > 100) {
  Serial.println("RED");
 }
 else if(greenfrequency < 100 && greenfrequency > 60) {
  Serial.println("BLUE");
 }
  else if(redfrequency < 40 && bluefrequency < 30) {
  Serial.println("WHITE");
 }
 else
 {
  Serial.println("ERROR");
 }
 
 }
