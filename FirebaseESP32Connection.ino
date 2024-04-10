#include <WiFi.h>
#include <Firebase_ESP_Client.h>  // Instala esta librería desde el Administrador de Bibliotecas de Arduino

// Configura tus credenciales WiFi
const char* WIFI_SSID = "Santi";
const char* WIFI_PASSWORD = "asd123";

// Configura tu proyecto de Firebase
const char* FIREBASE_HOST = "rtdb-expl-cf6bd-default-rtdb.firebaseio.com";  // Ejemplo: "tuproyecto.firebaseio.com"
const char* FIREBASE_AUTH = "AIzaSyCn0kFEZoAAUvakxaxMir7lom2fctQr9ag";      // La clave que obtuviste

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConexión WiFi establecida. IP local: " + WiFi.localIP().toString());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Leer el estado de los 6 botones (asume que están conectados a pines GPIO)
  for (int i = 0; i < 6; i++) {
    buttonStates[i] = digitalRead(i + 2);             // Lee el estado del botón
    Firebase.setInt(String(i + 1), buttonStates[i]);  // Asigna el valor a Firebase
  }

  if (button1State == HIGH) {
    Firebase.setInt("uno", 1);
  } else {
    Firebase.setInt("uno", 0);
  }

  if (button2State == HIGH) {
    Firebase.setInt("dos", 1);
  } else {
    Firebase.setInt("dos", 0);
  }

  if (button3State == HIGH) {
    Firebase.setInt("tres", 1);
  } else {
    Firebase.setInt("tres", 0);
  }

  if (button4State == HIGH) {
    Firebase.setInt("cuatro", 1);
  } else {
    Firebase.setInt("cuatro", 0);
  }

  if (button5State == HIGH) {
    Firebase.setInt("cinco", 1);
  } else {
    Firebase.setInt("cinco", 0);
  }

  if (button6State == HIGH) {
    Firebase.setInt("seis", 1);
  } else {
    Firebase.setInt("seis", 0);
  }
}
