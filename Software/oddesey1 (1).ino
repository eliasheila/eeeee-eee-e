const int Trigger = 10;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
int led = 8;
int motor11 = 9;
int motor12 = 11;
int motor21 = 5;
int motor22 = 6;
int BN = 1;

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  pinMode(led, OUTPUT);
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  
  pinMode(motor11, OUTPUT);
  pinMode(motor12, OUTPUT);
  pinMode(motor21, OUTPUT);
  pinMode(motor22, OUTPUT);
  
  pinMode(BN, INPUT);
  
}

void loop()
{
  
 delay(5000);
  
 digitalWrite(led, LOW);
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
  
  
  if(d <= 150){
    digitalWrite(led, HIGH);
    
    digitalWrite(motor11, HIGH);
    digitalWrite(motor12, LOW);
    digitalWrite(motor21, HIGH);
    digitalWrite(motor22, LOW);
  }
  else {
    digitalWrite(motor11, HIGH);
    digitalWrite(motor12, LOW);
    digitalWrite(motor21, LOW);
    digitalWrite(motor22, HIGH);
  }
  
  


}
