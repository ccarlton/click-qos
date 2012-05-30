#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include "qosclassifierelement.hh"

CLICK_DECLS
QoSClassifierElement::QoSClassifierElement()
{}

QoSClassifierElement::~QoSClassifierElement()
{}

int QoSClassifierElement::configure(Vector<String> &conf, ErrorHandler *errh) {
	return 0;
}

void QoSClassifierElement::push(int, Packet *p){
	click_chatter("Got a packet");


   if(1) {
	   output(0).push(p);
   }
   else if(0) {
      output(1).push(p);
   }
   else {
      output(2).push(p);
   }
}

CLICK_ENDDECLS
EXPORT_ELEMENT(QoSClassifierElement)
