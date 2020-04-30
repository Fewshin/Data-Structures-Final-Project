SetA = importdata("dataSetA.csv");
SetB = importdata("dataSetB.csv");

figure(1)
plot(SetA, 'blue')
title("Plot of points in Dataset A")
figure(2)
plot(SetB, 'red')
title("Plot of points in Dataset B")

IPLLA = importdata("insert_performance_LL_dataSetA.csv");
SPLLA = importdata("search_performance_LL_dataSetA.csv");

IPLLB = importdata("insert_performance_LL_dataSetB.csv");
SPLLB = importdata("search_performance_LL_dataSetB.csv");

figure(3)
hold on
plot(IPLLA, 'blue')
plot(IPLLB, 'red')
title("Plot of insert performance for Linked Lists")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(4)
hold on
plot(SPLLA, 'blue')
plot(SPLLB, 'red')
title("Plot of search performance for Linked Lists")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

IPBSTA = importdata("insert_performance_BST_dataSetA.csv");
SPBSTA = importdata("search_performance_BST_dataSetA.csv");

IPBSTB = importdata("insert_performance_BST_dataSetB.csv");
SPBSTB = importdata("search_performance_BST_dataSetB.csv");

figure(5)
hold on
plot(IPBSTA, 'blue')
plot(IPBSTB, 'red')
title("Plot of insert performance for Binary Search Trees")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(6)
hold on
plot(SPBSTA, 'blue')
plot(SPBSTB, 'red')
title("Plot of search performance for Binary Search Trees")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

IPLHTA = importdata("insert_performance_LHT_dataSetA.csv");
ICLHTA = importdata("insert_collisions_LHT_dataSetA.csv");
SPLHTA = importdata("search_performance_LHT_dataSetA.csv");
SCLHTA = importdata("search_collisions_LHT_dataSetA.csv");

IPLHTB = importdata("insert_performance_LHT_dataSetB.csv");
ICLHTB = importdata("insert_collisions_LHT_dataSetB.csv");
SPLHTB = importdata("search_performance_LHT_dataSetB.csv");
SCLHTB = importdata("search_collisions_LHT_dataSetB.csv");

figure(7)
hold on
plot(IPLHTA, 'blue')
plot(IPLHTB, 'red')
title("Plot of insert performance for Linear Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(8)
hold on
plot(SPLHTA, 'blue')
plot(SPLHTB, 'red')
title("Plot of search performance for Linear Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(9)
hold on
plot(ICLHTA, 'blue')
plot(ICLHTB, 'red')
title("Plot of collisions in inserts for Linear Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(10)
hold on
plot(SCLHTA, 'blue')
plot(SCLHTB, 'red')
title("Plot of collisions in searches for Linear Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

IPQHTA = importdata("insert_performance_QHT_dataSetA.csv");
ICQHTA = importdata("insert_collisions_QHT_dataSetA.csv");
SPQHTA = importdata("search_performance_QHT_dataSetA.csv");
SCQHTA = importdata("search_collisions_QHT_dataSetA.csv");

IPQHTB = importdata("insert_performance_QHT_dataSetB.csv");
ICQHTB = importdata("insert_collisions_QHT_dataSetB.csv");
SPQHTB = importdata("search_performance_QHT_dataSetB.csv");
SCQHTB = importdata("search_collisions_QHT_dataSetB.csv");

figure(11)
hold on
plot(IPQHTA, 'blue')
plot(IPQHTB, 'red')
title("Plot of insert performance for Quadratic Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(12)
hold on
plot(SPQHTA, 'blue')
plot(SPQHTB, 'red')
title("Plot of search performance for Quadratic Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(13)
hold on
plot(ICQHTA, 'blue')
plot(ICQHTB, 'red')
title("Plot of collisions in inserts for Quadratic Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(14)
hold on
plot(SCQHTA, 'blue')
plot(SCQHTB, 'red')
title("Plot of collisions in searches for Quadratic Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

IPCHTA = importdata("insert_performance_CHT_dataSetA.csv");
ICCHTA = importdata("insert_collisions_CHT_dataSetA.csv");
SPCHTA = importdata("search_performance_CHT_dataSetA.csv");
SCCHTA = importdata("search_collisions_CHT_dataSetA.csv");

IPCHTB = importdata("insert_performance_CHT_dataSetB.csv");
ICCHTB = importdata("insert_collisions_CHT_dataSetB.csv");
SPCHTB = importdata("search_performance_CHT_dataSetB.csv");
SCCHTB = importdata("search_collisions_CHT_dataSetB.csv");

figure(15)
hold on
plot(IPCHTA, 'blue')
plot(IPCHTB, 'red')
title("Plot of insert performance for Chain Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(16)
hold on
plot(SPCHTA, 'blue')
plot(SPCHTB, 'red')
title("Plot of search performance for Chain Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(17)
hold on
plot(ICCHTA, 'blue')
plot(ICCHTB, 'red')
title("Plot of collisions in inserts for Chain Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")

figure(18)
hold on
plot(SCCHTA, 'blue')
plot(SCCHTB, 'red')
title("Plot of collisions in searches for Chain Hash Tables")
ylabel("Time in nanoseconds")
legend("Set A", "Set B")