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