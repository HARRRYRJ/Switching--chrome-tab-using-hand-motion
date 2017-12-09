int trigger1 = 2; //Trigger pin of 1st Sesnor connected with Arduino port 2
int echo1 = 3; //Echo pin of 1st Sesnor conected with Arduino port 3
int trigger2 = 4; //Trigger pin of 2nd Sesnor connected with Arduino port 4
int echo2 = 5;//Echo pin of 2nd Sesnor connected with Arduino port 5
long time_taken;
int dist,dist_left,dist_right;
 
void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}
/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;

}
void loop() { 
calculate_distance(trigger1,echo1);//sensor 1 is pitting on the left side
dist_left =dist; //get distance from left sensor
calculate_distance(trigger2,echo2);//sensor 2 is putting on the right side
dist_right =dist; //get distance from right sensor

//for switching one tab to another in chrome
if ((dist_left >40 && dist_right>40) && (dist_left <50 && dist_right<50)) //Detect both hands
{
  Serial.println("Tab change"); 
  delay (500);
}

//for zoom in
if (( dist_left>30) && ( dist_left<50)) 
{
  Serial.println("Zoom In"); 
  delay (500);
}


//for zoom out
if (( dist_left>0) && ( dist_left<29)) 
{
  Serial.println("Zoom Out"); 
  delay (500);
}
calculate_distance(trigger1,echo1);
dist_left =dist;
calculate_distance(trigger2,echo2);
dist_right =dist;
delay(200);
}
 
