void setup() {
  setup_StatusControl();
  Serial.begin(9600);
}

void loop() {
  knopCheck();
  statusControl_loop();
}
