#include <Wire.h>

int x = 0;
int y = 0;
int z = 0;

void i2c_init_slave(){ //Gọi hàm này trong void setup() nếu muốn dùng thiết bị dưới dạng slave
  Wire.begin(I2C_SLAVE_ADDRESS); //Cài đặt địa chỉ thiết bị Slave
  Wire.onRequest(i2c_sendData); //Kích hoạt hàm sau khi ngắt I2C nhảy khi nhận được gói tin I2C
}

void i2c_sendData() {
  //Gửi thông tin về thiết bị Master
  Wire.write(x);
  Wire.write(y);
  Wire.write(z);
  x +=1;
  y +=2;
  z +=3;
}

void i2c_init_master(){ // Gọi hàm này trong void setup() nếu muốn dùng thiết bị dưới dạng master
  Serial.begin(BAUDRATE);
  Wire.begin(); //Khởi tạo giao thức I2C trên thiết bị Master (hàm để trống tức là khởi tạo thiết bị Master)
}

void i2c_readData(){ //Gọi hàm này trong void loop() để nhận thông tin liên tục qua bus I2C
  //Đọc thông tin từ thiết bị Slave
  Wire.requestFrom(I2C_SLAVE_ADDRESS, 3);
  x = Wire.read();
  y = Wire.read();
  z = Wire.read();
  
  // Trả thông tin thông qua UART
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.print(y);
  Serial.print(", Z: ");
  Serial.println(z);
  
  delay(1000);
}