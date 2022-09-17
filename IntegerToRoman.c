
char * intToRoman (int num)
{
  char *romanNumeral = calloc (5, sizeof (char));
  sprintf (romanNumeral, "%d", num);

  char *result = calloc (25, sizeof (char));

  int val[4];
  int digits = 0;
  int temp = num;
  int digits_iter = 0;

  while (temp > 0)
    {
      temp /= 10;
      digits++;
    }
  digits_iter = digits;

    for (int i = 3; i >= ((3-digits) + 1); i--)
    {
      val[i] = romanNumeral[digits_iter-1] - 48;
      digits_iter--;
    }
  if (digits == 4)
    {
      for (int i = 0; i < val[0]; i++){strcat (result, "M");}
    }
  
  if (digits >= 3)
    {

      if (val[1] == 9 || val[1] == 4)
	{
	  val[1] == 9 ? strcat (result, "CM") : strcat (result, "CD");
	}
      else if (val[1] >= 5)
	{
	  strcat (result, "D");
	  if (val[1] > 5)
	    {
	      for (int i = 0; i < (val[1]-5); i++){strcat (result, "C");}
	    }
	}
      else if (val[1] < 5)
	{
	  for (int i = 0; i < val[1]; i++){strcat (result, "C");}
	}
    }
  
  if (digits >= 2)
    {

      if (val[2] == 9 || val[2] == 4)
	{
	  val[2] == 9 ? strcat (result, "XC") : strcat (result, "XL");
	}
      else if (val[2] >= 5)
	{
	  strcat (result, "L");
	  if (val[2] > 5)
	    {
	      for (int i = 0; i < (val[2]-5); i++){strcat (result, "X");}
	    }
	}
      else if (val[2] < 5)
	{
	  for (int i = 0; i < val[2]; i++)
	    {
	      strcat (result, "X");
	    }
	}
    }
  
  if (digits >= 1)
    {
      if (val[3] == 9 || val[3] == 4)
	{
	  val[3] == 9 ? strcat (result, "IX") : strcat (result, "IV");
	}
      else if (val[3] >= 5)
	{
	  strcat (result, "V");
	  if (val[3] > 5)
	    {
	      for (int i = 0; i < (val[3]-5); i++){strcat (result, "I");}
	    }
	}
      else if (val[3] < 5)
	{
	  for (int i = 0; i < val[3]; i++){strcat (result, "I");}
	}
    }
  
  return result;
}