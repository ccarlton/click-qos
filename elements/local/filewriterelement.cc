#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include "filewriterelement.hh"

CLICK_DECLS
FileWriterElement::FileWriterElement()
{}

FileWriterElement::~ FileWriterElement()
{}

int FileWriterElement::configure(Vector<String> &conf, ErrorHandler *errh) {
	return 0;
}

Packet* FileWriterElement::pull(int){
    Packet *p = input(0).pull();

	if(p == 0){
		return 0;
	}
	click_chatter("Got a packet in fileWriter");
	return p;
}

CLICK_ENDDECLS
EXPORT_ELEMENT(FileWriterElement)
