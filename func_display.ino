
// This routine displays the appropriate bmp according
// to the state flag that is passed
// Input: state flag
// Output: none
void Display(uint8_t flag)
{
  switch (flag)
 {
   int i;
   case 1 :
     GLCD.DrawBitmap(fwd, 0, 0);
     break;
   case 2 :
     GLCD.DrawBitmap(right, 0, 0);
     break;
   case 3 :
     GLCD.DrawBitmap(left, 0, 0);
     break;
   case 4 :
     GLCD.DrawBitmap(turnaround, 0, 0);
     break;
   case 5 :
     for (i=0; i<4; i++) {
       GLCD.DrawBitmap(freakout, 0, 0);
       delay(80);
       GLCD.DrawBitmap(freakout2, 0, 0);
       delay(80);
     }
     break;
 }
  
  
}
