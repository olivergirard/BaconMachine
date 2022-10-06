# Bacon Machine
Bacon Machine is a program that creates a fake language out of English letters using the Baconian cipher, that basic phonetics of Japanese, and some preexisting rules that add diversity to the language and make it sound unique. This was developed with the idea of writing things that cannot be deciphered without some knowledge of the Baconian cipher and the special rules applied to it (see below!). The rules of the language were chosen based on the phonic sounds in the majority of Japanese UTAU voicebanks for more applicable pronunciation.

## Installation
As of right now, Bacon Machine needs a compiler in order to run. I would love to turn this into an executable file someday!

## Rules used when generating the language
### Consonant-Vowel to Consonant-Consonant-Vowel
| CV  | CCV |
| ------------- | ------------- |
| cx | chx |
| sx | shx |

Where "x" is any vowel except for "y".

### Usage of certain letters
Some of these changes make sense phonetically. Some of these changes are purely cosmetic.
- f is replaced with s
- l is replaced with r
- q is replaced with k
- v is replaced with m
- x is replaced with s
- y is replaced with n

## TODO
- General cleanup and optimization:
  - Make the yes-or-no option within main() more user-friendly.
  - Make cipher_array and language_array global.
  - Create multiple size variables.
  - Allow for user input of (virtually) any size. I'm hoping this is possible with the usage of %m?

## General Baconian cipher information
A copy of the Baconian cipher that will be used in this program can be found [here](https://www.cryptogram.org/downloads/aca.info/ciphers/Baconian.pdf).

## Fun fact
I don't like bacon. This program has nothing to do with bacon.
