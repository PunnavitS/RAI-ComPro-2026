int irPin = 2;
int switchPin = 3;
int MotorPin_A1 = 7;
int MotorPin_A2 = 4;
int MotorPin_B1 = 3;
int MotorPin_B2 = 2;

int ENA = 6;
int ENB = 5;

int front_echo = 13;
int front_trig = 12;
int left_echo = 11;
int left_trig = 10;
int right_echo = 9;
int right_trig = 8;
int startPos = 0;
//FMPS is Final map and Position Start, 1 is Start A of normal map. 2 is Start B of normal map. 3 is Start C of normal map. 4 is Start A of mirrored map. 5 is Start B of mirrored map. 6 is Start C of mirrored map.
int FMPS = 1;
int hardToggle = 0;
int finish = 0;
//D2WT is "distance to the wall threshold" from the ultrasonic
int D2WT = 11;

int turn_multi = 1;

int irVal = 0;
int previous_action = 0;
int current_action = 0;
int repetition = 0;
int first_turn = 0;
float time = 0;

struct list {
int moves[5] = {1,2,3,4};
int stepTaken = 0;
} movelog;

int *ptr;
// Switchpin 1 = A1
//  Switchpin2 =  A2

long duration_front, cm_front, duration_left, cm_left, duration_right, cm_right;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(front_echo, INPUT);
  pinMode(front_trig, OUTPUT);
  pinMode(left_echo, INPUT);
  pinMode(left_trig, OUTPUT);
  pinMode(right_echo, INPUT);
  pinMode(right_trig, OUTPUT);
  analogWrite(ENA, 100);  // right motor
  analogWrite(ENB, 100);  // left motor
}
void turnRight(int sec) {

  digitalWrite(MotorPin_A2, HIGH);
  digitalWrite(MotorPin_B1, HIGH);
  delay(sec * turn_multi);
  digitalWrite(MotorPin_A1, LOW);
  digitalWrite(MotorPin_B1, LOW);
  digitalWrite(MotorPin_A2, LOW);
  digitalWrite(MotorPin_B2, LOW);
  delay(250);
  time = time + sec;
}
void turnLeft(int sec) {
  digitalWrite(MotorPin_A1, HIGH);
  digitalWrite(MotorPin_B2, HIGH);
  delay(sec * turn_multi);
  digitalWrite(MotorPin_A1, LOW);
  digitalWrite(MotorPin_B1, LOW);
  digitalWrite(MotorPin_A2, LOW);
  digitalWrite(MotorPin_B2, LOW);
  delay(250);
  time = time + sec;
}

void moveForward(int sec) {
  digitalWrite(MotorPin_A1, HIGH);
  digitalWrite(MotorPin_B1, HIGH);
  delay(sec);
  digitalWrite(MotorPin_A1, LOW);
  digitalWrite(MotorPin_B1, LOW);
  digitalWrite(MotorPin_A2, LOW);
  digitalWrite(MotorPin_B2, LOW);
  delay(250);
  time = time + sec;
}

void uTurn(int sec) {

  digitalWrite(MotorPin_A1, HIGH);
  digitalWrite(MotorPin_B2, HIGH);
  delay(sec * turn_multi);
  digitalWrite(MotorPin_A1, LOW);
  digitalWrite(MotorPin_B1, LOW);
  digitalWrite(MotorPin_A2, LOW);
  digitalWrite(MotorPin_B2, LOW);
  delay(250);
  time = time + sec;
}

void reverse(int sec) {

  digitalWrite(MotorPin_A2, HIGH);
  digitalWrite(MotorPin_B2, HIGH);
  delay(sec);
  digitalWrite(MotorPin_A1, LOW);
  digitalWrite(MotorPin_B1, LOW);
  digitalWrite(MotorPin_A2, LOW);
  digitalWrite(MotorPin_B2, LOW);
  delay(250);
  time = time + sec;
}

