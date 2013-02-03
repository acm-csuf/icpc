
all: graph_test disjoint_sets_test kruskal_mst_test

graph_test: graph.hh graph_test.cpp
	g++ graph_test.cpp -o graph_test
	./graph_test

disjoint_sets_test: disjoint_sets.hh disjoint_sets_test.cpp
	g++ disjoint_sets_test.cpp -o disjoint_sets_test
	./disjoint_sets_test

kruskal_mst_test: graph_test kruskal_mst.hh kruskal_mst_test.cpp
	g++ kruskal_mst_test.cpp -o kruskal_mst_test
	./kruskal_mst_test
