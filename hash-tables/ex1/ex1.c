#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *answer = malloc(sizeof(Answer));

  for (int i = 0; i < length; i++)
  {
    int retrieve = hash_table_retrieve(ht, weights[i]);
    if (retrieve != -1)
    {
      answer->index_1 = i;
      answer->index_2 = retrieve;
      destroy_hash_table(ht);
      return answer;
    }
    else
    {
      hash_table_insert(ht, limit - weights[i], i);
    }
  }

  destroy_hash_table(ht);

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}