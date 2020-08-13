  #include <LiquidCrystal.h>
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  #define contra 9
  #define bri 10
  const int shotbutton = 8;
  const int hitbutton = 13;
  const int hitled = 6;
  const int shotled = 7;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(bri, OUTPUT);
  pinMode(contra, OUTPUT);
  digitalWrite(contra, LOW);
  analogWrite(bri, 255);
  pinMode(shotbutton, INPUT);
  pinMode(hitbutton, INPUT);
  pinMode(shotled, OUTPUT);
  pinMode(hitled, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int health = 20;
  int ammo = 10;
  int shot, hit;
  digitalWrite(hitled, LOW);
  digitalWrite(shotled, LOW);
  Serial.print("Health ");
  Serial.println(health);
  Serial.print("Ammo ");
  Serial.println(ammo);
  //lcd.setCursor(0, 0);
  //lcd.print("Health: ");
  //lcd.print(health);
  //lcd.setCursor(0, 1);
  //lcd.print("Ammo: ");
  //lcd.print(ammo);
  while(health > 0) {
    delay(1);
    hit = digitalRead(hitbutton);
    shot = digitalRead(shotbutton);
    
    if (hit == LOW){
      digitalWrite(hitled, HIGH);
      delay(250);
      health --;
      digitalWrite(hitled, LOW);
      Serial.print("Health ");
      Serial.println(health);
      //lcd.setCursor(8, 0);
      //lcd.print(health);
    }
    else    {
      digitalWrite(hitled, LOW);
    }
    
    if ((shot == LOW)&& (health > 0)){
      digitalWrite(shotled, HIGH);
      delay(250);
      digitalWrite(shotled, LOW);
      ammo --;
      Serial.print("Ammo ");
      Serial.println(ammo);
      //lcd.setCursor(6, 2);
      //lcd.print(ammo);
      if (ammo <= 0){
        ammo = 10;
        Serial.print("Ammo ");
        Serial.println(ammo);
        //lcd.setCursor(6, 2);
        //lcd.print(ammo);      
      }
      while(shot == LOW){
        shot = digitalRead(shotbutton);
        hit = digitalRead(hitbutton);
        if (hit == LOW){
          digitalWrite(hitled, HIGH);
          delay(250);
          health --;
          digitalWrite(hitled, LOW);
          Serial.print("Health ");
          Serial.println(health);
          //lcd.setCursor(8, 0);
          //lcd.print(health);
        }
        else    {
          digitalWrite(hitled, LOW);
        }
      }
    }
    else    {
      digitalWrite(shotled, LOW);
    }
  }
  Serial.println("---------------");
  Serial.println("You have Died");
  //lcd.clear();
  //lcd.setCursor(5, 0);
  //lcd.print("You Have");
  //lcd.setCursor(7, 1);
  //lcd.print("Died");
  while (health <=0){
    digitalWrite(hitled, HIGH);
    delay(100);
    digitalWrite(hitled, LOW);
    delay(100);
  }
}
