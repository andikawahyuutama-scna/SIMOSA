# SIMOSA — Smart Intelligent Modern Open Smart Automation

SIMOSA adalah prototype tempat sampah otomatis berbasis Arduino yang dirancang untuk mengurangi kontak langsung pengguna dengan tutup tempat sampah.

## ⚙️ Cara Kerja

Sistem menggunakan sensor ultrasonik HC-SR04 untuk mendeteksi keberadaan tangan pengguna.

1. Arduino melakukan inisialisasi sensor dan servo.
2. HC-SR04 membaca jarak objek.
3. Jika objek terdeteksi pada jarak kurang dari 15 cm, Arduino mengaktifkan servo.
4. Servo membuka tutup tempat sampah.
5. Sistem menunggu beberapa detik.
6. Servo kembali ke posisi awal dan menutup tutup.
7. Sistem kembali membaca sensor secara berulang.

## 🔧 Komponen

- Arduino Nano V3 CH340
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Breadboard
- Jumper Wires

## 💻 Teknologi

- C/C++ (Arduino)
- Arduino IDE
- HC-SR04
- Servo Motor

## 🎯 Tujuan

SIMOSA dikembangkan sebagai prototype sederhana untuk menerapkan teknologi mikrokontroler dalam otomatisasi tempat sampah serta mengurangi kontak langsung pengguna.

## 🚧 Pengembangan

Beberapa pengembangan yang dapat dilakukan:

- Power supply yang lebih stabil
- Pengaturan kecepatan servo
- Sensor pendeteksi kapasitas sampah
- Integrasi IoT
- Monitoring melalui aplikasi

## 📌 Status

Prototype / Educational Project
