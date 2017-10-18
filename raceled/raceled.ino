#define GRE1 2
#define GRE2 3
#define YEL1 4
#define YEL2 5
#define RED1 6
#define RED2 7 

void setup() {
  pinMode(GRE1,OUTPUT);
  pinMode(GRE2,OUTPUT);
  pinMode(YEL1,OUTPUT);
  pinMode(YEL2,OUTPUT);
  pinMode(RED1,OUTPUT);
  pinMode(RED2,OUTPUT);
}

void loop() {
  int port[6] = {GRE1,GRE2,YEL1,YEL2,RED1,RED2};
  for(int i = 0; i < sizeof(port); i++){
    digitalWrite(port[i],HIGH);
    if(i < 5){
      delay(500);
    }
    else{
      delay(100);
    }
  }
  for(int j = 0; j < 5; j++){
    for(int i = 0; i < sizeof(port); i++){
      digitalWrite(port[i],LOW);
    }
    delay(100);
    for(int i = 0; i < sizeof(port); i++){
      digitalWrite(port[i],HIGH);
    }
    delay(100); 
  }
  for(int i = 0; i < sizeof(port); i++){
      digitalWrite(port[i],LOW);
  }
  delay(1000);
}
