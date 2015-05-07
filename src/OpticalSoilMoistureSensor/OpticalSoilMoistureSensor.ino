int led = 13;
int inputPin = 0; 

int val = 0;           // variable to store the value read
const int numReadings = 100;
int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int long total = 0;                  // the running total
int average = 0;                // the average

int existingReadings = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);          //  setup serial
  pinMode(led, OUTPUT);     

}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(1); //wait for the LED to reach steady state

  for (int index = 0; index < numReadings; index++){
    int value = analogRead(inputPin); 
    readings[index] = value;  
    delay(1); 
  }
  total = 0;
  for (int index = 0; index < numReadings; index++){
    total = readings[index] + total; 
    Serial.print("total ");
    Serial.println(total);
  }
  average = total / numReadings;

  delay(1); 

  //print numbers
  Serial.print(readings[index]);
  Serial.print("Average: ");
  Serial.println(average); 

  Serial.print("Mapped average: ");
  Serial.println(map(average, 0, 1023, 0, 100));   
  delay(10);        // delay in between reads for stability            

  //delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second


} // loop ends here



