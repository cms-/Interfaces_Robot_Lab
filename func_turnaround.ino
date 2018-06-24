
// This routine turns the bot around
// Input: none
// Output: none
void TurnAround(void)
{
  Display(4);
  Squeak(4);
  display.println("!!! Turning around... ");
  motors[0].setSpeed(0);
  motors[1].setSpeed(0);
  delay(400);
  motors[0].setSpeed(-MAX_SPEED);
  motors[1].setSpeed(-MAX_SPEED);
  delay(700);
  motors[0].setSpeed(MAX_SPEED);
  motors[1].setSpeed(-MAX_SPEED);
  delay(2000);

}
