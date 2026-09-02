#include <Servo.h>

Servo servo;

// Sensor Tangan
#define trigTangan 2
#define echoTangan 3

// Sensor Penuh
#define trigPenuh 4
#define echoPenuh 5

#define buzzer 8
#define servoPin 10

long durasi;
int jarakTangan;
int jarakPenuh;

bool statusTutup = false;  // false = tertutup
unsigned long waktuBuka;
const int waktuTunggu = 3000; // 3 detik

// Fungsi baca jarak
int bacaJarak(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  durasi = pulseIn(echo, HIGH, 30000); // timeout 30ms
  int jarak = durasi * 0.034 / 2;

  return jarak;
}

void setup() {
  pinMode(trigTangan, OUTPUT);
  pinMode(echoTangan, INPUT);

  pinMode(trigPenuh, OUTPUT);
  pinMode(echoPenuh, INPUT);

  pinMode(buzzer, OUTPUT);

  servo.attach(servoPin);
  servo.write(0); // posisi awal tertutup

  Serial.begin(9600);
}

void loop() {

  jarakTangan = bacaJarak(trigTangan, echoTangan);
  delay(50); // jeda supaya sensor tidak bentrok
  jarakPenuh = bacaJarak(trigPenuh, echoPenuh);

  Serial.print("Tangan: ");
  Serial.print(jarakTangan);
  Serial.print(" | Penuh: ");
  Serial.println(jarakPenuh);

  // ==========================
  // CEK KONDISI PENUH
  // ==========================
  if (jarakPenuh > 0 && jarakPenuh <= 8) {
    digitalWrite(buzzer, HIGH);   // bunyi terus
  } else {
    digitalWrite(buzzer, LOW);
  }

  // ==========================
  // BUKA TUTUP (JIKA TIDAK PENUH)
  // ==========================
  if (jarakTangan > 0 && jarakTangan <= 15 && jarakPenuh > 8) {
    if (!statusTutup) {
      servo.write(90);   // buka
      statusTutup = true;
      waktuBuka = millis();
    }
  }

  // Tutup kembali setelah 3 detik
  if (statusTutup && millis() - waktuBuka >= waktuTunggu) {
    servo.write(0);   // tutup
    statusTutup = false;
  }

}