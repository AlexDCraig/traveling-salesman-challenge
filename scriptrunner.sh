#!/bin/bash
	rm SimulatedAnnealingAlgorithm
	rm tsp_example_3.txt.AlexHoffer.tour
	g++ SimulatedAnnealingAlgorithm.cpp -o SimulatedAnnealingAlgorithm
	./SimulatedAnnealingAlgorithm tsp_example_3.txt
