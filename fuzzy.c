#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool fuzzy_search(char *key, char *string)
{
  char *remaining_string;
  if ( strlen(key) == 0)
    return true;

  if ( (remaining_string = strchr(string, key[0])) != NULL )
      return fuzzy_search( key+1, remaining_string+1 );
  else
    return false;
}

main()
{
  char string[200] = "apply ceanvas";

  char *key;
  bool status;

  printf("%s", "Key:");
  scanf("%s", key);

  status = fuzzy_search(key, string);

  printf("The fuzzy string match ");
  if(status)
    printf("succeeded.\n");
  else
    printf("failed.\n");

}