#ifndef CLICK_FILEWRITERELEMENT_HH
#define CLICK_FILEWRITERELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

class FileWriterElement : public Element { 
	public:
		FileWriterElement();
		~FileWriterElement();
		
		const char *class_name() const	{ return "FileWriterElement"; }
		const char *port_count() const	{ return "1/1"; }
		const char *processing() const	{ return PULL; }
		int configure(Vector<String>&, ErrorHandler*);
		
		Packet* pull(int);
};

CLICK_ENDDECLS
#endif
