void pwm(){ //Gọi hàm này trong void setup() để phát xung PWM trên cổng 6,7,11,12
  pinMode(PWM0, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PWM3, OUTPUT);
  analogWrite(PWM0,50);
  analogWrite(PWM1,100);
  analogWrite(PWM2,150);
  analogWrite(PWM3,230);
}