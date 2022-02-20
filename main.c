#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void english_to_cipher(char *s, char *sentence, char* cipher_sentence);
int MAX_LENGTH = 500;
int BAD_I_SIZE = 14;
int BAD_U_SIZE = 3;

int main() {

  char *more_bacon = "\0";

  printf("Welcome to the Bacon Machine!\n");
  printf("RULES: Spaces are allowed, but no special characters!\n");
  printf("Sentences cannot be more than 500 characters.\n");
  do {
    char *sentence = "\0";
    sentence = (char*) malloc(MAX_LENGTH * sizeof(char));
    char *cipher_sentence = "\0";
    cipher_sentence = (char*) malloc((MAX_LENGTH * 5 * sizeof(char)) + 1);
    char *s = "\0";
    s = (char*) malloc(MAX_LENGTH * sizeof(char));
    more_bacon = (char*) malloc(MAX_LENGTH * sizeof(char));

    printf("Enter a sentence. Remember the rules!\n");
    scanf("%[^\n]", s);

    printf("Your sentence is being run through the Bacon Machine...\n");
    printf("Your completed sentence is:\n");
    english_to_cipher(s, sentence, cipher_sentence);
    printf("Would you like to make more Bacon? Enter \"NO\" or \"no\" if you're all Bacon-ed out!\n");
    scanf("%*c%[^\n]%*c", more_bacon);
  } while ((strcmp(more_bacon, "NO") != 0) && (strcmp(more_bacon, "no") != 0));

  return 0;
}

void english_to_cipher(char *s, char *sentence, char *cipher_sentence) {
  int count = 0;
  int size = 0;
  char *cipher_array[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaaa", "abaab", "baaaa", "ababb", "abbaa", "abbab", "abbba", "abaab", "baaaa", "baaab", "baaba", "baabb", "aabab", "babaa", "abaab", "babba", "babbb"};
  char *language_array[26] = { "a", "by", "ch", "d", "e", "f", "gy", "hy", "i", "j", "ky", "r", "my", "ny", "o", "py", "k", "ry", "sh", "t", "u", "f", "w", "s", "y", "z" };
  char *bad_i[] = {"by", "d", "gy", "hy", "ky", "my", "ny", "py", "ry", "s", "t", "w", "y", "z"};
  char *bad_u[] = {"d", "t", "w"};

  //size of s
  while (s[size] != '\0') {
    size++;
  }

  //removes all special characters from the sentence, including spaces
  for (int i = 0; i < size; i++) {
    if (((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122))) {
      strncat(sentence, &s[i], 1);
      count++;
    }
  }

  printf("sentence: %s", sentence);

  count = 0;
  size = 0;

  //size of sentence
  while (sentence[size] != '\0') {
    size++;
  }

  //creates new, long sentence using the Baconian cipher
  for (int j = 0; j < size; j++) {
    count = sentence[j];
    if (count <= 90) {
      count -= 65;
    } else {
      count -= 97;
    }
    strcat(cipher_sentence, cipher_array[count]);
  }

  int random = 0;

  //size of cipher_sentence
  size = 0;
  while (cipher_sentence[size] != '\0') {
    size++;
  }

  printf("Encoded sentence: %s\n", cipher_sentence);
  bool consonant = true;
  char *previous_consonant = "\0";
  previous_consonant = (char*) malloc((MAX_LENGTH * sizeof(char)));
  bool bad_consonant = false;

  //bacon time! a space should come after every vowel. print to terminal
  for (int p = 0; p < size; p++) {
    if (cipher_sentence[p] == 'a') {
    //this makes a consonant
      if (consonant == true) {
        do {
          random = (rand() % 13);
        } while ((random == 0) || (random == 4) || (random == 8));
        consonant = false;
        previous_consonant = language_array[random];
        } else {
        //this makes a or e or i
        do {
          random = (rand() % 13);
        } while ((random != 0) && (random != 4) && (random != 8));
        consonant = true;
      }
    } else {
    //this makes a consonant
      if (consonant == true) {
        do {
          random = (rand() % 13) + 13;
        } while ((random == 14) || (random == 20));
        consonant = false;
        previous_consonant = language_array[random];
      } else {
      //this makes o or u
        do {
          random = (rand() % 13) + 13;
        } while ((random != 14) && (random != 20));
        consonant = true;
      }
    }

    for (int i = 0; i < BAD_I_SIZE; i++) {
      if ((strcmp(previous_consonant, bad_i[i]) == 0) && (strcmp(language_array[random], "i") == 0)) {
        bad_consonant = true;
      }
    }

    for (int i = 0; i < BAD_U_SIZE; i++) {
      if ((strcmp(previous_consonant, bad_u[i]) == 0) && (strcmp(language_array[random], "u") == 0)) {
        bad_consonant = true;
      }
    }

    if (bad_consonant == true) {
      p--;
    } else {
      printf("%s", language_array[random]);
      if ((random == 0) || (random == 4) || (random == 8) || (random == 14) || (random == 20)) {
        printf(" ");
      }
    }

    random = 0;
  }
  printf("\n");
}
