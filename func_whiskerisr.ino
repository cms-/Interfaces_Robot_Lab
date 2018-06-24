
// This routine turns the bot around
// Input: none
// Output: none
void WhiskerISR(void)
{
  noInterrupts();
  turnFlag = 1;
  interrupts();
}
