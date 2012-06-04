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
	for (int i = 0; i < flows.size(); i++) {
		if (memcmp(&flow, &flows[i], sizeof(TorrentFlow)) == 0) {
			return true;
		}
	}
	return false;
}

void TorrentClassifier::push(int, Packet * p)
{
	TorrentFlow newflow;

	get_value(p->data() + 14 + 12, newflow.source_ip);
	get_value(p->data() + 14 + 20, newflow.source_port);
	
	bool is_torrent = false;
	
	if (has_flow(newflow)) {
		is_torrent = true;
	} else if (p->length() > 20 + 14 + 20 + 20) {
		if (p->data()[20+14+20] == 19 && memcmp(p->data()+1+20+14+20, "BitTorrent protocol", 19) == 0) {
			flows.push_back(newflow);
			is_torrent = true;
		}
	}
	if (is_torrent)
		output(0).push(p);
	else output(1).push(p);
	
}

CLICK_ENDDECLS
EXPORT_ELEMENT(TorrentClassifier)
