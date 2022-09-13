String bufferLectura;

char bufferCodigo[10];

char codigoResultado[10];

int cont=0;

String aux;


void shaker(){

  int i;

  if (cont >= 0 && cont <= 15) {   //Variable que se incrementa a medida que finaliza el ingreso de cantidad de botellas

        aux = String(cont, HEX);

        aux = "0" + aux;
        
     } else {

      aux = String (cont, HEX);
      
     }
     
  
  if(bufferLectura.length()==6){

    //bufferLectura.remove(bufferLectura.length()-1);
    
    bufferLectura.remove(4, 2);

    bufferLectura = bufferLectura + aux;
  
    bufferLectura.toCharArray(bufferCodigo, sizeof(bufferCodigo));
  
    //for(i=0;i<6;i++){
      
      //if(i==0){
        codigoResultado[2] = bufferCodigo[0];
      //}
      //else if(i==1){
        codigoResultado[0] = bufferCodigo[1];
     // }
      //else if(i==2){
        codigoResultado[5] = bufferCodigo[2];
      //}
      //else if(i==3){
        codigoResultado[3] = bufferCodigo[3];
      //}
      //else if(i==4){
        codigoResultado[1] = bufferCodigo[4];
      //}
      //else if (i==5){
        codigoResultado[4] = bufferCodigo[5];
      //}
      
      
    //}
    
    Serial.print("Codificado: ");
    Serial.println(codigoResultado);
    Serial.println("Caracteres de codigo resultado: ");

    for(i=0; i<7; i++){
       Serial.println(codigoResultado[i]);
    }

    Serial.print("Lo que hay dentro de buffer codigo es: ");

     for(i=0; i<7; i++){
       Serial.println(bufferCodigo[i]);
    }
   
    Serial.print("Contador: ");
    Serial.println(aux);
    
    //Serial.println(bufferCodigo);
    Serial.print("Lo que hay dentro de buffer Lectura es: ");
    Serial.println(bufferLectura);
    
  }else{
    return;
  }

  cont++;
  
}

void decodifShaker(){

  int i;

  strncpy(bufferCodigo, codigoResultado, sizeof(bufferCodigo));

  //for(i=0;i<6;i++){
    
   //if(i==0){
      codigoResultado[1] = bufferCodigo[0];
    //}
    //else if(i==1){
      codigoResultado[4] = bufferCodigo[1];
   // }
   // else if(i==2){
      codigoResultado[0] = bufferCodigo[2];
   // }
   // else if(i==3){
      codigoResultado[3] = bufferCodigo[3];
   // }
  //  else if(i==4){
      codigoResultado[5] = bufferCodigo[4];
   // }
    // else if(i==5){
      codigoResultado[2] = bufferCodigo[5];
   // }
    
  //}

  Serial.print("Decodificado: ");
  Serial.println(codigoResultado);
 
  
  
  
}


void setup() {
  Serial.begin(9600);

  Serial.print("Iniciando...");

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);

        
  delay(300);

  Serial.println("OK");
  Serial.println("Ingresar 4 caracteres");
}

void loop() {

  if(digitalRead(LED_BUILTIN) == HIGH){
    digitalWrite(LED_BUILTIN, LOW);
  }else{
    digitalWrite(LED_BUILTIN, HIGH);
  }

  while (Serial.available() > 0) {
    Serial.println("String: ");
    bufferLectura = Serial.readString();
    Serial.println(bufferLectura);

    shaker();   // Codificar

    delay(2000);

    decodifShaker(); // Decodificar
  }



  delay(300);
}
