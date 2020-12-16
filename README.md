# ParallelComputing
Optimized parallel algorithm for strongly connected components

A multistep algorithm which is a combination of FW-BW and Orzan’s coloring method is implemented. Thread level paral-lelism was used to optimize trimming, Breadth-First Search and coloring steps. This was tested on a Xenon server over agraph with 2 Billion edges and was decomposed in 3 seconds achieving a performance improvement of 20 times over serialalgorithm and 1.92 times over Hong et al. SCC method.
