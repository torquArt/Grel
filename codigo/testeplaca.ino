void setup(){
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4,INPUT);
pinMode(A5, INPUT);

Serial.begin(9600);
}

void loop(){
Serial.print(analogRead(A1));
Serial.print(" /// ");
Serial.print(analogRead(A2));
Serial.print(" /// ");
Serial.print(analogRead(A3));
Serial.print(" /// ");
Serial.print(analogRead(A4));
Serial.print(" /// ");
Serial.println(analogRead(A5));
}
