int led = 13;
int inputPin = 0;     // potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;           // variable to store the value read
const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int existingReadings = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);          //  setup serial
  pinMode(led, OUTPUT);     
  // initialize all the readings to 0: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor: 

  existingReadings++;

  //Serial.print("Total readings: ");
  //Serial.println(existingReadings); 

  int value = analogRead(inputPin); 
  Serial.print("Value: ");
  Serial.println(value); 

  readings[index] = value;
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  if (existingReadings > numReadings)
    average = total / numReadings;         
  else
    average = total / existingReadings;
  // send it to the computer as ASCII digits

    // Add this line, fix the quotes
  Serial.print("Average: ");

  Serial.println(average);

  Serial.print("Mapped average: ");
  Serial.println(map(average, 0, 1023, 0, 100));   
  delay(1);        // delay in between reads for stability            

  //delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(10);               // wait for a second
  val = analogRead(inputPin);    // read the input pin

    // Add this line, fix the quotes
  Serial.print("Low value: ");

  Serial.println(val);             // debug value

  // Add this line
  val = 0;

} // loop ends here
