
// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech

const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
//const int StepZ = 4;
//const int DirZ = 7;
int contador_vertical = 0;
int cantidad_fotos = 0;
bool bajando = true;
int contador_horizontal = 0;
void setup() {
  Serial.begin(9600);
  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  //pinMode(StepZ,OUTPUT);
  //pinMode( DirZ,OUTPUT);

}
// En este caso saca una grilla 15x15 de fotos pero se puede modificar para sacar la cantidad de fotos que se desee
void loop() {
  if (Serial.available()>0&&cantidad_fotos<15*15) {
    char option = Serial.read();
    if (option >= '1' && option <= '9')
      {
       cantidad_fotos = cantidad_fotos + 1;
       if(contador_vertical<14){
        if(bajando){
          move_vertical(false); 
          contador_vertical = contador_vertical+1;
        }
          else{
            move_vertical(true); 
            contador_vertical = contador_vertical+1;
          }
         }
        else{
          move_horizontal(true);
          contador_vertical = 0;
          bajando = !bajando;
          contador_horizontal = contador_horizontal + 1;          
        }
        }
      
  }
 
  }
 
  


void move_horizontal(bool direccion){
  digitalWrite(DirX, direccion);
  for(int x = 0; x<50; x++) { // loop for 100 steps
    digitalWrite(StepX,HIGH);
    delayMicroseconds(500);
    digitalWrite(StepX,LOW); 
    delayMicroseconds(500);
    }
   delay(1000); // delay for 1 second
}

void move_vertical(bool direccion){
  digitalWrite(DirY, direccion);
  for(int x = 0; x<80; x++) { // loop for 100 steps
    digitalWrite(StepY,HIGH);
    delayMicroseconds(500);
    digitalWrite(StepY,LOW); 
    delayMicroseconds(500);
    }
  delay(1000);
}

