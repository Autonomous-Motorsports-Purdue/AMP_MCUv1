#define FS1 35  //Foot Switch
//#define KS1   //Key Switch
#define FWD 29  //Forward
#define REV 53  //Reverse
#define EN_P 47 //Enable
#define INPUT_A 41 //input a for steeering motor

<<<<<<< HEAD
=======
  int prev_fs1 = 0;
  int prev_fwd = 0;
  int prev_rev = 0;
  int prev_enp = 0;
  int prev_inp = 0;

>>>>>>> origin/MitchDev
  int fs1 = 0;
  int fwd = 0;
  int rev = 0;
  int enp = 0;
  int inp = 0;

void setup() {
  // put your setup code here, to run once:
<<<<<<< HEAD
  SerialUSB.begin(4800);
=======

  pinMode(FS1, OUTPUT);
  pinMode(FWD, OUTPUT);
  pinMode(REV, OUTPUT);
  pinMode(EN_P, OUTPUT);
  pinMode(INPUT_A, OUTPUT);
  Serial.begin(9600);

  Serial.println("started digital test");
>>>>>>> origin/MitchDev

}

void loop() {
  // put your main code here, to run repeatedly:
<<<<<<< HEAD
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
  
=======

  prev_fs1 = fs1;
  prev_fwd = fwd;
  prev_rev = rev;
  prev_enp = enp;
  prev_inp = inp;
  if (Serial.available() > 0) {
    char x = Serial.read();
 
    Serial.print("echo: ");
    Serial.print(x);
    switch(x)
    {
      case '0':
        fs1 = (fs1 + 1)%2; 
        break;
  
      case '1':
        fwd = (fwd + 1)%2; 
        break;
  
      case '2':
        rev = (rev + 1)%2;
        break;
  
      case '3':
        enp = (enp + 1)%2;
        break;
  
      case '4':
        inp = (inp + 1)%2;
    }
  
    digitalWrite(FS1, fs1);
    digitalWrite(FWD, fwd);
    digitalWrite(REV, rev);
    digitalWrite(EN_P, enp);
    digitalWrite(INPUT_A, inp);
  }

  if (prev_fs1 != fs1 || prev_fwd != fwd || prev_rev != rev || prev_enp != enp || prev_inp != inp) {
    Serial.print("fs1: ");
    Serial.print(fs1);
    Serial.print(", fwd: ");
    Serial.print(fwd);
    Serial.print(", rev: ");
    Serial.print(rev);
    Serial.print(", enp: ");
    Serial.print(enp);
    Serial.print(", inp: ");
    Serial.println(inp); 
  }
>>>>>>> origin/MitchDev
}
