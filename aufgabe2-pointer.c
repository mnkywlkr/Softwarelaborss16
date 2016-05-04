/**
 * @file   aufgabe2-pointer.c
 * @brief  Aufgabe2 - Pointermanipulationen
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Falls notwendig erweitern Sie die Liste der includes

/**
   @brief Aufgabe2a: Scannen durch einen String
   @param [in] char* input
   @return char*

Input ist ein String der aus alphanumerischen Zeichen besteht die
durch :: getrennt sein koennen. Als Beispiele betrachte man

<p>

<ul>
  <li> "Ha::ll::o"
  <li> "47::11"
</ul>

Ihre Aufgabe ist es eine Funktion zu schreiben die den
laengsten suffix (Endung) liefert der kein :: enthaelt.
Laengste Endungen fuer unsere Beispiele:
<ul>
  <li> "o"
  <li> "11"
</ul>

<p>

Input ist der String (char pointer), das Ergebnis soll als
return Wert geliefert werden, welcher ein Zeiger auf den
Anfang der laengsten Endung ohne :: ist.

 */

char* extract(char* input) {
    int pos = 0;
    char* suffix = "";
    while (input[pos] != '\0') {
        if (input[pos] == ':' && input[pos+1] == ':' ) {
            suffix = &input[pos+2];
        }
        pos++;
    }
    return suffix;

}

/**
   @brief Aufgabe2b: Variation von 2a
   @param [in] char* input
   @param [out] char** output

Das Ergebnis soll hier nicht als return Wert geliefert werden.
Anstatt wird ein pointer auf einen pointer verwendet.
Wieso reicht ein pointer nicht aus?
*/

void extract2(char* input, char** output) {
    *output = extract(input);

}

/**
   @brief Aufgabe2c: Weitere Variation von Scannen
   @param [in] char* input
   @return int

Input ist ein String der aus einer Liste von alphanumerischen Woertern
die durch Leerzeichen (white-space) getrennt sind.
Ihre Aufgabe ist es eine Funktion zu schreiben, die die Anzahl der
Woerter zaehlt.
<p>
Beispiel:  "Ha ll o 5"
<p>
Soll liefern 4
*/
 /**
  *Ueberspringen von Leerzeichen.
  */
void skipWhitespace(char* input, char** output){
    while(*input == ' ') {
        input++;
    }
    *output = input;
    // return input;
 }
 
 int alphanumericChar(char* input, char**output){
    int n = 0;
     while (*input != '\0' && *input != ' '){
         input++;
        n++;
     }
     *output = input;
    return n;
 }

 //int wordSize(char* input){
    // int n;
    // while (*input != ' ' && *input != '\0'){
    //    input++;
    //    n++;
    // }
    // return n;
 //}
 
int count(char* input) {
    int n = 0;
    while(*input != '\0'){
        //*/*printf("%d\n", n);*/*/
        skipWhitespace(input,&input);
        if (*input != '\0') {
            n++;
            alphanumericChar(input,&input);
        }
    }
  return n; // Muss durch Ihre Loesung ersetzt werden
}
 
 
/**
   @brief Aufgabe2d: Aufsammeln von Woertern. Erweiterung von Aufgabe2c.
   @param [in] char* line
   @param [in] int maxwords
   @param [out] char* words[]
   @return int Anzahl aufgesammelter Woerter

Gegeben (als Input) ist ein String der aus einer Liste von alphanumerischen
Woertern die durch Leerzeichen (white-space) getrennt sind.
Ihre Aufgabe ist es die Woerter in einem Array von Strings aufzusammeln.
Das Array von Strings words wird pre-allokiert mit fester Groesse (maxwords).
Die Anzahl der aufgesammelten Woerter wird als return Wert zurueck
geliefert.

*/

