#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int sensorValue = 0;
String dataAtual = "2025-06-05";
String horaAtual = "15:42:00";
String bairro = "Santo Amaro - CIRCUITO A1";

bool dadosSalvos = false;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(A0, INPUT);  
  Serial.begin(9600);

  // Verifica flag na EEPROM
  //if (EEPROM.read(0) == 1) {
  //  int valorSalvo;
  //  char bairroLido[50], dataLida[20], horaLida[20];

   // EEPROM.get(1, valorSalvo);
   // readStringFromEEPROM(10, bairroLido, 50);
   // readStringFromEEPROM(60, dataLida, 20);
   // readStringFromEEPROM(80, horaLida, 20);

    //Serial.println("🔁 Dados recuperados da EEPROM:");
   // exportarParaBase(valorSalvo, String(bairroLido), String(dataLida), String(horaLida));

    //EEPROM.write(0, 0); // limpa flag
 // }
}

void loop() {
  int valor_Luz = analogRead(A0);

  if (valor_Luz < 300) {
    lcd.setCursor(0, 0);
    lcd.print("Queda de Energia");

   // if (!dadosSalvos) {
   //  EEPROM.write(0, 1); // Flag de dados salvos
   //   EEPROM.put(1, valor_Luz);
   //   writeStringToEEPROM(10, bairro);
   //   writeStringToEEPROM(60, dataAtual);
   //   writeStringToEEPROM(80, horaAtual);
   //   dadosSalvos = true;
   // }

    exportarParaBase(valor_Luz, bairro, dataAtual, horaAtual);
    delay(2000);
  } else {
    lcd.clear();
    dadosSalvos = false;
  }
}

void exportarParaBase(int valorSensor, String bairro, String data, String hora) {
  Serial.print("INSERT INTO monitor_energia (valor_sensor, bairro, data, hora) VALUES (");
  Serial.print(valorSensor);
  Serial.print(", '");
  Serial.print(bairro);
  Serial.print("', '");
  Serial.print(data);
  Serial.print("', '");
  Serial.print(hora);
  Serial.println("');");
}

// -------------------------------
// Funções auxiliares EEPROM
// -------------------------------
void writeStringToEEPROM(int startAddress, String data) {
  for (int i = 0; i < data.length(); i++) {
    EEPROM.write(startAddress + i, data[i]);
  }
  EEPROM.write(startAddress + data.length(), '\0'); // finalizador nulo
}

void readStringFromEEPROM(int startAddress, char* buffer, int maxLength) {
  for (int i = 0; i < maxLength; i++) {
    buffer[i] = EEPROM.read(startAddress + i);
    if (buffer[i] == '\0') break;
  }
}