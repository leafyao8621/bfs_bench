package util;

import java.util.LinkedList;
import java.util.Scanner;

public class Graph {
    private class Node {
        public boolean visited;
        public int prec;
        public LinkedList<Integer> idx;
        public Node() {
            this.visited = false;
            this.prec = 0;
            this.idx = new LinkedList<>();
        }
    }
    private Node[] al;
    public Graph(Scanner s, int node, int edge) {
        this.al = new Node[node];
        for (int i = 0; i < node; ++i) {
            this.al[i] = new Node();
        }
        for (int i = 0; i < edge; ++i) {
            int src = s.nextInt();
            int dest = s.nextInt();
            this.al[src].idx.add(dest);
            this.al[dest].idx.add(src);
        }
    }
    public void log() {
        int idx = 0;
        for (Node i : this.al) {
            System.out.printf("%d:", idx);
            for (int j : i.idx) {
                System.out.printf(" %d", j);
            }
            System.out.println("");
            ++idx;
        }
    }
    public boolean bfs(int src, int dest, boolean verbose) {
        LinkedList<Integer> queue = new LinkedList<>();
        for (Node i : this.al) {
            i.visited = false;
        }
        this.al[src].visited = true;
        queue.add(src);
        for (; !queue.isEmpty();) {
            int cur = queue.removeFirst();
            if (cur == dest) {
                if (verbose) {
                    for (; cur != src; cur = this.al[cur].prec) {
                        System.out.printf("%d<-\n", cur);
                    }
                    System.out.println(src);
                }
                return true;
            }
            for (int i : this.al[cur].idx) {
                if (!this.al[i].visited) {
                    queue.add(i);
                    this.al[i].visited = true;
                    this.al[i].prec = cur;
                }
            }
        }
        return false;
    }
}
