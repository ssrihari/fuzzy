#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool fuzzy_search(char *key, char *string)
{
  char *remaining_string = string;
  if ( strlen(key) == 0 || strlen(remaining_string) == 0 )
      return true;

  if ( (remaining_string = strchr(string, key[0])) != NULL )
      fuzzy_search( key+1, remaining_string+1 );
  return false;
}

main()
{
  char string[200] = "hollo i am srihari and i am trying out fuzzy_search search for tito";

  char *key;
  bool status;

  printf("%s", "Enter something:");
  scanf("%s", key);
  status = fuzzy_search(key, string);
  printf("The fuzzy_search string match returned %d\n", status);
}