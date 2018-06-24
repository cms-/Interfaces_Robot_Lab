
// This routine outputs sound over the piezoelectric
// squeaker depending on the state flag passed.
// Input: state flag
// Output: none
void Squeak(uint8_t flag)
{
  switch (flag)
  {
    case 1 :
      sound0.play(AudioSampleSwish);
      break;
    case 2 :
      sound0.play(AudioSamplePew);
      break;
    case 3 :
      sound0.play(AudioSamplePew);
      break;
    case 4 :
      sound0.play(AudioSampleSpacegas);
      delay(175);
      break;
    case 5 :
      sound0.play(AudioSampleYoink);
      delay(250);
      break;
    case 55 :
      sound0.play(AudioSampleR2d2);
      delay(380);
      break;
 }
  
}
