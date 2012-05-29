#ifndef CLICK_QOSCLASSIFIERELEMENT_HH
#define CLICK_QOSCLASSIFIERELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

class QoSClassifierElement : public Element { 
	public:
		QoSClassifierElement();
		~QoSClassifierElement();
		
		const char *class_name() const	{ return "QoSClassifierElement"; }
		const char *port_count() const	{ return "1/3"; }
		const char *processing() const	{ return PUSH; }
		int configure(Vector<String>&, ErrorHandler*);
		
		void push(int, Packet *);
};

CLICK_ENDDECLS
#endif
