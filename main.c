#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void english_to_cipher(char *s, char *sentence, char* cipher_sentence);
int MAX_LENGTH = 100;

int main() {
  char *s = "\0";
  s = (char*) malloc(MAX_LENGTH * sizeof(char));
  char *more_bacon = "\0";
  more_bacon = (char*) malloc(MAX_LENGTH * sizeof(char));

  printf("Welcome to the Bacon Machine!\n");
  printf("RULES: Spaces are allowed, but no special characters!\n");
  printf("Sentences cannot be more than 100 characters.\n");
  do {
    char *sentence = "\0";
    sentence = (char*) malloc(MAX_LENGTH * sizeof(char));
    char *cipher_sentence = "\0";
    cipher_sentence = (char*) malloc((MAX_LENGTH * 5 * sizeof(char)) + 1);

    printf("Enter a sentence. Remember the rules!\n");
    scanf("%s", s);
    printf("Your sentence is being run through the Bacon Machine...\n");
    printf("Your completed sentence is:\n");
    english_to_cipher(s, sentence, cipher_sentence);
    printf("Would you like to make more Bacon? Enter \"NO\" or \"no\" if you're all Bacon-ed out!\n");
    scanf("%s", more_bacon);
  } while ((strcmp(more_bacon, "NO") != 0) && (strcmp(more_bacon, "no") != 0));

  return 0;
}

void english_to_cipher(char *s, char *sentence, char *cipher_sentence) {
  int count = 0;
  int size = 0;
  char *cipher_array[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaaa", "abaab", "baaaa", "ababb", "abbaa", "abbab", "abbba", "abaab", "baaaa", "baaab", "baaba", "baabb", "aabab", "babaa", "abaab", "babba", "babbb"};
  char *language_array[26] = { "a", "by", "ch", "d", "e", "f", "gy", "hy", "i", "j", "ky", "r", "my", "ny", "o", "py", "k", "ry", "sh", "t", "u", "f", "w", "s", "y", "z" };


  //size of s
  while (s[size] != '\0') {
    size++;
  }

  //removes all special characters from the sentence, including spaces
  if (((s[0] >= 65) && (s[0] <= 90)) || ((s[0] >= 97) && (s[0] <= 122))) {
    strcat(sentence, &s[0]);
    count++;
  }

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

  //bacon time! a space should come after every vowel. print to terminal
  for (int p = 0; p < size; p++) {
    if (cipher_sentence[p] == 'a') {
      if (consonant == true) {
        do {
          random = (rand() % 13);
        } while ((random != 0) && (random != 4) && (random != 8));
        consonant = false;
      } else {
        do {
          random = (rand() % 13);
        } while ((random == 0) || (random == 4) || (random == 8));
        consonant = true;
      }
    } else {
      if (consonant == true) {
        do {
          random = (rand() % 13) + 13;
        } while ((random != 14) && (random != 20));
        consonant = false;
      } else {
        do {
          random = (rand() % 13) + 13;
        } while ((random == 14) || (random == 20));
        consonant = true;
      }
    }
    printf("%s", language_array[random]);
    if ((random == 0) || (random == 4) || (random == 8) || (random == 14) || (random == 20)) {
      printf(" ");
    }
  }
  printf("\n");
}
