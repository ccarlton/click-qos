#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>

#include "torrentclassifier.hh"

CLICK_DECLS
	
template<typename T>
inline void get_value(const void * data, T& target)
{
	target = ((T*)data)[0];
}
	
bool TorrentClassifier::has_flow(TorrentFlow flow) {
	return flows.find(flow) != flows.end();
}

void TorrentClassifier::push(int, Packet * p)
{
	TorrentFlow newflow;

	get_value(p->data() + 14 + 12, newflow.source_ip);
	get_value(p->data() + 14 + 20, newflow.source_port);
	
	struct timeval tv;
	gettimeofday(&tv, NULL);
		
	uint32_t ttl = tv.tv_sec + 240;
	
	bool is_torrent = false;
		
	if (has_flow(newflow)) {
		if (flows[newflow] < tv.tv_sec) {
			flows.erase(newflow);
		} else {
			is_torrent = true;
		}
	} else if (p->length() > 20 + 14 + 20 + 20) {
		if (p->data()[20+14+20] == 19 && memcmp(p->data()+1+20+14+20, "BitTorrent protocol", 19) == 0) {
			flows[newflow] = ttl;
			is_torrent = true;
		}
	}
	if (is_torrent)
		output(0).push(p);
	else output(1).push(p);
	
}

CLICK_ENDDECLS
EXPORT_ELEMENT(TorrentClassifier)
