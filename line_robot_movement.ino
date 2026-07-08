// --- Sensor Pin Definitions ---
const int RIGHT_SENSOR_PIN = 11;
const int LEFT_SENSOR_PIN = 12;

// Controling the turn speed
const int MOTOR_SPEED1 = 60;
const int MOTOR_SPEED2 = 150;

// --- Motor Direction Pins ---
const int RIGHT_MOTOR_IN1 = 5;
const int RIGHT_MOTOR_IN2 = 6;
const int LEFT_MOTOR_IN3 = 9;
const int LEFT_MOTOR_IN4 = 10;

enum MotorState {
  FORWARD,
  REVERSE,
  STOP
};

void setup() {
  // Initialize motor direction control pins as outputs
  pinMode(RIGHT_MOTOR_IN1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2, OUTPUT);
  pinMode(LEFT_MOTOR_IN3, OUTPUT);
  pinMode(LEFT_MOTOR_IN4, OUTPUT);

  // Initialize IR sensor pins as inputs
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);

  // Ensure motors are completely stopped on startup
  setRightMotor(STOP);
  setLeftMotor(STOP);
}

void loop() {
  // Read sensor values (assuming LOW = reflecting/white, HIGH = absorbing/black line)
  bool isRightOnLine = digitalRead(RIGHT_SENSOR_PIN);
  bool isLeftOnLine = digitalRead(LEFT_SENSOR_PIN);

  // --- Core Line Following Logic ---
  if (!isRightOnLine && !isLeftOnLine) {
    // Both sensors are off the line (LOW), move straight forward
    setRightMotor(FORWARD);
    setLeftMotor(FORWARD);
  } 
  else if (isRightOnLine && !isLeftOnLine) {
    // Right sensor detected the line, drift/turn right
    // Tank turn: Right motor reverses, Left motor goes forward for a sharp turn
    setRightMotor(REVERSE);
    setLeftMotor(FORWARD);
  } 
  else if (!isRightOnLine && isLeftOnLine) {
    // Left sensor detected the line, drift/turn left
    setRightMotor(FORWARD);
    setLeftMotor(REVERSE);
  } 
  else {
    // Both sensors detected the line (e.g., an intersection or T-junction)
    setRightMotor(STOP);
    setLeftMotor(STOP);
  }
}

// --- Motor Control Helper Functions ---

void setRightMotor(MotorState state) {
  if (state == FORWARD) {
    analogWrite(RIGHT_MOTOR_IN1, MOTOR_SPEED1);
    digitalWrite(RIGHT_MOTOR_IN2, LOW);
  } else if (state == REVERSE) {
    digitalWrite(LEFT_MOTOR_IN3, LOW);
    analogWrite(LEFT_MOTOR_IN4, MOTOR_SPEED2);
  } else {
    // STOP
    digitalWrite(RIGHT_MOTOR_IN1, LOW);
    digitalWrite(RIGHT_MOTOR_IN2, LOW);
  }
}

void setLeftMotor(MotorState state) {
  if (state == FORWARD) {
    analogWrite(LEFT_MOTOR_IN3, MOTOR_SPEED1);
    digitalWrite(LEFT_MOTOR_IN4, LOW);
  } else if (state == REVERSE) {
    digitalWrite(RIGHT_MOTOR_IN1, LOW);
    analogWrite(RIGHT_MOTOR_IN2, MOTOR_SPEED2);
  } else {
    // STOP
    digitalWrite(LEFT_MOTOR_IN3, LOW);
    digitalWrite(LEFT_MOTOR_IN4, LOW);
  }
}