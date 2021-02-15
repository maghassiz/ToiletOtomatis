#define PROXIMITY 3
#define PIR 4
#define RELAY1 5
#define RELAY2 6
#define RELAY3 7
#define RELAY4 8

int dataPintu = 0;
int dataOrang = 0;


void setup() {
  Serial.begin(9600);
  pinMode(PROXIMITY, INPUT);
  pinMode(PIR, INPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
}

void loop() {
  Pintu();
  Serial.println(dataPintu);
  switch(dataPintu){
    case 1:
      Serial.println("lampu nyala");
      Orang();
      if (dataOrang==1){
        digitalWrite(RELAY1, HIGH);
      }
      break;
    case 0:
      Serial.println("lampu mati");
      Orang();
      if (dataOrang==0){
        digitalWrite(RELAY1, LOW);
      }
      break;
  }
}

void Pintu(){
  int sensorPintu = digitalRead(PROXIMITY);

  if (sensorPintu==0){
    if (dataPintu==0){
      Serial.println("Orang Masuk");
      dataPintu = 1;
      delay(1000);
    }

    else{
      Serial.println("Orang Keluar");
      dataPintu = 0;
      delay(1000);
    }    
  }
}

void Orang(){
  int sensorOrang = digitalRead(PIR);

  if (sensorOrang==HIGH){
    if (dataOrang==0){
      Serial.println("ada orang");
      Serial.println(dataOrang);
      dataOrang = 1;
      delay(500);
    }

    else{
      Serial.println("gaada orang");
      Serial.println(dataOrang);
      dataOrang = 0;
      delay(500);
    }
  }
}
