#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C display(0x27,16,2);   // Creo el objeto display  dirección  0x27 y 16 columnas x 2 filas
#define STR_LEN 12                      // Este valor debe ser minimo 12 para que se pueda imprimir siempre en la posición inicial
char str_to_print[STR_LEN]={'A','i','r','e',' ','N','u','e','v','o'};

void logoUNAHUR() {
  byte UNAHUR1[] = {
    B11100,
    B11110,
    B11111,
    B11111,
    B11111,
    B11111,
    B01111,
    B00111
  };
  byte UNAHUR2[] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
  };
  byte UNAHUR3[] = {
    B00111,
    B01111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11110,
    B11100
  };
  display.createChar(0, UNAHUR1);
  display.createChar(1, UNAHUR2);
  display.createChar(2, UNAHUR3);
  display.setCursor(13, 0);       // Ubicamos el cursor en la posicion y linea deseada
  display.write(0);
  display.setCursor(14, 0);       // Ubicamos el cursor en la posicion y linea deseada
  display.write(1);
  display.setCursor(15, 0);       // Ubicamos el cursor en la posicion y linea deseada
  display.write(2);
  display.setCursor(13, 1);       // Ubicamos el cursor en la posicion y linea deseada
  display.write(2);
  display.setCursor(14, 1);       // Ubicamos el cursor en la posicion y linea deseada
  display.write(1);
  display.setCursor(15, 1);       // Ubicamos el cursor en la posicion y linea deseada
  display.write(0);
}

void setup() {
  display.begin();                       // Inicio el display            
  display.clear();                       // Limpio la pantalla 
  display.backlight();                   // Prendo la backlight 
}

void loop() {
  display.clear();
  aireNuevo();
  logoUNAHUR();
  delay(5000);
}

void scrollingText(uint8_t scrolled_by) {
  for (uint8_t i=0;i<10;i++) {
    display.setCursor(i,0);
    if (scrolled_by>=11) scrolled_by=0;                           // Esto permite volver al inicio del array de caracteres
    if (scrolled_by<10) display.print(str_to_print[scrolled_by]); // Mientras el valor de scrolled_by sea un indice del array, imprime el valor
    else display.print(' ');                                      // Se imprime un caracter vacío antes de volver al inicio del array para que haya un espacio entre la palabra Nuevo y Aire, en ese orden
    scrolled_by++;                          
  }
}

void aireNuevo() {
  for (uint8_t i=0;i<STR_LEN;i++) {
    scrollingText(i);
    delay(500);
  }
}
