

bool tempSmp = 0;
bool eTempSmp = 0;
bool fuelSmp = 0;
bool volSmp = 0;
bool tachSmp = 0;
bool speedSmp = 0;


l
unsigned int nSysT = 0;
unsigned int nTemp = 0;
unsigned int nETemp = 0;
unsigned int nSpeed = 0;
unsigned int nFuel = 0;
unsigned int nVol = 0;
unsigned int nTach = 0;

void rpm (){
  nTach++；
}

void setup() {

  T2_init()；
  attachInterrupt(0, rpm, RISING);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void T2_init(){
  OCR = 0x00;
  TCNT2 =0x00;
  TCCR2 = 0x03;  
  TIMSK |= (1 << TOIE2); 
}

ISR(TIMER2_OVF_vect)
{
  nSysT++;
}