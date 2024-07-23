void int_port_init(){ //Gọi hàm này trong void setup() để thiết lập các ngõ vào không có trở kéo lên cho các chân INT trên board
  Serial.begin(BAUDRATE);
  pinMode(ENC_INT0,INPUT);
  pinMode(ENC_INT1,INPUT);
  pinMode(ENC_INT2,INPUT);
  pinMode(ENC_INT3,INPUT);
  pinMode(ENC_INT4,INPUT);
  pinMode(ENC_INT5,INPUT);
  pinMode(ENC_INT6,INPUT);
  pinMode(ENC_INT7,INPUT);
}

void int_port_read(){ //Gọi hàm này trong void loop() để hiển thị giá trị analog của các chân INT trên board mỗi 0.5s
  Serial.print(analogRead(ENC_INT0));
  Serial.print(" ");
  Serial.print(analogRead(ENC_INT1));
  Serial.print(" ");
  Serial.print(analogRead(ENC_INT2));
  Serial.print(" ");
  Serial.print(analogRead(ENC_INT3));
  Serial.print(" ");
  Serial.print(analogRead(ENC_INT4));
  Serial.print(" ");
  Serial.print(analogRead(ENC_INT5));
  Serial.print(" ");
  Serial.print(analogRead(ENC_INT6));
  Serial.print(" ");
  Serial.println(analogRead(ENC_INT7));
  delay(500);
}