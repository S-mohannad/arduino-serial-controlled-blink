int x;
void setup() {
pinMode(2,OUTPUT);
Serial.begin(9600);
Serial.println("pls enter the delay u need in ms:");
while(Serial.available()==0){}
x=Serial.parseInt();
}
void loop(){
digitalWrite(2, HIGH);
delay(x);
digitalWrite(2,LOW);
delay(x);
}