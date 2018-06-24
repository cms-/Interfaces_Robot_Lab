
// This routine turns the bot around
// Input: none
// Output: none
void InitDisplay(void)
{
  analogWriteFrequency(4, 2000);
  analogWrite(4, 128);
  GLCD.Init();
  GLCD.DrawBitmap(initial, 0, 0);
  display.DefineArea(29, 2, 119, 29);
  display.SelectFont(System5x7);
  
  display.print("WHEELIE ");
  delay(3000);
  display.println("Project for BerkeleyX EE40LX edX.org");
  delay(5000);

}
