//dichiaro port di led
int rosso = 2;
int giallo = 3;
int verde = 4;
int rosso2 = 8;
int giallo2 = 9;
int verde2 = 10;
//tempo d'attesa
int duemila =2000;
int cinquemila=5000;
int cinquecento=500;
int mile=1000;

void semaforo(){
  //verde2 e rosso accendono insieme
  digitalWrite(rosso,HIGH);
  digitalWrite(verde2,HIGH);
  delay(duemila);//aspetto un'attimo
  digitalWrite(verde2,LOW);//spengo verde
  delay(cinquecento);//aspetto un'attimo
  
  for(int i = 0 ; i<4;i++)//lampeggia 4 volte verde2
    {
    digitalWrite(verde2,HIGH);
    delay(cinquecento);
    digitalWrite(verde2,LOW);
    delay(cinquecento);
    }
    
    digitalWrite(giallo,HIGH);//accendo i gialli
    digitalWrite(giallo2,HIGH);
    delay(cinquemila);//aspetto un'attimo
    digitalWrite(rosso,LOW);//chiudo rosso e anche i gialli 
    digitalWrite(giallo,LOW);
    digitalWrite(giallo2,LOW);
 
    digitalWrite(rosso2,HIGH);//accendo rosso2
    digitalWrite(verde,HIGH);//accendo verde
    delay(duemila);//aspetto un'attimo
    digitalWrite(verde,LOW);//chiudo verde
    //accendo verde
    for(int i = 0 ; i<4;i++)//lampeggia 4 volte verde
    {
    digitalWrite(verde,HIGH);
    delay(cinquecento);
    digitalWrite(verde,LOW);
    delay(cinquecento);
    }
    digitalWrite(rosso2,LOW);//chiudo rosso2
    digitalWrite(giallo,HIGH);//accendo i gialli
    digitalWrite(giallo2,HIGH);
    delay(cinquemila);//aspetto un'attimo
    digitalWrite(giallo,LOW);//chiudo i gialli e riparte il ciclo
    digitalWrite(giallo2,LOW);
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
}
void loop() {
  // put your main code here, to run repeatedly:
  //mio programma
semaforo();
} 
