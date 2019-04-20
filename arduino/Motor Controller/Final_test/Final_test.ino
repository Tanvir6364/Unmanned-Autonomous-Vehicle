// duration for output
int time = 50;
// initial command
int command = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //receive command
  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
   send_command(command,time);
}

void right(int time){
  analogWrite(12,90);
  analogWrite(7,0);
  analogWrite(8,125);
  analogWrite(9,125);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(time);
}

void left(int time){
  analogWrite(12,0);  //left
  analogWrite(7,90);   //right
  analogWrite(8,0);
  analogWrite(9,0);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(time);
}

void forward(int time){
  analogWrite(12,70);
  analogWrite(7,70);
  analogWrite(8,100);
  analogWrite(9,100);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(time);
}

void reverse(int time){
  analogWrite(12,100);
  analogWrite(7,100);
  analogWrite(8,100);
  analogWrite(9,100);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(time);
}

void forward_right(int time){
  analogWrite(12,150);
  analogWrite(7,150);
  analogWrite(8,150);
  analogWrite(9,150);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(time);
}

void reverse_right(int time){
  delay(time);
}

void forward_left(int time){
  analogWrite(12,150);
  analogWrite(7,150);
  analogWrite(8,150);
  analogWrite(9,150);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(time);
}

void reverse_left(int time){
  delay(time);
}

void reset(){
  analogWrite(12,0);
  analogWrite(7,0);
  analogWrite(8,0);
  analogWrite(9,0);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 'F': forward(time); break;
     case 'B': reverse(time); break;
     case 'R': right(time); break;
     case 'L': left(time); break;

     //combination command
     case 'D': forward_right(time); break;
     case 'A': forward_left(time); break;
     case 8: reverse_right(time); break;
     case 9: reverse_left(time); break;

     default: Serial.print("Inalid Command\n");
    }
}
