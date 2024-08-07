/* (invertido tem que ajeitar) cabo roxo longo, esquerdo
cinza longo, meio esquerda
roxo curto, meio direita
cinza curto, direita
amarelo, frente-*/

#include <Servo.h>

Servo servoEsquerda;
Servo servoDireita;

#define velEsq 180
#define velDir 0
#define velParar 90

///////////////////////

#define sensorF A1 // MAX: 506 MIN: 202
#define sensorEsq A3 // MAX: 632 MIN: 433
#define sensorDir A4 // MAX: 486 MIN: 120
#define sensorMesq A2 // MAX: 370 MIN: 102
#define sensorMdir A5 // MAX: 360 MIN: 120

//Ordem: Frente, esquerda, direita, meioesquerda e meiodireita.
int sensoresMax[5] = {506, 632, 482, 370, 360}; // valores de cada sensor no branco

int sensoresMin[5] = {202, 433, 120, 102, 120}; //valores de cada sensor no preto

int mediaSensores[5] = {0, 0, 0, 0, 0};

int pinosSensores[5] = {A1, A3, A4, A2, A5};

int valorF = 0;
int valorEsq = 0;
int valorDir = 0;
int valorMesq = 0;
int valorMdir = 0;

void setup(){
//definindo os tcrt como saídas.
  for(int i = 0; i<5; i++){
    pinMode (pinosSensores[i], INPUT);
  }

  servoEsquerda.attach(3);
  servoDireita.attach(6);

  Serial.begin(9600);
}


void loop(){

  media(0); media(1); media(2); media(3); media(4);

  if (analogRead(pinosSensores[0]) > mediaSensores[0] ){valorF = 0;} else{valorF = 1;}

  if (analogRead(pinosSensores[1]) > mediaSensores[1] ){valorEsq = 0;} else {valorEsq = 1;}
    
  if (analogRead(pinosSensores[2]) > mediaSensores[2] ){valorDir = 0;} else {valorDir = 1;}
    
  if (analogRead(pinosSensores[3]) > mediaSensores[3] ){valorMesq = 0;} else {valorMesq = 1;}
    
  if (analogRead(pinosSensores[4]) > mediaSensores[4] ){valorMdir = 0;} else {valorMdir = 1;}

  Serial.print(analogRead(sensorF)); Serial.print(" // ");
  Serial.print(valorEsq); Serial.print(" // ");
  Serial.print(valorMesq); Serial.print(" // ");
  Serial.print(valorF); Serial.print(" // ");
  Serial.print(valorMdir); Serial.print(" // ");
  Serial.print(valorDir); Serial.print(" // ");

  Serial.println();

  if(valorEsq == 0 && valorMesq == 1 && valorF == 1 && valorMdir == 1 && valorDir == 0 ){
    Serial.println("FRENTE");
  }

  else if((valorEsq == 1 && valorMesq == 1 && valorF == 0 && valorMdir == 0 && valorDir == 0) || 
    (valorEsq == 1 && valorMesq == 0 && valorF == 0 && valorMdir == 0 && valorDir == 0)||
    (valorEsq == 0 && valorMesq == 1 && valorF == 1 && valorMdir == 0 && valorDir == 0)){
    Serial.println("ESQUERDA");
  }

  else if((valorEsq == 0 && valorMesq == 0 && valorF == 0 && valorMdir == 1 && valorDir == 1) || 
    (valorEsq == 0 && valorMesq == 0 && valorF == 0 && valorMdir == 0 && valorDir == 1)||
    (valorEsq == 0 && valorMesq == 0 && valorF == 1 && valorMdir == 1 && valorDir == 0)){
      Serial.println("DIREITA");
    }

  else if(valorEsq == 0 && valorMesq == 1 && valorF == 0 && valorMdir == 1 && valorDir == 1){
      Serial.println("NOV GRAUS DIREITA");
    }
  
  else if(valorEsq == 1 && valorMesq == 1 && valorF == 0 && valorMdir == 1 && valorDir == 0){
      Serial.println("NOV GRAUS ESQUERDA");
    }

  else if(valorEsq == 1 && valorMesq == 1 && valorF == 0 && valorMdir == 1 && valorDir == 1){
      Serial.println("T");
    }

  else if(valorEsq == 1 && valorMesq == 1 && valorF == 1 && valorMdir == 1 && valorDir == 1){
      Serial.println("ENCRUZILHADA");
    }

  else{Serial.println("Sem condiçao");
  }
}

void media(int x){
  mediaSensores[x] = (sensoresMax[x] + sensoresMin[x])/2;
}

////////////////////

void frente(){
  servoEsquerda.write(velEsq);
  servoDireita.write(velDir);
}

void esquerda(){
  servoEsquerda.write(velEsq);
  servoDireita.write(velEsq);
}

void direita(){
  servoEsquerda.write(velDir);
  servoDireita.write(velDir);
}
void novg_esquerda(){}
void novg_direita(){}
void t(){}
void encruzilhada(){}
