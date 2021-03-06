#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//add ds18b20 library
#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensorSuhu(&oneWire);

struct sensor_data {
  float suhu;
  float o2;
  float ph;
  byte priority;
  }kumpulan_data[99]; 
/*
asumsikan maks 99 data struct, setiap data 4bytes float + 4bytes float 02 + 4bytes float 03 + 1byte priority = 13 bytes
13*99 = 1399 bytes digunakan untuk struct
*/ 
byte jumlah_data = 0;

RF24 radio(A0, 10); // CE, CSN
const byte address[6] = "00001";

/*
 role 0 = node
role 1 = gateway
*/
// byte role = 0;

void setup()
{
	setupnrf();
  Serial.begin(115200);
  sensorSuhu.begin();
}

void loop()
{
	
}

void setupnrf() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

int decisionTreeAlgorithm(float suhu, float o2, float ph) {
    return 0;
}

void baca_sensor() {
  sensors.requestTemperatures();
  float suhu = sensors.getTempCByIndex(0);
  float o2 = random(0,100); //buat data random
  float ph = random(0,14);
  byte priority = decisionTreeAlgorithm(suhu, o2, ph);
  jumlah_data++;
  kumpulan_data[jumlah_data].suhu = suhu;
  kumpulan_data[jumlah_data].o2 = o2;
  kumpulan_data[jumlah_data].ph = ph;
  kumpulan_data[jumlah_data].priority = priority;
}

void sendData(struct sensor_data kumpulan_data[99]) {
  for (int i = 1; i <= 3; i++) {
    for(int j = 0; j <= 99; j++) {
      if (kumpulan_data[j].priority == i) {
        radio.write(&kumpulan_data[j], sizeof(kumpulan_data[j]));
      }
    }
  }
  jumlah_data = 0;
}

void receiveData(){
  if (radio.available()) {
    jumlah_data++;
    radio.read(&kumpulan_data[jumlah_data], sizeof(kumpulan_data[jumlah_data]));
    if (kumpulan_data[jumlah_data].priority == 1) {
      //kirim data prioritas ke gateway
      radio.write(&kumpulan_data[jumlah_data], sizeof(kumpulan_data[jumlah_data]));
      jumlah_data--;
  }
  
  }
}