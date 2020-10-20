int OUT = 23; //pin 2 of Arduino is connected to the output of the sensor 
 
void setup() 
{ 
 Serial.begin(9600); //inicjalizaja monitor serial port 
 pinMode(OUT, INPUT); //setting Arduino pin 2 as output 
 Serial.println("Test of spacing"); 
 Serial.println(""); 
} 
 
void loop() 
{ 
 
 Serial.print("object: "); //display results on the screen in a loop for 500 MS 
 if(digitalRead(OUT) == 0) //low state indicates detection of the object 
 { //status is high, and the lack of 
 Serial.println("YES"); 
 } 
 if(digitalRead(OUT) == 1) 
 { 
 Serial.println("NOT"); 
 } 
 delay(500); 
} 
