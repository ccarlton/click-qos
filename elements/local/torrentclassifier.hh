#ifndef CLICK_QOSCLASSIFIERELEMENT_HH
#define CLICK_QOSCLASSIFIERELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

struct TorrentFlow {
	uint32_t source_ip;
	uint16_t source_port;
};

class TorrentClassifier : public Element { 
	public:
		TorrentClassifier(){}
		~TorrentClassifier(){}
		
		const char *class_name() const	{ return "TorrentClassifier"; }
		const char *port_count() const	{ return "1/2"; }
		const char *processing() const	{ return PUSH; }
		int configure(Vector<String>&, ErrorHandler*){return 0;}
		
		void push(int, Packet *);
		
		bool has_flow(TorrentFlow flow);
		
		Vector<TorrentFlow> flows;
};

CLICK_ENDDECLS
#endif
