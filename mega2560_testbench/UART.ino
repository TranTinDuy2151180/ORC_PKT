void uart_init(){ //Gọi hàm này trong void setup() để khởi tạo UART
  Serial.begin(BAUDRATE);
  Serial1.begin(BAUDRATE);
  Serial2.begin(BAUDRATE);
  Serial3.begin(BAUDRATE);
}

void uart_tx(){ //Gọi hàm này trong void loop() để truyền phát thông tin liên tục qua bus UART
  Serial.println("0"); //Truyền số 1 trên UART0, số 1 trên UART1, số 2 trên UART2, số 3 trên UART3
  Serial1.println("1");
  Serial2.println("2");
  Serial3.println("3");
  delay(500);
}

void uart_rx(){ //Gọi hàm này trong void loop() để nhận thông tin liên tục qua UART và truyền phát đến máy tính
  while(Serial1.available()<1); //Dùng Arduino như 1 module UART-USB. Đọc thông tin tại UART1 và phát thông tin về máy tính tại UART0
  while(Serial1.available()>0){
    char a = Serial1.read();
    Serial.write(a);
  }
}

