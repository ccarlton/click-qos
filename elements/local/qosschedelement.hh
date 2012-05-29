#ifndef CLICK_QOSSCHEDELEMENT_HH
#define CLICK_QOSSCHEDELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

class QoSSchedElement : public Element { 
	public:
		QoSSchedElement();
		~QoSSchedElement();
		
		const char *class_name() const	{ return "QoSSchedElement"; }
		const char *port_count() const	{ return "3/1"; }
		const char *processing() const	{ return PULL; }
		int configure(Vector<String>&, ErrorHandler*);
		
		Packet* pull(int);
};

CLICK_ENDDECLS
#endif
