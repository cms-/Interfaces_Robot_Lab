
// This routine drives the motors according
// to the state flag and duration in msecs.
// Input: state flag, duration is msecs
// Output: none
void Drive(uint8_t flag, uint16_t duration)
{
 switch (flag)
 {
   int i;
   case 1 :
     display.print("fwd... ");
     motors[0].setSpeed(MAX_SPEED);
     motors[1].setSpeed(MAX_SPEED);
     break;
   case 2 :
     display.print("right... ");
     motors[0].setSpeed(MAX_SPEED);
     motors[1].setSpeed(MAX_SPEED/TURN);
     break;
   case 3 :
     display.print("left... ");
     motors[0].setSpeed(MAX_SPEED/TURN);
     motors[1].setSpeed(MAX_SPEED);
     break;
   case 5 :
     display.print("LOUD NOISES!");
     for (i=0; i<6; i++)
     {
       display.print("!");
       if (turnFlag == 1)
       {
         TurnAround();
         turnFlag = 0;
       }
       Display(5);
       Squeak(55);
       Drive(2, 150);
       Squeak(5);
       Drive(3, 150);
       display.print("!");
     }
     TurnAround();
       Display(5);
       motors[0].setSpeed(0);
       motors[1].setSpeed(0);
       Squeak(5);
       delay(2000);
       TurnAround();
       Display(5);
       motors[0].setSpeed(0);
       motors[1].setSpeed(0);
       Squeak(5);
     delay(2000);
     Squeak(55);
     delay(2000);
     display.print("! ");
     Squeak(4);
     break;
 }
 delay(duration);
}

