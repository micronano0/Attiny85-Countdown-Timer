Der Attiny85 Countdown Timer ist eine Anpassung an das Projekt von Volos  
(Tiny Project - Countdown timer (Attiny85 , 64x32 OLED and datacute library)  
(https://www.youtube.com/watch?v=fnGzRqVI4YI)

Meine Wokwi Umsetzung: https://wokwi.com/projects/439648853914582017

Ich habe es mit einem Attiny85 Digispark nachgebaut.
Es sind im Programm 5 Countdownzeiten möglich: 1,2,3,4,5 Min  
Während ein Countdown läuft, kann er durch Klick auf die Taste von vorne
gestartet werden,  
man muß nicht warten, bis alles heruntergezählt wurde.
Am Ende erfolgt ein kurzer Piepston.

Programmiert habe ich den Attiny85 über einen Arduino Uno und in der 
Arduino IDE. Bevor das Programm hochgeladen wird, sollte man den Attiny 
Bootloader brennen. Das setzt die internen Timerflags passend.

Mit dem aufladbaren 9V Block ist die Schaltung durchgehend 12h gelaufen,
dann war der Akku leer.

Verwendete Teile:

Taster mit Hebel: https://www.amazon.de/dp/B07YDFH7H3  
Buzzer: https://www.amazon.de/dp/B09RFH1T8J  
OLED: https://www.amazon.de/dp/B074N9VLZX  
Attiny85: https://www.amazon.de/Entwicklungsboard-Binghe-kickstarter-Unterst%C3%BCtzung-kompatibel/dp/B0D8WB713R  
9V Block: https://www.amazon.de/dp/B0DYD26BQ1  
Ein.-Ausschalter: https://www.amazon.de/Gebildet-Kippschalter-Schiebeschalter-Positionen-Verriegelung/dp/B0BTM3WQXN  
Taster für Minutenauswahl: nicht mehr gefunden ;-(
