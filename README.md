# Bacon Machine
Bacon Machine is a program that creates a fake language out of English letters using the Baconian cipher, that basic phonetics of Japanese, and some preexisting rules that add diversity to the language and make it sound unique. This was developed with the idea of writing songs that cannot be deciphered without some knowledge of the Baconian cipher and the special rules applied to it (see below!).

## Installation
As of right now, Bacon Machine needs a compiler in order to run. I would love to turn this into an executable file someday!

## Rules used when generating the language
### Consonant-Vowel to Consonant-Vowel-Vowel
While "a" is used in this example, any vowel besides y is also applicable.
| CV  | CVV |
| ------------- | ------------- |
| ba  | bya  |
| ca | cha |
| ga | gya |
| ha  | hya  |
| ka | kya |
| ma | mya |
| na | nya |
| pa | pya |
| ra | rya |
| sa | sha |

### Usage of certain letters
- l is replaced with r, not ry
- q is replaced with k, not ky
- v is replaced with f
- x is replaced with k, not ky

## TODO
- General cleanup and optimization:
  - Make the yes-or-no option within main() more user-friendly.
  - Make cipher_array and language_array global.
  - Create multiple size variables.
  - Allow for user input of (virtually) any size. I'm hoping this is possible with the usage of %m?
- **Prevent certain combinations that cannot be pronounced.** These include myi, du, wi, etc.

## General Baconian cipher information
A copy of the Baconian cipher that will be used in this program can be found [here](https://www.cryptogram.org/downloads/aca.info/ciphers/Baconian.pdf).

## Fun fact
I don't like bacon. This program has nothing to do with bacon.
