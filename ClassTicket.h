#ifndef CLASSTICKET_H_INCLUDED
#define CLASSTICKET_H_INCLUDED
#include <string.h>

class TicketAdmin {
private:
    int idT;
    char infoTicket[35];
    char usuarioTicket[35];
    bool ticket;

public:
    TicketAdmin(int i = 0, const char* iT = "XXX", const char* uT = "usuario123@gmail.com", bool t=false) {
        strcpy(this->infoTicket, iT);
        strcpy(this->usuarioTicket, uT);
        this->idT = i;
        this->ticket=t;
}
void setIdT(int id);
void setInfo(const char it[35]);
void setUsuario(const char uT[35]);
void setTicket(bool t=false);
int getId();
const char* getInfoT();
const char* getUsuario();
bool getTicket();
void generarTicket(int id);
void mostrarTickets();
void darDeBajaTickets();
void ticketV(char* asunto);
void fechaV(char* f);
int generarIdTicket();
};


#endif // CLASSTICKET_H_INCLUDED
