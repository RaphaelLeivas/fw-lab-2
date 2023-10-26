#include "HX711.h"
#include "SoftwareSerial.h"

#define DT A1
#define SCK A0

#define HC05_TXD 4
#define HC05_RXD 5

int dadoBluetooth = 0;

// HX711 cell;
SoftwareSerial bluetooth(HC05_TXD, HC05_RXD);

void setup() {
  Serial.begin(9600);

  // cell.begin(DT, SCK);
  bluetooth.begin(9600);
}

void loop() {
  // float read = cell.read();
  // Serial.println(read);

  bluetooth.write("Hello World!");
  bluetooth.write("\n");

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