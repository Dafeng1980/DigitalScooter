bool tempSmp = 0;
bool eTempSmp = 0;
bool fueSmp = 0;
bool volSmp = 0;
bool eSpeeedSmp = 0;
bool speedSmp = 0;



unsigned int nSysT = 0;
unsigned int nTemp = 0;
unsigned int nETemp = 0;
unsigned int nSpeed = 0;
unsigned int nFue = 0;
unsigned int nVol = 0;
unsigned int nESpeed = 0;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void T2_init(){
  OCR = 0x00;
  TCNT2 =0x00;
  TCCR2 = 0x03;
  TIMSK =| (TOIE2 >> 1);
}

ISR(TIMER2_OVF_vect)
{
  nSysT++;
}