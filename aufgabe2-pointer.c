/**
 * @file   aufgabe2-pointer.c
 * @brief  Aufgabe2 - Pointermanipulationen
 */

#include <stdio.h>
#include <string.h>
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
	char* suffix = input;
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
 
 void alphanumericChar(char* input, char**output){
 	while (*input != '\0' && *input != ' '){
 		input++;
 	}
 	*output = input;
 }
 
int count(char* input) {
	int n = 0;
	while(*input != '\0'){
		skipWhitespace(input,&input);
		if (*input != ' '){
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
	int i;

	if (maxwords < count(line)) {
		n = maxwords;
	} else {
		n = count(line);
	}
	
	while (i < n ) {
		if (*line ==' '){
			skipWhitespace(line,&line);
		} else {
			words[i] = line;
			alphanumericChar(line,&line);
			i++;
		}
		if (*line == '\0'){
			break;
		}
	}
  return n; // Ihre Loesung
}


int main() {
  // Ihre Testroutinen

	char* input = "ada::monyet";
	char line[] = " I  have   homeworks ";
	int i = 0;
	int nwords;
	char* words[10];
	
	printf("Before: %s \n", input);
	input = extract(input);
	printf("After: %s \n", input);
	
	printf("count: %d \n", count(line));
	
//	printf("%s\n",strtok(line,' '));
	
	nwords = breakIntoWords(line, 10, words);
	for(i = 0; i < nwords; i++){
		printf("%s\n", words[i]);
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
