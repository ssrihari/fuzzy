#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool fuzzy(char *key, char *string)
{
  char *remaining_string = string;
  if ( strlen(remaining_string) == 0 || strlen(key) == 0 )
      return true;

  if ( (remaining_string = strchr(string, key[0])) != NULL )
      fuzzy( key+1, remaining_string+1 );
  else
    return false;

}

main()
{
  char string[200] = "hollo i am srihari and i am trying out fuzzy search for tito";

  char *key;
  bool status;

  printf("%s", "Enter something:");
  scanf("%s", key);
  status = fuzzy(key, string);
  printf("The fuzzy string match returned %d\n", status);
}