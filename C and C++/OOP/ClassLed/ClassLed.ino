
class Sensor {
protected:
     int pin;
     int power_; //sensor power_.
     String LedType;//sensor type (digital or analog)
public:   
     bool pwm_using;
     virtual void getConfig(){};// sensor conection characteristic
     virtual void shining(){};
};

class Led : public Sensor{
public:

Led (int);
void shining(int);
void getConfig();
String LedType="simple Led";  
};
Led::Led(int pin_){
  pin=pin_;
  pinMode(pin,OUTPUT);
}
void Led::shining(int powerr){
power_=powerr;

if(pwm_using==0){
digitalWrite(pin,power_);
  }
  if(pwm_using==1){
    analogWrite(pin,power_);
  }
}
void  Led::getConfig(){
Serial.print("pin of Led is ");Serial.println(pin);
Serial.print("Led type: ");Serial.println(LedType);
Serial.print("pwm using ");Serial.println(pwm_using);
Serial.print("power: ");Serial.println(power_);

}
class RGB : public Sensor{
private:
int Rpin;
int Gpin;
int Bpin;

int Rval;
int Bval;
int Gval;
public:
RGB(int,int,int);
void shining(int, int, int);
void getConfig();
String LedType="simple Led";
};

void RGB::getConfig(){
Serial.print("pin of Led is ");Serial.println(pin);
Serial.print("Led type: ");Serial.println(LedType);
Serial.print("pwm using ");Serial.println(pwm_using);
Serial.print("Rval ");Serial.println(Rval);
Serial.print("Gval ");Serial.println(Gval);
Serial.print("Bval ");Serial.println(Bval);

}

RGB::RGB(int R, int G, int B){
Rpin=R;
Gpin=G;
Bpin=B;

pinMode(Rpin,OUTPUT);
pinMode(Gpin,OUTPUT);
pinMode(Bpin,OUTPUT);

}

void RGB::shining(int r, int g, int b){
Rval=r;
Gval=g;
Bval=b;
if(pwm_using==0){
digitalWrite(Rpin,Rval);
digitalWrite(Gpin,Gval);
digitalWrite(Bpin,Bval);
}
if(pwm_using==1){
analogWrite(Rpin,Rval);
analogWrite(Gpin,Gval);
analogWrite(Bpin,Bval);
}
}
RGB LeD(11,10,9);

void setup() {
Serial.begin(9600);

LeD.pwm_using=2;
LeD.getConfig();
delay(2000);
}

void loop() {
LeD.shining(100,20,50);

}
