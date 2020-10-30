#define FS1 35  //Foot Switch
//#define KS1   //Key Switch
#define FWD 29  //Forward
#define REV 53  //Reverse
#define EN_P 47 //Enable
#define INPUT_A 41 //input a for steeering motor

  int fs1 = 0;
  int fwd = 0;
  int rev = 0;
  int enp = 0;
  int inp = 0;

void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(4800);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = SerialUSB.parseInt();
  switch(x)
  {
    case 0:
      fs1 = (fs1 + 1)%2; 
      break;

    case 1:
      fwd = (fwd + 1)%2; 
      break;

    case 2:
      rev = (rev + 1)%2;
      break;

    case 3:
      enp = (enp + 1)%2;
      break;

    case 4:
      inp = (inp + 1)%2;
  }



  digitalWrite(FS1, fs1);
  digitalWrite(FWD, fwd);
  digitalWrite(REV, rev);
  digitalWrite(EN_P, enp);
  digitalWrite(INPUT_A, inp);
  
}
