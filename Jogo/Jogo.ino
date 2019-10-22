#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <CapacitiveSensor.h>


LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
CapacitiveSensor cs_4_5 = CapacitiveSensor(4, 5);
CapacitiveSensor cs_4_6 = CapacitiveSensor(4, 6);
CapacitiveSensor cs_4_7 = CapacitiveSensor(4, 7);
CapacitiveSensor cs_4_11 = CapacitiveSensor(4, 11);
CapacitiveSensor cs_4_12 = CapacitiveSensor(4, 12);
CapacitiveSensor cs_4_13 = CapacitiveSensor(4, 13);

int pontuacao = 0, endereco1 = 0, endereco2 = 1;
long TempoJogo = 60000, TempoAtual;

void setup()
{
  lcd.begin(16, 2);
  cs_4_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void intro(void) {
  int msg = 0;
  lcd.clear();
  while (1) {
    long sensor1 = cs_4_5.capacitiveSensor(50);
    long sensor2 = cs_4_6.capacitiveSensor(50);
    long sensor3 = cs_4_7.capacitiveSensor(50);
    long sensor4 = cs_4_11.capacitiveSensor(50);
    long sensor5 = cs_4_12.capacitiveSensor(50);
    long sensor6 = cs_4_13.capacitiveSensor(50);
    if (sensor1 > 100 || sensor2 > 100 || sensor3 > 100 || sensor4 > 100 || sensor5 > 100 || sensor6 > 100) {
      return;
    }
    if (msg < 25) {
      lcd.setCursor(2, 0);
      lcd.print("Mole Hammers");
      lcd.setCursor(1, 1);
      lcd.print("~Press to Play");
      msg++;
    }
    else if (msg < 50) {
      lcd.setCursor(2, 0);
      lcd.print("Mole Hammers");
      lcd.setCursor(1, 1);
      lcd.print("                ");
      msg++;
    } else {
      msg = 0;
    }
  }
}

void LED_FUN(void) {
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(A0, HIGH);
  delay(100);
  digitalWrite(2, HIGH);
  delay(100);
  for (int i = 0; i < 5; i++) {
    digitalWrite(3, LOW);
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(A0, LOW);
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    digitalWrite(8, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    digitalWrite(A0, HIGH);
    delay(100);
    digitalWrite(8, LOW);
    digitalWrite(2, HIGH);
    delay(100);
  }
  digitalWrite(3, LOW);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(A0, LOW);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  digitalWrite(9, LOW);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
  return;
}

void game(void) {
  long randomNumber1, led1, led2, led3, timerpoint;
  int a;
  TempoAtual = millis();
  unsigned long tempo = millis();
  while ((TempoAtual - tempo) < TempoJogo) {
    TempoAtual = millis();
    a = 0;
    lcd.clear();
    lcd.print("Score: ");
    lcd.print(pontuacao);
    lcd.setCursor(0, 1);
    randomNumber1 = random(1, 1);
    if (randomNumber1 == 1) {
      led1 = random(1, 7);
      if (led1 == 1) {
        digitalWrite(3, HIGH);
        while (a == 0) {
          long sensor4 = cs_4_11.capacitiveSensor(50);
          if (sensor4 > 100) {
            timerpoint = millis();
            pontuacao += (60 - ((timerpoint - TempoAtual) / 200));
            a = 1;
            digitalWrite(3, LOW);
          }
        }
      }
      if (led1 == 2) {
        digitalWrite(A0, HIGH);
        while (a == 0) {
          long sensor5 = cs_4_12.capacitiveSensor(50);
          if (sensor5 > 100) {
            timerpoint = millis();
            pontuacao += (60 - ((timerpoint - TempoAtual) / 200));
            a = 1;
            digitalWrite(A0, LOW);
          }
        }
      }
      if (led1 == 3) {
        digitalWrite(10, HIGH);
        while (a == 0) {
          long sensor6 = cs_4_13.capacitiveSensor(50);
          if (sensor6 > 100) {
            timerpoint = millis();
            pontuacao += (60 - ((timerpoint - TempoAtual) / 200));
            a = 1;
            digitalWrite(10, LOW);
          }
        }
      }
      if (led1 == 4) {
        digitalWrite(8, HIGH);
        while (a == 0) {
          long sensor1 = cs_4_5.capacitiveSensor(50);
          if (sensor1 > 100) {
            timerpoint = millis();
            pontuacao += (60 - ((timerpoint - TempoAtual) / 200));
            a = 1;
            digitalWrite(8, LOW);
          }
        }
      }
      if (led1 == 5) {
        digitalWrite(9, HIGH);
        while (a == 0) {
          long sensor2 = cs_4_6.capacitiveSensor(50);
          if (sensor2 > 100) {
            timerpoint = millis();
            pontuacao += (60 - ((timerpoint - TempoAtual) / 200));
            a = 1;
            digitalWrite(9, LOW);
          }
        }
      }
      if (led1 == 6) {
        digitalWrite(2, HIGH);
        while (a == 0) {
          long sensor3 = cs_4_7.capacitiveSensor(50);
          if (sensor3 > 100) {
            timerpoint = millis();
            pontuacao += (60 - ((timerpoint - TempoAtual) / 200));
            a = 1;
            digitalWrite(2, LOW);
          }
        }
      }
    } else if (randomNumber1 == 2) {
      led1 = random(1, 6);
      led2 = random(1, 6);
    } else {
      led1 = random(1, 6);
      led2 = random(1, 6);
      led3 = random(1, 6);
    }
  }
  return;
}

void loop()
{
  pontuacao = 0;
  lcd.setBacklight(HIGH);
  intro();
  lcd.clear();
  lcd.print(" The Game Will");
  lcd.setCursor(5, 2);
  lcd.print("Start!");
  LED_FUN();
  lcd.clear();
  lcd.print("    START!!!");
  delay(2000);
  lcd.clear();
  game();
  lcd.clear();
  lcd.print("   Final Score");
  lcd.setCursor(5, 1);
  lcd.print(pontuacao);
  LED_FUN();
  lcd.clear();
  lcd.print(" Current Record" );
  lcd.setCursor(5,1);
  int parte1 = EEPROM.read(0);
  int parte2 = EEPROM.read(1);
  int numero_original = (parte1 * 256) + parte2;
  lcd.print(numero_original);
  delay(5000);
  if(numero_original < pontuacao){
    lcd.clear();
    lcd.print("Congratulations!");
    lcd.setCursor(0,1);
    lcd.print("A New Record!!!");
    EEPROM.write(0, pontuacao/256);
    EEPROM.write(1, pontuacao%256);
  }else{
    lcd.clear();
    lcd.print("   Better Luck");
    lcd.setCursor(4,1);
    lcd.print("Next Time");
  }
  delay(10000);
}

