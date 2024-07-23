#include <SPI.h>

void spi_slave_init(){ //Gọi hàm này trong void setup() để khởi tạo thiết bị với giao thức SPI dưới dạng slave
  Serial.begin(BAUDRATE);
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
}

ISR (SPI_STC_vect) //Ngắt khi thiết bị nhận thông tin qua Bus SPI
{
  byte Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  Serial.println(char(Slavereceived));
}

void spi_master_init(){ //Gọi hàm này trong void setup() để khởi tạo thiết bị với giao thức SPI dưới dạng master
  pinMode(CS,OUTPUT);
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV128);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(CS,HIGH);
  digitalWrite(SS,HIGH);
}

void spi_master_port0(){ //Gọi hàm này trong void loop() để truyền phát thông tin liên tục trên bus SPI, điều khiển thiết bị slave bằng cổng SS(53)
  byte Mastersend,Mastereceive;
  digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master
  Mastersend = 'A';                            
  Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
  digitalWrite(SS, HIGH);                  //Starts communication with Slave connected to master
  delay(1000);
}

void spi_master_port1(){ //Gọi hàm này trong void loop() để truyền phát thông tin liên tục trên bus SPI, điều khiển thiết bị slave bằng cổng CS(49)
  byte Mastersend,Mastereceive;
  digitalWrite(CS, LOW);                  //Starts communication with Slave connected to master
  Mastersend = 'A';                            
  Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
  digitalWrite(CS, HIGH);                  //Starts communication with Slave connected to master
  delay(1000);
}