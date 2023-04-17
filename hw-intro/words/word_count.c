/*

Copyright © 2019 University of California, Berkeley

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

word_count provides lists of words and associated count

Functional methods take the head of a list as first arg.
Mutators take a reference to a list as first arg.
*/

#include "word_count.h"

/* Basic utilities */

void to_lower(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    str[i] = tolower(str[i]);
    i++;
  }
}

char *new_string(char *str) {
  char *new_str = (char *) malloc(strlen(str) + 1);
  if (new_str == NULL) {
    return NULL;
  }
  return strcpy(new_str, str);
}

int init_words(WordCount **wclist) {
  /* Initialize word count.
     Returns 0 if no errors are encountered
     in the body of this function; 1 otherwise.
  */
  *wclist = malloc(sizeof(struct word_count));
  (*wclist)->word = NULL;
  (*wclist)->count = 0;
  (*wclist)->next = NULL;
  return 0;
}

ssize_t len_words(WordCount *wchead) {
  /* Return -1 if any errors are
     encountered in the body of
     this function.
  */
    size_t len = 0;
    if (wchead == NULL) {
      return len;
    }
    WordCount *last_node = wchead;
    while (last_node->next != NULL) {
      last_node = last_node->next;
      len++;
    }
    return len;
}

WordCount *find_word(WordCount *wchead, char *word) {
  /* Return count for word, if it exists */
  WordCount *wc = NULL;
  return wc;
}

int add_word(WordCount **wclist, char *word) {
  /* If word is present in word_counts list, increment the count.
     Otherwise insert with count 1.
     Returns 0 if no errors are encountered in the body of this function; 1 otherwise.
  */
  to_lower(word);
  WordCount *tmp = malloc(sizeof(struct word_count));
  if (tmp == NULL) {
    // malloc failed
    return 1;
  }
  tmp->count = 1;
  tmp->next = NULL;
  tmp->word = word;
  if (*wclist == NULL) {
    *wclist = tmp;
    return 0;
  } 
  // else if (strcmp((*wclist)->word, word) == 0) {
  //   (*wclist)->count++;
  //   return  0;
  // }

  
  WordCount *last_node = *wclist;
  // append to the tail
  while (last_node->next != NULL) {
    last_node = last_node->next;
    if (strcmp(last_node->word, word) == 0) {
      // if the word has occured
      last_node->count++;
      return 0;
    }
  }
  last_node->next = tmp;
  return 0;
}

void fprint_words(WordCount *wchead, FILE *ofile) {
  /* print word counts to a file */
  WordCount *wc;
  for (wc = wchead; wc; wc = wc->next) {
    if (wc->count != 0) {
      fprintf(ofile, "%i\t%s\n", wc->count, wc->word);
    }
  }
}
