int pulse = 0;
int pulse_real = 0;
int previous_pulse = 0;
int previous_state = 0;
int present_state = 0;

void encoder_init(){ //Gọi hàm này trong void setup() để theo khởi tạo các chân ngõ vào cho encoder.
  Serial.begin(BAUDRATE);
  pinMode(ENC_INT0,INPUT);
  pinMode(ENC_INT1,INPUT);
  pinMode(ENC_INT2,INPUT);
  pinMode(ENC_INT3,INPUT);
  pinMode(ENC_INT4,INPUT);
  pinMode(ENC_INT5,INPUT);
  pinMode(ENC_INT6,INPUT);
  pinMode(ENC_INT7,INPUT);
  PCICR = 0x04; //Tham khảo datasheet ATMEGA2560 tr.112
  PCMSK2 = 0x55; //Chỉ xét 1 trong 2 cặp chân để tính tốc độ quay
  sei(); //Kích hoạt interrupt
}

int read_previous_state(){ //Gọi hàm này trong void loop() để liên tục giám sát trạng thái của encoder
  if(digitalRead(ENC_INT1) == 0 && digitalRead(ENC_INT0) == 0)previous_state = 0;
  if(digitalRead(ENC_INT1) == 0 && digitalRead(ENC_INT0) == 1)previous_state = 1;
  if(digitalRead(ENC_INT1) == 1 && digitalRead(ENC_INT0) == 1)previous_state = 3;
  if(digitalRead(ENC_INT1) == 1 && digitalRead(ENC_INT0) == 0)previous_state = 2;
}

int read_present_state(){ //Hàm này sẽ theo dõi trạng thái của encoder ngay khi pin change interrupt kích hoạt
  if(digitalRead(ENC_INT1) == 0 && digitalRead(ENC_INT0) == 0)present_state = 0;
  if(digitalRead(ENC_INT1) == 0 && digitalRead(ENC_INT0) == 1)present_state = 1;
  if(digitalRead(ENC_INT1) == 1 && digitalRead(ENC_INT0) == 1)present_state = 3;
  if(digitalRead(ENC_INT1) == 1 && digitalRead(ENC_INT0) == 0)present_state = 2;
}

ISR(PCINT2_vect){ //Interrupt sẽ so sánh trạng thái của encoder trước khi và sau khi interrupt được kích hoạt, để biết chiều quay của encoder đang tiến hay lùi
read_present_state();
if((present_state == 1 && previous_state == 0) || (present_state == 3 && previous_state == 1) || (present_state == 2 && previous_state == 3) || (present_state == 0 && previous_state == 2))pulse += 1;
if((present_state == 0 && previous_state == 1) || (present_state == 1 && previous_state == 3) || (present_state == 3 && previous_state == 2) || (present_state == 2 && previous_state == 0))pulse -= 1;
previous_pulse = pulse_real;
pulse_real = pulse/4;
if(pulse_real != previous_pulse)Serial.println(pulse_real);
}