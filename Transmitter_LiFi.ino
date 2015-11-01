int arr[8]={0,0,0,0,0,0,0,0};
char data;
unsigned byte i=0b00000001;
int k=0;
void setup() {
pinMode(3,OUTPUT);
TCCR1A = 0b00000000;
TCCR1B = 0b00001001;
TIMSK1 = 0b00000010; 
OCR1A=7999;
}


void loop() 
{
  if(Serial.available())
  {
  data=Serial.read();
  i=0b00000001;
  }
}

ISR(vect_TIMER1_COMPA)
{
  if(k==1)
  {
      if(data&i==i)
      {
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      i<<1;
      }
      else
      {
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      i<<1;
      }
      k=0;
  }
  else
  {
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  k=1;
  }
}
