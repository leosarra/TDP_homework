#include <stdio.h>
#include <math.h>
int main()
{
  int num1, num2, max;
  printf("Inserisci due numeri interi: ");
  scanf("%d %d", &num1, &num2);
  max=(num1>num2) ? num1 : num2; /* VALORE MASSIMO SALVATO IN MAX */
  while(3)                       /* SEMPRE VERO */
  {
      if(max%num1==0 && max%num2==0)
      {
          printf("MCM di %d e %d è %d \n", num1, num2,max);
          break;          /* <---- ROMPE IL CICLO WHILE. */
      }
      ++max;
  }
  return 0;
}
