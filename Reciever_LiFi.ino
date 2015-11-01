int a=0;
volatile char i=0b10000000;
void setup()
{
  pinMode(A0,input);
  pinMode(A1,input);    //thresh
 //Hardware Interrupts
 EICRA=0b00000001;
 EIMSK=0b00000001;
 
 //Timer Interrupts
 TCCR1A = 0b00000000;
 TCCR1B = 0b00001001;
 TIMSK1 = 0b00000010; 
 TCCR1C = 0x00000000;
}

void loop() 
{
  
}

ISR(vect_INT0)
{
  OCR1A=TCNT1>>1;
  TCNT1=0;
}

ISR(vect_TIMER1_COMPA)
{
  if(i%4==1)
  {
    if(analogRead(A0)>analogRead(A1))
    {
     data=data>>1;
    data=data|0b10000000;
    }
    else if(analogRead(A0)<analogRead(A1))
    {
    data=data>>1;  
    }   
  }
  i++;
}
