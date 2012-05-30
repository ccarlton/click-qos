// test.click

// This configuration should print this line five times:
// ok:   40 | 45000028 00000000 401177c3 01000001 02000002 13691369

// Run it at user level with
// 'click test.click'

// Run it in the Linux kernel with
// 'click-install test.click'
// Messages are printed to the system log (run 'dmesg' to see them, or look
// in /var/log/messages), and to the file '/click/messages'.

sc::QoSSchedElement;
fw::FileWriterElement;

   FromDevice(eth0)
   -> Strip(14)
   -> cl::QoSClassifierElement
  
   cl[0] -> Paint(1) -> q1::Queue
   cl[1] -> Paint(2) -> q2::Queue
   cl[2] -> Paint(3) -> q3::Queue


   q1 -> [0]sc
   q2 -> [1]sc
   q3 -> [2]sc

   sc -> fw

   fw -> Discard;
