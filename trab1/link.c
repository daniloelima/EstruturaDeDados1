#include "link.h"
#include "pagina.h"

struct cellink{
    Link link;
    struct cellink * proxLink;
};

struct link{
    char * nome;
    Pagina * pag;
};