void loop() {
  if (time <= 99999) {
    if (finish == 0) {
      // put your main code here, to run repeatedly:


      /*
    int switchState2 = analogRead(A2);
    //Serial.println(switchState1);
    //Serial.println(switchState2);
    int status = 0;
    int status2 = 0;
    int finalstat = 0;
    if (finish == 0) {
      if (switchState2 < 500) {
        status2 = 1;
      } else if (switchState2 > 500) {
        status2 = 2;
      }
      if (status2 == 2) {
        Serial.println("Using hugging right wall method");
        digitalWrite(LED_BUILTIN, LOW);
        if (finish == 0) {
          FMPS = 1;
        }
      } else if (status2 == 1) {
        Serial.println("Using hugging left wall method");
        digitalWrite(LED_BUILTIN, LOW);
        if (finish == 0) {
          FMPS = 2;
        }
      }
    }*/






      digitalWrite(front_trig, 0);
      delay(2);
      digitalWrite(front_trig, 1);
      delay(10);
      digitalWrite(front_trig, 0);
      duration_front = pulseIn(front_echo, HIGH);
      if (duration_front < 5820) {
        cm_front = duration_front / (29.1 * 2);
      }
      Serial.print("front distance: ");
      Serial.print(cm_front);
      Serial.println("cm");

      digitalWrite(left_trig, 0);
      delay(2);
      digitalWrite(left_trig, 1);
      delay(10);
      digitalWrite(left_trig, 0);
      duration_left = pulseIn(left_echo, HIGH);
      if (duration_left < 5820) {
        cm_left = duration_left / (29.1 * 2);
      }
      Serial.print("left distance: ");
      Serial.print(cm_left);
      Serial.println("cm");

      digitalWrite(right_trig, 0);
      delay(2);
      digitalWrite(right_trig, 1);
      delay(10);
      digitalWrite(right_trig, 0);
      duration_right = pulseIn(right_echo, HIGH);
      if (duration_right < 5820) {
        cm_right = duration_right / (29.1 * 2);
      }
      Serial.print("right distance: ");
      Serial.print(cm_right);
      Serial.println("cm");
      if (cm_front <= D2WT && cm_left >= D2WT && cm_right >= D2WT) {
        Serial.println("wall detected in front");
      } else if (cm_front >= D2WT && cm_left <= D2WT && cm_right >= D2WT) {
        Serial.println("wall detected left side");
      } else if (cm_front >= D2WT && cm_left >= D2WT && cm_right <= D2WT) {
        Serial.println("wall detected right side");
      } else if (cm_front <= D2WT && cm_left <= D2WT && cm_right >= D2WT) {
        Serial.println("wall detected in front and left");
      } else if (cm_front <= D2WT && cm_left >= D2WT && cm_right <= D2WT) {
        Serial.println("wall detected in front and right");
      } else if (cm_front >= D2WT && cm_left <= D2WT && cm_right <= D2WT) {
        Serial.println("wall detected on the left and right");
      } else if (cm_front <= D2WT && cm_left <= D2WT && cm_right <= D2WT) {
        Serial.println("wall detected on all sides");
      } else {
        Serial.println("No walls detected");
      }



      //TESTING RIGHT WALL ALGORITHM

      if (repetition >= 3 && finish == 0) {

        reverse(300);
        repetition = 0;
        previous_action = 9;
        if (cm_front >= D2WT && cm_left >= D2WT && cm_right >= D2WT) {

          current_action = 2;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          }

          moveForward(505);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[0];
          previous_action = 2;
          //Serial.println(stepTaken);
        }
      }


      if (FMPS == 1 && finish == 0) {
        // 1. If right is clear -> turn right and drive forward

        if (cm_front <= D2WT && cm_left <= D2WT && cm_right >= D2WT) {

          current_action = 1;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          }
          moveForward(100);
          reverse(100);
          turnRight(310);
          moveForward(475);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[1];
          previous_action = 1;

          //Serial.println(stepTaken);
        }
        // 2. If front is clear -> drive forward
        else if (cm_front >= D2WT && cm_left <= D2WT && cm_right <= D2WT) {

          current_action = 2;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          }

          moveForward(500);
          movelog.stepTaken = movelog.stepTaken + 1;
          previous_action = 2;
          //Serial.println(stepTaken);
        }
        // 3. If left is clear -> turn left and drive forward
        else if (cm_front <= D2WT && cm_left >= D2WT && cm_right <= D2WT) {

          current_action = 3;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          } else {
            repetition = 0;
          }
          moveForward(100);
          reverse(100);
          turnLeft(310);
          moveForward(475);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[2];
          previous_action = 3;
          //Serial.println(stepTaken);
        }
        // 3. If left and front is clear -> turn left
        else if (cm_front >= D2WT && cm_left >= D2WT && cm_right <= D2WT) {

          current_action = 4;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          } else {
            repetition = 0;
          }
          moveForward(100);
          reverse(100);
          turnLeft(310);
          moveForward(475);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[2];
          previous_action = 4;
          //Serial.println(stepTaken);
        }
        // 3. If right and front is clear -> turn right
        else if (cm_front >= D2WT && cm_left <= D2WT && cm_right >= D2WT) {

          current_action = 5;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          } else {
            repetition = 0;
          }
          moveForward(100);
          reverse(100);
          turnRight(310);
          moveForward(475);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[1];
          previous_action = 5;
          //Serial.println(stepTaken);
        }
        // 3. If right and left is clear -> turn left
        else if (cm_front <= D2WT && cm_left >= D2WT && cm_right >= D2WT) {

          current_action = 6;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          } else {
            repetition = 0;
          }
          moveForward(100);
          reverse(100);
          turnLeft(310);
          moveForward(500);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[2];
          previous_action = 6;
          //Serial.println(stepTaken);
        }
        // 4. Dead end -> U-turn
        else if (cm_front <= D2WT && cm_left <= D2WT && cm_right <= D2WT) {

          current_action = 7;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          } else {
            repetition = 0;
          }
          turnRight(310);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[1];
          previous_action = 7;
        }

        else {

          current_action = 8;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          } else {
            repetition = 0;
          }
          if (previous_action == 1 || previous_action == 5) {
            moveForward(100);
            reverse(100);
            turnRight(310);
            moveForward(475);
            movelog.stepTaken = movelog.stepTaken + 1;
            ptr = &movelog.moves[1];
          } else if (previous_action == 2) {
            moveForward(510);
            movelog.stepTaken = movelog.stepTaken + 1;
            ptr = &movelog.moves[0];

          } else if (previous_action == 3 || previous_action == 4 || previous_action == 6) {
            moveForward(100);
            reverse(100);
            turnRight(310);
            moveForward(475);
            movelog.stepTaken = movelog.stepTaken + 1;
            ptr = &movelog.moves[1];
          }

          previous_action = 8;
        }
      }


      /*------------------------------------------

   LEFT WALL THING

------------------------------------------*/




      else if (FMPS == 2 && finish == 0) {
        // 1. If left is clear -> turn left and drive forward

        if (cm_front <= D2WT && cm_left >= D2WT && cm_right <= D2WT) {

          current_action = 1;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          }
          moveForward(100);
          reverse(100);
          turnLeft(310);
          moveForward(475);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[2];
          previous_action = 1;

          //Serial.println(stepTaken);
        }
        // 2. If front is clear -> drive forward
        else if (cm_front >= D2WT && cm_left <= D2WT && cm_right <= D2WT) {

          current_action = 2;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          }

          moveForward(510);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[0];
          previous_action = 2;
          //Serial.println(stepTaken);
        }
        // 3. If right is clear -> turn right and drive forward
        else if (cm_front <= D2WT && cm_left <= D2WT && cm_right >= D2WT) {
          current_action = 3;
          if (previous_action == current_action) {
            repetition = repetition + 1;
          } else {
            repetition = 0;
          }
          moveForward(100);
          reverse(100);
          turnRight(310);
          moveForward(475);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[1];
          previous_action = 3;
          //Serial.println(stepTaken);
        }
      }
      // 3. If left and front is clear -> turn left
      else if (cm_front >= D2WT && cm_left >= D2WT && cm_right <= D2WT) {

        current_action = 4;
        if (previous_action == current_action) {
          repetition = repetition + 1;
        } else {
          repetition = 0;
        }
        moveForward(100);
        reverse(100);
        turnLeft(310);
        moveForward(475);
        movelog.stepTaken = movelog.stepTaken + 1;
        ptr = &movelog.moves[2];
        previous_action = 4;
        //Serial.println(stepTaken);
      }
      // 3. If right and front is clear -> turn right
      else if (cm_front >= D2WT && cm_left <= D2WT && cm_right >= D2WT) {

        current_action = 5;
        if (previous_action == current_action) {
          repetition = repetition + 1;
        } else {
          repetition = 0;
        }
        moveForward(100);
        reverse(100);
        turnRight(320);
        moveForward(475);
        movelog.stepTaken = movelog.stepTaken + 1;
        ptr = &movelog.moves[1];
        previous_action = 5;
        //Serial.println(stepTaken);
      }
      // 3. If right and left is clear -> turn left
      else if (cm_front <= D2WT && cm_left >= D2WT && cm_right >= D2WT) {

        current_action = 6;
        if (previous_action == current_action) {
          repetition = repetition + 1;
        } else {
          repetition = 0;
        }
        moveForward(100);
        reverse(100);
        turnLeft(320);
        moveForward(475);
        movelog.stepTaken = movelog.stepTaken + 1;
        ptr = &movelog.moves[2];
        previous_action = 6;
        //Serial.println(stepTaken);
      }
      // 4. Dead end -> U-turn
      else if (cm_front <= D2WT && cm_left <= D2WT && cm_right <= D2WT) {

        current_action = 7;
        if (previous_action == current_action) {
          repetition = repetition + 1;
        } else {
          repetition = 0;
        }
        turnRight(320);
        ptr = &movelog.moves[1];
        previous_action = 7;
      }

      else {

        current_action = 8;
        if (previous_action == current_action) {
          repetition = repetition + 1;
        } else {
          repetition = 0;
        }
        if (previous_action == 1 || previous_action == 5) {
          moveForward(100);
          reverse(100);
          turnRight(320);
          moveForward(475);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[1];
        } else if (previous_action == 2) {
          moveForward(510);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[0];

        } else if (previous_action == 3 || previous_action == 4 || previous_action == 6) {
          moveForward(100);
          reverse(100);
          turnRight(320);
          moveForward(500);
          movelog.stepTaken = movelog.stepTaken + 1;
          ptr = &movelog.moves[1];
          
        } else if (previous_action == 9) {
          if (cm_front >= D2WT && cm_left >= D2WT && cm_right >= D2WT) {

            current_action = 2;
            if (previous_action == current_action) {
              repetition = repetition + 1;
            }

            moveForward(510);
            movelog.stepTaken = movelog.stepTaken + 1;
            ptr = &movelog.moves[0];
            previous_action = 2;
            //Serial.println(stepTaken);
          }
        }

        previous_action = 8;
      }
    }
  }
  irVal = analogRead(A0);

  if (irVal <= 500) {
    Serial.print("light ground, Value = ");
    Serial.println(irVal);

  } else if (irVal >= 500) {
    Serial.print("dark ground, Value = ");
    Serial.println(irVal);
    FMPS = 5;
    if (finish == 0) {
      moveForward(2000);
    }
    finish = 1;
    Serial.println("reached finish line, ending all movement");
  }
  time = time + 333;
  Serial.print("current time: ");
  Serial.println(time / 1000);
  Serial.print("previous move: ");
  if (*ptr == 1){
    Serial.print ("Move Forward");
  }
  else if (*ptr == 2){
    Serial.print ("Turn Right");
  }
    else if (*ptr == 3){
    Serial.print ("Turn Left");
  }
    else if (*ptr == 4){
    Serial.print ("Reverse");
  }
  Serial.print(" as move number: ");
  Serial.println((movelog.stepTaken)+1);
  delay(333);
}
