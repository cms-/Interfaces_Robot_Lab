
// This routine outputs sound over the piezoelectric
// squeaker depending on the state flag passed.
// Input: state flag
// Output: none
void InitSqueaker(void)
{
    AudioMemory(4);
    mix1.gain(0, 6.4);
}
