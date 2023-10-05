int cnt=1;
int DL=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(cnt);
  Serial.print(" Mississippi");
  cnt = cnt + 1;
  delay(DL);
}
