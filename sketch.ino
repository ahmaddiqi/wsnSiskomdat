#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
struct sensor_data {
  float suhu;
  float o2;
  float ph;
  int priority;
}kumpulan_data[99];


RF24 radio(A0, 10); // CE, CSN
const byte address[6] = "00001";
void setup()
{
	setupnrf();
    Serial.begin(115200);
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

int decisionTreeAlgorithm(struct sensor_data data) {
    return 3;
}

void sendData(struct sensor_data kumpulan_data[99]) {
  for (int i = 1; i <= 3; i++) {
    for(int j = 0; j <= 99; j++) {
      if (kumpulan_data[j].priority == i) {
        radio.write(&kumpulan_data[j], sizeof(kumpulan_data[j]));
      }
    }
  }
}

void receiveData(){

}
