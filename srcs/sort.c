#include "../includes/nm.h"

int compare_value(void *a, void *b) {
  t_symbol *symbol_a = a;
  t_symbol *symbol_b = b;
  uint16_t va, vb;
  if (symbol_a->sym64 && symbol_b->sym64) {
    va = symbol_a->sym64->st_value;
    vb = symbol_b->sym64->st_value;
  } else {
    va = symbol_a->sym32->st_value;
    vb = symbol_b->sym32->st_value;
  }
  return (va - vb);
}

// nm sort alphabetically, skipping non alphanum, and case insensitive
int compare_symbol(void *a, void *b) {
  t_symbol *symbol_a = a;
  t_symbol *symbol_b = b;
  const char *s1 = symbol_a->name;
  const char *s2 = symbol_b->name;

  if (s1 == NULL || s2 == NULL)
    return (0);
  while (*s1 && *s2) {
    while (*s1 && !ft_isalnum(*s1))
      s1++;
    while (*s2 && !ft_isalnum(*s2))
      s2++;
    if (ft_tolower(*s1) != ft_tolower(*s2)) {
      return ((unsigned char) ft_tolower(*s1) - (unsigned char) ft_tolower(*s2));
    }
    s1++;
    s2++;
  }
  if (*s1 == *s2) {
    if      (symbol_b->type == 'W' && symbol_a->type == 'D') return -1;
    else if (symbol_b->type == 'D' && symbol_a->type == 'W') return 1;
    else if (symbol_b->type == 't' && symbol_a->type == 'T') return -1;
    else if (symbol_b->type == 'T' && symbol_a->type == 't') return 1; 
    else if (symbol_b->type == 'T' && symbol_a->type == 'W') return -1;
    else if (symbol_b->type == 'W' && symbol_a->type == 'T') return 1;
    return (compare_value(a, b));
    /* return ft_strlen(symbol_a->name) - ft_strlen(symbol_b->name); */
    /* if (symbol_a->type + 32 == symbol_b->type) */
    /*   return (1); */
    /* else if (symbol_a->type - 32 == symbol_b->type) */
    /*   return (-1); */
    /* return (ft_strcmp(symbol_a->name, symbol_b->name)); */
  }
  return ((unsigned char) *s1 - (unsigned char) *s2);
}
