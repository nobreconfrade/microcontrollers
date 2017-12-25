int buffer;
int i, d[6], last[6] = {1,1,1,0,0,0};
char    pecas[32] = {'T','C','R',0,0,0};

void saiu(int i){
  buffer = i;
}
#define SIZE 2
void entrou(int i){
  char a = buffer%SIZE + 'a';
  char b = i%SIZE + 'a';
  char peca = pecas[buffer];
  Serial.print(peca);
  Serial.print(a);
  Serial.print(buffer/SIZE + 1);
  Serial.print('-');
  Serial.print(b);
  Serial.print(i/SIZE + 1);
  Serial.print('\n');
  
  pecas[buffer] = 0;
  pecas[i] = peca;
}

void setup()
{
  int i;
  for(i=48; i<=53; i++)
    pinMode(i, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //while(!digitalRead(9)){}
  //Serial.print("Start\n");

  
    for(i=0; i<6; i++){
      d[i] = digitalRead(i+48);

      if(d[i] == 0 && last[i] == 1)
          saiu(i);
      if(d[i] == 1 && last[i] == 0)
          entrou(i);

      last[i] = d[i];
    }
  //}

  delay(10); // Delay a little bit to improve simulation performance
}
