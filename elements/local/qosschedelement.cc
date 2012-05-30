#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include "qosschedelement.hh"

CLICK_DECLS
QoSSchedElement::QoSSchedElement()
{}

QoSSchedElement::~ QoSSchedElement()
{}

int QoSSchedElement::configure(Vector<String> &conf, ErrorHandler *errh) {
	return 0;
}

Packet* QoSSchedElement::pull(int){
        int pullFrom = 0;
        Packet* p;
        p = input(pullFrom).pull();
        pullFrom = pullFrom + 1 % 3;

	if(p == 0){
		return 0;
	}
	click_chatter("Got a packet");
	return p;
}

CLICK_ENDDECLS
EXPORT_ELEMENT(QoSSchedElement)
