
FromDevice(eth0) ->
EtherClass::Classifier(12/0800, 12/??);


EtherClass[1] -> Print(NonIPPacket, 10)
              -> NonIP::Queue
              -> NonIPShaper::BandwidthShaper(100000);
EtherClass[0] -> CheckIPHeader(14) -> MarkIPHeader(14) -> IPC::IPClassifier(tcp, -);

IPC[0] -> TC::TorrentClassifier;
IPC[1] -> Print(NonTCPPacket, 10)
       -> NonTCP::Queue
       -> NonTCPShaper::BandwidthShaper(100000);

TC[0] -> Print(TorrentPacket, 10)
      -> Queue
      -> TorrentShaper::BandwidthShaper(500000);

TC[1]
      -> Print(TCPNonTorrent, 10)
      -> RED(MIN_THRESH 100, MAX_THRESH 500, MAX_P .2)
      -> TCPQ::Queue;

RR::RoundRobinSched;

TorrentShaper -> [0]RR;
TCPQ          -> [1]RR;
NonTCPShaper  -> [2]RR;
NonIPShaper   -> [3]RR;

RR -> FileWriter::Print(Packet, 10) -> Discard;








