# "Traveling Salesman Problem Implementations" -- A code repository consisting of implementations of the Euclidean TSP.
# Key Files:
TravelingFrankenstein.cpp -- A C++ file that uses the Simulated Annealing algorithm to generate an initial best path, which is then improved upon by the Two-Opt heuristic and then the 2.5-Opt heuristic. 

test-input-x, where x = [1,7] -- Test cases provided by my instructor that need to finish before three minutes has elapsed.

tsp_example_x, where x = [1,3] -- Test cases that must be optimal within a 1.25 bound of the optimal solution. No running time requirement.

Solutions for test-input-x are in test-input-x-tour and the time taken to generate these solutions are in test-input-x-time.

Solutions for tsp_example_x are in tsp_example_x.txt.AlexHoffer.tour.

Approaches:

For test-input-x where x = [1,5]: Same as for all tsp_example_x.

For all tsp_example_x: Run at a starting temperature of 1000000000 and at each temperature iteration run 100000 options.

For test-input-x where x = 6: Run at a starting temperature of 1000000 and at each temperature iteration run 50000 options.

For test-input-x where x = 7:
