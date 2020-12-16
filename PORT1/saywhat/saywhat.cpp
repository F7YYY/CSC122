#include <fstream>
#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

inline bool word_end(char ch) { // PUNCTUATION CALLER
  return ch == ' ' || ch == ',' || ch == '.' || ch == ':' || ch == ';' ||
         ch == '!' || ch == '?';
}

short word_count(string english) { // #-WORDS
  short words = 0, i = 0;
  char foundless = '<', foundg8r = '>';

  while (english[i] != '\0') {
    if (english[i] == foundless && i > 0 && word_end(english[i - 1])) {
      --words;
    }
    if (english[i] == foundless) { // OPTIONAL - FIND <HTML_TAGS>
      do {
        ++i;
      } while (english[i] != foundg8r && english[i] != '\0');
    }
    if (english[i] == foundg8r) {
      ++i;
    }
    if (word_end(english[i]) && !word_end(english[i + 1])) {
      words++;
    }
    ++i;
  }
  if (i > 0 && !word_end(english[i - 1])) {
    words++;
  }
  if (english[0] == '\0') {
    words = 0;
  }
  return words;
}

short sentence_count(string english) { // #-SENTENCES
  short sentences = 0, i = 0;

  while (english[i] != '\0') { // SPECIFIES FOR "Colon" && "Semicolon"
    if (english[i] == '.' || english[i] == '!' || english[i] == '?' ||
        english[i] == ':' || english[i] == ';') {
      ++sentences;
    }
    ++i;
  }
  return sentences;
}
inline bool isvowel(char ch) { // VOWEL CALLER
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

short syllable_count(string english) { // #-SYLLABLES
  short syllables = 0, i = 0;

  while (english[i] != '\0') {
    if (isvowel(english[i]) && !isvowel(english[i + 1])) {
      ++syllables;
    }
    ++i;
  }
  return syllables;
}

double index_count(string english) { // INDEX-#
  double index = 206.835 -
                 84.6 * syllable_count(english) / word_count(english) -
                 1.015 * word_count(english) / sentence_count(english);
  return index;
}

int main(void) { // REQUESTS && PROCESSES USER'S WRITTEN RESPONCE || FILE.TXT
  ifstream filetxt;
  string answer, english, file, dest;

  system("clear"); // INITIAL REQUEST
  cout << "|[SAY_WHAT??]|\n\nGOT_FILE.TXT?: ";
  getline(cin, answer);
  switch (answer[0]) { // PROCESSING USER'S ANSWER
  case 'N':            // WRITTEN RESPONCE
  case 'n':
    system("clear");
    cout << "|||[SAY_WHAT??]|||\n\n__ENTER_ENGLISH__\n" << endl;
    getline(cin, english);
    break;
  case 'Y': // OPTIONAL - FILE.TXT
  case 'y':
    cout << "\nFILENAME: ";
    getline(cin, file);
    filetxt.open(file);
    if (filetxt.fail()) {
      cout << "^FILENAME_INVALID^" << endl;
    } else {
      filetxt.peek();
      cout << "FOUND_FILE: " << file << "! ^_^" << endl;
      while (!filetxt.eof()) {
        getline(filetxt, dest);
        english += dest + '\n';
        filetxt.peek();
      }
      filetxt.close();
      filetxt.clear();
    }
    break;
  default:
    cout << "\n^ANSWER_INVALID^\n" << endl;
    break;
  }
  cout << "\n#-WORDS: " << word_count(english);
  cout << "\n#-SENTENCES: " << sentence_count(english);
  cout << "\n#-SYLLABLES: " << syllable_count(english);
  cout << "\nINDEX-#: " << index_count(english) << endl << endl;
  return 0;
} // !MOST COMPLEX PROGRAM EVER ACCOMPLISHED!
