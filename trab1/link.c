#include "link.h"
#include "pagina.h"

struct celLink{
    Link lin;
    struct cellink * proxLink;
};

struct link{
    char * nome;
    Pagina * pag;
};