//ClassLed.ino


class Sensor {
protected:
	 int pin;
     int power_; //sensor power.
     String LedType;//sensor type 
     const int max_val = 255;
public:   
     bool pwm_using;
     virtual void getConfig(){};// sensor conection characteristic
     virtual void shining(){};
     virtual void showpower(){};
};

class Led : public Sensor{
private:
	 Led (int);
	 String LedType="simple Led";
public:
	 void shining(int);
	 void getConfig();
	 void showpower();
};

Led::Led(int pin)
{
  this->pin=pin;
  pinMode(pin,OUTPUT);
}

void Led::shining(int power_)
{
 this->power_=power_;
 if(power_>max_val)power_=max_val;

 if(pwm_using==0)
 {
  digitalWrite(pin,power_);
 }
 if(pwm_using==1)
 {
  analogWrite(pin,power_);
 }
}
void  Led::getConfig()
{
 Serial.print("pin of Led is ");Serial.println(pin);
 Serial.print("Led type: ");Serial.println(LedType);
 Serial.print("pwm using ");Serial.println(pwm_using);
}

void Led::showpower()
{
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

void RGB::getConfig()
{
 Serial.print("pin of Led is ");Serial.println(pin);
 Serial.print("Led type: ");Serial.println(LedType);
 Serial.print("pwm using ");Serial.println(pwm_using);
 Serial.print("Rval ");Serial.println(Rval);
 Serial.print("Gval ");Serial.println(Gval);
 Serial.print("Bval ");Serial.println(Bval);
}

RGB::RGB(int R, int G, int B)
{
 Rpin=R;
 Gpin=G;
 Bpin=B;

 pinMode(Rpin,OUTPUT);
 pinMode(Gpin,OUTPUT);
 pinMode(Bpin,OUTPUT);
}

void RGB::shining(int r, int g, int b)
{
 if(Rval>max_val)Rval=max_val;
 if(Gval>max_val)Gval=max_val;
 if(Bval>max_val)Bval=max_val;

 Rval=r;
 Gval=g;
 Bval=b;

 if(pwm_using==0)
 {
  digitalWrite(Rpin,Rval);
  digitalWrite(Gpin,Gval);
  digitalWrite(Bpin,Bval);
 }
 if(pwm_using==1)
 {
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