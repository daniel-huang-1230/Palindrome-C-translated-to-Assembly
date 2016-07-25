

#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[]) {

char input[BUFSIZ];

while(fgets(input,BUFSIZ,stdin)!=NULL) {


printf("%s\n", input);

}


return 0;
}
