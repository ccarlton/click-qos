


EtherClass::Classifier(12/0800, 12/??)


EtherClass[1] -> NonIP::Queue -> NonIPUnqueue::Unqueue
EtherClass[0] -> CheckIPHeader(14) -> MarkIPHeader(14) -> IPC::IPClassifier(tcp, not tcp);

IPC[0] -> TC::TorrentClassifier
IPC[1] -> NonTCP::Queue
       -> NonTCPUnqueue::BandwidthRatedUnqueue();

TC[0] -> TorrentQueue::Queue
      -> TorrentUnqueue::BandwidthRatedUnqueue();

TC[1] 
      -> RED(MIN_THRESH 100, MAX_THRESH 500, MAX_P .2)
      -> Queue
      -> NonTorrentUnqueue::Unqueue;









