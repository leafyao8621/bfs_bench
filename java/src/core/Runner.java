package core;

import util.Graph;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Runner {
    private int node;
    private int edge;
    private int graph;
    private int query;
    private File f;
    private Scanner s;
    public Runner(String fn) throws FileNotFoundException {
        this.f = new File(fn);
        this.s = new Scanner(this.f);
        this.node = this.s.nextInt();
        this.edge = this.s.nextInt();
        this.graph = this.s.nextInt();
        this.query = this.s.nextInt();
    }
    public void run(boolean verbose, boolean graph, boolean path) {
        for (int i = 0; i < this.graph; ++i) {
            if (verbose) {
                System.out.printf("graph %d\n", i);
            }
            Graph g = new Graph(this.s, this.node, this.edge);
            if (graph) {
                g.log();
            }
            for (int j = 0; j < query; ++j) {
                if (verbose) {
                    System.out.printf("query %d\n", j);
                }
                int src = this.s.nextInt();
                int dest = this.s.nextInt();
                boolean res = g.bfs(src, dest, path);
                if (verbose) {
                    System.out.printf("%d %s %d\n",
                                      src,
                                      res ? "->" : "X",
                                      dest);
                }
            }
        }
        this.s.close();
    }
}