int breakIntoWords(char* line, int maxwords, char* words[]) {
    int n;
    int i = 0;

    if (maxwords < count(line)) {
        n = maxwords;
    } else {
        n = count(line);
    }
   
    while (i < n ) {
        if (*line ==' '){
            skipWhitespace(line,&line);
        } else {
            char* beginningOfWord = line;
            int size = alphanumericChar(line,&line);
            words[i] = (char*)malloc(sizeof(char) * (size + 1));
            memcpy(words[i], beginningOfWord, sizeof(char)*size);
            words[i][size] = '\0';
            i++;
        }
        if (*line == '\0'){
            break;
        }
    }
  return n; // Ihre Loesung
}

typedef enum {
    OK,
    FAIL
}Test;

//Test fuer Extract.
Test testExtract(char* input, char* expected){
    Test t;
    if (*expected == *extract(input)){
        t = OK;
    } else {
        t = FAIL;
    }
    return t;
}

typedef struct {
  char* input;
  char* expected;
} TestCaseExtract;

void runTestsExtract(int no, TestCaseExtract test[]) {
  Test t;
  int i;

  for(i=0; i < no; i++) {
    printf("Test %d: ", i);
    t = testExtract(test[i].input, test[i].expected);
    if(OK == t){
      printf("OK \n");
    }
    if(FAIL == t){
      printf("FAIL \n");
    }
   }
}
//Test testExtract2(char* input, char* expected){
//    Test t;
//    char** output;
//    extract2(input, output);
//    if (expected == *output){
//        t =  OK;
//    } else {
//        t = FAIL;
//    }
//    return t;
//}

Test testCount(char* input, int expected){
    Test t;
    if (expected == count(input)){
        t = OK;
    } else {
        t = FAIL;
    }
    return t;
}

typedef struct {
  char* input;
  int expected;
} TestCaseCount;


void runTestsCount(int no, TestCaseCount test[]) {
  Test t;
  int i;

  for(i=0; i < no; i++) {
    printf("Test %d: ", i);
    t = testCount(test[i].input, test[i].expected);
    if(OK == t){
      printf("OK \n");
    }
    if(FAIL == t){
      printf("FAIL \n");
    }
  }
}

int main() {
  // Ihre Testroutinen

   
    char* input = "Hallo::";
    char* input2 = "I::sleep";
    char line[] = " I  have   homework ";
    int i = 0;
    int nwords;
    char* words[10];
    char** output = &input;
   
    //Anzahl der Test
    const int testNoCount = 9;
    const int testNoExtract = 4;
   
    // Intialize TestCase for testExtract
    TestCaseExtract testsExtract[4] = {
       {"", ""},
       {":lo", ""},
       {"::", ""},
       {"H:all:::o", "o"}
     };

    // Initialize TestCase for testCount
    TestCaseCount testsCount[9] = {
       {"", 0},
       {"Hallo", 1},
       {"  Hallo", 1},
       {"Hallo ", 1},
       {"  Hallo  ", 1},             

       {"Hal   lo", 2}, 
       {" Hal  lo", 2}, 
       {"Hal  lo ", 2}, 
       {"  Hal  lo  ", 2}             
     };

	printf("Testing Extract \n");
    runTestsExtract(testNoExtract,testsExtract);
    
    printf("Testing Count \n");
    runTestsCount(testNoCount,testsCount);
    //printf("count: %d \n", count(line));

   
    printf("Example : \n");
    printf("Before: %s \n", input);
    input = extract(input);
    printf("After: %s \n", input);
    printf("Test result:");

   
    extract2(input2, output);
    printf("input: %s    output: %s \n", input2, *output);
   
    //
   
   
    nwords = breakIntoWords(line, 2, words);
    for(i = 0; i < nwords; i++){
        printf("%s\n", words[i]);
		free(words[i]);
    }
   
  /* Beispieltest fuer Aufgabe2d
char line[] = "this is a test";
    int i;
        int nwords;
        char* words[10];

    nwords = breakIntoWords(line, 10, words);
    for(i = 0; i < nwords; i++)
        printf("%s\n", words[i]);

 soll liefern

this
is
a
test

  */
}