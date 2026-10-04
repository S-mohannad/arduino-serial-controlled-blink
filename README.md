# 💡 User-Controlled LED Blink Speed via Serial

> **Arduino Project #13** — المستخدم يحدد سرعة وميض LED عبر Serial Monitor

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

مشروع يتيح للمستخدم التحكم بسرعة وميض LED عبر إدخال قيمة من Serial Monitor:

- عند تشغيل الجهاز، يطلب البرنامج من المستخدم إدخال قيمة الـ delay بالـ ms
- البرنامج ينتظر حتى يُدخل المستخدم القيمة (`while Serial.available() == 0`)
- بعد الإدخال، يومض LED على pin 2 بنفس القيمة تشغيلاً وإطفاءً للأبد

---

## 🔌 Circuit

```
Arduino UNO
                    ┌─────────────┐
                    │             │
  pin 2  ──[220Ω]──┤► (LED)      │── GND
                    │             │
                    └─────────────┘
```

| المكون | التوصيل |
|--------|---------|
| LED | الساق الطويلة → مقاومة 220Ω → pin 2 / الساق القصيرة → GND |

---

## 💡 Concepts Used

- `Serial.begin()` — فتح اتصال Serial بسرعة 9600 baud
- `Serial.println()` — طباعة رسالة للمستخدم في Serial Monitor
- `Serial.available()` — التحقق من وجود بيانات واردة
- `Serial.parseInt()` — قراءة رقم صحيح من المستخدم
- `while` — الانتظار حتى يُدخل المستخدم القيمة
- المتغير العام `x` — يُقرأ مرة واحدة في `setup()` ويُستخدم في `loop()`

---

## 📊 Behavior

| المرحلة | الحدث |
|---------|-------|
| البداية | يطبع "pls enter the delay u need in ms:" |
| الانتظار | البرنامج يتوقف حتى المستخدم يُدخل رقم |
| بعد الإدخال | LED يومض بالتأخير المُدخل (HIGH → delay → LOW → delay) |
| إلى الأبد | نفس السرعة طوال وقت التشغيل |

---

## 🔗 Code

```cpp
int x;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  Serial.println("pls enter the delay u need in ms:");
  while (Serial.available() == 0) {}
  x = Serial.parseInt();
}

void loop() {
  digitalWrite(2, HIGH);
  delay(x);
  digitalWrite(2, LOW);
  delay(x);
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل الدائرة كما في الرسم (LED على pin 2)
3. انسخ الكود والصقه في المحرر
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. افتح **Serial Monitor** (9600 baud)
8. اكتب قيمة الـ delay بالـ ms (مثلاً `500`) واضغط Enter
9. راقب LED يومض بالسرعة اللي اخترتها

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
