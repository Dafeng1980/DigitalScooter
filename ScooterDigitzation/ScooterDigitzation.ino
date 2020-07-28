#define ADSELVOL 0x20  // ADC channel 0 for bettery voltage
#define ADSELFUEL 0x21 // ADC channel 1 for fuel
#define ADSETEMP 0x22  // ADC channel 2 for ambient temperature


bool tempSmp = 0;
bool eTempSmp = 0;
bool fuelSmp = 0;
bool volSmp = 0;
bool tachSmp = 0;
bool speedSmp = 0;

unsigned char fuelSmpTM = 0;			// fuel sample counter 
unsigned char tmpSmpTM = 0;			// temperature sample counter 
unsigned char volSmpTM = 0;			// voltage sample counter 

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
uint8_t uctmp;
  T2_init()；
  attachInterrupt(0, rpm, RISING);
  sei();
  ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);  //ADC Enable ADC 1/64= 125K
  ADMUX = ADSELVOL;  // ADC set channel 0
  volSmp = 1; //enable voltage sample
  ADCSRA |= (1<<ADSC);  //Star ADC 

}

void loop() {
        if (((ADCSRA & (1<<ADSC)) != 0) && (volSmp != 0))
        {
          uctmp = ADCH;
          nVol += uctmp;
          volSmpTM++;
          ADMUX = ADSELFUEL;
          volSmp = 0;
          tempSmp = 0;
          fuelSmp = 0;
          _delayus(30);
          ADCSRA |= (1<<ADSC);
          if(volSmpTM <= 16)
          voltage = (unsigned char)(nVol >> 4);

        }
 

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