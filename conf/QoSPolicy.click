
Script(
    label main,
    set nonipq $(NonIP.length),
    print "-------------Non IP:" $nonipq,

    set nontcp $(NonTCP.length),
    print "-------------Non TCP:" $nontcp,
    
    set tor $(TorQ.length),
    print "-------------Tor:" $tor,

    wait 1,
    goto main $(eq 1 1),    
    stop)

FromDevice(eth0) ->
EtherClass::Classifier(12/0800, 12/??);


EtherClass[1] -> NonIP::Queue
              -> NonIPShaper::BandwidthShaper(100000);
EtherClass[0] -> CheckIPHeader(14) -> MarkIPHeader(14) -> IPC::IPClassifier(tcp, -);

IPC[0] -> TC::TorrentClassifier;
IPC[1] -> NonTCP::Queue
       -> NonTCPShaper::BandwidthShaper(100000);

TC[0] -> TorQ::Queue
      -> TorrentShaper::BandwidthShaper(500000);

TC[1]
      -> RED(MIN_THRESH 100, MAX_THRESH 500, MAX_P .2)
      -> TCPQ::Queue;

RR::RoundRobinSched;

TorrentShaper -> [0]RR;
TCPQ          -> [1]RR;
NonTCPShaper  -> [2]RR;
NonIPShaper   -> [3]RR;

RR -> Discard;








