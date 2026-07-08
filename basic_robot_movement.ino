// --- Motor Direction Pins ---
const int RIGHT_MOTOR_IN1 = 5;
const int RIGHT_MOTOR_IN2 = 6;
const int LEFT_MOTOR_IN3 = 9;
const int LEFT_MOTOR_IN4 = 10;

// --- Motor Speed ---
// Set a single comfortable testing speed (0 to 255)
const int MOTOR_SPEED = 150; 

void setup() {
  // Initialize motor control pins as outputs
  pinMode(RIGHT_MOTOR_IN1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2, OUTPUT);
  pinMode(LEFT_MOTOR_IN3, OUTPUT);
  pinMode(LEFT_MOTOR_IN4, OUTPUT);

  // Ensure motors are completely stopped on startup
  stop_motors();
}

void loop() {
  // --- Demonstration Sequence ---
  move_forward();
  delay(2000);      // Move forward for 2 seconds

  stop_motors();
  delay(1000);      // Pause for 1 second

  turn_right();
  delay(1000);      // Turn right in place for 1 second

  stop_motors();
  delay(1000);
}

// ==========================================
// --- Basic Movement Helper Functions ---
// ==========================================

void move_forward() {
  // Right motor forward
  analogWrite(RIGHT_MOTOR_IN1, MOTOR_SPEED);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);
  
  // Left motor forward
  analogWrite(LEFT_MOTOR_IN3, MOTOR_SPEED);
  digitalWrite(LEFT_MOTOR_IN4, LOW);
}

void move_backward() {
  // Right motor reverse
  digitalWrite(RIGHT_MOTOR_IN1, LOW);
  analogWrite(RIGHT_MOTOR_IN2, MOTOR_SPEED);
  
  // Left motor reverse
  digitalWrite(LEFT_MOTOR_IN3, LOW);
  analogWrite(LEFT_MOTOR_IN4, MOTOR_SPEED);
}

void turn_right() {
  // Tank turn: Right motor reverses, Left motor goes forward
  digitalWrite(RIGHT_MOTOR_IN1, LOW);
  analogWrite(RIGHT_MOTOR_IN2, MOTOR_SPEED);
  
  analogWrite(LEFT_MOTOR_IN3, MOTOR_SPEED);
  digitalWrite(LEFT_MOTOR_IN4, LOW);
}

void turn_left() {
  // Tank turn: Right motor goes forward, Left motor reverses
  analogWrite(RIGHT_MOTOR_IN1, MOTOR_SPEED);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);
  
  digitalWrite(LEFT_MOTOR_IN3, LOW);
  analogWrite(LEFT_MOTOR_IN4, MOTOR_SPEED);
}

void stop_motors() {
  // Setting both IN pins to LOW stops the motor
  digitalWrite(RIGHT_MOTOR_IN1, LOW);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);
  
  digitalWrite(LEFT_MOTOR_IN3, LOW);
  digitalWrite(LEFT_MOTOR_IN4, LOW);
}