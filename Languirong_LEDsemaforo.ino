//dichiaro port di led
int rosso = 2;
int giallo = 3;
int verde = 4;
int rosso2 = 8;
int giallo2 = 9;
int verde2 = 10;
//tempo d'attesa
int tempogiallo=2000;
int temporosso=5000;
int tempolampeggioverde=500;

void semaforo(){
  //verde2 e rosso accendono insieme
  digitalWrite(rosso,HIGH);
  digitalWrite(verde2,HIGH);
  delay(tempogiallo);//aspetto un'attimo
  digitalWrite(verde2,LOW);//spengo verde
  delay(tempolampeggioverde);//aspetto un'attimo
  
  for(int i = 0 ; i<4;i++)//lampeggia 4 volte verde2
    {
    digitalWrite(verde2,HIGH);
    delay(tempolampeggioverde);
    digitalWrite(verde2,LOW);
    delay(tempolampeggioverde);
    }
    
    digitalWrite(giallo,HIGH);//accendo i gialli
    digitalWrite(giallo2,HIGH);
    delay(temporosso);//aspetto un'attimo
    digitalWrite(rosso,LOW);//chiudo rosso e anche i gialli 
    digitalWrite(giallo,LOW);
    digitalWrite(giallo2,LOW);
 
    digitalWrite(rosso2,HIGH);//accendo rosso2
    digitalWrite(verde,HIGH);//accendo verde
    delay(tempogiallo);//aspetto un'attimo
    digitalWrite(verde,LOW);//chiudo verde
    //accendo verde
    for(int i = 0 ; i<4;i++)//lampeggia 4 volte verde
    {
    digitalWrite(verde,HIGH);
    delay(tempolampeggioverde);
    digitalWrite(verde,LOW);
    delay(tempolampeggioverde);
    }
    digitalWrite(rosso2,HIGH);//accendo rosso2
    digitalWrite(giallo,HIGH);//accendo i gialli
    digitalWrite(giallo2,HIGH);
    delay(temporosso);//aspetto un'attimo
    digitalWrite(giallo,LOW);//chiudo i gialli e riparte il ciclo
    digitalWrite(giallo2,LOW);
    digitalWrite(rosso2,LOW);
}

void setup() {
  // put your setup code here, to run once:
  //output
  pinMode(rosso,OUTPUT);
  pinMode(giallo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(rosso2,OUTPUT);
  pinMode(giallo2,OUTPUT);
  pinMode(verde2,OUTPUT);
  Serial.begin(9600);
  Serial.println("quante volte vuoi fare lamppeggiare il rosso");
  Serial.println("dammi un numero");
  while(Serial.available() == 0){
  }
  temporosso = Serial.readString().toInt();
  Serial.println("quante volte vuoi fare lamppeggiare il giallo");
  Serial.println("dammi un numero");
  while(Serial.available() == 0){
  }
  tempogiallo = Serial.readString().toInt();
  Serial.println("quante volte vuoi fare lamppeggiare il verde");
  Serial.println("dammi un numero");
  while(Serial.available() == 0){
  }
  tempolampeggioverde = Serial.readString().toInt();
}

void loop() {
  // put your main code here, to run repeatedly:
  //mio programma
semaforo();
} 
