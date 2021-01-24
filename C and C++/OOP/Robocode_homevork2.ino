

class Sensor {
public:
     int pin; //sensor pin
     int val; //sensor value. why val shining ?
     String SensorType;//sensor type (digital or analog)
     
     Sensor(int);// output constructor// sensor pin 
     void printData();//data out
     void getConfig();// sensor conection characteristic
     void sensor_type(String);// sensor type input method
};
Sensor::Sensor(int pin_){
    pin=pin_;
}

void Sensor::printData(){
    if(SensorType=="digital"){
    val=digitalRead(pin);
    pinMode(pin,INPUT);
}
    if(SensorType=="analog")val=analogRead(pin);

    Serial.print("Sensor data is ");Serial.println(val);
 }
void  Sensor::getConfig(){
Serial.print("pin of sensor is ");Serial.println(pin);
Serial.print("Sensor type: ");Serial.println(SensorType);
}
void Sensor::sensor_type(String SensorType_){
SensorType=SensorType_;
}
//Sensor pot(0) ;
Sensor button(13);
void setup() {
Serial.begin(9600);
//pot.sensor_type("analog");
//pot.getConfig();

button.sensor_type("digital");
button.getConfig();
delay(2000);
}

void loop() {
button.printData();
//pot.printData();
//if(pot.val>123&pot.val<321){
//  delay(1000);
//}

}
