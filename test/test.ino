#include "HX711.h"
#include "SoftwareSerial.h"

#define DT A1
#define SCK A0

#define HC05_TXD 4
#define HC05_RXD 5
#define HC05_STATE 3
#define LED_PIN 3

#define MESSAGE_LENGTH 32]
#define NUMBER_OF_BALANCES 3

int dadoBluetooth = 0;

HX711 cell;
SoftwareSerial bluetooth(HC05_TXD, HC05_RXD);

float getGramsFromRead(float read) {
  // y = -2x + 1068

  return -2.02 * (read / 1000) + 1074.68;
}

void setup() {
  // pinMode(LED_PIN, OUTPUT);
  // digitalWrite(LED_PIN, HIGH);

  Serial.begin(9600);

  // cell.begin(DT, SCK);
  bluetooth.begin(9600);
  pinMode(HC05_STATE, INPUT);
}

void loop() {
  // float read = cell.read();
  // Serial.println(getGramsFromRead(read));

  const bool isBluetoothConnected = digitalRead(HC05_STATE);

  char jsonString[256] = "{\"balances\":[{\"id\":1,\"measure\":128.52},{\"id\":2,\"measure\":74.01},{\"id\":3,\"measure\":0}],\"bootTime\":15263221}";

  if (isBluetoothConnected) {
    double read = 128.57;
    char message[MESSAGE_LENGTH];
    strcpy(message, "Medido: ");
    dtostrf(read, 2, 2, &message[strlen(message)]);

    bluetooth.write(jsonString);
    bluetooth.write("\n");
  }

  if (bluetooth.available()) {         //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
    dadoBluetooth = bluetooth.read();  //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH

    if (dadoBluetooth == '1') {      //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("LED LIGADO");  //IMPRIME O TEXTO NA SERIAL
    }
    if (dadoBluetooth == '0') {         //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("LED DESLIGADO");  //IMPRIME O TEXTO NA SERIAL
    }
    if (dadoBluetooth == 'b') {               //SE O VALOR RECEBIDO FOR IGUAL A b, FAZ
      Serial.println("LOOP DO LED ATIVADO");  //IMPRIME O TEXTO NA SERIAL
    }
  }

  delay(1000);
}