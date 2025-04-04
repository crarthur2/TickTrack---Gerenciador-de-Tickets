#include "sistema.h"

int main(){
    Sistema *s = criaSistema();

    rodaSistema(s);

    desalocaSistema(s);

    return 0;
}
